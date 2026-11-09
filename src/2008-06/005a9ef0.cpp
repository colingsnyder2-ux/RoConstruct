// from server: 100% by king_originala
struct String {
    unsigned int reserved;
    union {
        char buffer[16];
        char* pointer;
    };
    unsigned int length;
    unsigned int capacity;
};

struct Object {
    unsigned int reserved;
    String name;
};

struct Node {
    unsigned int reserved;
    Object* object;
};

struct Result {
    Node* node;
};

extern void* g;
extern "C" Result* __cdecl a(void*, int, void*);
extern "C" void __cdecl b(void*, const char*);

extern "C" int __cdecl f(void* p)
{
    String* s = &a(p, 1, g)->node->object->name;
    b(p, s->capacity >= 16 ? s->pointer : s->buffer);
    return 1;
}
