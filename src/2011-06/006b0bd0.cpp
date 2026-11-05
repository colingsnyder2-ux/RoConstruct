// from server: 65% by atomic.potato
struct Sub1 {
    void sub_4c1670(int);
};

struct Sub2 {
    void sub_6afec0(int, int);
};

struct EventDesc {
    char pad0[4];
    Sub1 field4;
    int method(int, int);
};

int EventDesc::method(int a, int b)
{
    field4.sub_4c1670(1);
    ((Sub2*)this)->sub_6afec0(a, b);
    return a;
}
