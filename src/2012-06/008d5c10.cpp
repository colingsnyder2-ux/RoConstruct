// from server: 63% by atomic.potato
extern "C" void G1_func_008d3a70(void*);

struct S
{
    void f(void*);
};

void S::f(void* value)
{
    char* base = *(char**)((char*)this + 0x2c);
    if (value)
        G1_func_008d3a70(base + ((char*)value - (char*)0) - 0x1c);
    else
        G1_func_008d3a70(base);
}
