// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no native headers were shown, so every type below is a local stand-in.
// The layouts follow the offsets used in the disassembly.
// INFERRED: this is boost::signals signal1<void, shared_ptr<Instance>>::connect(slot, at).
// The hidden return connection pointer is the first stack argument, then the slot, then 'at'.

extern "C" long __cdecl _InterlockedDecrement(long volatile* addend);
#pragma intrinsic(_InterlockedDecrement)

struct placeholder {
    virtual ~placeholder() {}
};

struct any_t {
    placeholder* content;
};

// INFERRED: shared_ptr control block; the vtable slots used are +4 (dispose) and +8 (destroy).
struct sp_counted_base {
    virtual void unused0();
    virtual void dispose();
    virtual void destroy();
    long use_count;
    long weak_count;
};

struct shared_data {
    void* px;
    sp_counted_base* pn;
};

struct SlotCtl {
    char pad[8];
    int  active;
};

struct SlotHdr {
    char     pad[0x1c];
    SlotCtl* ctl;
};

struct Slot {
    SlotHdr* hdr;       // +0
    int      pad4;
    int      function;  // +8: the boost::function stored in the slot
};

struct Connection {
    int  pad0;
    int  a;     // +4
    int  b;     // +8
    char c;     // +0xc
};

// INFERRED: boost::signals::detail::stored_group { kind; shared_ptr<void> group; }
struct stored_group {
    int              kind;
    void*            px;
    sp_counted_base* pn;
};

struct SignalImpl;

struct Signal {
    SignalImpl* impl;
};

extern "C" void* __fastcall fn_00499a40(any_t* self, int unusedEdx, void* srcFunction);
extern "C" void  __fastcall fn_004915b0(Slot* self, int unusedEdx, shared_data* outData);
extern "C" Connection* __fastcall fn_0056a900(SignalImpl* self, int unusedEdx,
                                              Connection* ret,
                                              const any_t* fn,
                                              const stored_group* group,
                                              shared_data data, int at);

extern "C" Connection* __fastcall fn_00499aa0(Signal* self, int unusedEdx,
                                              Connection* ret, Slot* slot, int at)
{
    SlotCtl* ctl = slot->hdr->ctl;
    if (ctl == 0 || ctl->active == 0) {
        ret->a = 0;
        ret->b = 0;
        ret->c = 0;
        return ret;
    }

    any_t fn;
    fn_00499a40(&fn, 0, &slot->function);

    shared_data data;
    fn_004915b0(slot, 0, &data);

    stored_group group;
    group.kind = 0;
    group.px = 0;
    group.pn = 0;

    fn_0056a900(self->impl, 0, ret, &fn, &group, data, at);

    // ~stored_group: release shared_ptr<void>
    sp_counted_base* pn = group.pn;
    if (pn) {
        if (_InterlockedDecrement(&pn->use_count) == 0) {
            pn->dispose();
            if (_InterlockedDecrement(&pn->weak_count) == 0)
                pn->destroy();
        }
    }

    // ~any
    if (fn.content)
        delete fn.content;

    return ret;
}
