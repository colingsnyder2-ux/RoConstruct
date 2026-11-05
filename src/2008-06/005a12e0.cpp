// from server: 100% by king_originala
struct Tag {};

extern void __cdecl manage(void*, void*, int, Tag);

void __cdecl dispatch(void* source, void* destination, int operation)
{
    if (operation != 3)
        manage(source, destination, operation, Tag());
    else
        *static_cast<unsigned long*>(destination) = 0x0094B940UL;
}
