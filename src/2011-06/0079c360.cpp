// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD /Ob2 /Oy /GF
struct Value { int x; };
Value& sub_00592b40(int);

Value& func_0079c360()
{
    static Value& value = sub_00592b40(11267216);
    return value;
}
