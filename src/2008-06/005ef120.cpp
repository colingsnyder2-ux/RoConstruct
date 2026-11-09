// from server: 100% by king_originala
extern char descriptorName[];
extern void __cdecl descriptorCallback();
extern void __cdecl registerDescriptor(void (__cdecl *)(), const char *);
extern void * __cdecl getDescriptor();
extern void * __cdecl allocate(unsigned int);

struct Node;
typedef void (__thiscall *DestroyNode)(Node *, unsigned int);

struct Node {
    DestroyNode *vtable;
    unsigned int value;
};

extern DestroyNode nodeVtable[];

struct SurfaceDescriptor {
    void *descriptor;
    Node *storage;
    SurfaceDescriptor *initialize(unsigned int *source);
};

SurfaceDescriptor *SurfaceDescriptor::initialize(unsigned int *source)
{
    registerDescriptor(descriptorCallback, descriptorName);
    descriptor = getDescriptor();

    Node **destination = &storage;
    Node *replacement = static_cast<Node *>(allocate(8));
    if (replacement) {
        replacement->vtable = nodeVtable;
        replacement->value = *source;
    } else {
        replacement = 0;
    }

    Node *previous = replacement;
    if (static_cast<void *>(&source) != static_cast<void *>(destination)) {
        previous = *destination;
        *destination = replacement;
    }

    if (previous)
        previous->vtable[0](previous, 1);

    return this;
}
