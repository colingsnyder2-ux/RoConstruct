// from server: 100% by tester
extern void (__thiscall *destroy_string)(void *);

struct String {
    char storage[32];
    ~String();
};

__forceinline String::~String()
{
    destroy_string(this);
}

struct Value {
    String toString() const;
};

struct Accessor {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void set(void *, const String &);
};

struct Descriptor {
    char padding[24];
    Accessor *accessor;
    void set(void *, const Value &) const;
};

void Descriptor::set(void *object, const Value &value) const
{
    Accessor *a = accessor;
    a->set(object, value.toString());
}
