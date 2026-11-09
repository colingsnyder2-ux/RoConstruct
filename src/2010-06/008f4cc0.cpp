// from server: 35% by atomic.potato
struct Elem {
    char pad[0x48];
};

struct S {
};

Elem* __cdecl copy_range(Elem* first, Elem* last, Elem* dest) {
    while (first != last) {
        if (dest) {
            dest->~Elem();
            *dest = *first;
        }
        ++first;
        ++dest;
    }
    return dest;
}
