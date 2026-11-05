// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
struct Value { int x; };
extern struct Desc0 { int pad[8]; } g_00a0bbe4;
Value& sub_005cd6b0(void*);

Value& func_004b3a50()
{
    static Value& value = sub_005cd6b0(&g_00a0bbe4);
    return value;
}
