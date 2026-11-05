// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
struct Value { int x; };
extern struct Desc0 { int pad[8]; } g_008df1b8;
Value& sub_005cd6b0(void*);

Value& func_00445a20()
{
    static Value& value = sub_005cd6b0(&g_008df1b8);
    return value;
}
