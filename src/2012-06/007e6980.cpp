// from server: 83% by atomic.potato
struct S
{
    int pad[102];
    int value198;
    int value19c;
    int value1a0;
    int value1a4;
    void f(int *out);
};

void S::f(int *out)
{
    out[0] = value198;
    out[1] = value19c;
    out[2] = value1a0;
    out[3] = value1a4;
}
