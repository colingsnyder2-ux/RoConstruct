// from server: 100% by king_originala
struct Holder;
typedef void (__thiscall *Destroy)(Holder*, unsigned int);

struct Holder {
    Destroy* table;
    unsigned int value;
};

struct Color {
    unsigned int value;
};

struct S {
    void* type;
    Holder* holder;

    void assign(const Color* value);
};

struct Accessor;
typedef Color* (__thiscall *Getter)(Accessor*, void**, void*);

struct Accessor {
    Getter* table;
};

struct Descriptor {
    unsigned char reserved[24];
    Accessor* accessor;

    void f(void* instance, S* output);
};

void Descriptor::f(void* instance, S* output)
{
    output->assign(accessor->table[2](accessor, &instance, instance));
}
