// from server: 75% by atomic.potato
struct S
{
    int value;
    volatile float field;
    S(float);
};

S::S(float v)
{
    value = 0xabd3a0;
    field = v;
}
