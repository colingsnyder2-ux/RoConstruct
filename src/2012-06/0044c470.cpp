// from server: 100% by Xemicl
// roc 2012-06 0044c470  unit: CMemberTreeView  size: 146 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0044c470
//
// 0044c470  8b442404             mov eax, dword ptr [esp + 4]
// 0044c474  56                   push esi
// 0044c475  8b705c               mov esi, dword ptr [eax + 0x5c]
// 0044c478  57                   push edi
// 0044c479  8bf9                 mov edi, ecx
// 0044c47b  83bfa800000000       cmp dword ptr [edi + 0xa8], 0
// 0044c482  7450                 je 0x44c4d4
// 0044c484  6a00                 push 0
// 0044c486  68b010d600           push 0xd610b0
// 0044c48b  684001d600           push 0xd60140
// 0044c490  6a00                 push 0
// 0044c492  56                   push esi
// 0044c493  e8b06f5300           call 0x983448
// 0044c498  83c414               add esp, 0x14
// 0044c49b  85c0                 test eax, eax
// 0044c49d  740e                 je 0x44c4ad
// 0044c49f  8b8fa8000000         mov ecx, dword ptr [edi + 0xa8]
// 0044c4a5  50                   push eax
// 0044c4a6  e865feffff           call 0x44c310
// 0044c4ab  eb27                 jmp 0x44c4d4
// 0044c4ad  6a00                 push 0
// 0044c4af  68ec83d600           push 0xd683ec
// 0044c4b4  684001d600           push 0xd60140
// 0044c4b9  6a00                 push 0
// 0044c4bb  56                   push esi
// 0044c4bc  e8876f5300           call 0x983448
// 0044c4c1  83c414               add esp, 0x14
// 0044c4c4  85c0                 test eax, eax
// 0044c4c6  740c                 je 0x44c4d4
// 0044c4c8  8b8fa8000000         mov ecx, dword ptr [edi + 0xa8]
// 0044c4ce  50                   push eax
// 0044c4cf  e89cecffff           call 0x44b170
// 0044c4d4  8b8fac000000         mov ecx, dword ptr [edi + 0xac]
// 0044c4da  85c9                 test ecx, ecx
// 0044c4dc  7415                 je 0x44c4f3
// 0044c4de  56                   push esi
// 0044c4df  e83ceeffff           call 0x44b320
// 0044c4e4  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0044c4e8  5f                   pop edi
// 0044c4e9  c70100000000         mov dword ptr [ecx], 0
// 0044c4ef  5e                   pop esi
// 0044c4f0  c20800               ret 8
// 0044c4f3  8b542410             mov edx, dword ptr [esp + 0x10]
// 0044c4f7  5f                   pop edi
// 0044c4f8  c70200000000         mov dword ptr [edx], 0
// 0044c4fe  5e                   pop esi
// 0044c4ff  c20800               ret 8
// copied from an identical function in another client (function ?fn_ROCX00000c_00435fa0@CClassTreeView@ns_ROCX00000c@@QAEXPAUArgument@2@PAH@Z)

namespace ns_ROCX00000c {
extern unsigned char descriptor_00928fe8;
extern unsigned char descriptor_0092f39c;
extern unsigned char descriptor_0092f3cc;

extern "C" void* __cdecl fn_ROCX00000c_006a17c6(
    void*, int, const void*, const void*, int);

struct Handler
{
    void fn_ROCX00000c_00435c80(void*);
    void fn_ROCX00000c_00435180(void*);
    void fn_ROCX00000c_00435860(void*);
};

struct Argument
{
    unsigned char padding[0x5c];
    void* descriptor;
};

struct CClassTreeView
{
    unsigned char padding[0xa8];
    Handler* primary;
    Handler* secondary;

    void fn_ROCX00000c_00435fa0(Argument*, int*);
};

void CClassTreeView::fn_ROCX00000c_00435fa0(Argument* argument, int* result)
{
    void* descriptor = argument->descriptor;

    if (primary)
    {
        void* converted = fn_ROCX00000c_006a17c6(
            descriptor, 0, &descriptor_00928fe8, &descriptor_0092f39c, 0);

        if (converted)
        {
            primary->fn_ROCX00000c_00435c80(converted);
        }
        else
        {
            converted = fn_ROCX00000c_006a17c6(
                descriptor, 0, &descriptor_00928fe8, &descriptor_0092f3cc, 0);

            if (converted)
                primary->fn_ROCX00000c_00435180(converted);
        }
    }

    if (secondary)
        secondary->fn_ROCX00000c_00435860(descriptor);

    *result = 0;
}
}