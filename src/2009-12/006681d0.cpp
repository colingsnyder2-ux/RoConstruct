// from server: 88% by atomic.potato
extern "C" void __cdecl sub_7e78e0(void*);
extern "C" void __cdecl sub_7f385a(void*);

struct UEvents
{
    void f();
};

void UEvents::f()
{
    void* p = *(void**)((char*)this + 12);
    if (p != 0)
    {
        sub_7e78e0((char*)p + 4);
        sub_7e78e0(p);
        sub_7f385a(p);
    }
}
