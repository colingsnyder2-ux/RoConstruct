// from server: 37% by Intel
struct D6Link {
    D6Link* m_parent;
    D6Link* m_left;
    D6Link* m_right;
    char m_color;

    D6Link* __cdecl getNext(D6Link* sentinel, long* refCount);
};

extern "C" void __stdcall InterlockedIncrement(long* addend);

D6Link* D6Link::getNext(D6Link* sentinel, long* refCount) {
    D6Link* current = this;
    if (current == sentinel)
        return current;

    while (true) {
        InterlockedIncrement(refCount);

        if (current->m_color != 0)
            break;

        D6Link* left = current->m_left;
        if (left->m_color == 0) {
            D6Link* node = left;
            while (true) {
                D6Link* nextLeft = node->m_left;
                if (nextLeft->m_color != 0)
                    break;
                node = nextLeft;
            }
            current = node;
        } else {
            D6Link* parent = current->m_parent;
            if (parent->m_color == 0) {
                while (current == parent->m_right) {
                    current = parent;
                    parent = parent->m_parent;
                }
                current = parent;
            } else {
                current = parent;
            }
        }

        if (current == sentinel)
            break;
    }
    return current;
}
