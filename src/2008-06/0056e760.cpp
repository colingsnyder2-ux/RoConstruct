// from server: 100% by king_originala
struct S {
    int reserved;
    int type;
    union {
        double number;
        float single;
        const char *text;
    } value;
    bool toNumber(double *);
};

struct Value {
    char reserved[16];
    S data;
    bool check();
};

struct Setter;

struct SetterTable {
    void *reserved[3];
    void (__thiscall *set)(Setter *, void *, const double *);
};

struct Setter {
    SetterTable *table;
};

struct Descriptor {
    char reserved[24];
    Setter *setter;
    void apply(void *, Value *, void *);
};

void Descriptor::apply(void *object, Value *value, void *)
{
    double number;
    if (!value->check() && value->data.toNumber(&number))
        setter->table->set(setter, object, &number);
}
