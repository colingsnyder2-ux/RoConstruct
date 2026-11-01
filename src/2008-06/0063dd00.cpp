// from server: 100% by king_originala
struct Base1 {};
struct Base2 {};

struct __multiple_inheritance Object : Base1, Base2
{
    void notify(void* property);
};

struct S
{
    int reserved0;
    void* property;
    int offset;
    int reserved1;
    void (Object::*changed)(void*);

    void setValue(void* instance, const bool& value);
};

void S::setValue(void* instance, const bool& value)
{
    Object* object = instance
        ? reinterpret_cast<Object*>(static_cast<char*>(instance) - 20)
        : 0;

    bool& field = *reinterpret_cast<bool*>(
        reinterpret_cast<char*>(object) + offset);

    if (field != value)
    {
        field = value;
        if (changed)
            (object->*changed)(property);
        object->notify(property);
    }
}
