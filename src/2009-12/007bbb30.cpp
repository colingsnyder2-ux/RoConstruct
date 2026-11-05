// from server: 50% by atomic.potato
struct S
{
    int value;
    unsigned char flag;
    float x;
    float y;
    float z;

    S(int);
};

S::S(int v)
{
    value = v;
    flag = 1;
    x = 0.0f;
    y = 0.0f;
    z = 0.0f;
}
