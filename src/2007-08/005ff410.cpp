// from server: 100% by colin
struct VerbContainer;

struct Verb {
    void* vtable;
    Verb(VerbContainer* container, const char* name);
};

struct RedoVerb : Verb {
    char pad[0x28];
    int field_0x2c;
    RedoVerb(VerbContainer* container, const char* name);
};

RedoVerb::RedoVerb(VerbContainer* container, const char* name)
    : Verb(container, name)
{
    this->vtable = (void*)0x7c27e8;
    this->field_0x2c = 0;
}
