// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD

struct A { char a[0x54]; };
struct B { int b; };
struct D : A, B {};
struct S
{
    char padding[0x50];
    int count;
    D** items;
    int find(B* value);
};
int S::find(B* value)
{
    for (int i = 0; i < count; ++i)
    {
        if (items[i] == value)
            return i;
    }
    return -1;
}
