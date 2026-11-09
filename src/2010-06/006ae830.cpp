// from server: 49% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __cdecl sub_4B2790();
extern "C" void __cdecl sub_6AD640();

extern unsigned char byte_BA805C;

struct Inner {
    int a;
    volatile long ref;
};

struct Outer {
    char pad0[0x24];
    int m24;
    Inner* m28;
    void sub_6AE830(int, int, int, int);
};

void Outer::sub_6AE830(int a1, int a2, int a3, int a4)
{
    sub_4B2790();
    unsigned char v = byte_BA805C;
    Inner* p = m28;
    int tmp[2];
    tmp[0] = m24;
    tmp[1] = (int)p;
    if (p != 0) {
        _InterlockedExchangeAdd(&p->ref, 1);
    }
    sub_6AD640();
}
