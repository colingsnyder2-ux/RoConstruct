// from server: 52% by atomic.potato
struct EThrottleEnumDesc {
    char pad0[0x24];
    unsigned int count;
    char pad1[0x60];
    int* items;
    bool get(unsigned int index, int* out);
};

extern "C" void __stdcall helper(int* out, int value);

bool EThrottleEnumDesc::get(unsigned int index, int* out) {
    bool result;
    if (index >= count) {
        result = false;
    } else {
        int value = items[index];
        helper(out, value);
        result = true;
    }
    return result;
}
