// from server: 25% by Intel
struct E {
    char pad[0x1C];
    int field_1C;
};

struct S {
    void __cdecl f(E* a, E* b, E* c);
};

extern "C" void __stdcall construct_string(void* thisptr, const void* src);

void S::f(E* a, E* b, E* c) {
    E* esi = c;
    E* edi = a;
    E* end = b;

    while (edi != end) {
        if (esi != 0) {
            construct_string(esi, edi);
            esi->field_1C = edi->field_1C;
        }
        esi = reinterpret_cast<E*>(reinterpret_cast<char*>(esi) + 0x20);
        edi = reinterpret_cast<E*>(reinterpret_cast<char*>(edi) + 0x20);
    }
}
