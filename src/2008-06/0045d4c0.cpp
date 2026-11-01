// from server: 100% by king_originala
extern int modeFlag;
extern const float resetValue;
extern float currentValue;

extern int __cdecl queryValue();

struct S {
    char padding[0x5c];
    int mode;

    void special(int, int);
    void ordinary(int, int);
    void update(int, int);
};

void S::update(int a, int b)
{
    if (mode == 2)
        special(a, b);
    else
        ordinary(a, b);

    modeFlag = (mode == 2);

    if (queryValue() < 0x1ab3f00)
        currentValue = resetValue;
}
