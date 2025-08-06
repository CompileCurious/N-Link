#ifndef TEA_H
#define TEA_H

#include <e32std.h>

class TEA {
public:
    static void Encrypt(TUint32* v, const TUint32* k);
    static void Decrypt(TUint32* v, const TUint32* k);
};

#endif
