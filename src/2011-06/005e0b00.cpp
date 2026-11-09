// from server: 39% by atomic.potato
struct S {
    char pad0[0x24];
    unsigned int count;
    char pad1[0x60];
    int* items;
    bool get(unsigned int index, int* out);
};

extern "C" void __stdcall helper(int* out, int value);

bool S::get(unsigned int index, int* out) {
    bool result;
    if (index >= count) {
        result = false;
    } else {
        int v = items[index];
        result = true;
    }
    helper(out, 0);
    return result;
}
