// from server: 100% by tester
struct CXTPPropertyGridItemBool {
    char pad0[0x110];
    int m_value;
    int sub_6989a0(int, int, int);
    int sub_69e490(int, int);
    int sub_69e4d0(int, int, int);
};

int CXTPPropertyGridItemBool::sub_69e4d0(int a, int b, int c)
{
    if (sub_6989a0(a, b, c) == 0)
        return 0;
    if (m_value != 0) {
        if (sub_69e490(b, c) != 0) {
            if (((int (__thiscall *)(CXTPPropertyGridItemBool *))(*(int **)this)[0x58 / 4])(this) == 0) {
                ((void (__thiscall *)(CXTPPropertyGridItemBool *, int, int, int))(*(int **)this)[0xb8 / 4])(this, a, b, c);
            }
        }
    }
    return 1;
}
