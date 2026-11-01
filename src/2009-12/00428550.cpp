// from server: 100% by atomic.potato
extern "C" int __stdcall sub_007f41b4(void*);

struct CWrapperView
{
    int f(void*);
};

int CWrapperView::f(void* arg)
{
    if (!sub_007f41b4(arg))
        return 0;
    *(int*)((char*)arg + 0x2c) &= 0xfffffdff;
    return 1;
}
