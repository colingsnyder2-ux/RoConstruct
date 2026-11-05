// from server: 56% by atomic.potato
struct S {
    char padding[440];
    float value;
    void f(float);
};

void S::f(float v)
{
    if (v != value)
    {
        value = v;
        *(unsigned int*)4 = 0x00e4aa38;
    }
}
