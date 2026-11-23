// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: layout of a boost::signals slot: shared_ptr<data_t> at +0 (px, pn),
// followed by the stored function object at +8.
struct SlotFunctionArg {
    int first;   // [arg + 0]
    int second;  // [arg + 4]
};

struct SlotObject {
    void* px;   // +0
    void* pn;   // +4
    // +8: function object, constructed by fn_004e9e80
};

extern "C" int __fastcall fn_004e9e80(void* self, int unusedEdx, int a1, int a2, int a3);
extern "C" int fn_006a0920(int a1);
// data_t::data_t()  (boost::signals::detail::slot_base::data_t)
extern "C" int __fastcall fn_0041ad40(void* self, int unusedEdx);
// shared_ptr<data_t>::reset(data_t*)
extern "C" int __fastcall fn_0041b0f0(void* self, int unusedEdx, void* p);
extern "C" int __fastcall fn_00595840(void* self, int unusedEdx);

extern "C" SlotObject* __fastcall fn_004ea720(SlotObject* self, int unusedEdx, SlotFunctionArg* arg)
{
    self->px = 0;
    self->pn = 0;

    fn_004e9e80((char*)self + 8, 0, arg->first, arg->second, 0);

    void* mem = (void*)fn_006a0920(0x28);
    void* data = 0;
    if (mem) {
        fn_0041ad40(mem, 0);
        data = mem;
    }
    fn_0041b0f0(self, 0, data);
    fn_00595840(self, 0);
    return self;
}
