// from server: 61% by atomic.potato
struct S
{
    int f(void* p);
};

extern "C" int G1_func_008d7660(void*);

int S::f(void* p)
{
    char* base = *(char**)((char*)this + 0x2c);
    if (p)
        return G1_func_008d7660(base + ((char*)p - (char*)0) - 0x1c);
    return G1_func_008d7660(base);
}
