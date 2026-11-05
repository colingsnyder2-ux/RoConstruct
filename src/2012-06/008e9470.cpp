// from server: 53% by atomic.potato
struct FloorWire {
    char pad0[0x10];
    void** m_array;
    int m_capacity;
    int m_size;
    int m_index;
    void grow(int);
    void initElem(void*);
};

extern "C" void* __cdecl operator_new(unsigned int);
extern "C" void __cdecl FloorWire_initElem(void*, void*);

void FloorWire::grow(int n)
{
    if (m_capacity <= m_index + 1)
        grow(1);
    int cap = m_capacity;
    int idx = m_size + m_index;
    if (cap <= idx)
        idx -= cap;
    if (m_array[idx] == 0)
        m_array[idx] = operator_new(0x48);
    void* p = m_array[idx];
    initElem(p);
    m_index++;
}

void FloorWire::initElem(void* p)
{
    FloorWire_initElem(p, p);
}
