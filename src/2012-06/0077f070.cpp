// from server: 79% by atomic.potato
typedef unsigned int DWORD;

extern "C" void* __cdecl sub_0087A160(void*);
extern "C" void sub_0076A190(void*, void*);

struct W4SpecialKey
{
    void f(void*);
};

void W4SpecialKey::f(void* p)
{
    void* q = sub_0087A160((char*)p + 4);
    void* r = *(void**)q;
    sub_0076A190(this, &r);
}
