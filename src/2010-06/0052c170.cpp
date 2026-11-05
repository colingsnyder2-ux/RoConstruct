// from server: 45% by atomic.potato
struct S
{
    int unused;
    float *p;
    void Set(float value);
    S();
};

void S::Set(float value)
{
    *p = value;
}

S::S()
{
    *(int *)this = 0xA1ED84;
}
