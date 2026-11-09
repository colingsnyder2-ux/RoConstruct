// from server: 50% by atomic.potato
struct P8Script_GetSetImpl {
    char pad[8];
    int (__stdcall *fn)(void *);
    int offset;
    int method(int, int);
};

extern "C" void __stdcall sub_98B6F0(void *, void *);

int P8Script_GetSetImpl::method(int a, int b)
{
    int tmp = 0;
    int *p = (int *)b;
    if (p != 0)
        p = (int *)((char *)p - 0x1c);
    int result = fn((void *)((char *)p + this->offset));
    sub_98B6F0((void *)a, (void *)result);
    *(int *)(a + 0x1c) = *(int *)(result + 0x1c);
    return a;
}
