#ifndef CHATENGINE_H
#define CHATENGINE_H

#include <e32base.h>
#include <es_sock.h>
#include "TEA.h"

class CChatEngine : public CBase {
public:
    static CChatEngine* NewL();
    ~CChatEngine();

    void SendMessageL(const TDesC& aMsg);
    void SetUsernameL(const TDesC& aName);
    TBuf<16> Username() const;

    // Bluetooth peer-to-peer
    void StartBluetoothDiscoveryL();
    void ConnectToDeviceL(const TDesC& aBtAddr);
    void ListenForConnectionL();
    void HandleIncomingConnectionL();
    void ExchangeUsernamesL();
    bool IsUsernameUnique(const TDesC& aPeerName) const;

private:
    CChatEngine();
    void ConstructL();
    HBufC8* EncryptMessageL(const TDesC& aMsg);
    HBufC* DecryptMessageL(const TDesC8& aData);
    void SaveUsernameEncryptedL(const TDesC& aName);
    TBuf<16> LoadUsernameEncryptedL();

private:
    RSocketServ iSocketServ;
    RSocket iSocket;
    TUint32 iKey[4];
    TBuf<16> iUsername;
    TBuf<16> iPeerUsername;
};

#endif
