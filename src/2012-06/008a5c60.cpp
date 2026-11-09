// from server: 73% by atomic.potato
typedef int (__thiscall *Fn495F40)(void *);
typedef int (__cdecl *Fn983B6A)(int);
typedef int (__stdcall *FnImport)(void *, int);

extern "C" int __cdecl Call495F40(void *);
extern "C" int __cdecl Call983B6A(int);
extern "C" int __stdcall CallImport(void *, int);

struct TToolVerb
{
    int f();
    void *pad0;
    void *pad1;
    void *pad2;
};

int TToolVerb::f()
{
    void *a = ((void **)this)[3];
    void *b = ((void **)a)[0x2b1];
    int v = Call495F40(b);
    if (!v)
        return 0;
    v = Call983B6A(v);
    return CallImport((void *)0x00debf74, v);
}
