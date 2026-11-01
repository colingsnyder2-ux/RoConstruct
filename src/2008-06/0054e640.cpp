// from server: 100% by king_originala
struct VChunk;
extern char* __cdecl flag(VChunk*);

struct Mesh {
    char pad[0x18];
    VChunk* chunk;
    int state;

    VChunk* acquire();
    VChunk** slot1();
    VChunk** slot2();
    char* get();
    void f();
};

#pragma optimize("", off)
void Mesh::f()
{
    chunk = acquire();
    *flag(chunk) = 1;
    *slot1() = chunk;
    *slot2() = chunk;
    *(VChunk**)get() = chunk;
    state = 0;
}
#pragma optimize("", on)
