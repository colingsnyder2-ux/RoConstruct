// from server: 100% by king_originala
extern "C" bool __cdecl convert(void* value, void** result);

struct Setter {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void set(void* instance, void** value);
};

struct S {
    char padding[24];
    Setter* setter;

    bool f(void* instance, void* value);
};

bool S::f(void* instance, void* value)
{
    if (convert(value, &value)) {
        setter->set(instance, &value);
        return true;
    }
    return false;
}
