// from server: 83% by colin
struct CRobloxWnd {
    char pad[0x68];
    int field_68;
    char pad2[0x74 - 0x6c];
    int field_74;
    void method_4598a0();
    void method_458c00();
    void method_63023e();
    void method_464d30();
    void func_00459ba0(int);
};

void CRobloxWnd::func_00459ba0(int arg)
{
    switch (arg) {
    case 0:
        method_458c00();
        method_4598a0();
        break;
    case 1:
        if (field_68 != 0) {
            if (field_74 != 0) {
                method_464d30();
                method_63023e();
                return;
            }
        }
        break;
    }
    method_63023e();
}
