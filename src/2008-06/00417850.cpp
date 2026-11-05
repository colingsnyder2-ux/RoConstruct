// from server: 100% by king_originala
struct TypeInfo { char data[1]; };

extern TypeInfo target_type;
extern bool (__thiscall *compare_types)(const TypeInfo*, const TypeInfo*);

void __cdecl f(void* source, void** destination, int operation)
{
    if (operation != 3)
    {
        if (operation == 0)
        {
            if (destination)
                *destination = *(void**)source;
        }
        else if (operation != 1)
        {
            *destination = compare_types((const TypeInfo*)*destination,
                                         &target_type) ? source : 0;
        }
    }
    else
    {
        *destination = &target_type;
    }
}
