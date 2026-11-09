// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct Vector3
{
    float x, y, z;
};

struct Result;

struct Accessor
{
    virtual void slot0();
    virtual void slot1();
    virtual Vector3* get(Vector3* value, void* object);
};

extern void __cdecl convert(Result* result, const Vector3* value);

struct Descriptor
{
    char padding[24];
    Accessor* accessor;

    Result* read(Result* result, void* object);
};

Result* Descriptor::read(Result* result, void* object)
{
    volatile int state = 0;
    Vector3 temporary;
    accessor->get(&temporary, object);
    convert(result, &temporary);
    return result;
}
