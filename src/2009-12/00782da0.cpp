// from server: 36% by atomic.potato
struct S_func_00782da0 {
    void f();
};

extern "C" void __stdcall sub_005ea3e0(void*);
extern "C" void __stdcall sub_00782740(void*, void*);
extern "C" void __stdcall sub_00783f30(void*, void*, void*, void*);

void S_func_00782da0::f()
{
    void* p1 = 0;
    void* p2 = 0;
    void* p3 = 0;
    sub_00782740(*(void**)((char*)this + 0), &p1);
    sub_00783f30(*(void**)((char*)this + 0), &p2, *(void**)((char*)this + 4), *(void**)((char*)this + 8));
    sub_005ea3e0(p3);
}
