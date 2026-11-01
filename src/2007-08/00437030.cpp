// from server: 100% by Yeetserama
// roc 2007-08 00437030  unit: RBX::VStandardOut::?$Listener  size: 90 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00437030
//
// 00437030  83ec18               sub esp, 0x18
// 00437033  a188518b00           mov eax, dword ptr [0x8b5188]
// 00437038  33c4                 xor eax, esp
// 0043703a  89442414             mov dword ptr [esp + 0x14], eax
// 0043703e  0fb744241c           movzx eax, word ptr [esp + 0x1c]
// 00437043  56                   push esi
// 00437044  8b742424             mov esi, dword ptr [esp + 0x24]
// 00437048  57                   push edi
// 00437049  50                   push eax
// 0043704a  689ccd7800           push 0x78cd9c
// 0043704f  8d4c2410             lea ecx, [esp + 0x10]
// 00437053  6a09                 push 9
// 00437055  51                   push ecx
// 00437056  ff156ce97700         call dword ptr [0x77e96c]
// 0043705c  6a10                 push 0x10
// 0043705e  8d54241c             lea edx, [esp + 0x1c]
// 00437062  52                   push edx
// 00437063  6a12                 push 0x12
// 00437065  56                   push esi
// 00437066  8bf8                 mov edi, eax
// 00437068  ff15d4e67700         call dword ptr [0x77e6d4]
// 0043706e  50                   push eax
// 0043706f  e86ca6fcff           call 0x4016e0
// 00437074  8b4c2440             mov ecx, dword ptr [esp + 0x40]
// 00437078  83c424               add esp, 0x24
// 0043707b  8bc7                 mov eax, edi
// 0043707d  5f                   pop edi
// 0043707e  5e                   pop esi
// 0043707f  33cc                 xor ecx, esp
// 00437081  e898991f00           call 0x630a1e
// 00437086  83c418               add esp, 0x18
// 00437089  c3                   ret 
// copied from an identical function in another client (function ?format_output@ns_ROCX000001@@YAHGPAX@Z)

namespace ns_ROCX000001 {
// from server: 100% by king_originala
extern "C" {
    extern int (__cdecl *swprintf_s)(wchar_t *, unsigned int,
                                    const wchar_t *, ...);
    extern int (__cdecl *memcpy_s)(void *, unsigned int,
                                  const void *, unsigned int);
    void __cdecl check_error(int);
}

extern const wchar_t format[];

int __cdecl format_output(unsigned short value, void *destination)
{
    wchar_t buffer[9];
    int result = swprintf_s(buffer, 9, format, value);
    check_error(memcpy_s(destination, 18, buffer, 16));
    return result;
}
}
