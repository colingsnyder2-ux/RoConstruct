// from server: 38% by Intel
struct KeyframeSequence {
};

void __cdecl copyData(void* dest, void* src, void* end) {
    if (src == end) {
        return;
    }

    char* d = static_cast<char*>(dest);
    char* s = static_cast<char*>(src);
    char* e = static_cast<char*>(end);

    do {
        if (d != 0) {
            *reinterpret_cast<int*>(d) = *reinterpret_cast<int*>(s);
            *reinterpret_cast<int*>(d + 4) = *reinterpret_cast<int*>(s + 4);
        }
        s += 0x20;
        d += 0x20;
    } while (s != e);
}
