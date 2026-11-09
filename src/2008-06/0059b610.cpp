// from server: 100% by king_originala
struct Vector3
{
    float x, y, z;
};

struct Accessor
{
    virtual void slot0();
    virtual void slot1();
    virtual Vector3* get(Vector3* value, void* object);
};

struct Holder
{
    void assign(const Vector3& value);
};

struct Result
{
    void* type;
    Holder value;
};

extern void* getType();

struct Descriptor
{
    char padding[24];
    Accessor* accessor;

    void read(void* object, Result* result);
};

void Descriptor::read(void* object, Result* result)
{
    Vector3 temporary;
    Vector3* value = accessor->get(&temporary, object);
    result->type = getType();
    result->value.assign(*value);
}
