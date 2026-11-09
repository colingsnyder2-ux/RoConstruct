// from server: 0% by atomic.potato
struct S {
    char __thiscall sub_5fb5b0(void**);
    void f(void*);
};

extern "C" void __stdcall sub_7f90e0(int, const char*, const char*, int, int, int, int);
extern "C" void __stdcall sub_40ddc0(void*);
extern "C" void __stdcall sub_666da0(void*, void*);
extern char g_cd6199;

void S::f(void* arg)
{
    void* local = 0;
    if (g_cd6199) {
        sub_7f90e0(3, (const char*)0xa5cf5c, (const char*)0xa5cf24, 0x1c6, 0, 0, 0);
    }
    while (sub_5fb5b0(&local)) {
        sub_666da0(local, arg);
    }
    if (local) {
        sub_40ddc0((char*)local + 5);
    }
}
