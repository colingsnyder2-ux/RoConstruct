// from server: 0% by atomic.potato
struct S_func_00654270 {
    void f();
};

extern "C" void __stdcall close_ifstream(void* p);

void S_func_00654270::f()
{
    void* p = *(void**)0x00000008;
    close_ifstream(p);
}
