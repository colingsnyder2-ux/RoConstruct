// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
struct Value { int x; };
extern struct Desc0 { int pad[8]; } g_00abe6e8;
Value& sub_00592b40(void*);

Value& func_00785b50()
{
    static Value& value = sub_00592b40(&g_00abe6e8);
    return value;
}
