// from server: 100% by colin
namespace RBX {
class Body {
public:
    const char* key() const;
};
class Assembly {
public:
    char pad[0x1c];
    Body* body;
};
int __cdecl compareKeys(const char*, const char*);
bool lessAssembly(const Assembly* a, const Assembly* b)
{
    if (a == b)
        return false;
    const Body* x = a->body;
    const Body* y = b->body;
    if (x == y)
        return false;
    return compareKeys(x->key(), y->key()) == -1;
}
}
