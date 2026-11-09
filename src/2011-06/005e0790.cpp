// from server: 55% by atomic.potato
struct S {
    char pad[0x24];
    unsigned int count;
    char pad2[0x60];
    int* items;
    bool get(unsigned int index, int* out);
};

extern "C" void __stdcall sub_5df610(int* out, int value);

bool S::get(unsigned int index, int* out) {
    if (index < count) {
        int v = items[index];
        sub_5df610(out, v);
        return true;
    }
    sub_5df610(out, 0);
    return false;
}
