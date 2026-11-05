// from server: 56% by atomic.potato
struct S
{
};

int __cdecl f(void* a, void* b, void* c)
{
    if (*(int*)((char*)a + 0x5c) != *(int*)((char*)b + 0x5c))
        return 0;

    void* p = *(void**)c;
    if (!p)
        return 0;

    void (**v)(void*, void*) = *(void (***)(void*, void*))p;
    v[1](a, b);
    return 0;
}
