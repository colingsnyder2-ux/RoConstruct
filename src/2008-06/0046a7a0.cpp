// from server: 100% by atomic.potato
extern "C" void __cdecl func_006a0c68();

struct CWebToolbox
{
    void f(CWebToolbox* value);
};

void CWebToolbox::f(CWebToolbox* value)
{
    func_006a0c68();
    *(int*)((char*)value + 12) = 50;
}
