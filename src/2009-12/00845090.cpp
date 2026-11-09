// from server: 100% by atomic.potato
struct Inner
{
    void **vtbl;
};

typedef void (__thiscall *InnerVCall)(void *, void *, int);

struct CXTPPopupToolBar
{
    Inner *getInner();
    Inner *func(int arg);
};

Inner *CXTPPopupToolBar::func(int arg)
{
    Inner *inner = getInner();
    InnerVCall fn = *(InnerVCall *)((char *)inner->vtbl + 0x1dc);
    fn(inner, this, arg);
    return inner;
}
