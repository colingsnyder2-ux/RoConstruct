// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
struct Value { int x; };
extern struct Desc0 { int pad[8]; } g_00aa7968;
Value& sub_00592b40(void*);

Value& func_006deaa0()
{
    static Value& value = sub_00592b40(&g_00aa7968);
    return value;
}
