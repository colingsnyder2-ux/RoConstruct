// from server: 73% by atomic.potato
extern "C" void __stdcall G1_func_007a7f70();

struct CWebToolbox
{
    void f(int);
};

void CWebToolbox::f(int)
{
    G1_func_007a7f70();
    *(int*)((char*)this + 0x0c) = 0x32;
}
