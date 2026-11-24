// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no class header was available, so the object layout and types below are guesses.
// INFERRED: the unwind funclets (EH states 0..2) are not reproduced; the body is written straight-line.

struct fn_004ea860_Self {
    void* px;          // +0  shared_ptr<data_t>::px
    void* pn;          // +4  shared_ptr<data_t>::pn
    char  member8[1];  // +8  sub-object constructed by fn_004ea260
};

struct fn_004ea860_Arg {
    int a;   // +0
    int b;   // +4
};

extern "C" int  __fastcall fn_004ea260(void* self, int unusedEdx, int a1, int a2, int a3);
extern "C" int  fn_006a0920(int a1);
extern "C" int  __fastcall fn_0041ad40(void* self, int unusedEdx);               // data_t::data_t()
extern "C" int  __fastcall fn_0041b0f0(void* self, int unusedEdx, void* p);      // shared_ptr::reset(data_t*)
extern "C" int  __fastcall fn_00595840(void* self, int unusedEdx);

extern "C" fn_004ea860_Self* __fastcall fn_004ea860(fn_004ea860_Self* self, int unusedEdx, fn_004ea860_Arg* arg)
{
    self->px = 0;
    self->pn = 0;
    fn_004ea260(&self->member8, 0, arg->a, arg->b, 0);

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
