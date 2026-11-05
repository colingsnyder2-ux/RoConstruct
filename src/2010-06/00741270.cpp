// from server: 100% by atomic.potato
struct Inner {
    char pad[0x20];
    int field20;
};

struct Outer {
    char pad[0x28];
};

struct Copier {
    void copy(const Inner* src);
};

Outer* copy_range(Outer* first, Outer* last, Outer* dst) {
    if (first != last) {
        do {
            Copier* c = (Copier*)dst;
            c->copy((const Inner*)first);
            ((Inner*)dst)->field20 = ((Inner*)first)->field20;
            first = (Outer*)((char*)first + 0x28);
            dst = (Outer*)((char*)dst + 0x28);
        } while (first != last);
    }
    return dst;
}
