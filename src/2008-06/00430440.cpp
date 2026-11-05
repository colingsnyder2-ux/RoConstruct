// from server: 100% by king_originala
struct Object {
    virtual void first();
    virtual void destroy(unsigned int);
};

struct CWrapperView {
    Object *object;
    void replace(Object *);
};

void CWrapperView::replace(Object *value)
{
    Object *old = object;
    object = value;
    if (old)
        old->destroy(1);
}
