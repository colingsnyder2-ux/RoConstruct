// from server: 100% by king_originala
#pragma optimize("", off)

struct VChunk {
    char pad[4];
};

char* __cdecl getPointer(VChunk* p);

struct S {
    char pad[0x18];
    VChunk* pointer;
    char* f();
};

char* S::f() {
    return getPointer(pointer);
}
