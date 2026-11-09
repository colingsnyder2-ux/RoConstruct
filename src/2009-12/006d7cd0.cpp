// from server: 51% by atomic.potato
struct S
{
    void f();
};

extern "C" void __stdcall Call(int, double, const char *, S *);

double g_adjust;
const char *g_message = "AEnumDisplaySettings failed. GetLastError() == %d";

void S::f()
{
    int value = *((int *)((char *)this + 0));
    double converted = (double)value;

    if (value < 0)
        converted += g_adjust;

    Call(value, converted, g_message, this);
}
