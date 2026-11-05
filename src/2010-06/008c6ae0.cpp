// from server: 100% by colin
namespace ns_ROCX000015 {
struct S
{
    int pad0;
    int object;
    int value;
    int f(int amount);
};

int S::f(int amount)
{
    int* p = *(int**)(object);
    ((void (__thiscall *)(int, int))p[0x3b])(object, value + amount);
    return value;
}
}
