// from server: 100% by king_originala
struct S;
struct Visitor;
struct Object;

extern void* key975310;
extern void* key97530c;
extern void* key97535c;

struct Object {
    unsigned char padding[16];
    void* type;

    char* __thiscall findSignal(void*);
    void* __thiscall findProduct(void*);
};

struct Visitor {
    virtual void visit(void*, S*);
};

typedef void (__thiscall *Dispatch)(S*, Object*, Visitor*);

struct DispatchTable {
    unsigned char padding[44];
    Dispatch dispatch;
};

struct S {
    DispatchTable* table;

    void __thiscall process(Object*, Visitor*);
    void __thiscall processProduct(void*, Visitor*);
    void __thiscall processSignal(Object*, Visitor*);
};

void S::process(Object* object, Visitor* visitor)
{
    char* signal = object->findSignal(key975310);
    if (signal)
        visitor->visit(signal + 8, this);

    if (object->type == key97535c) {
        void* product = object->findProduct(key97530c);
        if (product)
            processProduct(product, visitor);
        processSignal(object, visitor);
    } else {
        table->dispatch(this, object, visitor);
    }
}
