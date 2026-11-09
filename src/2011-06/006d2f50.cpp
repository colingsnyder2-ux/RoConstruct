// from server: 46% by atomic.potato
struct S {
    int f();
    int value;
};

extern "C" int callee(int, int);

int S::f()
{
    return callee(1, value + 0xcc);
}
