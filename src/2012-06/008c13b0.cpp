// from server: 47% by atomic.potato
struct S_func_008c13b0
{
    char pad0[204];
    void* m_object;
    void f(void* result);
};

void S_func_008c13b0::f(void* result)
{
    struct V
    {
        int x;
        int y;
        int z;
        int w;
    };

    V* source = (V*)m_object;
    V* destination = (V*)result;
    destination->x = source->x;
    destination->y = source->y;
    destination->z = source->z;
    destination->w = source->w;
}
