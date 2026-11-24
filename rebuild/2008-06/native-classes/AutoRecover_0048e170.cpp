// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// Reconstruction of boost::signal1<void, shared_ptr<Instance>, ...>::connect(const slot_type&, connect_position).
// No native headers were available to include, so this file uses file-local layout structs.
// The stack layout could not be fully resolved from the disassembly, so several parts are guesses (marked INFERRED).

// INFERRED: layout of the slot's shared data block (data_t); +0x1c -> object with a flag at +8.
struct SlotActiveInfo {
    int pad0;
    int pad1;
    int connectedFlag;      // +8
};
struct SlotData {
    char pad[0x1c];
    SlotActiveInfo* active; // +0x1c
};
// INFERRED: slot = slot_base (shared_ptr<data_t>) followed by the boost::function at +8
struct SlotType {
    SlotData* data;         // +0
    void* dataCount;        // +4
    int function;           // +8: boost::function<void(shared_ptr<Instance>)>
};
// INFERRED: result connection written at +4/+8/+0xc of the first stack argument
struct ConnectionRet {
    int pad;
    void* px;
    void* pn;
    bool controlling;
};
// INFERRED: signal object whose first member is the impl pointer
struct SignalImpl;
struct SignalType {
    SignalImpl* impl;
};

struct SharedPtrPair {
    void* px;
    void* pn;
};
struct AnyHolder {          // boost::any
    void* content;
};
struct StoredGroup {        // INFERRED: 3 dwords zeroed (group_key: enum + optional<int>)
    int a;
    int b;
    int c;
};

// boost::any::any(const boost::function<void(float,float)>&) in the symbol; used here for the slot function
extern "C" AnyHolder* __fastcall fn_0048e110(AnyHolder* self, int unusedEdx, void* function);
// slot_base::get_data() const -> shared_ptr<data_t>
extern "C" SharedPtrPair* __fastcall fn_004915b0(SlotType* self, int unusedEdx, SharedPtrPair* ret);
// signal_base_impl::connect_slot(...)
extern "C" void __fastcall fn_0056a900(SignalImpl* self, int unusedEdx, ConnectionRet* ret,
                                       void* groupArg, StoredGroup* group);

extern "C" ConnectionRet* __fastcall fn_0048e170(SignalType* self, int unusedEdx,
                                                 ConnectionRet* ret, SlotType* in_slot, int at)
{
    // if (!in_slot.is_active()) return connection();
    SlotActiveInfo* a = in_slot->data->active;
    if (a == 0 || a->connectedFlag == 0) {
        ret->px = 0;
        ret->pn = 0;
        ret->controlling = false;
        return ret;
    }

    AnyHolder slotFunction;
    fn_0048e110(&slotFunction, 0, &in_slot->function);

    SharedPtrPair data;
    fn_004915b0(in_slot, 0, &data);

    StoredGroup group;
    group.a = 0;
    group.b = 0;
    group.c = 0;

    fn_0056a900(self->impl, 0, ret, &in_slot, &group);
    // temporaries (shared_ptr<data_t> release, any delete) are destroyed here by the compiler
    return ret;
}
