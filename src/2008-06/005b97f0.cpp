// from server: 100% by king_originala
extern "C" void* __stdcall convert(void*, int);
extern "C" void __cdecl dispose(void*);

struct Node {
    char padding[8];
    int count;
};

struct Reference {
    Node* pointer;
    void release();
};

struct S {
    char padding[0x134];
    Reference reference;
    char gap[4];
    void* resource;

    void f();
};

void S::f()
{
    if (resource) {
        dispose(convert(resource, 0));
        resource = 0;
    }

    if (reference.pointer) {
        --reference.pointer->count;
        reference.release();
    }
}
