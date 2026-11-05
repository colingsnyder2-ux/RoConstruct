// from server: 100% by atomic.potato
struct BallPolyContact
{
    int value0;
    int value4;
    int value8;
    int valueC;
    int value10;
    int value14;
    BallPolyContact(int, int, int *);
};

BallPolyContact::BallPolyContact(int a, int b, int *v)
{
    value0 = 0xbfdb74;
    valueC = v[0];
    value10 = v[1];
    value14 = v[2];
    value4 = a;
    value8 = b;
}
