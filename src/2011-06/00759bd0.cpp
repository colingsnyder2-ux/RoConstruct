// from server: 100% by atomic.potato
struct RBX_BallBallContact {
    char pad0[0x1c];
    int field1c;
    int field20;
    short field24;
    char pad26[2];
    int field28;
    int field2c;
    void sub_7c4a40(int, int);
    RBX_BallBallContact* construct(int, int);
};

RBX_BallBallContact* RBX_BallBallContact::construct(int a, int b)
{
    sub_7c4a40(a, b);
    field1c = -1;
    field20 = -1;
    field24 = 0;
    field28 = 0;
    field2c = 0;
    *(int*)this = 0xab6324;
    return this;
}
