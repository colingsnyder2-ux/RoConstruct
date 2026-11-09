// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
struct Value { int x; };
extern struct Desc0 { int pad[8]; } g_00bb1efc;
Value& sub_0067f2e0(void*);

Value& func_0047ad10()
{
    static Value& value = sub_0067f2e0(&g_00bb1efc);
    return value;
}
