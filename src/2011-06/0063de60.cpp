// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
struct Value { int x; };
extern struct Desc0 { int pad[8]; } g_00ab63e4;
Value& sub_00592b40(void*);

Value& func_0063de60()
{
    static Value& value = sub_00592b40(&g_00ab63e4);
    return value;
}
