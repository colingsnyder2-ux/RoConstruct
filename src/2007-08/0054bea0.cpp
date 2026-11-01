// from server: 100% by colin
// roc 2007-08 0054bea0  unit: boost::iostreams::DUoutput::V?$basic_null_device::?$stream_buffer  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0054bea0
//
// 0054bea0  f6415401             test byte ptr [ecx + 0x54], 1
// 0054bea4  7421                 je 0x54bec7
// 0054bea6  8b4944               mov ecx, dword ptr [ecx + 0x44]
// 0054bea9  85c9                 test ecx, ecx
// 0054beab  741a                 je 0x54bec7
// 0054bead  8b442404             mov eax, dword ptr [esp + 4]
// 0054beb1  50                   push eax
// 0054beb2  8d542408             lea edx, [esp + 8]
// 0054beb6  52                   push edx
// 0054beb7  ff15f8e47700         call dword ptr [0x77e4f8]
// 0054bebd  8d4c2404             lea ecx, [esp + 4]
// 0054bec1  ff15fce47700         call dword ptr [0x77e4fc]
// 0054bec7  c20400               ret 4
// copied from an identical function in another client (function ?f@S@@QAEXPBX@Z)

// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
typedef void (__thiscall *ImbueFunction)(void *, void *, const void *);
typedef void (__thiscall *DestroyFunction)(void *);

extern ImbueFunction imbue;
extern DestroyFunction destroy;

struct S {
    unsigned char padding0[0x44];
    void *stream;
    unsigned char padding1[0x0C];
    unsigned char flags;

    void f(const void *locale);
};

void S::f(const void *locale)
{
    if ((flags & 1) && stream) {
        imbue(stream, &locale, locale);
        destroy(&locale);
    }
}