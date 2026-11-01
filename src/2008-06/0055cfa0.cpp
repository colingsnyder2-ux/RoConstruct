// from server: 100% by king_originala
extern const char target_type;
extern bool (__thiscall *type_equal)(const void *, const void *);

void manage(const unsigned int *source, unsigned int *destination, int operation)
{
    if (operation == 0)
    {
        if (destination)
        {
            destination[0] = source[0];
            destination[1] = source[1];
            destination[2] = source[2];
            destination[3] = source[3];
        }
    }
    else if (operation != 1)
    {
        destination[0] =
            type_equal((const void *)destination[0], &target_type)
            ? (unsigned int)source : 0;
    }
}
