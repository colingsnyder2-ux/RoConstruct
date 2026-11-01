// from server: 100% by king_originala
struct Reader {
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual float get(void* object) = 0;
};

struct Deletable {
    virtual void destroy(unsigned int flags) = 0;
};

struct Holder {
    void** table;
    float value;
};

struct Value {
    void* type;
    Holder* holder;
};

extern void* holderTable[];
extern void* __cdecl getType();
void* __cdecl operator new(unsigned int size);

struct S {
    unsigned char padding[24];
    Reader* reader;
    void get(void* object, Value* result);
};

void S::get(void* object, Value* result)
{
    float value = reader->get(object);
    result->type = getType();

    Holder** destination = &result->holder;
    Holder* temporary = static_cast<Holder*>(operator new(8));
    if (temporary) {
        temporary->table = holderTable;
        temporary->value = value;
    } else {
        temporary = 0;
    }

    Deletable* previous = reinterpret_cast<Deletable*>(temporary);
    if (&temporary != destination) {
        previous = reinterpret_cast<Deletable*>(*destination);
        *destination = temporary;
    }

    if (previous)
        previous->destroy(1);
}
