// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: layout from disassembly only; no native class header exists for this object.
// Sorted-insert of a listener into this->vec at +0x0, then recursive notify of children at +0x18,
// then sorted-insert into a function-local static global vector.
#include <vector>
#include <algorithm>

struct NameRef { int pad[1]; int key; };
struct Entry { int pad0; NameRef* a; int pad1; NameRef* b; };

extern "C" int __fastcall fn_0056fff0(void* self, int unusedEdx, Entry* a1);
extern "C" int fn_006a0920(int a1);

struct GuidLock { void lock(); void unlock(); };
extern "C" GuidLock* __fastcall fn_0056fe30(void* self);

extern "C" int fn_0041faa0(NameRef* a, NameRef* b); // Name::compare

// comparator passed to lower_bound at 0x56b500
extern "C" bool fn_0056b500(const Entry* a, const Entry* b);

struct ListenerHolder {
    std::vector<Entry*> sorted;      // INFERRED: +0x00 (debug-iterator layout)
    char pad[0x0c];
    std::vector<ListenerHolder*> children; // INFERRED: +0x18
};

static std::vector<Entry*> g_registry; // INFERRED: 0x974cb8 function-local static

extern "C" int __fastcall fn_0056fff0(void* self, int unusedEdx, Entry* a1)
{
    ListenerHolder* h = (ListenerHolder*)self;
    GuidLock* lk = fn_0056fe30(self);
    lk->lock();

    std::vector<Entry*>::iterator it =
        std::lower_bound(h->sorted.begin(), h->sorted.end(), a1, fn_0056b500);
    if (it == h->sorted.end() || *it != a1)
        h->sorted.insert(it, a1);

    for (std::vector<ListenerHolder*>::iterator c = h->children.begin();
         c != h->children.end(); ++c)
        fn_0056fff0(*c, 0, a1);

    std::vector<Entry*>::iterator g = g_registry.begin();
    for (; g != g_registry.end(); ++g) {
        Entry* e = *g;
        if (e == a1)
            goto done;
        int r = fn_0041faa0(e->a, a1->a);
        if (r < 0) break;
        if (r == 0 && fn_0041faa0(e->b, a1->b) < 0) break;
    }
    g_registry.insert(g, a1);
done:
    lk->unlock();
    return 0;
}
