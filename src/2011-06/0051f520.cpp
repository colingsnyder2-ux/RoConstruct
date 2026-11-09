// from server: 100% by atomic.potato
struct AtomicInt32 {
    void increment();
};

struct S {
    char pad0[0xac8];
    AtomicInt32 first;
    char pad1[0x14];
    int value;
    int f();
};

int S::f()
{
    first.increment();
    int result = value;
    first.increment();
    return result;
}
