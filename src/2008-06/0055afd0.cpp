// from server: 100% by king_originala
extern "C" void (__cdecl *invalid_parameter_noinfo)();

struct Object;
struct Vector;

struct Entry {
    Object* object;
    unsigned long control;
};

struct Proxy {
    Vector* owner;
};

struct Iterator {
    Proxy* proxy;
    Entry* position;

    Iterator(Entry*, Vector*);
    Vector* owner() const;
    Iterator& operator-=(int);
    Iterator operator-(int) const;
    Entry* operator->() const;
};

struct Vector {
    Proxy* proxy;
    unsigned long reserved[2];
    Entry* first;
    Entry* last;

    Iterator end();
};

struct Object {
    unsigned char reserved[0x108];
    Vector* children;

    void setParent(Object*);
    void clearChildren();
};

inline Iterator::Iterator(Entry* p, Vector* v)
    : proxy(v->proxy), position(p)
{
}

inline Vector* Iterator::owner() const
{
    return proxy ? proxy->owner : 0;
}

inline Iterator Vector::end()
{
    Entry* p = last;
    if (first > p)
        invalid_parameter_noinfo();
    return Iterator(p, this);
}

inline Iterator& Iterator::operator-=(int n)
{
    if (!proxy)
        invalid_parameter_noinfo();

    if (position - n > owner()->last ||
        position - n < owner()->first)
        invalid_parameter_noinfo();

    position -= n;
    return *this;
}

inline Iterator Iterator::operator-(int n) const
{
    Iterator result = *this;
    result -= n;
    return result;
}

inline Entry* Iterator::operator->() const
{
    if (!proxy)
        invalid_parameter_noinfo();

    if (position >= owner()->last)
        invalid_parameter_noinfo();

    return position;
}

void Object::clearChildren()
{
    while (children)
        (children->end() - 1)->object->setParent(0);
}
