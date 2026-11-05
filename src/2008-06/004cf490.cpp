// from server: 100% by colin
struct S_func_004cf490 {
    int m_count;
    void* m_head;
    void* m_tail;
    void f();
};

extern "C" void __cdecl sub_006a067a(void*);

void S_func_004cf490::f()
{
    if (m_count == 0)
        return;

    if (m_count == 1) {
        sub_006a067a(m_head);
        m_head = 0;
        m_count = 0;
        m_tail = 0;
        return;
    }

    void* node = m_tail;
    void* prev = *(void**)((char*)node + 4);
    void* next = *(void**)((char*)node + 8);
    *(void**)((char*)prev + 8) = next;

    node = m_tail;
    prev = *(void**)((char*)node + 4);
    next = *(void**)((char*)node + 8);
    *(void**)((char*)next + 4) = prev;

    node = m_tail;
    void* newTail = *(void**)((char*)node + 8);
    if (node == m_head)
        m_head = newTail;

    sub_006a067a(node);
    m_count--;
    m_tail = newTail;
}
