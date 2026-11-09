// from server: 100% by colin
// roc 2007-08 0054e410  unit: std::D::V?$allocator::V?$basic_gzip_decompressor::?$stream_buffer  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0054e410
//
// 0054e410  f681b000000001       test byte ptr [ecx + 0xb0], 1
// 0054e417  7424                 je 0x54e43d
// 0054e419  8b89a0000000         mov ecx, dword ptr [ecx + 0xa0]
// 0054e41f  85c9                 test ecx, ecx
// 0054e421  741a                 je 0x54e43d
// 0054e423  8b442404             mov eax, dword ptr [esp + 4]
// 0054e427  50                   push eax
// 0054e428  8d542408             lea edx, [esp + 8]
// 0054e42c  52                   push edx
// 0054e42d  ff15f8e47700         call dword ptr [0x77e4f8]
// 0054e433  8d4c2404             lea ecx, [esp + 4]
// 0054e437  ff15fce47700         call dword ptr [0x77e4fc]
// 0054e43d  c20400               ret 4
// copied from an identical function in another client (function ?f@S@@QAEXPBX@Z)

// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct Stream;

extern void (__thiscall *imbue)(Stream*, void*, const void*);
extern void (__thiscall *destroyLocale)(void*);

struct S {
    char padding[160];
    Stream* stream;
    char reserved[12];
    unsigned char flags;

    void f(const void* locale);
};

void S::f(const void* locale)
{
    if ((flags & 1) && stream) {
        imbue(stream, &locale, locale);
        destroyLocale(&locale);
    }
}