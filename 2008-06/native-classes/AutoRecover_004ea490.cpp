// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: the object is a boost::signals slot-like wrapper: [0]/[4] hold a
// shared_ptr<data_t>, and the 16-byte functor lives at +8.

struct Func16 {
    int a, b, c, d;
};

struct SlotObj {
    void* px;          // shared_ptr<data_t>::px
    void* pn;          // shared_ptr<data_t>::pn
    int   functor[4];  // function object at +8
};

extern "C" int  __fastcall fn_004e9fa0(void* self, int unusedEdx, int a1, int a2, int a3, int a4, int a5);
extern "C" int  fn_006a0920(int a1);
extern "C" int  __fastcall fn_00595840(void* self, int unusedEdx);
// data_t::data_t()
extern "C" void* __fastcall fn_0041ad40(void* self, int unusedEdx);
// shared_ptr<data_t>::reset(data_t*)
extern "C" void  __fastcall fn_0041b0f0(void* self, int unusedEdx, void* p);

extern "C" SlotObj* __fastcall fn_004ea490(SlotObj* self, int unusedEdx, const Func16* arg)
{
    self->px = 0;
    self->pn = 0;

    Func16 f = *arg;
    fn_004e9fa0(&self->functor[0], 0, f.a, f.b, f.c, f.d, 0);

    void* mem = (void*)fn_006a0920(0x28);
    void* data = 0;
    if (mem)
        data = fn_0041ad40(mem, 0);
    fn_0041b0f0(self, 0, data);

    fn_00595840(self, 0);
    return self;
}
