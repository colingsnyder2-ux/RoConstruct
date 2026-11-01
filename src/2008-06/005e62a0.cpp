// from server: 100% by colin
#include <intrin.h>
// roc-cl: 21022
struct Clump {
    char pad0[0x14];
    unsigned char f14;
    char pad15[0xb];
    Clump* f20;
    char pad24[0x30];
    unsigned char f54;
    char pad55[0x14];
    unsigned char f69;
    void mark();
};

void Clump::mark() {
    unsigned char one = 1;
    f14 = one;
    f54 = one;
    _ReadWriteBarrier();
    f69 = one;
    Clump** pp = &f20;
    while (*pp != 0) {
        _ReadWriteBarrier();
        Clump* p = *pp;
        p->f14 = one;
        p->f54 = one;
        p->f69 = one;
        pp = &p->f20;
    }
}
