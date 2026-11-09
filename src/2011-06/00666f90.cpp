// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
struct Value { int x; };
extern struct Desc0 { int pad[8]; } g_00a9c0c4;
Value& sub_00592b40(void*);

Value& func_00666f90()
{
    static Value& value = sub_00592b40(&g_00a9c0c4);
    return value;
}
