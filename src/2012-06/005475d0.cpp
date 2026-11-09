// from server: 100% by tajop
struct Sub {
    void assign(const int* v);
};

struct Out {
    int head;
    Sub tail;
};

struct S {
    char pad0[0x2c];
    unsigned int count;
    char pad1[0x90 - 0x30];
    int* items;
    bool get(unsigned int index, Out* out);
};

extern "C" int __cdecl sub_557590();

bool S::get(unsigned int index, Out* out) {
    bool ok;
    int value;
    if (index < count) {
        value = items[index];
        ok = true;
    } else {
        ok = false;
    }
    out->head = sub_557590();
    out->tail.assign(&value);
    return ok;
}
