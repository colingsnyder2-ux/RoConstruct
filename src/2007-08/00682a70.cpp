// from server: 100% by colin
struct CXTPPropertyGrid {
    char pad[0x154];
    int field_154;
    int sub_00682a70(int);
};

extern "C" int __stdcall func_0062fcf2(int);

int CXTPPropertyGrid::sub_00682a70(int arg)
{
    if (func_0062fcf2(arg) == 0)
        return 0;
    field_154 = 0;
    return 1;
}
