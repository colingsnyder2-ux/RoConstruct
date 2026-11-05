// from server: 100% by king_originala
struct Tag {
    char value;
};

extern char typeInfo;
extern void __cdecl manageObject(void *, void *, int, Tag);

void __cdecl manage(void *source, void *destination, int operation)
{
    if (operation != 3) {
        Tag tag = { 0 };
        manageObject(source, destination, operation, tag);
    } else {
        *static_cast<void **>(destination) = &typeInfo;
    }
}
