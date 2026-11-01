// from server: 100% by atomic.potato
struct CWebToolbox
{
    void f(int);
};

extern "C" int __stdcall sub_0080a40c(int);

void CWebToolbox::f(int value)
{
    if (!sub_0080a40c(value))
        *(int *)(value + 4) |= 0x01844017;
}
