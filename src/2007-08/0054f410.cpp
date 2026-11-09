// from server: 100% by colin
struct S {
    unsigned char pad0[0x10];
    int* p10;
    int* p14;
    unsigned char pad18[0x8];
    int* p20;
    int* p24;
    unsigned char pad28[0x8];
    int* p30;
    int* p34;
    unsigned char pad38[0x64];
    unsigned int flags9c;
    void f(unsigned int);
};

void S::f(unsigned int a)
{
    if (a == 1) {
        if ((flags9c & 2) == 0) {
            *p10 = 0;
            *p20 = 0;
            *p30 = 0;
            flags9c |= 2;
        }
    } else if (a == 2) {
        if ((flags9c & 4) == 0) {
            (*(void (__thiscall **)(void))(*((int*)this) + 0x30))();
            *p14 = 0;
            *p24 = 0;
            *p34 = 0;
            flags9c |= 4;
        }
    }
}
