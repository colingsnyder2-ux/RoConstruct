// from server: 100% by tester
struct Value {
    void* convert(Value** value);
};

struct Target;
typedef void (__thiscall *Setter)(Target*, void*, void*);

struct Target {
    Setter* table;
};

struct S {
    char padding[24];
    Target* target;
    void set(void* object, Value* value);
};

void S::set(void* object, Value* value)
{
    Target* destination = target;
    Setter* slot = destination->table + 3;
    void* converted = value->convert(&value);
    (*slot)(destination, object, converted);
}
