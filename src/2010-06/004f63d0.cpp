// from server: 79% by atomic.potato
struct S
{
    int f(int, int);
};

extern "C" S* GetObject(S*);
extern "C" void Send(S*, int, int, double);

int S::f(int a, int b)
{
    S* p = GetObject(this);
    float value = *(float*)((char*)p + 0x100);
    Send(this, b, a, (double)value);
    return b;
}
