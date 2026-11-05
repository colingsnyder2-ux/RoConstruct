// from server: 100% by king_originala
struct TypeInfo;
extern const TypeInfo target_type;

typedef bool (__thiscall *TypeEqual)(const TypeInfo *, const TypeInfo *);
extern TypeEqual type_equal;

struct Data
{
    unsigned int a, b, c, d;
};

void func_0066ecb0(Data *source, void *output, int operation)
{
    if (operation == 0)
    {
        if (output)
            *static_cast<Data *>(output) = *source;
    }
    else if (operation != 1)
    {
        const TypeInfo *type = *static_cast<const TypeInfo **>(output);
        *static_cast<Data **>(output) =
            type_equal(type, &target_type) ? source : 0;
    }
}
