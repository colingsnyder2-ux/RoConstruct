// from server: 38% by atomic.potato
// roc 2011-06 0092b9c0  size: 57 bytes
// Reconstructs a backward copy loop over 0x20-byte elements, assigning
// a std::string member at offset 0 and copying a dword at offset 0x1c.

struct Elem {
    char pad0[0x1c];
    int field1c;
};

struct StringAssign {
    void assign(const void* src);
};

extern "C" void* __stdcall string_assign_import(void* dst, const void* src);

Elem* copy_backward(Elem* first, Elem* last, Elem* result) {
    if (first == last) {
        return result;
    }
    Elem* src = last;
    Elem* dst = result;
    do {
        src -= 1;
        dst -= 1;
        string_assign_import(dst, src);
        dst->field1c = src->field1c;
    } while (src != first);
    return dst;
}
