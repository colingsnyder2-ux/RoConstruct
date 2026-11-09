// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct Accessor {
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual bool get(const void* object) = 0;
};

struct Descriptor {
    unsigned char padding[24];
    Accessor* accessor;
    bool equal(const void* first, const void* second);
};

bool Descriptor::equal(const void* first, const void* second)
{
    bool a = accessor->get(first);
    bool b = accessor->get(second);
    return a == b;
}