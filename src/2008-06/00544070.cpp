// from server: 100% by king_originala
#pragma optimize("g", off)

struct VChunk;

char* __cdecl flag(VChunk*);
char* __cdecl link(VChunk*);
void* __cdecl access(void*);
VChunk** __cdecl back(VChunk*);

struct S {
    VChunk** root();
    void f(VChunk*);
};

void S::f(VChunk* p)
{
    VChunk* q = *(VChunk**)access(p);
    *(VChunk**)access(p) = *(VChunk**)link(q);

    if (!*flag(*(VChunk**)link(q)))
        *back(*(VChunk**)link(q)) = p;

    *back(q) = *back(p);

    if (p == *root())
        *root() = q;
    else if (p == *(VChunk**)link(*back(p)))
        *(VChunk**)link(*back(p)) = q;
    else
        *(VChunk**)access(*back(p)) = q;

    *(VChunk**)link(q) = p;
    *back(p) = q;
}
