#include "ChatEngine.h"

CChatEngine* CChatEngine::NewL() {
    CChatEngine* self = new (ELeave) CChatEngine();
    CleanupStack::PushL(self);
    self->ConstructL();
    CleanupStack::Pop(self);
    return self;
}

CChatEngine::CChatEngine() {
    iKey[0] = 0xA56BABCD;
    iKey[1] = 0x0000FACE;
    iKey[2] = 0xDEADBEEF;
    iKey[3] = 0x12345678;
}

void CChatEngine::ConstructL() {
    iUsername = LoadUsernameEncryptedL();
}

CChatEngine::~CChatEngine() {}

void CChatEngine::SetUsernameL(const TDesC& aName) {
    iUsername.Copy(aName);
    SaveUsernameEncryptedL(iUsername);
}

TBuf<16> CChatEngine::Username() const {
    return iUsername;
}

HBufC8* CChatEngine::EncryptMessageL(const TDesC& aMsg) {
    TInt len = aMsg.Length();
    TInt blocks = (len + 7) / 8;
    HBufC8* encrypted = HBufC8::NewL(blocks * 8);
    TPtr8 encPtr = encrypted->Des();

    for (TInt i = 0; i < blocks; i++) {
        TUint32 block[2] = {0};
        TInt chunkLen = Min(8, len - i * 8);
        Mem::Copy(&block, aMsg.Ptr() + i * 8, chunkLen);
        TEA::Encrypt(block, iKey);
        encPtr.Append(reinterpret_cast<TUint8*>(&block), 8);
    }

    return encrypted;
}

void CChatEngine::SendMessageL(const TDesC& aMsg) {
    TBuf<80> taggedMsg;
    taggedMsg.Format(_L("%S: %S"), &iUsername, &aMsg);
    HBufC8* enc = EncryptMessageL(taggedMsg);
    iSocket.Write(*enc);
    delete enc;
}

void CChatEngine::SaveUsernameEncryptedL(const TDesC& aName) {
    RFs fs;
    User::LeaveIfError(fs.Connect());
    CleanupClosePushL(fs);

    RFile file;
    User::LeaveIfError(file.Replace(fs, _L("E:\\System\\Apps\\NLink\\username.dat"), EFileWrite));

    TUint32 block[2] = {0};
    Mem::Copy(&block, aName.Ptr(), Min(aName.Length(), 8));
    TEA::Encrypt(block, iKey);

    TBuf8<8> data;
    data.Copy(reinterpret_cast<TUint8*>(&block), 8);
    file.Write(data);
    file.Close();

    CleanupStack::PopAndDestroy(&fs);
}

TBuf<16> CChatEngine::LoadUsernameEncryptedL() {
    RFs fs;
    User::LeaveIfError(fs.Connect());
    CleanupClosePushL(fs);

    RFile file;
    TBuf<16> name;
    if (file.Open(fs, _L("E:\\System\\Apps\\NLink\\username.dat"), EFileRead) == KErrNone) {
        TBuf8<8> data;
        file.Read(data);

        TUint32 block[2];
        Mem::Copy(&block, data.Ptr(), 8);
        TEA::Decrypt(block, iKey);

        name.Copy(reinterpret_cast<TUint8*>(&block), 8);
        file.Close();
    } else {
        name.Copy(_L("N-LinkUser"));
    }

    CleanupStack::PopAndDestroy(&fs);
    return name;
}
