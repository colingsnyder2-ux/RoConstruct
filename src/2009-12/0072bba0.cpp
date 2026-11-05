// from server: 40% by atomic.potato
struct Elem {
    char pad0[0x20];
    int field20;
};

struct Iter {
    Elem* cur;
};

extern "C" void __fastcall sub_7007B0(Elem* dst, Elem* src);

Elem* __fastcall func(Elem* first, Elem* last, Elem* result) {
    if (first == last) {
        return result;
    }
    Elem* d = result;
    Elem* s = last;
    do {
        s = (Elem*)((char*)s - 0x28);
        d = (Elem*)((char*)d - 0x28);
        sub_7007B0(d, s);
        d->field20 = s->field20;
    } while (s != first);
    return d;
}
