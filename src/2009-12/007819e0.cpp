// from server: 100% by atomic.potato
struct S_007819e0
{
    char pad0[8];
    void f();
};

extern "C" void __cdecl sub_00782eb0(void*);
extern "C" void __cdecl sub_00782960(void*);

void S_007819e0::f()
{
    void* p = (void*)((char*)this + 8);
    sub_00782eb0(p);
    sub_00782960(p);
}
