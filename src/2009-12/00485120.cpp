// from server: 38% by atomic.potato
// roc 2009-12 00485120  unit: G3D::GCamera  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00485120

extern "C" {
typedef unsigned int size_t;
}

struct std_string_assign {
    void* dummy;
};

// std::string assignment operator
extern "C" void* __stdcall string_assign(void* dest, const void* src);

struct Elem {
    char pad[0x1c];
    int field_1c;
};

struct GCamera {
    Elem* __cdecl copy_range(Elem* first, Elem* last, Elem* dest);
};

Elem* GCamera::copy_range(Elem* first, Elem* last, Elem* dest) {
    if (first == last) {
        return dest;
    }
    Elem* src = last - 1;
    Elem* dst = dest - 1;
    do {
        string_assign(dst, src);
        dst->field_1c = src->field_1c;
        src--;
        dst--;
    } while (src != first);
    return dst;
}
