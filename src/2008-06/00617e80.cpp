// from server: 100% by king_originala
struct Value {
    char padding[0x328];
    float value;
};

struct Object {
    Value* getValue();
};

extern "C" void* __cdecl lookup(void*);
extern "C" Object* __cdecl getObject(void*);

struct S {
    char padding[0x18];
    void* context;
    bool f();
};

bool S::f()
{
    void* p = lookup(context);
    if (p) {
        Object* object = getObject(p);
        if (object) {
            Value* v = object->getValue();
            if (v && v->value == 0.0f)
                return true;
        }
    }
    return false;
}
