// from server: 59% by atomic.potato
struct Node {
    Node* m_next;
    int m_count;
    Node* m_prev;
    Node* m_prev2;
};

struct List {
    Node* m_head;
    Node* m_tail;
    int m_size;
    int m_pad;
};

extern "C" void __stdcall sub_c2ee8c(void*, void*, void*);

struct S {
    char pad0[4];
    Node* m_a;
    int m_b;
    int m_c;
    int m_d;
    char pad1[0x5f0 - 0x14];
    List* m_list;
    void f(void* a1, void* a2, void* a3);
};

void S::f(void* a1, void* a2, void* a3)
{
    Node* n = m_list->m_head;
    if (n->m_count == 0) {
        *(Node**)n->m_next = (Node*)a1;
        n->m_count++;
        m_c--;
        n->m_prev->m_prev2 = n->m_prev2;
        n->m_prev2->m_prev = n->m_prev;
        if (m_c > 0 && n == m_a) {
            m_a = n->m_prev;
        }
        int old = m_b;
        m_b = old + 1;
        if (old == 0) {
            m_list->m_head = n;
            n->m_prev = n;
            n->m_prev2 = n;
            return;
        }
        n->m_prev = m_list->m_head;
        n->m_prev2 = m_list->m_head->m_prev2;
        m_list->m_head->m_prev2->m_prev = n;
        m_list->m_head->m_prev2 = n;
        return;
    }
    ((Node**)n->m_next)[n->m_count] = (Node*)a1;
    n->m_count++;
    unsigned int q = (unsigned int)(0xab8f69e3ULL * (unsigned int)m_d >> 32) >> 10;
    if ((unsigned int)n->m_count == q && m_b >= 4) {
        if (n == m_list->m_head) {
            m_list->m_head = n->m_prev;
        }
        n->m_prev2->m_prev = n->m_prev;
        n->m_prev->m_prev2 = n->m_prev2;
        m_b--;
        sub_c2ee8c(n->m_next, a2, a3);
        sub_c2ee8c(n->m_prev, a2, a3);
        sub_c2ee8c(n, a2, a3);
    }
}
