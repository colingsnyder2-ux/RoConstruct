// from server: 100% by tester
int g_SetGridState;

struct SetGridToOff
{
    void __thiscall f(int);
};

void __thiscall SetGridToOff::f(int)
{
    g_SetGridState = 2;
}
