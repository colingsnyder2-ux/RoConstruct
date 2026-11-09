// from server: 58% by atomic.potato
struct EventDesc
{
    void f(int);
    int* field;
};

extern "C" void G1_func_005366e0(int*);

void EventDesc::f(int value)
{
    int* p = field;
    if (value != 0)
        G1_func_005366e0(p + value - 0x1c);
    else
        G1_func_005366e0(p);
}
