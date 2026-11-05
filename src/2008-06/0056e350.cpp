// from server: 100% by king_originala
struct Vector3
{
    float x, y, z;
};

extern bool __cdecl convert(void* source, Vector3* value);

struct Accessor
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void set(void* object, const Vector3* value);
};

struct Descriptor
{
    char padding[24];
    Accessor* accessor;

    bool write(void* object, void* source);
};

bool Descriptor::write(void* object, void* source)
{
    Vector3 value = { 0.0f, 0.0f, 0.0f };
    if (convert(source, &value))
    {
        accessor->set(object, &value);
        return true;
    }
    return false;
}
