// from server: 100% by colin
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Value { int x; };
Value& sub_00592b40(void*);
struct Desc { int pad[8]; };
extern Desc g_00a96c9c;

Value& func_00635dc0()
{
    static Value& value = sub_00592b40(&g_00a96c9c);
    return value;
}
