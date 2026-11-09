// from server: 100% by king_originala
extern bool __cdecl convert(unsigned int value, unsigned int *result);

struct Setter {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void set(void *object, const unsigned int *value);
};

struct S {
    unsigned char padding[24];
    Setter *setter;
    bool apply(void *object, unsigned int value);
};

bool S::apply(void *object, unsigned int value)
{
    if (convert(value, &value)) {
        setter->set(object, &value);
        return true;
    }
    return false;
}
