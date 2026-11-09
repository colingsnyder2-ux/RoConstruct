// from server: 100% by king_originala
struct PartInstance {
    char padding[0x104];
    void* instance;
};

struct GetSetImpl {
    static PartInstance* get(PartInstance*);
};

struct Node {
    char padding[0x0c];
    PartInstance* parts[2];
};

struct Geometry {
    char pad0[0x38];
    int* field38;
    int field3c;
    int f();
    Node* next(Node*);
};

extern "C" void* __cdecl __RTDynamicCast(
    void*, long, void*, void*, int);

struct S {
    char padding[0x228];
    Geometry geometry;
    void* f();
};

void* S::f()
{
    Geometry* g = &geometry;
    Node* node = reinterpret_cast<Node*>(g->f());

    while (node) {
        for (int i = 0; i < 2; ++i) {
            void* instance = GetSetImpl::get(node->parts[i])->instance;
            void* result = __RTDynamicCast(
                instance, 0,
                reinterpret_cast<void*>(0x92907c),
                reinterpret_cast<void*>(0x94be40), 0);
            if (result)
                return result;
        }
        node = g->next(node);
    }

    return 0;
}
