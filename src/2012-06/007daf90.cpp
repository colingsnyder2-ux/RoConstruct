// from server: 70% by atomic.potato
extern "C" void __stdcall Call785420(void*);

struct S
{
    int f(void*);
};

int S::f(void* value)
{
    if (value)
        Call785420(*(char**)((char*)this + 0x2c) + (int)value - 0x1c);
    else
        Call785420(*(char**)((char*)this + 0x2c));
    return 0;
}
