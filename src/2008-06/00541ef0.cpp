// from server: 100% by king_originala
#pragma optimize("", off)

struct VChunk;

char* __cdecl flag(VChunk*);
char* __cdecl child(VChunk*);
void* __cdecl next(VChunk*);

struct Helper {
    void remove(VChunk*);
    void destroy(VChunk*, int);
};

struct S {
    char reserved[12];
    Helper helper;

    void f(VChunk*);
};

void S::f(VChunk* p) {
    for (VChunk* current = p; !*flag(current); p = current) {
        f(*reinterpret_cast<VChunk**>(child(current)));
        current = *reinterpret_cast<VChunk**>(next(current));
        helper.remove(p);
        helper.destroy(p, 1);
    }
}
