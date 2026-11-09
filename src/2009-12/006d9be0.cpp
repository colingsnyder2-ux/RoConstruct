// from server: 100% by atomic.potato
struct StatsItem
{
    void f();
};

extern "C" void G1_func_00637b00();

void StatsItem::f()
{
    *(int*)this = 0x9d95c4;
    *(int*)((char*)this + 4) = 0x9d95b8;
    *(int*)((char*)this + 24) = 0x9d95ac;
    *(int*)((char*)this + 28) = 0x9d95a4;
    G1_func_00637b00();
}
