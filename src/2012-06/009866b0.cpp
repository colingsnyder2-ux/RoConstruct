// from server: 88% by Intel
struct CMap
{
    void func_009866b0();
};

void CMap::func_009866b0()
{
    while (*(int *)((char *)this + 0x64) > 0)
    {
        int v1 = *(int *)((char *)this + 0x60);
        int v2 = *(int *)v1;
        int v3 = *(int *)v2;
        void (__stdcall *v4)(int) = (void (__stdcall *)(int))*(int *)(v3 + 0xB8);
        v4(0);
    }
}
