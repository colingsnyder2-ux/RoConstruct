// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: object layout is a boost::shared_ptr<slot_base::data_t> at +0/+4
// followed by a sub-object constructed at +8; the class name is unknown.
struct fn_004ea7c0_Obj {
    void* px;
    void* pn;
};

extern "C" int __fastcall fn_004e9ee0(void* self, int unusedEdx, int a1, int a2, int a3);
extern "C" int fn_006a0920(int a1);
extern "C" int __fastcall fn_00595840(void* self, int unusedEdx);
// slot_base::data_t::data_t()
extern "C" void* __fastcall fn_0041ad40(void* self, int unusedEdx);
// shared_ptr<data_t>::reset(data_t*)
extern "C" void __fastcall fn_0041b0f0(void* self, int unusedEdx, void* p);

extern "C" fn_004ea7c0_Obj* __fastcall fn_004ea7c0(fn_004ea7c0_Obj* self, int unusedEdx, int* arg1)
{
    self->px = 0;
    self->pn = 0;
    fn_004e9ee0((char*)self + 8, 0, arg1[0], arg1[1], 0);

    void* mem = (void*)fn_006a0920(0x28);
    void* data = 0;
    if (mem)
        data = fn_0041ad40(mem, 0);
    fn_0041b0f0(self, 0, data);
    fn_00595840(self, 0);
    return self;
}
