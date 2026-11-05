// from server: 100% by atomic.potato
struct CWrapperView
{
    void* value;
    void Set(void* value);
};

void CWrapperView::Set(void* value)
{
    void* old = this->value;
    this->value = value;
    if (old)
    {
        typedef void (__thiscall *Fn)(void*, int);
        Fn fn = *(Fn *)((char *)*(void **)old + 4);
        fn(old, 1);
    }
}
