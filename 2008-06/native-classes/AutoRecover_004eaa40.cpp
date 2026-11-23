// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: layout is a boost::signals slot: shared_ptr<slot_base::data_t> at +0/+4,
// followed by the stored function object at +8 (built by fn_004ea380).
struct SlotArg {
    int first;
    int second;
};

struct SlotData; // boost::signals::detail::slot_base::data_t

struct SlotObject {
    SlotData* px;   // shared_ptr::px
    void*     pn;   // shared_ptr::pn
    // function object starts at +8
    char      func[1];
};

extern "C" int  __fastcall fn_004ea380(void* self, int unusedEdx, int a1, int a2, int a3);
extern "C" int  fn_006a0920(int a1);
extern "C" int  __fastcall fn_00595840(void* self, int unusedEdx);
// data_t::data_t()
extern "C" void __fastcall fn_0041ad40(void* self, int unusedEdx);
// shared_ptr<data_t>::reset(data_t*)
extern "C" void __fastcall fn_0041b0f0(void* self, int unusedEdx, void* p);

extern "C" SlotObject* __fastcall fn_004eaa40(SlotObject* self, int unusedEdx, SlotArg* arg)
{
    self->px = 0;
    self->pn = 0;
    fn_004ea380(self->func, 0, arg->first, arg->second, 0);

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
