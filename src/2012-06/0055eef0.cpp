// from server: 90% by atomic.potato
extern "C" int G1_func_007090e0();
extern "C" void G1_func_0055eb60(void* p, int value);

struct EventDesc
{
    int f(int value);
};

int EventDesc::f(int value)
{
    int* p = (int*)this;
    *p = G1_func_007090e0();
    G1_func_0055eb60((char*)this + 4, value);
    return (int)this;
}
