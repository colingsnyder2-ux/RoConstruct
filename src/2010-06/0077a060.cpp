// from server: 68% by atomic.potato
struct Sub {
    char pad0[0x38];
    void (__thiscall *fn)(void);
};

struct Outer {
    char pad0[0x24];
    int field24;
    char pad1[0x1c];
    Sub sub;
    int method();
};

extern "C" void __stdcall sub_717e80(int);

int Outer::method()
{
    sub_717e80(field24);
    Sub* s = &sub;
    s->fn();
    return 0;
}
