// from server: 94% by atomic.potato
extern "C" void __cdecl _wassert(const wchar_t* expr, const wchar_t* file, unsigned int line);
extern "C" void __cdecl free(void* block);
extern "C" void* __cdecl realloc(void* block, unsigned int size);

struct S {
    void* m_data;
    int m_len;
    int m_cap;
    int reserve(int n);
};

int S::reserve(int n) {
    if (n < 0) {
        _wassert(L"n >= 0", L"d3dformat.cpp", 0x2a0);
        return (int)0x80070057;
    }
    if (n == 0) {
        if (m_data) {
            free(m_data);
            m_data = 0;
        }
        m_cap = 0;
        m_len = 0;
        return 0;
    }
    if (m_data == 0 || n > m_cap) {
        int cap = m_cap;
        int grow = 16;
        if (cap) grow = cap;
        int newcap = cap + grow;
        if (n <= newcap) {
            n = newcap;
        }
        void* p = realloc(m_data, (unsigned int)(n * 4));
        if (p == 0) {
            return (int)0x8007000e;
        }
        m_data = p;
        m_cap = n;
    }
    return 0;
}
