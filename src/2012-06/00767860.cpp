// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
struct Value { int x; };
extern struct Desc0 { int pad[8]; } g_00bed648;
Value& sub_0067f2e0(void*);

Value& func_00767860()
{
    static Value& value = sub_0067f2e0(&g_00bed648);
    return value;
}
