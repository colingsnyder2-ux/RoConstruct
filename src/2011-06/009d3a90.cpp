// from server: 34% by colin
struct seg_009d0000 {
    int f();
};

int seg_009d0000::f() {
    int result;
    result = 0;
    if (reinterpret_cast<unsigned int>(this) != 0) {
        result = reinterpret_cast<int>(this) & *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x75b6e900);
    }
    return result;
}
