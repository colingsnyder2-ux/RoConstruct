// from server: 100% by colin
struct Object;
struct Input;

typedef Input* (__thiscall *Method)(Object*, int);

struct VTable {
    Method slots[13];
};

struct Context {
    char padding[44];
    int count;
};

struct Object {
    VTable* table;
    char padding[20];
    Context* context;
};

struct Input {
    Object* object;
    int value;
};

struct Sink {
    void write(Input** value, int count, bool flag);
};

void __cdecl process(Input* input, Sink* sink)
{
    Object* object = input->object;
    int value = input->value;
    Input* result = object->table->slots[12](object, value);
    int count = object->context->count + 1;
    sink->write(&result, count, true);
}
