// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: map<unsigned, V>::operator[] where V holds an Ogre AxisAlignedBox; V is modelled as an opaque blob.
extern "C" int __fastcall fn_006976f0(void* self, int unusedEdx, int a1, int a2, int a3, int a4);

struct Node {
    Node* left;
    Node* parent;
    Node* right;
    unsigned key;
    char value[0x2c];
    char pad[1];
    char isnil;
};

struct Map {
    void* proxy;
    Node* head;
};

struct Pair {
    unsigned key;
    char value[0x2c];
};

extern "C" void* __fastcall fn_006999f0(Map* self, int unusedEdx, unsigned* keyp)
{
    Node* head = self->head;
    Node* bound = head;
    Node* n = head->parent;
    while (!n->isnil) {
        if (n->key < *keyp) {
            n = n->right;
        } else {
            bound = n;
            n = n->left;
        }
    }
    if (bound == self->head || *keyp < bound->key) {
        Pair p;
        char ret[8];
        p.key = *keyp;
        int* r = (int*)(void*)fn_006976f0(self, 0, (int)ret, (int)self->proxy, (int)bound, (int)&p);
        bound = (Node*)r[1];
    }
    return (char*)bound + 0x10;
}
