// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// Looks like boost::signals::slot<F>::slot(const F&):
//   slot_function(f) { data.reset(new data_t); create_connection(); }
// INFERRED: layout is shared_ptr<data_t> at +0/+4, slot function storage at +8.

struct SlotArg {
    int a;
    int b;
};

struct SlotObj {
    void* px;      // shared_ptr<data_t>::px
    void* pn;      // shared_ptr<data_t>::pn
    char  func[1]; // INFERRED: slot function storage at +8, real size unknown
};

extern "C" int  __fastcall fn_004dba40(void* self, int unusedEdx, int a1, int a2, int a3);
extern "C" int  fn_006a0920(int a1);
extern "C" int  __fastcall fn_00595840(void* self, int unusedEdx);
// boost::signals::detail::slot_base::data_t::data_t()
extern "C" void* __fastcall fn_0041ad40(void* self);
// shared_ptr<data_t>::reset<data_t>(data_t*)
extern "C" void  __fastcall fn_0041b0f0(void* self, int unusedEdx, void* p);

extern "C" SlotObj* __fastcall fn_004dbb40(SlotObj* self, int unusedEdx, const SlotArg* arg)
{
    self->px = 0;
    self->pn = 0;

    fn_004dba40(self->func, 0, arg->a, arg->b, 0);

    void* mem = (void*)fn_006a0920(0x28);
    void* data = 0;
    if (mem)
        data = fn_0041ad40(mem);

    fn_0041b0f0(self, 0, data);
    fn_00595840(self, 0);
    return self;
}
