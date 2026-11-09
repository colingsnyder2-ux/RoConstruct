// from server: 75% by atomic.potato
struct S
{
    unsigned char pad0[0x10];
    unsigned char flag;
    unsigned char pad1[7];
    void (*callback)(void *, void *, int);
    unsigned char pad2[4];
    unsigned char value[1];
    void f();
};

void S::f()
{
    if (flag)
    {
        if (callback)
        {
            callback(value, value, 2);
        }
        callback = 0;
    }
    flag = 0;
}
