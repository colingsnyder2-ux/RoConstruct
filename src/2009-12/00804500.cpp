// from server: 100% by atomic.potato
struct S
{
    int Get();
};

extern "C" int __fastcall GetValue(S *);

int S::Get()
{
    int *p = (int *)GetValue(this);
    if (p)
        return p[23];
    return 0;
}
