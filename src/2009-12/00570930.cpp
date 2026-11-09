// from server: 57% by atomic.potato
struct CSHA1
{
    int a[9];

    void f();
};

void CSHA1::f()
{
    a[0] = 0;
    a[2] = 0;
    a[4] = 0;
    a[6] = 0;
    a[8] = 0;
    a[7] = 0;
}
