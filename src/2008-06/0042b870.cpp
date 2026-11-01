// from server: 100% by king_originala
struct Flag
{
    bool value;
};

extern void __cdecl manage_impl(const void*, void*, int, Flag);

void __cdecl manage(const void* source, void* destination, int operation)
{
    if (operation != 3)
    {
        Flag flag = { false };
        manage_impl(source, destination, operation, flag);
    }
    else
    {
        *static_cast<unsigned long*>(destination) = 0x0092e9b8;
    }
}
