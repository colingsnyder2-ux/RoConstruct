// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <stdlib.h>
#include <windows.h>

// INFERRED: the CRT header does not declare this here; the original calls it through the import table.
extern "C" __declspec(dllimport) void __cdecl _invalid_parameter_noinfo(void);

// INFERRED: layout of a tree node as seen from the disassembly.
// Key (x,y,z,w) lives at node+0x0c, mapped value at node+0x1c.
struct FnKey {
    float x, y, z;
    int w;
};

// INFERRED: minimal stand-in for a G3D::ReferenceCountedObject-derived object.
struct FnRefObj {
    virtual void* deletingDtor(unsigned flags) = 0;
    volatile long refCount;
};

// INFERRED: G3D::ReferenceCountedPointer<Texture> equivalent with inline release.
struct FnTexPtr {
    FnRefObj* p;
    FnTexPtr() : p(0) {}
    ~FnTexPtr() {
        if (p) {
            if (InterlockedDecrement(&p->refCount) == 0) {
                // zeroWeakPointers() is called by the original before deletion
                p->deletingDtor(1);
            }
        }
    }
};

struct FnPair {
    FnKey key;
    FnTexPtr tex;
    int extra;
};

struct FnIter {
    char* head;
    char* node;
};

struct FnTree {
    char* proxy;      // +0x00
    char pad[0x14];
    char* head;       // +0x18 (end node)
};

extern "C" TreeNode* __fastcall fn_004e61e0(TreeOwner* self, int unusedEdx, TreeKey* arg);
extern "C" int __fastcall fn_004e9c50(void* self, int unusedEdx, int a1, int a2, int a3, int a4);

extern "C" void* __fastcall fn_004ea140(FnTree* self, int unusedEdx, FnKey* key)
{
    char* node = (char*)fn_004e61e0((int)key);
    if (!self)
        _invalid_parameter_noinfo();
    char* endNode = self->head;
    char* proxy = self->proxy;
    if (!proxy)
        _invalid_parameter_noinfo();

    bool insert = false;
    if (node == endNode) {
        insert = true;
    } else {
        int nodeW = *(int*)(node + 0x18);
        const FnKey* nodeKey = (const FnKey*)(node + 0x0c);
        if (key->w < nodeW)
            insert = true;
        else if (key->w > nodeW)
            insert = false;
        else
            insert = (const void*)key < (const void*)nodeKey;
    }

    if (insert) {
        FnPair pair;
        pair.key.x = key->x;
        pair.key.y = key->y;
        pair.key.z = key->z;
        pair.key.w = key->w;
        pair.extra = 0;
        FnIter tmp;
        FnIter* r = (FnIter*)fn_004e9c50(self, 0, (int)&tmp, (int)proxy, (int)node, (int)&pair);
        proxy = r->head;
        node = r->node;
    }

    if (!proxy)
        _invalid_parameter_noinfo();
    else
        proxy = *(char**)proxy;
    if (node == *(char**)(proxy + 0x18))
        _invalid_parameter_noinfo();
    return node + 0x1c;
}
