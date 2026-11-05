// from server: 82% by atomic.potato
extern "C" void helper_00649a50(void*, double, const char*);

struct Item_00649bc0
{
    void f(int*);
};

double global_0064a05248;
const char* global_0064a07674;

void Item_00649bc0::f(int* value)
{
    int v = *value;
    double d = (double)v;
    if (v < 0)
        d += global_0064a05248;
    helper_00649a50(this, d, global_0064a07674);
}
