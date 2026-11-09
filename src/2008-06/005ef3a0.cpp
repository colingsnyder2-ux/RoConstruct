// from server: 100% by king_originala
struct Input {
    int convert();
};

struct Setter {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void set(void* object, const int* value);
};

struct S {
    char padding[28];
    Setter* setter;

    void set(void* object, int value);
};

void S::set(void* object, int value)
{
    value = reinterpret_cast<Input*>(value)->convert();
    setter->set(object, &value);
}
