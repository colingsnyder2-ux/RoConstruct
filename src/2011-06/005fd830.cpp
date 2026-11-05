// from server: 67% by atomic.potato
struct BoundFuncDesc
{
    void *f(void *);
};

void *BoundFuncDesc::f(void *p)
{
    if (*(unsigned char *)((char *)this + 0xb31) && *(int *)p)
        return p;
    return 0;
}
