// from server: 63% by atomic.potato
struct ChangePropertyItem
{
    void __cdecl f(int a, int b);
};

extern "C" void __cdecl sub_4f09a0(int, void *);
extern "C" void __cdecl sub_4f9060(void *);

void ChangePropertyItem::f(int a, int b)
{
    char value[8];

    sub_4f09a0(b, value);
    if (*(int *)((char *)b + 4) != 0)
        sub_4f9060(value);
}
