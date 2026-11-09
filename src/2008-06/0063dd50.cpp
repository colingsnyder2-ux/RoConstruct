// from server: 100% by king_originala
extern char instanceType;
extern char partType;

extern "C" void* __cdecl castObject(
    void* object, int offset, void* sourceType, void* targetType, int isReference);

struct Instance
{
    void setValue(bool value);
};

struct Part
{
    void setValue(bool value);
};

void __cdecl setValue(Instance* instance, const bool& value)
{
    bool newValue = value;
    Part* part = static_cast<Part*>(
        castObject(instance, 0, &instanceType, &partType, 0));

    if (part)
        part->setValue(newValue);
    else
        instance->setValue(newValue);
}
