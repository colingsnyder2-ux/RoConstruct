// from server: 100% by king_originala
struct VChunk;

char * __cdecl rightLink(VChunk *);
void * __cdecl leftLink(void *);
char * __cdecl parentLink(VChunk *);
char * __cdecl nilFlag(VChunk *);

struct S {
    char *rootLink();
    void f(VChunk *);
};

#pragma optimize("", off)
void S::f(VChunk *node)
{
    VChunk *replacement = *reinterpret_cast<VChunk **>(rightLink(node));

    *reinterpret_cast<VChunk **>(rightLink(node)) =
        *reinterpret_cast<VChunk **>(leftLink(replacement));

    if (*nilFlag(*reinterpret_cast<VChunk **>(leftLink(replacement))) == 0) {
        *reinterpret_cast<VChunk **>(
            parentLink(*reinterpret_cast<VChunk **>(leftLink(replacement)))) = node;
    }

    *reinterpret_cast<VChunk **>(parentLink(replacement)) =
        *reinterpret_cast<VChunk **>(parentLink(node));

    if (node == *reinterpret_cast<VChunk **>(rootLink())) {
        *reinterpret_cast<VChunk **>(rootLink()) = replacement;
    } else if (node == *reinterpret_cast<VChunk **>(
                           leftLink(*reinterpret_cast<VChunk **>(parentLink(node))))) {
        *reinterpret_cast<VChunk **>(
            leftLink(*reinterpret_cast<VChunk **>(parentLink(node)))) = replacement;
    } else {
        *reinterpret_cast<VChunk **>(
            rightLink(*reinterpret_cast<VChunk **>(parentLink(node)))) = replacement;
    }

    *reinterpret_cast<VChunk **>(leftLink(replacement)) = node;
    *reinterpret_cast<VChunk **>(parentLink(node)) = replacement;
}
#pragma optimize("", on)
