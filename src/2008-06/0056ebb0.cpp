// from server: 100% by king_originala
struct TypeInfo {};
extern bool (__thiscall *type_equal)(const TypeInfo*, const TypeInfo&);

extern const TypeInfo int_type;
extern const TypeInfo float_type;
extern const TypeInfo double_type;
extern const double double_zero;

struct Holder;
struct HolderTable {
    void* (__thiscall *destroy)(Holder*, unsigned int);
};

struct Holder {
    const HolderTable* table;
    bool value;
};

extern const HolderTable bool_holder_table;
extern void* __cdecl allocate(unsigned int);

struct Owned {
    Holder* pointer;
    ~Owned();
    void swap(Owned&);
};

inline Owned::~Owned()
{
    if (pointer)
        pointer->table->destroy(pointer, 1);
}

inline void Owned::swap(Owned& other)
{
    if (this != &other) {
        Holder* old = pointer;
        pointer = other.pointer;
        other.pointer = old;
    }
}

extern int __cdecl cast_int(const Owned*);
extern float __cdecl cast_float(const Owned*);
extern double __cdecl cast_double(const Owned*);

struct Descriptor {
    unsigned long words[2];
    const TypeInfo* type;
    const TypeInfo& getType() const;
};

__forceinline const TypeInfo& Descriptor::getType() const
{
    return *type;
}

extern Descriptor* __cdecl bool_descriptor();

struct S {
    Descriptor* descriptor;
    Owned value;
    void finish();
    void func_0056ebb0();
};

void S::func_0056ebb0()
{
    bool (__thiscall *equal)(const TypeInfo*, const TypeInfo&) = type_equal;

    if (equal(&int_type, descriptor->getType())) {
        bool result = cast_int(&value) != 0;
        Holder* holder = static_cast<Holder*>(allocate(8));
        if (holder) {
            holder->table = &bool_holder_table;
            holder->value = result;
        } else {
            holder = 0;
        }
        {
            Owned temporary;
            temporary.pointer = holder;
            temporary.swap(value);
        }
        descriptor = bool_descriptor();
    }

    if (equal(&float_type, descriptor->getType())) {
        bool result = static_cast<double>(cast_float(&value)) != 0.0;
        Holder* holder = static_cast<Holder*>(allocate(8));
        if (holder) {
            holder->table = &bool_holder_table;
            holder->value = result;
        } else {
            holder = 0;
        }
        {
            Owned temporary;
            temporary.pointer = holder;
            temporary.swap(value);
        }
        descriptor = bool_descriptor();
    }

    if (equal(&double_type, descriptor->getType())) {
        bool result = cast_double(&value) != double_zero;
        Holder* holder = static_cast<Holder*>(allocate(8));
        if (holder) {
            holder->table = &bool_holder_table;
            holder->value = result;
        } else {
            holder = 0;
        }
        {
            Owned temporary;
            temporary.pointer = holder;
            temporary.swap(value);
        }
        descriptor = bool_descriptor();
    }

    finish();
}
