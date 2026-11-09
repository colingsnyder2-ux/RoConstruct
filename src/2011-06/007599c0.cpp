// from server: 29% by atomic.potato
struct BallBlockConnector
{
    BallBlockConnector* initialize(int, int);
    int field00;
    int field04;
    short field08;
    int field0c;
    int field1c;
    int field20;
    short field24;
    int field28;
};

BallBlockConnector* BallBlockConnector::initialize(int a, int b)
{
    field1c = -1;
    field20 = -1;
    field24 = 0;
    field28 = 0;
    return this;
}
