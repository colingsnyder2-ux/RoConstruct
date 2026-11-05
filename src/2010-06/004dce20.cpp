// from server: 100% by atomic.potato
struct S
{
    int value0;
    int value4;
    int value8;
    int valueC;
    char value10;

    S();
};

S::S()
{
    value0 = 0;
    value4 = 0x2000;
    value8 = 0;
    valueC = (int)((char *)this + 0x11);
    value10 = 1;
}
