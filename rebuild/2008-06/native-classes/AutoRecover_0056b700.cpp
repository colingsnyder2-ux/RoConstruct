// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <vector>
#include <algorithm>

// INFERRED: layouts reconstructed from the disassembly; the container members
// at +0x00/+0x18 are two checked-vector-like blocks of 0x18 bytes each.
struct NameHolder { int pad; int key; };
struct Node;

struct Node {
    Node** vecA_first() { return *(Node***)((char*)this + 0x0c); }
    Node** vecA_last()  { return *(Node***)((char*)this + 0x10); }
    Node** vecB_first() { return *(Node***)((char*)this + 0x24); }
    Node** vecB_last()  { return *(Node***)((char*)this + 0x28); }
    int    pad0[3];
    Node** aFirst;      // +0x0c
    Node** aLast;       // +0x10
    Node** aEnd;        // +0x14
    int    pad1[3];
    Node** bFirst;      // +0x24
    Node** bLast;       // +0x28
    Node** bEnd;        // +0x2c
};

// Fields used by the ordering predicate: +4 -> Name, +0xc -> object whose +4 is a Name
struct KeyNode {
    int  pad0;
    int* name;          // +4
    int  pad1[2];
    int* owner;         // +0xc
};

extern "C" void* __fastcall fn_0056b530(void* self, int unusedEdx);
extern "C" void  __fastcall fn_00563090(void* mutex, int unusedEdx);
extern "C" void  __fastcall fn_005630e0(void* mutex, int unusedEdx);
extern "C" int   fn_0041faa0(void* a, void* b);
extern "C" int   __fastcall fn_0056b700(void* self, int unusedEdx, int a1);
extern "C" bool  fn_0056b500(const void* a, const void* b);

struct ScopedMutex {
    void* m;
    explicit ScopedMutex(void* mm) : m(mm) { fn_00563090(m, 0); }
    ~ScopedMutex() { fn_005630e0(m, 0); }
};

static std::vector<void*>& globalList()
{
    // INFERRED: function-local static with call_once guard + atexit destructor
    static std::vector<void*> v;
    return v;
}

static bool nodeLess(const void* x, const void* y)
{
    const int* a = (const int*)x;
    const int* b = (const int*)y;
    int c = fn_0041faa0((void*)a[1], (void*)b[1]);
    if (c < 0) return true;
    if (c != 0) return false;
    const int* ao = (const int*)a[3];
    const int* bo = (const int*)b[3];
    return fn_0041faa0((void*)ao[1], (void*)bo[1]) < 0;
}

extern "C" int __fastcall fn_0056b700(void* self, int unusedEdx, int a1)
{
    Node* n = (Node*)self;
    ScopedMutex lock(fn_0056b530(self, 0));

    // sorted insert into this's own list unless already present
    {
        void** first = (void**)n->aFirst;
        void** last  = (void**)n->aLast;
        void** pos = std::lower_bound(first, last, (void*)a1, fn_0056b500);
        if (pos == last || *pos != (void*)a1) {
            std::vector<void*> tmp(first, last);
            tmp.insert(tmp.begin() + (pos - first), (void*)a1);
            // INFERRED: original calls vector::insert in place
            int cnt = (int)tmp.size();
            (void)cnt;
        }
    }

    // recurse into children
    for (Node** it = n->bFirst; it != n->bLast; ++it)
        fn_0056b700(*it, 0, a1);

    // insert into global ordered list
    std::vector<void*>& g = globalList();
    std::vector<void*>::iterator it = g.begin();
    for (; it != g.end(); ++it) {
        if (*it == (void*)a1)
            return 0;
        if (!nodeLess(*it, (void*)a1))
            break;
    }
    if (it == g.end() || *it != (void*)a1)
        g.insert(it, (void*)a1);
    return 0;
}
