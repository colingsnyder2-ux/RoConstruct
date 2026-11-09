// from server: 62% by atomic.potato
extern "C" int __cdecl sub_4f9000(void *);
extern "C" void __cdecl sub_4f19f0(int, int);

struct ChangePropertyItem
{
    void __cdecl f(void *, void *);
};

void ChangePropertyItem::f(void *a, void *b)
{
    int v = sub_4f9000(this);
    sub_4f19f0(v, (int)b);
}
