// from server: 30% by atomic.potato
struct Elem {
    char pad0[0x1c];
    int a;
    float b;
    float c;
    float d;
    float e;
};

extern "C" void __stdcall sub_689d70(int*);

Elem* copy_elems(Elem* first, Elem* last, Elem* dest) {
    if (first == last) {
        return dest;
    }
    Elem* src = last;
    Elem* dst = dest;
    do {
        src = (Elem*)((char*)src - 0x28);
        dst = (Elem*)((char*)dst - 0x28);
        dst->a = src->a;
        sub_689d70((int*)((char*)dst + 4));
        dst->b = src->b;
        dst->c = src->c;
        dst->d = src->d;
        dst->e = src->e;
    } while (src != first);
    return dst;
}
