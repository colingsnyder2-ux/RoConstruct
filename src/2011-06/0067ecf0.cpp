// from server: 55% by atomic.potato
struct P8Humanoid_GetSetImpl {
    char pad[0x18];
    int (__stdcall *fn)(int, float);
    char pad2[0x4];
    int offset;
    int index;
    int method(int, float);
};

int P8Humanoid_GetSetImpl::method(int a, float b)
{
    int obj;
    if (a != 0)
        obj = a - 0x1c;
    else
        obj = 0;

    int idx = this->index;
    int base = *(int *)(obj + 0x144);
    int val = *(int *)(base + idx);
    val += this->offset;
    int (__stdcall *f)(int, float) = this->fn;
    return f(val + obj + 0x144, b);
}
