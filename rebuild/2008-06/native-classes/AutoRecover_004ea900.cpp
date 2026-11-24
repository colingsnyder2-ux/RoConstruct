// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

extern "C" int __fastcall fn_004ea2c0(void* self, int unusedEdx, int a1, int a2, int a3);
extern "C" int fn_006a0920(int a1);
extern "C" int __fastcall fn_00595840(void* self, int unusedEdx);
// INFERRED: data_t ctor (0x41ad40) and shared_ptr<data_t>::reset (0x41b0f0) named by their mangled symbols
extern "C" void* __fastcall fn_0041ad40(void* self, int unusedEdx);
extern "C" void __fastcall fn_0041b0f0(void* self, int unusedEdx, void* p);

struct Pair2 { int a; int b; };

// INFERRED: layout: shared_ptr<data_t> at +0 (px, pn), function object at +8
struct SlotObj { void* px; int pn; };

extern "C" SlotObj* __fastcall fn_004ea900(SlotObj* self, int unusedEdx, Pair2* arg)
{
    self->px = 0;
    self->pn = 0;
    fn_004ea2c0((char*)self + 8, 0, arg->a, arg->b, 0);
    void* mem = (void*)fn_006a0920(0x28);
    void* d = mem ? fn_0041ad40(mem, 0) : 0;
    fn_0041b0f0(self, 0, d);
    fn_00595840(self, 0);
    return self;
}
