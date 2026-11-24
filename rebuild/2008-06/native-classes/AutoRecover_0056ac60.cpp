// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <new>

struct SlotList; // INFERRED: boost::signals connection_slot_pair std::list, sentinel head at +0, extra node pointer at +0x14

extern "C" void __fastcall fn_0056a870(SlotList* self, int unusedEdx); // list::clear

struct SlotList {
    void* head;      // +0x00 sentinel node
    int pad[4];
    void* extra;     // +0x14
    ~SlotList();
};

// INFERRED: std::list destructor; the SEH frame (state 0) in the original is not reproduced here
SlotList::~SlotList()
{
    fn_0056a870(this, 0);
    ::operator delete(extra);
    extra = 0;
    ::operator delete(head);
}

extern "C" void __fastcall fn_0056ac60(SlotList* self, int unusedEdx)
{
    self->~SlotList();
}
