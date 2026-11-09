// from server: 28% by colin
struct VDHTMLWindow_SignalDesc
{
    int field0;
    int field4;
    int field8;
    void construct(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o);
};

extern "C" void __stdcall sub_414840(int *a, int *b);
extern "C" void __stdcall sub_418A50(int *a);
extern "C" void __stdcall sub_4144E0(int *a);

void VDHTMLWindow_SignalDesc::construct(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o)
{
    int local[14];
    int *p;

    field0 = 0;
    field4 = 0;
    field8 = 0;

    local[0] = a;
    local[1] = b;

    p = &local[2];
    sub_414840(p, &local[13]);

    sub_418A50((int *)this);

    sub_4144E0(&local[9]);
}
