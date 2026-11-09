// from server: 72% by atomic.potato
struct S_007e3930 {
};

void __cdecl f(char* a, char* b)
{
    typedef void (__thiscall *F)(char*, char*);
    char* p = b;
    if (p != 0) {
        F f = *(F*)(*(char**)(p + 0x1c) + 4);
        f(p + 0x1c, a + 0x1c);
    } else {
        F f = *(F*)(*(char**)0 + 4);
        f(0, a + 0x1c);
    }
}
