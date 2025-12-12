#ifndef TEA_H
#define TEA_H

#include <e32std.h>


class TEA {
public:
    static void Encrypt(TUint32* v, const TUint32* k);
    static void Decrypt(TUint32* v, const TUint32* k);
    // CBC helpers
    static void EncryptCBC(TUint8* data, TInt len, const TUint32* k, TUint8* iv);
    static void DecryptCBC(TUint8* data, TInt len, const TUint32* k, TUint8* iv);
    // Padding helpers
    static TInt Pad(TUint8* data, TInt len, TInt blockSize);
    static TInt Unpad(const TUint8* data, TInt len);
};

#endif
