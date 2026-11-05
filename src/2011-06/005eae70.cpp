// from server: 100% by atomic.potato
typedef unsigned int DWORD;

extern "C" void __fastcall ReleaseObject(void *);
extern "C" void __cdecl DestroyObject(void *);

struct UEvents {
    DWORD pad0;
    DWORD pad1;
    DWORD pad2;
    void *value;
    void f();
};

void UEvents::f()
{
    void *p = value;
    if (p != 0) {
        ReleaseObject((char *)p + 4);
        ReleaseObject(p);
        DestroyObject(p);
    }
}
