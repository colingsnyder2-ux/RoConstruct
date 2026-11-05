// from server: 100% by atomic.potato
extern "C" void __stdcall func_0080a62e();

struct CWebToolbox
{
    void f(int*);
};

void CWebToolbox::f(int* p)
{
    func_0080a62e();
    p[3] = 0x32;
}
