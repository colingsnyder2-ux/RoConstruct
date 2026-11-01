// from server: 100% by king_originala
struct ShortPair
{
    short x;
    short y;
};

struct Arguments
{
    ShortPair pair;
    float value;
    int half;
};

struct HeadBuilder
{
    char padding[0x20];
    float field20;
    volatile int field24;

    void sub_4FFD40(int, int, ShortPair, int);
    void sub_500140(int);
};

void HeadBuilder::sub_500140(int a)
{
    Arguments args;
    args.value = field20;
    args.half = (field24 + 1) / 2;
    int value = field24;
    args.pair.x = (short)value;
    args.pair.y = (short)value;
    sub_4FFD40(*(int*)&args.value, args.half, args.pair, a);
}
