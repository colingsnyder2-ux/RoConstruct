// from server: 60% by atomic.potato
struct ContentProviderJob
{
    int f(int, int);
    int field0;
    int field4;
    unsigned char field8;
    unsigned char field9;
    int fieldC;
    int field10;
    int field14;
    int field18;
};

int ContentProviderJob::f(int value, int other)
{
    field4 = 0;
    field8 = 0;
    fieldC = value;
    field9 = 3;
    field10 = other;
    field14 = -1;
    field18 = -1;
    return 0;
}
