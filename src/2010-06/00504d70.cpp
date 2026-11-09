// from server: 46% by atomic.potato
struct Inner {
    char pad0[4];
    Inner* m_next;
    Inner* m_prev;
};

struct Outer {
    Inner** m_data;
    unsigned int m_size;
    void insert(unsigned int, Inner*, Inner*);
};

struct S {
    Inner** m_data;
    unsigned int m_count;
    char pad8[8];
    void f(char*);
};

extern "C" void* __cdecl operator_new(unsigned int);
extern "C" void __stdcall func_005028c0(char*);

void S::f(char* p)
{
    unsigned char idx = *(unsigned char*)(p + 0x18);
    if (idx >= 0x20)
        return;
    Inner* node;
    if (idx < m_count && m_data[idx] != 0) {
        node = m_data[idx];
        if (node->m_next == 0) {
        } else {
            if (idx < m_count)
                node = m_data[idx];
            else
                node = 0;
        }
    } else {
        Inner* n = (Inner*)operator_new(0xc);
        if (n != 0) {
            n->m_next = 0;
            n->m_prev = 0;
            n->m_next = 0;
        } else {
            n = 0;
        }
        ((Outer*)this)->insert(*(unsigned char*)(p + 0x18), 0, n);
        node = m_data[*(unsigned char*)(p + 0x18)];
    }
    Inner* next = node->m_next;
    if (next != 0) {
        node->m_prev = next->m_next;
    }
    func_005028c0((char*)&p);
}
