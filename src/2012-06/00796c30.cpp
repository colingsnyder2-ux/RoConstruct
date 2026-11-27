// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Q { char pad[0x108]; int value; };
struct R { char pad[0x198]; Q* q; };
struct S
{
    char pad[0x224];
    int member;
    R* Helper(int, int*);
    int Get();
};
int S::Get()
{
    R* r = Helper(0, &member);
    if (r)
        return r->q->value;
    return 0;
}
