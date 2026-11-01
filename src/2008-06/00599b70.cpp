// from server: 100% by king_originala
struct Value {
    char data[104];
    Value(const Value&);
    Value& operator=(const Value&);
};

typedef Value* (__thiscall *Getter)(void*, Value*);

struct Object {
    char padding[308];
    int* table;
};

struct S {
    Value value;
    bool dirty;
    Object* object;
    Getter getter;
    int adjustment;
    int tableOffset;

    Value get();
};

Value S::get()
{
    if (dirty) {
        char temporary[104];
        value = *getter(
            (char*)object + 308
                + *(int*)((char*)object->table + tableOffset)
                + adjustment,
            (Value*)temporary);
        dirty = false;
    }
    return value;
}
