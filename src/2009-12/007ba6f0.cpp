// from server: 55% by atomic.potato
struct S
{
    char padding[0x24];
    int *field;
    int f();
};

int S::f()
{
    int value = field[7];
    if (value)
        return value - 8;
    return 0;
}

extern "C" int __cdecl sub_701650();
extern "C" void __stdcall sub_7ba690(int *, int, int);

struct TreeStage
{
    void f(int *);
};

void TreeStage::f(int *value)
{
    int result = sub_701650();
    sub_7ba690(value, result, (int)0x77e3b0);
}
