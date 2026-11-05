// from server: 72% by atomic.potato
struct FilterStairs
{
    FilterStairs(int, int);
};

struct BallBlockConnector
{
    char pad0[0x20];
    int field20;
    int field24;
    float field28;
    float field2c;
    float field30;
    BallBlockConnector(int, int);
};

BallBlockConnector::BallBlockConnector(int a, int b)
{
    FilterStairs *p = (FilterStairs *)this;
    p->FilterStairs::FilterStairs(a, b);
    field20 = -1;
    field24 = -1;
    field28 = 0.0f;
    field2c = 0.0f;
    field30 = 0.0f;
}
