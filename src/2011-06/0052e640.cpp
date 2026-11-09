// from server: 100% by atomic.potato
struct S_func_0052e640 {
    static unsigned int f(const unsigned int* a, const unsigned int* b);
};

unsigned int S_func_0052e640::f(const unsigned int* a, const unsigned int* b)
{
    unsigned int x = *a;
    unsigned int y = *b;
    if (x < y)
        return 0xffffffffU;
    return x != y;
}
