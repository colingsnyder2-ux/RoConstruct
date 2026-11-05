// from server: 52% by atomic.potato
struct S
{
    int f(int);
};

extern "C" void CallTarget(void *, const char *, unsigned char);

int S::f(int value)
{
    unsigned char flag = *(unsigned char *)((char *)this + 0x94);
    void *object = *(void **)((char *)this + 0x98);
    if (object)
        CallTarget(object, "T$ R", flag);
    return value;
}
