// from server: 91% by atomic.potato
struct VPlayerEventDesc
{
    char pad0[0x24];
    int offset24;

    void func(int a, int b);
};

extern "C" int __stdcall sub_418F70(int);
extern "C" void __stdcall sub_4C0650(int, double);

void VPlayerEventDesc::func(int a, int b)
{
    int *p = (int *)a;
    if (p)
        p = (int *)((char *)p - 0x1c);
    else
        p = 0;
    int *q = (int *)(offset24 + (int)p);
    int v = *(int *)(b + 4);
    int r = sub_418F70(v);
    double d = *(double *)r;
    sub_4C0650((int)q, d);
}
