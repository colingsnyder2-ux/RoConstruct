// from server: 35% by atomic.potato
struct Elem {
    char pad[0x48];
};

struct S {
};

Elem* __cdecl copy_range(Elem* first, Elem* last, Elem* dest) {
    while (first != last) {
        if (dest) {
            Elem* d = dest;
            Elem* f = first;
            d->~Elem();
            *d = *f;
        }
        first = (Elem*)((char*)first + 0x48);
        dest = (Elem*)((char*)dest + 0x48);
    }
    return dest;
}
