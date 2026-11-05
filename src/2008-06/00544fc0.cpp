// from server: 100% by king_originala
#pragma optimize("", off)

struct VChunk;

extern "C" char* __cdecl link8(VChunk*);
extern "C" char* __cdecl flag29(VChunk*);
extern "C" void* __cdecl link0(void*);
extern "C" void* __cdecl link4(VChunk*);

struct S {
    VChunk** root();
    void f(VChunk*);
};

void S::f(VChunk* p)
{
    VChunk* q = *(VChunk**)link8(p);

    *(VChunk**)link8(p) = *(VChunk**)link0(q);

    if (*flag29(*(VChunk**)link0(q)) == 0)
        *(VChunk**)link4(*(VChunk**)link0(q)) = p;

    *(VChunk**)link4(q) = *(VChunk**)link4(p);

    if (p == *root())
        *root() = q;
    else if (p == *(VChunk**)link0(*(VChunk**)link4(p)))
        *(VChunk**)link0(*(VChunk**)link4(p)) = q;
    else
        *(VChunk**)link8(*(VChunk**)link4(p)) = q;

    *(VChunk**)link0(q) = p;
    *(VChunk**)link4(p) = q;
}
