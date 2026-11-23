// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

#include <new>

// INFERRED: this is boost::detail::shared_count constructed from a raw Item*.
// It heap-allocates a 0x10-byte sp_counted_impl_p (vtable, use_count=1,
// weak_count=1, px). If allocation throws, the catch handler calls
// EnumDesc<CRenderSettings::GraphicsMode>::deleteItem(p) and rethrows.

namespace RBX { namespace Reflection { class Item; } }
typedef RBX::Reflection::Item Item;

extern "C" void* fn_006a0920(int size);     // operator new (cdecl, one real arg)
extern "C" void fn_00427b70(Item* p);       // EnumDesc<...>::deleteItem (cdecl)

// INFERRED: control block layout
struct sp_counted_base
{
    virtual void dispose() = 0;
    virtual void destroy() { }
    int use_count_;
    int weak_count_;
};

struct sp_counted_impl_p : public sp_counted_base
{
    Item* px_;
    explicit sp_counted_impl_p(Item* p) : px_(p) { use_count_ = 1; weak_count_ = 1; }
    virtual void dispose() { fn_00427b70(px_); }
};

struct shared_count_item
{
    sp_counted_base* pi_;
    shared_count_item(Item* p);
};

extern "C" shared_count_item* __fastcall fn_00569260(shared_count_item* self, int unusedEdx, Item* p)
{
    self->pi_ = 0;
    try
    {
        void* mem = fn_006a0920(0x10);
        self->pi_ = mem ? new (mem) sp_counted_impl_p(p) : 0;
    }
    catch (...)
    {
        fn_00427b70(p);
        throw;
    }
    return self;
}
