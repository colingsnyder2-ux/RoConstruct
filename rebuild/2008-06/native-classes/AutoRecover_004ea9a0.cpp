// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

struct SlotBase {
    void* px;       // shared_ptr<data_t>::px
    void* pn;       // shared_ptr<data_t>::pn
    char  member[1];  // INFERRED: sub-object at +8 built by fn_004ea320, real type/size unknown
};

extern "C" int __fastcall fn_004ea320(void* self, int unusedEdx, int a1, int a2, int a3);
extern "C" int fn_006a0920(int a1);
extern "C" int __fastcall fn_00595840(void* self, int unusedEdx);
// boost::signals::detail::slot_base::data_t::data_t()
extern "C" void* __fastcall fn_0041ad40(void* self, int unusedEdx);
// boost::shared_ptr<data_t>::reset(data_t*)
extern "C" void __fastcall fn_0041b0f0(void* self, int unusedEdx, void* p);

// INFERRED: __thiscall ctor taking a pointer to a 2-dword argument; returns this
extern "C" SlotBase* __fastcall fn_004ea9a0(SlotBase* self, int unusedEdx, const int* arg)
{
    self->px = 0;
    self->pn = 0;
    // INFERRED: EH unwind of the +8 member omitted (type unknown)
    fn_004ea320(self->member, 0, arg[0], arg[1], 0);

    void* mem = (void*)fn_006a0920(0x28);
    void* data = mem ? fn_0041ad40(mem, 0) : 0;
    fn_0041b0f0(self, 0, data);
    fn_00595840(self, 0);
    return self;
}
