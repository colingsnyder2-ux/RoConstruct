// from server: 68% by atomic.potato
struct S {
    int f();
};

int S::f()
{
    float value = f();
    return value > 0.0f ? 1 : 0;
}
