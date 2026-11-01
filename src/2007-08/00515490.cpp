// from server: 100% by colin
struct DialogTemplate
{
    char pad[0x244];
    int field244;
    int field248;
};

extern "C" int __cdecl sub_51EA60(int a, int b, int c);
extern "C" void __cdecl sub_514F30(int* p, int n);

int __cdecl sub_515490(DialogTemplate* p)
{
    if (p == 0)
        return 0;

    int v = sub_51EA60(2, p->field248, p->field244);
    if (v != 0)
    {
        sub_514F30(&v, 0x120);
    }
    return v;
}
