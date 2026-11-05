// from server: 76% by atomic.potato
struct S
{
    int f(int);
};

extern "C" void __stdcall imported(void*, int*);

int S::f(int value)
{
    int zero = 0;
    imported((char*)this + 0x20, &zero);
    return value;
}
