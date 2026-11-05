// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
struct Value { int x; };
extern struct Desc0 { int pad[8]; } g_00b8ff7c;
Value& sub_0067f2e0(void*);

Value& func_00402550()
{
    static Value& value = sub_0067f2e0(&g_00b8ff7c);
    return value;
}
