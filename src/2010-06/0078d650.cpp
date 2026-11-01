// from server: 92% by atomic.potato
struct Elem {
    char pad[4];
    int field_4;
};

struct Obj {
    void method70bb60(Elem* e);
};

struct S {
    char pad0[0x34];
    Elem* m_elems[40];
    unsigned int m_count;
    Obj* createObj();
    void f();
};

void S::f()
{
    unsigned int i = 0;
    Obj* obj = 0;
    for (Elem** p = m_elems; i < m_count; i++, p++) {
        if ((*p)->field_4 != -1) {
            if (obj == 0)
                obj = createObj();
            obj->method70bb60(*p);
        }
    }
}
