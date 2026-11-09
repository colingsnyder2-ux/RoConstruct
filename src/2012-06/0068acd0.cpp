// from server: 32% by atomic.potato
extern "C" int __cdecl sub_68A5E0(int);
extern "C" void __cdecl sub_6CAB60();
extern "C" void __cdecl sub_9831F5(void*);

extern unsigned char byte_E2AFEC;
extern int dword_BA3820;
extern unsigned char byte_E2AE08;

struct S {
    void f();
};

void S::f()
{
    if ((byte_E2AFEC & 1) == 0) {
        byte_E2AFEC |= 1;
        int v = 0;
        char buf[12];
        buf[0] = 0;
        buf[1] = 0;
        *(int*)(buf + 4) = 0;
        *(int*)(buf + 8) = 0x1b;
        int r = sub_68A5E0(dword_BA3820);
        sub_6CAB60();
        sub_9831F5((void*)0xB15B10);
    }
}
