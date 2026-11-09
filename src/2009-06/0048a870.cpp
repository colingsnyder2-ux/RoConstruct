// from server: 100% by colin
namespace ns_ROCX000009 {
// from server: 100% by atomic.potato
struct S
{
    int f();
};

int S::f()
{
    if ((int)this < 2)
        return 2;

    int value = 1;
    while (value < (int)this)
        value += value;

    return value;
}
}
