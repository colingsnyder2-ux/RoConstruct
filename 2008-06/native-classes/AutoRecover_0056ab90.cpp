// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: boost::signals::detail::signal_base_impl::empty() (named_slot_map at this+8):
// true when no slot is still connected. The iterator is a checked-iterator
// wrapper (0x1c bytes), laid out from the disassembly.
struct SlotConnection { char pad[8]; int connected; };
struct SlotNode { char pad[0xc]; SlotConnection* con; };

struct NamedSlotMapIterator {
    void* container;   // +0x00
    void* node;        // +0x04
    void* pad[2];
    void* slotsCont;   // +0x10
    void* slotsNode;   // +0x14
    void* pad2[2];
};

extern "C" NamedSlotMapIterator* __fastcall fn_00571380(void* map, int unusedEdx, NamedSlotMapIterator* out);
extern "C" NamedSlotMapIterator* __fastcall fn_005713b0(void* map, int unusedEdx, NamedSlotMapIterator* out);
extern "C" void __fastcall fn_0040aaa0(NamedSlotMapIterator* it, int unusedEdx);

extern "C" bool __fastcall fn_0056ab90(char* self, int unusedEdx)
{
    void* map = self + 8;
    NamedSlotMapIterator it;
    NamedSlotMapIterator endIt;
    fn_00571380(map, 0, &it);
    for (;;) {
        NamedSlotMapIterator* e = fn_005713b0(map, 0, &endIt);
        if (it.node == e->node)
            return true;
        SlotNode* n = (SlotNode*)it.slotsNode;
        if (n->con && n->con->connected != 0)
            return false;
        fn_0040aaa0(&it, 0);
    }
}
