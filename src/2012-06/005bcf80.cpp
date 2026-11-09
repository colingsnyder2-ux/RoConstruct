// from server: 81% by atomic.potato
struct S_func_005bcf80 {
    void* m_data;
    int m_count;
    int m_capacity;
    void f(void* a, void* b, void* c);
};

extern "C" void* __cdecl sub_005bbbf0(int, void*, void*);
extern "C" void __cdecl sub_009823ba(void*);

void S_func_005bcf80::f(void* a, void* b, void* c)
{
    if (m_count == m_capacity) {
        if (m_capacity == 0)
            m_capacity = 0x10;
        else
            m_capacity += m_capacity;
        void* p = sub_005bbbf0(m_capacity, b, c);
        if (m_data != 0) {
            unsigned int i = 0;
            if (m_count > 0) {
                char* src = (char*)m_data;
                char* dst = (char*)p;
                do {
                    *(int*)(dst + 0) = *(int*)(src + 0);
                    *(int*)(dst + 4) = *(int*)(src + 4);
                    *(short*)(dst + 8) = *(short*)(src + 8);
                    i++;
                    src += 0x10;
                    dst += 0x10;
                } while (i < (unsigned int)m_count);
            }
            sub_009823ba(m_data);
        }
        m_data = p;
    }
    char* dst = (char*)m_data + (m_count << 4);
    *(int*)(dst + 0) = *(int*)((char*)a + 0);
    *(int*)(dst + 4) = *(int*)((char*)a + 4);
    *(short*)(dst + 8) = *(short*)((char*)a + 8);
    m_count++;
}
