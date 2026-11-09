// from server: 87% by atomic.potato
struct CSettingsPropGrid
{
    int sub_40A3B0();
    int sub_43F510(int, void*);
    int sub_662CF0(const void*);
    void func(int, void*);
};

void CSettingsPropGrid::func(int a, void* b)
{
    sub_40A3B0();
    if (sub_662CF0(b) != 0)
    {
        sub_43F510(a, b);
    }
}
