// from server: 100% by king_originala
struct TypeInfo {};
extern TypeInfo target_type;

struct Buffer {
    const TypeInfo* type;
};

struct Tag {};

extern void __cdecl manage_impl(const Buffer&, Buffer&, int, Tag);

struct Manager {
    static void __cdecl manage(const Buffer&, Buffer&, int);
};

void __cdecl Manager::manage(const Buffer& source, Buffer& destination, int operation)
{
    if (operation != 3)
        manage_impl(source, destination, operation, Tag());
    else
        destination.type = &target_type;
}
