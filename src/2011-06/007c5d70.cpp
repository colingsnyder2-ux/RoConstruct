// from server: 100% by atomic.potato
struct BallPolyContact
{
    int v0;
    int v1;
    int v2;
    int v3;
    int v4;
    int v5;
    BallPolyContact(int, int, int*);
};

BallPolyContact::BallPolyContact(int a, int b, int* c)
{
    v0 = 0xabd5d0;
    v3 = c[0];
    v4 = c[1];
    v5 = c[2];
    v1 = a;
    v2 = b;
}
