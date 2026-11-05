// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /Od /Ob0 /GS /EHsc /MD
#pragma optimize("", off)

struct Base {
    char storage[12];
    Base(void*);
    ~Base();
};

struct S {
    void* pointer;
    void assign(void*);
    S(const S&);
};

struct Object : Base {
    S member;
    Object(void*, const S&);
};

Object::Object(void* arg, const S& other)
    : Base(arg), member(other)
{
}
