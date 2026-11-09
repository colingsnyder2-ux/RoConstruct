// from server: 73% by atomic.potato
struct S
{
    void* f(void*);
};

extern "C" void* __cdecl sub_72ee20(void*, void*);
extern "C" void* __cdecl sub_76a190(void*, void*);

void* S::f(void* p)
{
    void* value = sub_72ee20(this, (char*)p + 4);
    void* local = *(void**)value;
    return sub_76a190(this, &local);
}
