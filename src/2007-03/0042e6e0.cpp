// from server: 100% by tester
struct AnyHolder {
    virtual void destroy(int);
    virtual void* clone() const;
    virtual void* clone2() const;
};

struct AnyValue {
    void* m_type;
    AnyHolder* m_holder;
};

AnyValue* __cdecl copy_backward(AnyValue* first, AnyValue* last, AnyValue* dest)
{
    if (first != last) {
        do {
            --last;
            --dest;
            dest->m_type = last->m_type;
            AnyHolder* src = last->m_holder;
            void* cloned;
            if (src)
                cloned = src->clone2();
            else
                cloned = 0;
            AnyHolder* old = dest->m_holder;
            dest->m_holder = (AnyHolder*)cloned;
            if (old)
                old->destroy(1);
        } while (last != first);
    }
    return dest;
}
