// from server: 100% by king_originala
struct Value {
    bool convert();
};

struct Receiver;

struct VTable {
    void* unused[3];
    void (__thiscall* set)(Receiver*, void*, const bool*);
};

struct Receiver {
    VTable* vtable;
};

struct S {
    unsigned char padding[24];
    Receiver* receiver;
    void f(void* object, Value* value);
};

void S::f(void* object, Value* value)
{
    *reinterpret_cast<bool*>(&value) = value->convert();
    receiver->vtable->set(receiver, object, reinterpret_cast<const bool*>(&value));
}
