// from server: 60% by atomic.potato
typedef int BOOL;

struct S {
    void* field;
    BOOL f();
};

extern "C" void* __cdecl sub_495f40(void*);
extern "C" void* __cdecl sub_983b6a(void*);
typedef void (__cdecl *Fn)(void*, void*);
extern Fn g_call;

BOOL S::f()
{
    void* a = sub_495f40(*(void**)((char*)this->field + 0xac4));
    if (!a)
        return 0;
    a = sub_983b6a(a);
    g_call((void*)0x00dec4a4, a);
    return 1;
}
