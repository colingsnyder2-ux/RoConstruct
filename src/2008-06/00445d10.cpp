// from server: 100% by king_originala
struct Getter;
typedef void* (__thiscall *GetValue)(Getter*, void**, void*);

struct Getter {
    GetValue* table;
};

struct Output {
    void assign(void* value);
};

struct S {
    unsigned char padding[24];
    Getter* getter;
    void get(void* object, Output* output);
};

void S::get(void* object, Output* output)
{
    void* value = getter->table[2](getter, &object, object);
    output->assign(value);
}
