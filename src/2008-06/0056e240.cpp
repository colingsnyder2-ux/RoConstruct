// from server: 100% by king_originala
extern "C" bool __cdecl convert(const void *, double *);

struct Setter {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void set(void *, const double &);
};

struct S {
    unsigned char padding[24];
    Setter *setter;
    bool assign(void *, const void *);
};

bool S::assign(void *object, const void *source)
{
    double value;
    if (convert(source, &value)) {
        setter->set(object, value);
        return true;
    }
    return false;
}
