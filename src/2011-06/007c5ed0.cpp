// from server: 60% by atomic.potato
struct S
{
    int value[41];

    S();
};

S::S()
{
    value[40] = 0;
}
