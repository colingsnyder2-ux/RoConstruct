// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: best-effort draft. Layouts guessed from the disassembly; not compiled or diffed.
// The code looks like a boost::signals named_slot_map clear loop: walk each group, erase its slot list, then erase the group.

struct SlotNode {
    SlotNode* next;      // +0x00
    int pad04[2];
    void* pad0c;         // +0x0c, checked for null
};

struct GroupNode {
    int pad00[6];
    SlotNode* slots;     // +0x18 list head
    int pad1c[4];
    SlotNode* slotsEnd;  // +0x2c
};

struct SlotMap {
    void* vtbl0;
    int pad04[0x0f];
    GroupNode** groups;  // +0x40
};

extern "C" void fn_005711a0(void* list, int unusedEdx, void* outIter, void* a, void* b);
extern "C" bool fn_00571120(SlotMap* self, int unusedEdx, void* a, void* b);
extern "C" void fn_00409f60(void* iter);
extern "C" void fn_0056ad40(SlotMap* self, int unusedEdx, void* out, void* a, void* b);

extern "C" void __fastcall fn_00572230(SlotMap* self, int unusedEdx)
{
    GroupNode* cur = *self->groups;
    SlotMap* first = (SlotMap*)self->vtbl0;
    while (cur != (GroupNode*)*self->groups) {
        SlotNode* it = cur->slots;
        while (it != cur->slotsEnd) {
            if (!it->pad0c || !((int*)it->pad0c)[2])
                break;
            it = it->next;
        }
        if (it == cur->slotsEnd) {
            if (fn_00571120(self, 0, first, cur)) {
                fn_00409f60(&first);
                fn_0056ad40(self, 0, &cur, first, cur);
            } else {
                fn_00409f60(&first);
            }
        } else {
            fn_005711a0(&cur->slots, 0, &it, it, it);
        }
    }
}
