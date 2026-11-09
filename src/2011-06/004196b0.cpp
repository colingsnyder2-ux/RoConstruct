// from server: 51% by atomic.potato
struct S {
    char pad0[0x1c];
    int field1c;
    S* __cdecl f(S* other);
};

extern "C" void* __stdcall sub_419270(void*);
extern "C" void* __stdcall sub_a404c8();

S* S::f(S* other) {
    void* p = sub_419270(other);
    sub_a404c8();
    this->field1c = *(int*)((char*)p + 0x1c);
    return this;
}
