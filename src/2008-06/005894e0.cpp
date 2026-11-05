// from server: 100% by king_originala
struct Object {
    virtual ~Object();
    virtual void reserved();
    virtual Object* clone();

    void* value;
    Object* owned;
};

struct Slot {
    void* value;
    Object* owned;
};

struct Storage {
    Slot* get(Object*);
};

struct S {
    char padding[24];
    Storage storage;
    void f(Object*);
};

void S::f(Object* source)
{
    Slot* slot = storage.get(source);
    slot->value = source->value;

    Object*& owned = slot->owned;
    Object* object = source->owned;
    source = object ? object->clone() : 0;

    if (&source != &owned) {
        Object* replacement = source;
        source = owned;
        owned = replacement;
    }

    if (source)
        delete source;
}
