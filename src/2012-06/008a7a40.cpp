// from server: 77% by atomic.potato
typedef int (__thiscall *Fn495f40)(void *);
typedef void * (__cdecl *Fn983b6a)(int);
typedef int (__thiscall *FnImport)(void *, void *);

extern "C" int __cdecl call_495f40(void *);
extern "C" void * __cdecl call_983b6a(int);
extern "C" FnImport g_import;

struct TToolVerb {
    char padding[12];
    void *field_0c;
    int f();
};

int TToolVerb::f()
{
    int value = call_495f40(*(void **)((char *)field_0c + 0xac4));
    if (value)
    {
        void *converted = call_983b6a(value);
        return g_import((void *)0xdecb98, converted);
    }
    return 0;
}
