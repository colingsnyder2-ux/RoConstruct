// from server: 76% by atomic.potato
extern "C" void __declspec(noreturn) Function_0040C080(void*);

struct S
{
    int f(int*);
};

int S::f(int* value)
{
    int v = *value;
    if (v != *(int*)((char*)this + 0xa0))
    {
        *(int*)((char*)this + 0xa0) = v;
        value = (int*)0x00b7ff40;
        Function_0040C080(value);
    }
    return 0;
}
