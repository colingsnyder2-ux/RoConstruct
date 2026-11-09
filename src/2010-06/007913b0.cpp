// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
struct Value { int x; };
extern struct Desc0 { int pad[8]; } g_00a53e98;
Value& sub_00594140(void*);

Value& func_007913b0()
{
    static Value& value = sub_00594140(&g_00a53e98);
    return value;
}
