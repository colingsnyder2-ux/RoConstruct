// from server: 100% by king_originala
struct TypeInfo
{
    char data[1];
};

extern const TypeInfo function_type;
extern bool (__thiscall *type_equal)(const TypeInfo *, const TypeInfo *);

void manage(const void *source, const void **destination, int operation)
{
    if (operation != 3)
    {
        if (operation == 0)
        {
            *destination = *static_cast<const void *const *>(source);
            return;
        }

        if (operation == 1)
        {
            *destination = 0;
            return;
        }

        *destination = type_equal(
            static_cast<const TypeInfo *>(*destination),
            &function_type) ? source : 0;
    }
    else
    {
        *destination = &function_type;
    }
}
