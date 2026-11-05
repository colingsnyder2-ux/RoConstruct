// from server: 88% by atomic.potato
struct TextLabel
{
    int f();
    int pad;
    int value8;
    int valueC;
};

extern "C" int __cdecl sub_7655d0(int, int);

int TextLabel::f()
{
    return sub_7655d0(value8, valueC);
}
