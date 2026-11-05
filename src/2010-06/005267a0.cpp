// from server: 52% by atomic.potato
extern "C" void __stdcall std_string_destructor(void*);

struct S_func_005267a0
{
    void f();
};

void S_func_005267a0::f()
{
    std_string_destructor((char*)this + 4);
}
