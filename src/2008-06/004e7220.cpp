// from server: 100% by king_originala
struct Pair {
    void *first;
    void *second;
};

extern char typeTag;
extern bool (__thiscall *typeEqual)(const void *, const void *);

void __cdecl manage(Pair *source, Pair *destination, int operation)
{
    if (operation != 3) {
        if (operation == 0) {
            if (destination) {
                destination->first = source->first;
                destination->second = source->second;
            }
        } else if (operation != 1) {
            destination->first =
                typeEqual(destination->first, &typeTag) ? source : 0;
        }
        return;
    }
    destination->first = &typeTag;
}
