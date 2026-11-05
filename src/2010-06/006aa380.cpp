// from server: 69% by atomic.potato
struct S
{
    int vtable;
    int a;
    int b;
    void f();
};

extern "C" void __stdcall func_00795310(void*);

void S::f()
{
    vtable = 0xA41218;
    func_00795310((char*)this + 8);
    func_00795310((char*)this + 4);
}
