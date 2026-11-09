// from server: 35% by atomic.potato
struct Elem {
    char pad[0x44];
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
        first += 1;
        dest += 1;
    }
    return dest;
}
