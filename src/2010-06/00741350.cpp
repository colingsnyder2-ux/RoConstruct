// from server: 28% by atomic.potato
struct Elem {
    char pad[0x20];
    int field20;
};

struct S {
};

Elem* __cdecl f(Elem* first, Elem* last, Elem* dest) {
    if (first != last) {
        Elem* d = dest - 1;
        Elem* s = last - 1;
        do {
            d->~Elem();
            *d = *s;
            d->field20 = s->field20;
            --s;
            --d;
        } while (s != first - 1);
        return dest - 1;
    }
    return dest;
}
