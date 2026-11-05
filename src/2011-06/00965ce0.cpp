// from server: 58% by atomic.potato
struct RbxPartBinding
{
    void *get();
};

void *RbxPartBinding::get()
{
    void *p = *(void **)((char *)this + 0x1c);
    void *q = *(void **)((char *)p + 0x1c4);
    return *(void **)q;
}
