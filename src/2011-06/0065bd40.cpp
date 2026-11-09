// from server: 79% by atomic.potato
extern "C" int __cdecl G1_func_0065bbd0(const char*, double, int);

double g_00a66290 = 0.0;

struct Item
{
    int f(int*);
};

int Item::f(int* value)
{
    int number = *value;
    double converted = (double)number;
    if (number < 0)
        converted += g_00a66290;
    return G1_func_0065bbd0("ACurrent screen resolution - %d x %d", converted, 0);
}
