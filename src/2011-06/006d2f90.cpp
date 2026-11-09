// from server: 65% by atomic.potato
struct S
{
    int f();
    int value[181];
};

extern "C" int __stdcall target(int, int);

int S::f()
{
    return target(3, value[180] + 204);
}
