// from server: 100% by atomic.potato
struct StrData {
    int pad0;
    union {
        char buf[16];
        const char* ptr;
    } bx;
    unsigned int length;
    unsigned int capacity;
};

extern "C" void __cdecl sub_6d6e00(int* out, const char* data, unsigned int size);

int sub_6d6e50(const StrData* s) {
    unsigned int len = s->length;
    const char* data;
    if (s->capacity >= 16) {
        data = s->bx.ptr;
    } else {
        data = (const char*)&s->bx;
    }
    int result = 0;
    sub_6d6e00(&result, data, len);
    return result;
}
