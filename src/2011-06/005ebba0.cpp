// from server: 69% by atomic.potato
extern "C" void sub_5e9160(void *, void *);

struct S
{
    int value0;
    int value1;
    int value2;
    int value3;
    int value4;
    int value5;
    int value6;
    int value7;
    int value8;
    int value9;
    int value10;
    S *f(void *);
};

S *S::f(void *arg)
{
    sub_5e9160(this, arg);
    value10 = 0xA5BEE8;
    value0 = 0xA91198;
    value5 = 0xA91190;
    value10 = 0xA91180;
    return this;
}
