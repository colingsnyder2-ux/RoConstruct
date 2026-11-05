// from server: 48% by atomic.potato
struct RbxPartBinding
{
    void *padding24[9];
    void *field24;
    void *get();
};

void *RbxPartBinding::get()
{
    void *p = field24;
    return *(void ***)((char *)p + 0x238);
}
