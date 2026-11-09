// from server: 78% by atomic.potato
extern "C" void __cdecl call_983270(void *, unsigned int, unsigned int, void *);
extern "C" void __cdecl call_982114(void *);
extern "C" void *global_5b5770;

struct S {
    void *field_0c;
    void f();
};

void S::f()
{
    void *p = field_0c;
    if (p != 0) {
        call_983270((char *)p + 8, 0x28, 0x28, global_5b5770);
        call_982114(p);
    }
}
