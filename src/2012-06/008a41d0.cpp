// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
struct Value { int x; };
extern struct Desc0 { int pad[8]; } g_00c00e94;
Value& sub_0067f2e0(void*);

Value& func_008a41d0()
{
    static Value& value = sub_0067f2e0(&g_00c00e94);
    return value;
}
