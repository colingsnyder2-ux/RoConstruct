// from server: 21% by atomic.potato
// roc 2012-06 0044d860  unit: PasteVerb  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0044d860

struct PasteVerb {
};

void __cdecl copy_range(char** outEnd, char* out, const char* first, const char* last) {
    char* dst = out;
    const char* cur = first;
    while (cur != last) {
        *dst = *cur;
        dst += 1;
        cur += 1;
    }
    *outEnd = dst;
}
