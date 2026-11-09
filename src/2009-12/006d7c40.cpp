// from server: 50% by atomic.potato
struct StatsItem
{
    void f(int*);
};

extern "C" void __stdcall G1_func_006d7b60(StatsItem*, double, const char*);

void StatsItem::f(int* value)
{
    G1_func_006d7b60(this, (double)*value, (const char*)0x9a68d4);
}
