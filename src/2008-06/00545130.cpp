// from server: 100% by king_originala

#pragma optimize("g", off)

struct VChunk;

char* __cdecl left(VChunk*);
char* __cdecl right(VChunk*);
char* __cdecl parent(VChunk*);
char* __cdecl color(VChunk*);

struct S {
    VChunk** root();
    void f(VChunk*);
};

void S::f(VChunk* p)
{
    VChunk* q = *reinterpret_cast<VChunk**>(right(p));

    *reinterpret_cast<VChunk**>(right(p)) =
        *reinterpret_cast<VChunk**>(left(q));

    if (*color(*reinterpret_cast<VChunk**>(left(q))) == 0)
        *reinterpret_cast<VChunk**>(
            parent(*reinterpret_cast<VChunk**>(left(q)))) = p;

    *reinterpret_cast<VChunk**>(parent(q)) =
        *reinterpret_cast<VChunk**>(parent(p));

    if (p == *root())
        *root() = q;
    else if (p == *reinterpret_cast<VChunk**>(
                      left(*reinterpret_cast<VChunk**>(parent(p)))))
        *reinterpret_cast<VChunk**>(
            left(*reinterpret_cast<VChunk**>(parent(p)))) = q;
    else
        *reinterpret_cast<VChunk**>(
            right(*reinterpret_cast<VChunk**>(parent(p)))) = q;

    *reinterpret_cast<VChunk**>(left(q)) = p;
    *reinterpret_cast<VChunk**>(parent(p)) = q;
}
