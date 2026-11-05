// from server: 100% by atomic.potato
struct S
{
    void f();
};

extern "C" void __cdecl sub_915d40(void*, int);
extern "C" void __cdecl sub_982114(void*);

void S::f()
{
    void* p = *(void**)((char*)this + 12);
    if (p)
    {
        int v = *(int*)((char*)p + 12);
        sub_915d40(p, v);
        sub_982114(p);
    }
}
