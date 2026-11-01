// from server: 100% by tester
struct CRobloxControlColorSelector
{
    char pad[0x174];
    int field_168;
    int sub_44BBD0(int, int);
    void sub_63A690(int);
    void sub_44BF20(int, int);
};

void CRobloxControlColorSelector::sub_44BF20(int a, int b)
{
    int r = sub_44BBD0(a, b);
    if (r != -1)
    {
        field_168 = r;
        sub_63A690(1);
    }
}
