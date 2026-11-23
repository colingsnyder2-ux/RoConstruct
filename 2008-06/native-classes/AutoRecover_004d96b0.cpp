// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: this is a boost::signals slot-style constructor. Layout is a
// shared_ptr<slot_base::data_t> at +0/+4, followed by a function-like member at +8.
struct SlotLike {
    void* px;   // +0
    void* pn;   // +4
    int   fn[4]; // +8 ... (INFERRED: boost::function-like member, size unknown)
};

extern "C" int __fastcall fn_004d8760(void* self, int unusedEdx, int a1, int a2, int a3);
extern "C" int fn_006a0920(int a1);
extern "C" int __fastcall fn_00595840(void* self, int unusedEdx);
// data_t::data_t()
extern "C" void __fastcall fn_0041ad40(void* self, int unusedEdx);
// shared_ptr<data_t>::reset(data_t*)
extern "C" void __fastcall fn_0041b0f0(void* self, int unusedEdx, void* p);

extern "C" SlotLike* __fastcall fn_004d96b0(SlotLike* self, int unusedEdx, const int* arg)
{
    self->px = 0;
    self->pn = 0;
    fn_004d8760(&self->fn[0], 0, arg[0], arg[1], 0);

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
