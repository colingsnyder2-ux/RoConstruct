// from server: 66% by atomic.potato
struct MyXTPCommandBars
{
    int unused0[27];
    int value5c;
    int unused1[3];
    int value6c;
    int unused2;
    int pointer74;
    void f(int);
};

struct KeyboardTip
{
};

struct CommandBar
{
};

void G1_func_00814da0(KeyboardTip *, int);
void G1_func_00815b40(CommandBar *, int);

void MyXTPCommandBars::f(int value)
{
    *(int *)(pointer74 + 0x4c) = 1;
    value6c = value;
    value5c = value;
    G1_func_00814da0((KeyboardTip *)this, 0);
    G1_func_00815b40((CommandBar *)this, value5c);
}
