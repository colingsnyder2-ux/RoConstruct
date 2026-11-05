// from server: 100% by atomic.potato
struct S_func_007933d0
{
    char pad[140];
    void* m_data;
    int f(unsigned int index);
};

int S_func_007933d0::f(unsigned int index)
{
    char* p = (char*)m_data;
    int count = (*(int*)(p + 8) - *(int*)(p + 4)) >> 2;
    if (index >= (unsigned int)count)
        return -1;
    return ((int*)*(void**)(p + 16))[index];
}
