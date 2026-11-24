// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: boost::signals slot-like object: shared_ptr<data_t> at +0, sub-object at +8.
struct SlotObj {
    void* px;
    void* pn;
};

extern "C" int __fastcall fn_004db9e0(void* self, int unusedEdx, int a1, int a2, int a3);
extern "C" int fn_006a0920(int a1);
extern "C" int __fastcall fn_00595840(void* self, int unusedEdx);
extern "C" void __fastcall fn_0041ad40(void* self, int unusedEdx);
extern "C" void __fastcall fn_0041b0f0(void* self, int unusedEdx, void* p);

extern "C" SlotObj* __fastcall fn_004dbaa0(SlotObj* self, int unusedEdx, int* arg)
{
    self->px = 0;
    self->pn = 0;
    fn_004db9e0((char*)self + 8, 0, arg[0], arg[1], 0);
    void* d = (void*)fn_006a0920(0x28);
    if (d)
        fn_0041ad40(d, 0);
    fn_0041b0f0(self, 0, d);
    fn_00595840(self, 0);
    return self;
}
