// from server: 100% by colin
struct LiveThreadRef;

struct ThreadRef {
    int* liveThreadRef;
    void* node;

    ThreadRef(LiveThreadRef* ref);
};

struct Node {
    void* vtable;
    void* ref;
    Node(void* r);
};

extern "C" void* __cdecl sub_56dcc0();
extern "C" void* __cdecl sub_62fef6(unsigned int size);

void* g_vtable_7a577c = (void*)0x7a577c;

ThreadRef::ThreadRef(LiveThreadRef* ref)
{
    liveThreadRef = (int*)sub_56dcc0();
    Node* n = (Node*)sub_62fef6(8);
    if (n) {
        n->vtable = &g_vtable_7a577c;
        n->ref = *(void**)ref;
    } else {
        n = 0;
    }
    void* old = node;
    node = n;
    if (old) {
        (*(void(__thiscall**)(void*, int))*(void**)old)(old, 1);
    }
}
