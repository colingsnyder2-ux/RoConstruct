// from server: 42% by atomic.potato
extern "C" int __cdecl sub_719EB6(int, int, int);

struct RBX_MeshPartCustomizableKey
{
    int compute(int a, int b);
};

int RBX_MeshPartCustomizableKey::compute(int a, int b)
{
    int local = 0x69;
    if (a == 0)
        return 0;
    int chosen;
    if (a > 0x69)
        chosen = local;
    else
        chosen = a;
    sub_719EB6(a, chosen, chosen);
    return chosen;
}
