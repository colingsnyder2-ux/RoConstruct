// from server: 44% by atomic.potato
struct BoundVerb
{
    int value;
    int field8;
    int fieldC;
    int field10;
    int field14;
    int field18;
    int field1C;
    int field20;
    int field24;
    int field28;
    int field2C;
    int field30;
    int f();
};

extern "C" int __cdecl Function40dd60(int);

int BoundVerb::f()
{
    if (field30 == 0)
        return 1;
    return Function40dd60(field8);
}
