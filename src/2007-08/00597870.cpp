// from server: 100% by colin
struct Inner {
    char pad[0xe8];
    void* m_value;
};

struct S {
    char pad[0xc];
    Inner* m_inner;

    void* getValue();
};

void* S::getValue() {
    Inner* p = m_inner;
    if (p) {
        return p->m_value;
    }
    return 0;
}
