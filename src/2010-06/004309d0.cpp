// from server: 100% by Yeetserama
// roc 2010-06 004309d0  unit: CMemberTreeView  size: 146 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004309d0
//
// 004309d0  8b442404             mov eax, dword ptr [esp + 4]
// 004309d4  56                   push esi
// 004309d5  8b705c               mov esi, dword ptr [eax + 0x5c]
// 004309d8  57                   push edi
// 004309d9  8bf9                 mov edi, ecx
// 004309db  83bfa800000000       cmp dword ptr [edi + 0xa8], 0
// 004309e2  7450                 je 0x430a34
// 004309e4  6a00                 push 0
// 004309e6  685895b700           push 0xb79558
// 004309eb  68ac8db700           push 0xb78dac
// 004309f0  6a00                 push 0
// 004309f2  56                   push esi
// 004309f3  e8f2813700           call 0x7a8bea
// 004309f8  83c414               add esp, 0x14
// 004309fb  85c0                 test eax, eax
// 004309fd  740e                 je 0x430a0d
// 004309ff  8b8fa8000000         mov ecx, dword ptr [edi + 0xa8]
// 00430a05  50                   push eax
// 00430a06  e825feffff           call 0x430830
// 00430a0b  eb27                 jmp 0x430a34
// 00430a0d  6a00                 push 0
// 00430a0f  6878e2b700           push 0xb7e278
// 00430a14  68ac8db700           push 0xb78dac
// 00430a19  6a00                 push 0
// 00430a1b  56                   push esi
// 00430a1c  e8c9813700           call 0x7a8bea
// 00430a21  83c414               add esp, 0x14
// 00430a24  85c0                 test eax, eax
// 00430a26  740c                 je 0x430a34
// 00430a28  8b8fa8000000         mov ecx, dword ptr [edi + 0xa8]
// 00430a2e  50                   push eax
// 00430a2f  e82cf0ffff           call 0x42fa60
// 00430a34  8b8fac000000         mov ecx, dword ptr [edi + 0xac]
// 00430a3a  85c9                 test ecx, ecx
// 00430a3c  7415                 je 0x430a53
// 00430a3e  56                   push esi
// 00430a3f  e81cf3ffff           call 0x42fd60
// 00430a44  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00430a48  5f                   pop edi
// 00430a49  c70100000000         mov dword ptr [ecx], 0
// 00430a4f  5e                   pop esi
// 00430a50  c20800               ret 8
// 00430a53  8b542410             mov edx, dword ptr [esp + 0x10]
// 00430a57  5f                   pop edi
// 00430a58  c70200000000         mov dword ptr [edx], 0
// 00430a5e  5e                   pop esi
// 00430a5f  c20800               ret 8
// copied from an identical function in another client (function ?fn_ROCX000007_00435fa0@CClassTreeView@ns_ROCX000007@@QAEXPAUArgument@2@PAH@Z)

namespace ns_ROCX000007 {
// from server: 100% by king_originala
extern unsigned char descriptor_00928fe8;
extern unsigned char descriptor_0092f39c;
extern unsigned char descriptor_0092f3cc;

extern "C" void* __cdecl fn_ROCX000007_006a17c6(
    void*, int, const void*, const void*, int);

struct Handler
{
    void fn_ROCX000007_00435c80(void*);
    void fn_ROCX000007_00435180(void*);
    void fn_ROCX000007_00435860(void*);
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

    void fn_ROCX000007_00435fa0(Argument*, int*);
};

void CClassTreeView::fn_ROCX000007_00435fa0(Argument* argument, int* result)
{
    void* descriptor = argument->descriptor;

    if (primary)
    {
        void* converted = fn_ROCX000007_006a17c6(
            descriptor, 0, &descriptor_00928fe8, &descriptor_0092f39c, 0);

        if (converted)
        {
            primary->fn_ROCX000007_00435c80(converted);
        }
        else
        {
            converted = fn_ROCX000007_006a17c6(
                descriptor, 0, &descriptor_00928fe8, &descriptor_0092f3cc, 0);

            if (converted)
                primary->fn_ROCX000007_00435180(converted);
        }
    }

    if (secondary)
        secondary->fn_ROCX000007_00435860(descriptor);

    *result = 0;
}
}
