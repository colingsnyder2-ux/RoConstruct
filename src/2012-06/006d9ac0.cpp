// from server: 84% by atomic.potato
struct S {
    char pad0[0x2c];
    unsigned int count;
    char pad1[0x90 - 0x30];
    int* items;
    bool f(unsigned int index, int* out);
};

extern "C" int __cdecl sub_783c30();
extern "C" void __cdecl sub_6d6be0(int*);

bool S::f(unsigned int index, int* out) {
    bool ok;
    int value;
    if (index < count) {
        value = items[index];
        ok = true;
    } else {
        ok = false;
    }
    *out = sub_783c30();
    sub_6d6be0(&value);
    return ok;
}
