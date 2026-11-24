// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: this is the copy constructor of a boost::signals
// list<connection_slot_pair>, written as a __thiscall with one stack argument.

struct SlotList {
    void** head;       // 0x00: allocator/proxy block, points back to the list
    int    pad[4];     // 0x04..0x13
    int*   node;       // 0x14: sentinel node from _Buynode
    int    size;       // 0x18
};

// INFERRED: func_006a0920 is called with a single argument (push 4), so it is
// declared with one parameter instead of the eight in the prompt.
extern "C" void* fn_006a0920(int size);
extern "C" int* __fastcall fn_00570d40(void* self, int unusedEdx); // _Buynode
extern "C" int __fastcall fn_00571230(void* self, int unusedEdx, int a1, int a2, int a3, int a4, int a5, int a6, int a7);
extern "C" int __fastcall fn_0056ab70(void* self, int unusedEdx);

extern "C" SlotList* __fastcall fn_005715a0(SlotList* self, int unusedEdx, SlotList* other)
{
    void** p = (void**)fn_006a0920(4);
    if (p)
        *p = self;
    self->head = p;
    try {
        int* n = fn_00570d40(self, 0);
        void** h = self->head;
        self->node = n;
        self->size = 0;
        int edx = *n;
        int* on = other->node;
        int ebx = *on;
        void** oh = other->head;
        fn_00571230(self, 0, (int)h, edx, (int)oh, ebx, (int)oh, (int)on, (int)other);
    } catch (...) {
        fn_0056ab70(self, 0);
        throw;
    }
    return self;
}
