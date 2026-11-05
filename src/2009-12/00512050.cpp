// from server: 16% by atomic.potato
struct S {
    void f();
};

void S::f()
{
    if (*(int*)this != 0)
        goto target;
target:
    return;
}
