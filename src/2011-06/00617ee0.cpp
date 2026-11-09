// from server: 75% by colin
// roc 2011-06 00617ee0  unit: boost::bad_lexical_cast  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00617ee0

extern "C" int __cdecl sub_762960(const char*, const char*, unsigned int);

struct S {
    int __cdecl f(const char* a, const char* b, void* c);
};

int S::f(const char* a, const char* b, void* c) {
    unsigned int* p = (unsigned int*)c;
    unsigned int n = p[5];
    if (p[6] >= 0x10) {
        return sub_762960(a, (const char*)((char*)p + 4), n);
    }
    return sub_762960(a, (const char*)p[1], n);
}
