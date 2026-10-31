// from server: 100% by EspClaude
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
