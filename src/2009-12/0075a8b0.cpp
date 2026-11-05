// from server: 100% by atomic.potato
struct TextLabel
{
    int field0;
    int field4;
    int field8;
    int fieldC;
    int f();
};

extern "C" int __cdecl sub_7be050(int, int);

int TextLabel::f()
{
    return sub_7be050(field8, fieldC);
}
