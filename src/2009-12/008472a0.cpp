// from server: 100% by atomic.potato
extern "C" void __stdcall sub_00847260(int, int);

struct CXTPControls
{
    void f(int);
};

void CXTPControls::f(int value)
{
    sub_00847260(value, -1);
}
