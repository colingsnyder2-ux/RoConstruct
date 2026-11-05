// from server: 41% by atomic.potato
struct S
{
    int *p;
    void f(float value);
    S();
};

void S::f(float value)
{
    *p = value;
}

S::S()
{
    *(int*)this = 0x9b3794;
}
