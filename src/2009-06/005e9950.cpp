// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
struct Value { int x; };
extern struct Desc0 { int pad[8]; } g_00a1cf20;
Value& sub_005cd6b0(void*);

Value& func_005e9950()
{
    static Value& value = sub_005cd6b0(&g_00a1cf20);
    return value;
}
