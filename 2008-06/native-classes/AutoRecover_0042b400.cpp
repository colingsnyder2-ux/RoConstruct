// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: this is a boost::signals connect() wrapper that forwards to
// signal_base_impl::connect_slot(slot_any, name_any, shared_ptr<data_t>, at).
// Boost types are modelled as opaque structs because no headers were available.

struct SigConnection {          // returned through the hidden pointer (arg1)
    int pad0;
    int body;
    int count;
    char controlling;
};

struct SlotData {
    char pad[8];
    int  func;                  // +8: function being wrapped
};

struct SlotBase {               // boost::signals::detail::slot_base
    struct Data { char pad[0x1c]; } *dummy;
};

struct SlotObj {
    char* data;                 // shared_ptr<data_t>::px, checked at +0x1c
};

struct SpCountBase {
    virtual void dispose() = 0;
    virtual void destroy() = 0;
};

struct SharedPtrInt {
    int*         px;
    SpCountBase* pn;
};

struct AnyHolder {
    struct Placeholder { virtual ~Placeholder() {} } *content;
};

struct SignalImpl;

struct SignalOwner {
    SignalImpl* impl;
};

extern "C" void* __cdecl fn_006a0920(unsigned size);
extern "C" void  __fastcall fn_0042a800(void* sharedCount, int unusedEdx, int* p);
extern "C" void  __cdecl fn_0047d410(void* sp, void* a, void* b);
extern "C" void  __fastcall fn_0042b220(void* anyOut, int unusedEdx, void* func);
extern "C" void  __fastcall fn_004915b0(void* slot, int unusedEdx, void* retSharedPtr);
extern "C" void  __fastcall fn_0056a900(SignalImpl* self, int unusedEdx,
                                        SigConnection* result, void* slotAny,
                                        void* nameAny, void* dataPtr0, void* dataPtr1,
                                        int at);

extern "C" SigConnection* __fastcall fn_0042b400(SignalOwner* self, int unusedEdx,
                                                 SigConnection* result, int* group,
                                                 SlotObj* slot, int at)
{
    char* d = slot->data;
    if (d == 0 || *(int*)(d + 8) == 0) {
        result->body = 0;
        result->count = 0;
        result->controlling = 0;
        return result;
    }

    int* raw = (int*)fn_006a0920(4);
    if (raw) {
        *raw = *group;
    }

    SharedPtrInt nameSp;
    nameSp.px = raw;
    fn_0042a800(&nameSp.pn, 0, raw);
    fn_0047d410(&nameSp, raw, raw);

    AnyHolder slotAny;
    fn_0042b220(&slotAny, 0, (char*)slot + 8);

    struct { void* px; void* pn; } data;
    fn_004915b0(slot, 0, &data);

    fn_0056a900(self->impl, 0, result, &slotAny, &nameSp, data.px, data.pn, at);

    if (slotAny.content) {
        delete slotAny.content;
    }

    if (nameSp.pn) {
        nameSp.pn->dispose();
        nameSp.pn->destroy();
    }
    return result;
}
