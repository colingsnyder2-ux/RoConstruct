// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

extern "C" void __stdcall fn_00401000(long hr); // ATL::AtlThrowImpl

// INFERRED: immediates 0x81f038 / 0x850114 are addresses of GUID/IID globals
extern "C" const unsigned char data_0081f038[];
extern "C" const unsigned char data_00850114[];

typedef long (__stdcall *Slot4)(void* self, const void* a, void* b, int c);
typedef long (__stdcall *Slot2)(void* self, const void* a);
typedef long (__stdcall *SlotRc)(void* self, int a, void* b);

struct Vtbl { void** slots; };

// INFERRED: class unknown; fields at +0x174 (COM ptr) and +0x17c (COM ptr out)
extern "C" void __fastcall fn_004675e0(char* self, int unusedEdx)
{
    void* src = *(void**)(self + 0x174);
    void** out = (void**)(self + 0x17c);

    long hr = ((Slot4)(*(void***)src)[3])(src, data_0081f038, out, 0);
    if (hr < 0)
        fn_00401000(hr);

    void* p = *out;
    hr = ((Slot2)(*(void***)p)[0x2c / 4])(p, data_00850114);
    if (hr < 0)
        fn_00401000(hr);

    void* q = *out;
    // INFERRED: 5-dword descriptor struct (size 0x14)
    int desc[5];
    desc[0] = 0x14;
    desc[1] = 0x10;
    desc[2] = 0;
    desc[3] = 0;
    desc[4] = 0x800;
    hr = ((SlotRc)(*(void***)q)[0x18 / 4])(q, 1, desc);
    if (hr < 0)
        fn_00401000(hr);
}
