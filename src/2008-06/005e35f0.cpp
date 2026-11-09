// from server: 100% by king_originala
extern "C" void* __cdecl convert(void*);

struct Target {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void set(void*, void**);
};

struct S {
    char padding[28];
    Target* target;

    void f(void* object, void* value);
};

void S::f(void* object, void* value)
{
    void* converted = value ? convert(value) : 0;
    target->set(object, &(value = converted));
}
