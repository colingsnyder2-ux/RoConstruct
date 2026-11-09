// from server: 32% by atomic.potato
extern "C" void __stdcall sub_401610(int, int);
extern "C" void __stdcall sub_80B15D(int);

struct S {
    int f();
};

int S::f()
{
    *(int*)this = 0;
    sub_401610(0xcce6e8, 0x67eb90);
    if (!(*(unsigned char*)0xcce6d8 & 1)) {
        *(unsigned int*)0xcce6d8 |= 1;
        *(unsigned int*)0xcce6d0 = 0;
        *(unsigned int*)0xcce6d4 = 0;
        sub_80B15D(0xa3b4b0);
    }
    return (int)this;
}
