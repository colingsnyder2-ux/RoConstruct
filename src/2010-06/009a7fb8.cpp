// from server: 51% by atomic.potato
extern "C" void __cdecl func_007a8ade(void *, int, int, void *);

struct S_func_009a7fb8
{
    char pad[0x34];
    void f();
};

void S_func_009a7fb8::f()
{
    func_007a8ade((void *)0x8f2000, 4, 0x18, (char *)(*(char **)(pad - 0x10) + 0x34));
}
