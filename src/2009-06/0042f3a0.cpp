// from server: 100% by EspClaude
// roc 2009-06 0042f3a0  unit: CMemberTreeView  size: 146 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0042f3a0
//
// 0042f3a0  8b442404             mov eax, dword ptr [esp + 4]
// 0042f3a4  56                   push esi
// 0042f3a5  8b705c               mov esi, dword ptr [eax + 0x5c]
// 0042f3a8  57                   push edi
// 0042f3a9  8bf9                 mov edi, ecx
// 0042f3ab  83bfa800000000       cmp dword ptr [edi + 0xa8], 0
// 0042f3b2  7450                 je 0x42f404
// 0042f3b4  6a00                 push 0
// 0042f3b6  6820c59d00           push 0x9dc520
// 0042f3bb  68acbd9d00           push 0x9dbdac
// 0042f3c0  6a00                 push 0
// 0042f3c2  56                   push esi
// 0042f3c3  e8b2a82e00           call 0x719c7a
// 0042f3c8  83c414               add esp, 0x14
// 0042f3cb  85c0                 test eax, eax
// 0042f3cd  740e                 je 0x42f3dd
// 0042f3cf  8b8fa8000000         mov ecx, dword ptr [edi + 0xa8]
// 0042f3d5  50                   push eax
// 0042f3d6  e825feffff           call 0x42f200
// 0042f3db  eb27                 jmp 0x42f404
// 0042f3dd  6a00                 push 0
// 0042f3df  6860119e00           push 0x9e1160
// 0042f3e4  68acbd9d00           push 0x9dbdac
// 0042f3e9  6a00                 push 0
// 0042f3eb  56                   push esi
// 0042f3ec  e889a82e00           call 0x719c7a
// 0042f3f1  83c414               add esp, 0x14
// 0042f3f4  85c0                 test eax, eax
// 0042f3f6  740c                 je 0x42f404
// 0042f3f8  8b8fa8000000         mov ecx, dword ptr [edi + 0xa8]
// 0042f3fe  50                   push eax
// 0042f3ff  e83cf0ffff           call 0x42e440
// 0042f404  8b8fac000000         mov ecx, dword ptr [edi + 0xac]
// 0042f40a  85c9                 test ecx, ecx
// 0042f40c  7415                 je 0x42f423
// 0042f40e  56                   push esi
// 0042f40f  e82cf3ffff           call 0x42e740
// 0042f414  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0042f418  5f                   pop edi
// 0042f419  c70100000000         mov dword ptr [ecx], 0
// 0042f41f  5e                   pop esi
// 0042f420  c20800               ret 8
// 0042f423  8b542410             mov edx, dword ptr [esp + 0x10]
// 0042f427  5f                   pop edi
// 0042f428  c70200000000         mov dword ptr [edx], 0
// 0042f42e  5e                   pop esi
// 0042f42f  c20800               ret 8
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
