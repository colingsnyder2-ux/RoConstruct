// from server: 66% by king_originala
struct String;

extern void (__thiscall* copyString)(String*, const String&);
extern void (__thiscall* destroyString)(String*);

struct String
{
    void* data;

    String(const String& other)
    {
        copyString(this, other);
    }

    ~String() throw()
    {
        destroyString(this);
    }
};

struct S;

struct VTable
{
    void* preceding[57];
    float (__thiscall* getNumber)(S*);
};

struct S
{
    VTable* vtable;

    void baseValueChanged(String value);
    void updateNumber(const float& value);
    void valueChanged(String value);
};

void S::valueChanged(String value)
{
    baseValueChanged(value);
    float number = vtable->getNumber(this);
    updateNumber(number);
}
