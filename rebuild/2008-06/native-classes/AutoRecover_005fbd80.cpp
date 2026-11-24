// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no class header available. Layout is taken from the disassembly:
// +0x108 slot_base, +0x1a0 shared_ptr-like member (ptr, refcount block).
// INFERRED: the checked-iterator calls (_invalid_parameter_noinfo) come from
// vector iteration over the slot's connected-slot list; a plain loop stands in.
#include <boost/shared_ptr.hpp>
#include <vector>

struct Target {
    // INFERRED: vtable slots 0..32 unused here; placeholders so slots 0x84/0x88 land correctly.
    virtual void s00(); virtual void s01(); virtual void s02(); virtual void s03();
    virtual void s04(); virtual void s05(); virtual void s06(); virtual void s07();
    virtual void s08(); virtual void s09(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15();
    virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
    virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23();
    virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27();
    virtual void s28(); virtual void s29(); virtual void s30(); virtual void s31();
    virtual void s32();
    virtual void slot84();
    virtual void slot88();
};

struct Listener {
    char pad[0x148];
    Target* owner;                      // +0x148
};

struct SlotItem {                       // INFERRED: 8-byte stride in the original
    Listener* listener;
    void* extra;
};

struct SlotData {
    std::vector<SlotItem> items;
};

struct Obj {
    char pad0[0x108];
    char slotBase[0x98];                // +0x108 slot_base
    boost::shared_ptr<Target> member;   // +0x1a0
};

extern "C" void __fastcall fn_004915b0(void* slotBase, int unusedEdx,
                                       boost::shared_ptr<SlotData>* out);

extern "C" void __fastcall fn_005fbd80(Obj* self, int unusedEdx)
{
    if (!self->member)
        return;

    boost::shared_ptr<SlotData> data;
    fn_004915b0(self->slotBase, 0, &data);

    if (data) {
        for (size_t i = 0; i < data->items.size(); ++i) {
            Listener* l = data->items[i].listener;
            if (l->owner != self->member.get())
                l->owner->slot88(); // INFERRED: virtual slot 0x88 on owner
        }
    }
    self->member->slot84();         // INFERRED: virtual slot 0x84
    self->member.reset();
}
