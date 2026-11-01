// from server: 100% by colin
struct TypeInfo
{
    unsigned int data[3];
};

extern TypeInfo intType;
extern TypeInfo boolType;
extern TypeInfo floatType;
typedef bool (__thiscall *TypeEqual)(const TypeInfo *, const TypeInfo *);
extern TypeEqual typeEqual;

struct Descriptor
{
    unsigned int data[2];
    const TypeInfo *type;
};

struct Holder;
typedef void (__thiscall *DestroyHolder)(Holder *, unsigned int);

struct Holder
{
    DestroyHolder *vtable;
    unsigned int padding;
    double value;

    Holder(double);
};

extern DestroyHolder doubleHolderVtable[];
extern void * __cdecl operator new(unsigned int);
extern int __cdecl getInt(Holder **);
extern bool __cdecl getBool(Holder **);
extern double __cdecl getFloat(Holder **);
extern Descriptor * __cdecl getDoubleDescriptor();

inline Holder::Holder(double v)
{
    vtable = doubleHolderVtable;
    value = v;
}

struct Owner
{
    Holder *pointer;

    void swap(Owner &);
    ~Owner();
};

inline void Owner::swap(Owner &other)
{
    if (this != &other)
    {
        Holder *old = pointer;
        pointer = other.pointer;
        other.pointer = old;
    }
}

inline Owner::~Owner()
{
    if (pointer)
        pointer->vtable[0](pointer, 1);
}

struct S
{
    Descriptor *descriptor;
    Owner holder;

    double f();
    double finish();
};

double S::f()
{
    TypeEqual equal = typeEqual;

    {
        const TypeInfo *currentType = descriptor->type;
        if (equal(&intType, currentType))
        {
            double value = getInt(&holder.pointer);
            {
                Owner temporary = { new Holder(value) };
                temporary.swap(holder);
            }
            descriptor = getDoubleDescriptor();
        }
    }

    {
        const TypeInfo *currentType = descriptor->type;
        if (equal(&boolType, currentType))
        {
            double value = getBool(&holder.pointer) ? 1 : 0;
            {
                Owner temporary = { new Holder(value) };
                temporary.swap(holder);
            }
            descriptor = getDoubleDescriptor();
        }
    }

    {
        const TypeInfo *currentType = descriptor->type;
        if (equal(&floatType, currentType))
        {
            double value = getFloat(&holder.pointer);
            {
                Owner temporary = { new Holder(value) };
                temporary.swap(holder);
            }
            descriptor = getDoubleDescriptor();
        }
    }

    return finish();
}
