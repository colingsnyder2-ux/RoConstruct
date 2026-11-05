// from server: 100% by king_originala
struct VChunk { char pad[8]; };
extern char* __cdecl f(VChunk*);

struct S {
    char pad[0x18];
    VChunk* chunk;
    char* get();
};

#pragma optimize("", off)
char* S::get()
{
    return f(chunk);
}
