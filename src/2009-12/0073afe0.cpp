// from server: 12% by atomic.potato
struct S {
    int value;
    void release(int);

    void f();
};

void S::release(int value)
{
}

void S::f()
{
    int value = *(int*)((char*)this + 0x0c);
    if (value)
        release(value);
}
