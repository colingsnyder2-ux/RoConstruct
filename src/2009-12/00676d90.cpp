// from server: 41% by atomic.potato
struct GlobalSettings {
    int mode;
    int value;
    bool compare(const char* other);
};

extern "C" int __stdcall string_compare(const void* a, const void* b);

bool GlobalSettings::compare(const char* other) {
    int m = mode - 1;
    if (m == 0) {
        return other == (const char*)value;
    }
    m = m - 1;
    if (m == 0) {
        int r = string_compare((const void*)value, other);
        return r == 0;
    }
    return false;
}
