// from server: 23% by colin
struct VPlayerListener {
    void evaluate(int a, int b);
};

void VPlayerListener::evaluate(int a, int b)
{
    VPlayerListener* p = this;
    if (p)
        p = (VPlayerListener*)((char*)p - 0x100);
    else
        p = 0;
    int* vtbl = *(int**)b;
    void (__stdcall* fn)(VPlayerListener*, int) = *(void (__stdcall**)(VPlayerListener*, int))vtbl;
    fn(p, a);
}
