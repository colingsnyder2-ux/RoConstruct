// from server: 100% by tester
struct S {
    char pad[0x1c];
    bool field_1c;
    void f(const void*);
};

extern "C" void* __stdcall sub_616080(const void*, const void*);

void S::f(const void* a) {
    field_1c = sub_616080(a, (const void*)0x97bee0) != 0;
}
