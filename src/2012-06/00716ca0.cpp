// from server: 100% by Xemicl
// roc 2012-06 00716ca0  unit: FLog::VFastLogSettingsItem::?$FactoryProduct::Creator  size: 141 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00716ca0
//
// 00716ca0  55                   push ebp
// 00716ca1  56                   push esi
// 00716ca2  57                   push edi
// 00716ca3  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00716ca7  8bf1                 mov esi, ecx
// 00716ca9  8b16                 mov edx, dword ptr [esi]
// 00716cab  8b6af4               mov ebp, dword ptr [edx - 0xc]
// 00716cae  85ff                 test edi, edi
// 00716cb0  7504                 jne 0x716cb6
// 00716cb2  33c0                 xor eax, eax
// 00716cb4  eb14                 jmp 0x716cca
// 00716cb6  8bc7                 mov eax, edi
// 00716cb8  53                   push ebx
// 00716cb9  8d5801               lea ebx, [eax + 1]
// 00716cbc  8d642400             lea esp, [esp]
// 00716cc0  8a08                 mov cl, byte ptr [eax]
// 00716cc2  40                   inc eax
// 00716cc3  84c9                 test cl, cl
// 00716cc5  75f9                 jne 0x716cc0
// 00716cc7  2bc3                 sub eax, ebx
// 00716cc9  5b                   pop ebx
// 00716cca  b901000000           mov ecx, 1
// 00716ccf  2b4afc               sub ecx, dword ptr [edx - 4]
// 00716cd2  8b52f8               mov edx, dword ptr [edx - 8]
// 00716cd5  8d442801             lea eax, [eax + ebp + 1]
// 00716cd9  2bd0                 sub edx, eax
// 00716cdb  0bca                 or ecx, edx
// 00716cdd  7d08                 jge 0x716ce7
// 00716cdf  50                   push eax
// 00716ce0  8bce                 mov ecx, esi
// 00716ce2  e8e989d5ff           call 0x46f6d0
// 00716ce7  8b06                 mov eax, dword ptr [esi]
// 00716ce9  57                   push edi
// 00716cea  50                   push eax
// 00716ceb  ff15303ab200         call dword ptr [0xb23a30]
// 00716cf1  8bf8                 mov edi, eax
// 00716cf3  8b06                 mov eax, dword ptr [esi]
// 00716cf5  8b48f8               mov ecx, dword ptr [eax - 8]
// 00716cf8  85c0                 test eax, eax
// 00716cfa  740f                 je 0x716d0b
// 00716cfc  51                   push ecx
// 00716cfd  50                   push eax
// 00716cfe  ff15e82ab200         call dword ptr [0xb22ae8]
// 00716d04  83c408               add esp, 8
// 00716d07  85c0                 test eax, eax
// 00716d09  7c18                 jl 0x716d23
// 00716d0b  8b0e                 mov ecx, dword ptr [esi]
// 00716d0d  3b41f8               cmp eax, dword ptr [ecx - 8]
// 00716d10  7f11                 jg 0x716d23
// 00716d12  8941f4               mov dword ptr [ecx - 0xc], eax
// 00716d15  8b0e                 mov ecx, dword ptr [esi]
// 00716d17  c6040800             mov byte ptr [eax + ecx], 0
// 00716d1b  8bc7                 mov eax, edi
// 00716d1d  5f                   pop edi
// 00716d1e  5e                   pop esi
// 00716d1f  5d                   pop ebp
// 00716d20  c20400               ret 4
// 00716d23  6857000780           push 0x80070057
// 00716d28  e883d4ceff           call 0x4041b0
// copied from an identical function in another client (function ?append@S@ns_ROCX000002@@QAEHPBD@Z)

namespace ns_ROCX000002 {
// from server: 100% by king_originala
// roc 2008-06 0055df40  unit: RBX::VInstance::?$NonFactoryProduct  size: 141 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0055df40
//
// 0055df40  55                   push ebp
// 0055df41  56                   push esi
// 0055df42  57                   push edi
// 0055df43  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0055df47  8bf1                 mov esi, ecx
// 0055df49  8b16                 mov edx, dword ptr [esi]
// 0055df4b  8b6af4               mov ebp, dword ptr [edx - 0xc]
// 0055df4e  85ff                 test edi, edi
// 0055df50  7504                 jne 0x55df56
// 0055df52  33c0                 xor eax, eax
// 0055df54  eb14                 jmp 0x55df6a
// 0055df56  8bc7                 mov eax, edi
// 0055df58  53                   push ebx
// 0055df59  8d5801               lea ebx, [eax + 1]
// 0055df5c  8d642400             lea esp, [esp]
// 0055df60  8a08                 mov cl, byte ptr [eax]
// 0055df62  40                   inc eax
// 0055df63  84c9                 test cl, cl
// 0055df65  75f9                 jne 0x55df60
// 0055df67  2bc3                 sub eax, ebx
// 0055df69  5b                   pop ebx
// 0055df6a  b901000000           mov ecx, 1
// 0055df6f  2b4afc               sub ecx, dword ptr [edx - 4]
// 0055df72  8b52f8               mov edx, dword ptr [edx - 8]
// 0055df75  8d442801             lea eax, [eax + ebp + 1]
// 0055df79  2bd0                 sub edx, eax
// 0055df7b  0bca                 or ecx, edx
// 0055df7d  7d08                 jge 0x55df87
// 0055df7f  50                   push eax
// 0055df80  8bce                 mov ecx, esi
// 0055df82  e87994eaff           call 0x407400
// 0055df87  8b06                 mov eax, dword ptr [esi]
// 0055df89  57                   push edi
// 0055df8a  50                   push eax
// 0055df8b  ff15182b8000         call dword ptr [0x802b18]
// 0055df91  8bf8                 mov edi, eax
// 0055df93  8b06                 mov eax, dword ptr [esi]
// 0055df95  8b48f8               mov ecx, dword ptr [eax - 8]
// 0055df98  85c0                 test eax, eax
// 0055df9a  740f                 je 0x55dfab
// 0055df9c  51                   push ecx
// 0055df9d  50                   push eax
// 0055df9e  ff1570288000         call dword ptr [0x802870]
// 0055dfa4  83c408               add esp, 8
// 0055dfa7  85c0                 test eax, eax
// 0055dfa9  7c18                 jl 0x55dfc3
// 0055dfab  8b0e                 mov ecx, dword ptr [esi]
// 0055dfad  3b41f8               cmp eax, dword ptr [ecx - 8]
// 0055dfb0  7f11                 jg 0x55dfc3
// 0055dfb2  8941f4               mov dword ptr [ecx - 0xc], eax
// 0055dfb5  8b0e                 mov ecx, dword ptr [esi]
// 0055dfb7  c6040800             mov byte ptr [eax + ecx], 0
// 0055dfbb  8bc7                 mov eax, edi
// 0055dfbd  5f                   pop edi
// 0055dfbe  5e                   pop esi
// 0055dfbf  5d                   pop ebp
// 0055dfc0  c20400               ret 4
// 0055dfc3  6857000780           push 0x80070057
// 0055dfc8  e83330eaff           call 0x401000

extern "C" unsigned int __cdecl strlen(const char *);
extern "C" unsigned int (__cdecl *strnlen)(const char *, unsigned int);
extern "C" int (__stdcall *PathAppendA)(char *, const char *);

namespace ATL {
    __declspec(noreturn) void __stdcall AtlThrowImpl(long);
}

struct S {
    char *data;
    void grow(int);
    int append(const char *);
};

int S::append(const char *path)
{
    int *header = reinterpret_cast<int *>(data);
    int oldLength = header[-3];
    int length = path == 0 ? 0 : static_cast<int>(strlen(path));
    int required = oldLength + length + 1;

    if (((1 - header[-1]) | (header[-2] - required)) < 0)
        grow(required);

    int result = PathAppendA(data, path);

    char *buffer = data;
    int capacity = *reinterpret_cast<int *>(
        reinterpret_cast<unsigned int>(buffer) - 8);
    int newLength = buffer == 0
        ? 0
        : static_cast<int>(strnlen(buffer, capacity));

    if (newLength < 0 ||
        newLength > reinterpret_cast<int *>(data)[-2])
        ATL::AtlThrowImpl(static_cast<long>(0x80070057UL));

    reinterpret_cast<int *>(data)[-3] = newLength;
    data[newLength] = 0;
    return result;
}
}
