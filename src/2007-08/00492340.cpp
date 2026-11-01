// from server: 100% by colin
struct T_00492340 {
    char pad[0x130];
    int* field_130;
    int m();
};

int T_00492340::m()
{
    int* p = field_130;
    int first = p[1];
    if (first == 0)
        return 0;
    return (p[2] - first) >> 3;
}
