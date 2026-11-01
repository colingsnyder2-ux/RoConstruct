// from server: 100% by king_originala
struct Value
{
    double get();
};

struct Accessor;

struct AccessorTable
{
    unsigned char padding[12];
    void (__thiscall *set)(Accessor *, void *, const double *);
};

struct Accessor
{
    AccessorTable *table;
};

struct Descriptor
{
    unsigned char padding[24];
    Accessor *accessor;

    void set(void *object, Value *value);
};

void Descriptor::set(void *object, Value *value)
{
    double converted = value->get();
    accessor->table->set(accessor, object, &converted);
}
