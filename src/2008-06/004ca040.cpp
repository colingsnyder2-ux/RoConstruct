// from server: 100% by king_originala
struct Object;
struct Result;
struct Node;
struct Interface;

typedef Result* (__thiscall *GetResult)(Object*);
typedef char* (__thiscall *GetValue)(Interface*);

struct Object
{
    GetResult* vtable;
};

struct Result
{
    char padding[0x170];
    Node* node;
};

struct Node
{
    char padding[0x134];
    int* vbtable;
};

struct Interface
{
    GetValue* vtable;
};

extern "C" void* __cdecl sub_5E50C0(void*);

struct S
{
    int padding;
    Object* object;
    void* f();
};

void* S::f()
{
    Result* result = object->vtable[17](object);
    if (result)
    {
        Node* node = result->node;
        if (node)
        {
            Interface* interfaceObject = reinterpret_cast<Interface*>(
                reinterpret_cast<char*>(node) + 0x134 + node->vbtable[1]);
            char* value = interfaceObject->vtable[0](interfaceObject);
            if (value)
                return sub_5E50C0(value + 0x228);
        }
    }
    return 0;
}
