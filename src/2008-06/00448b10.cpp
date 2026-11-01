// from server: 100% by king_originala
struct Value {
    int convert();
};

struct Descriptor;

typedef void (__thiscall *Setter)(Descriptor*, void*, int);

struct DispatchTable {
    void* padding[15];
    Setter set;
};

struct Descriptor {
    DispatchTable* table;
    void apply(void*, Value*);
};

void Descriptor::apply(void* object, Value* value)
{
    DispatchTable* dispatch = table;
    int converted = value->convert();
    dispatch->set(this, object, converted);
}
