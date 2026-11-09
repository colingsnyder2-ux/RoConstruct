// from server: 87% by atomic.potato
struct S
{
};

void __cdecl f(void *p)
{
    void **v = *(void ***)((char *)p - 8);
    ((void (__cdecl *)(void *))(*(void ***)v))(v);
}
