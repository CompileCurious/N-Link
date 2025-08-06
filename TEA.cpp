#include "TEA.h"

void TEA::Encrypt(TUint32* v, const TUint32* k) {
    TUint32 v0 = v[0], v1 = v[1], sum = 0, delta = 0x9e3779b9;
    for (TInt i = 0; i < 32; i++) {
        sum += delta;
        v0 += ((v1 << 4) + k[0]) ^ (v1 + sum) ^ ((v1 >> 5) + k[1]);
        v1 += ((v0 << 4) + k[2]) ^ (v0 + sum) ^ ((v0 >> 5) + k[3]);
    }
    v[0] = v0; v[1] = v1;
}

void TEA::Decrypt(TUint32* v, const TUint32* k) {
    TUint32 v0 = v[0], v1 = v[1], sum = 0xC6EF3720, delta = 0x9e3779b9;
    for (TInt i = 0; i < 32; i++) {
        v1 -= ((v0 << 4) + k[2]) ^ (v0 + sum) ^ ((v0 >> 5) + k[3]);
        v0 -= ((v1 << 4) + k[0]) ^ (v1 + sum) ^ ((v1 >> 5) + k[1]);
        sum -= delta;
    }
    v[0] = v0; v[1] = v1;
}
