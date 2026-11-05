// from server: 70% by atomic.potato
struct EventDesc
{
    int f(int value);
};

extern "C" void __stdcall G1_func_00803f70(void*);

int EventDesc::f(int value)
{
    if (value)
        G1_func_00803f70((char*)*(char**)((char*)this + 0x2c) + value - 0x1c);
    else
        G1_func_00803f70(*(char**)((char*)this + 0x2c));
    return 0;
}
