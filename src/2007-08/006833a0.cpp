// from server: 100% by colin
extern "C" __declspec(dllimport) int __stdcall InvalidateRect(void*, const void*, int);

struct CXTPPropertyGrid
{
    char pad[0x20];
    void* field20;
    char pad2[0x140 - 0x24];
    int field140;
    void sub_63023e();
    void func(int);
};

void CXTPPropertyGrid::func(int a)
{
    if (field140 != -1)
    {
        field140 = -1;
        InvalidateRect(field20, 0, 0);
    }
    sub_63023e();
}
