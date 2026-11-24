// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: this is a std::map<Key, Value>::operator[] instantiation (MSVC 2008, checked
// iterators). The key layout, node layout and the exact types are guesses from the offsets.
struct MapKey {
    float x, y, z;       // compared by fn_004dc360
    unsigned int a;      // key + 0x0c
    int b;               // key + 0x10
};

struct MapNode {
    MapNode* left;
    MapNode* parent;
    MapNode* right;
    MapKey   key;        // node + 0x0c
    int      value;      // node + 0x20  (returned by address)
};

struct MapContainer {
    void*    proxy;      // + 0x00
    char     pad[0x14];
    MapNode* head;       // + 0x18
};

extern "C" TreeNode* __fastcall fn_004dc590(Tree* self, int unusedEdx, const Key* key);
extern "C" int __fastcall fn_004dc360(void* self, int unusedEdx);
extern "C" int __fastcall fn_004dd9a0(void* self, int unusedEdx, int a1, int a2, int a3, int a4);

extern "C" int* __fastcall fn_004ddf80(MapContainer* self, int unusedEdx, MapKey* key)
{
    MapNode* where = (MapNode*)fn_004dc590((int)key);
    MapNode* head  = self->head;
    bool needInsert = false;

    if (where == head) {
        needInsert = true;
    } else {
        int c = fn_004dc360(&where->key, (int)key);
        if (c < 0) {
            needInsert = true;
        } else if (c > 0) {
            needInsert = false;
        } else if (key->a < where->key.a) {
            needInsert = true;
        } else if (key->a > where->key.a) {
            needInsert = false;
        } else if (key->b < where->key.b) {
            needInsert = true;
        }
    }

    if (needInsert) {
        struct Pair { MapKey key; int value; } p;
        p.value = 0;
        p.key = *key;
        int result[2];
        int* r = (int*)fn_004dd9a0(self, 0, (int)result, (int)self->proxy, (int)where, (int)&p);
        // INFERRED: iterator result {container proxy, node}
        where = (MapNode*)r[1];
    }
    return &where->value;
}
