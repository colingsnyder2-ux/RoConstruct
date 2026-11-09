// from server: 64% by atomic.potato
typedef float real32;

struct GuiTarget
{
    char padding9c[156];
    real32 value9c;
    real32 valuea0;
    int valuea4;

    void f();
};

extern real32 g_value_a92730;
extern real32 g_value_a9272c;

void GuiTarget::f()
{
    value9c = g_value_a92730;
    valuea0 = g_value_a9272c;
    valuea4 = 0;
}
