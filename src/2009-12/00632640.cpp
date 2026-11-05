// from server: 26% by atomic.potato
struct S
{
    void* field4c;
    void* get();
};

void* S::get()
{
    void* p = field4c;
    if (p != 0)
        return (*(void* (**)(void*))(*(char**)p + 0x3c))(p);
    return 0;
}
