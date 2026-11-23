// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: layout from the disassembly. Offset 0 holds a pointer to a 4-byte
// heap cell that stores the owner's `this`. A std::list-like container sits at
// +0x10 (empty allocator slot, then head at +0x14, size at +0x18). The bytes in
// +4..+0x10 are not touched by this function.
struct Fn571540Obj {
    void** owner_cell;   // +0x00
    int    unused[3];    // +0x04..+0x0F
    int    list_alloc;   // +0x10 (empty allocator slot)
    void*  list_head;    // +0x14
    unsigned list_size;  // +0x18
};

// INFERRED: operator new-like allocator; the disassembly pushes one argument (4)
// and pops 4 bytes, so it is declared with one parameter here.
extern "C" void* fn_006a0920(int size);

// list<connection_slot_pair,...>::_Buynode (thiscall, no stack args)
extern "C" void* __fastcall fn_00570d40(void* self, int unusedEdx);

extern "C" Fn571540Obj* __fastcall fn_00571540(Fn571540Obj* self, int unusedEdx)
{
    void** cell = (void**)fn_006a0920(4);
    if (cell)
        *cell = self;
    self->owner_cell = cell;

    self->list_head = fn_00570d40(self, 0);
    self->list_size = 0;
    return self;
}
