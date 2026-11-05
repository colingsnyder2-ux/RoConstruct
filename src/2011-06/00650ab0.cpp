// from server: 100% by Yeetserama
// roc 2011-06 00650ab0  unit: std::D::DU?$char_traits::DV?$basic_streambuf::?$lexical_stream_limited_src  size: 190 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00650ab0
//
// 00650ab0  6aff                 push -1
// 00650ab2  68c3c69e00           push 0x9ec6c3
// 00650ab7  64a100000000         mov eax, dword ptr fs:[0]
// 00650abd  50                   push eax
// 00650abe  64892500000000       mov dword ptr fs:[0], esp
// 00650ac5  83ec20               sub esp, 0x20
// 00650ac8  53                   push ebx
// 00650ac9  55                   push ebp
// 00650aca  56                   push esi
// 00650acb  8b742440             mov esi, dword ptr [esp + 0x40]
// 00650acf  57                   push edi
// 00650ad0  33db                 xor ebx, ebx
// 00650ad2  8d4624               lea eax, [esi + 0x24]
// 00650ad5  895c2410             mov dword ptr [esp + 0x10], ebx
// 00650ad9  8b7c2440             mov edi, dword ptr [esp + 0x40]
// 00650add  50                   push eax
// 00650ade  57                   push edi
// 00650adf  895c2440             mov dword ptr [esp + 0x40], ebx
// 00650ae3  e848feffff           call 0x650930
// 00650ae8  83c408               add esp, 8
// 00650aeb  895c2438             mov dword ptr [esp + 0x38], ebx
// 00650aef  c744241001000000     mov dword ptr [esp + 0x10], 1
// 00650af7  c744244403000000     mov dword ptr [esp + 0x44], 3
// 00650aff  90                   nop 
// 00650b00  bd03000000           mov ebp, 3
// 00650b05  eb09                 jmp 0x650b10
// 00650b07  8da42400000000       lea esp, [esp]
// 00650b0e  8bff                 mov edi, edi
// 00650b10  68e888a600           push 0xa688e8
// 00650b15  8bcf                 mov ecx, edi
// 00650b17  ff15b004a400         call dword ptr [0xa404b0]
// 00650b1d  8d4c2414             lea ecx, [esp + 0x14]
// 00650b21  56                   push esi
// 00650b22  51                   push ecx
// 00650b23  e888f9ffff           call 0x6504b0
// 00650b28  83c408               add esp, 8
// 00650b2b  50                   push eax
// 00650b2c  8bcf                 mov ecx, edi
// 00650b2e  c744243c01000000     mov dword ptr [esp + 0x3c], 1
// 00650b36  ff15b804a400         call dword ptr [0xa404b8]
// 00650b3c  8d4c2414             lea ecx, [esp + 0x14]
// 00650b40  885c2438             mov byte ptr [esp + 0x38], bl
// 00650b44  ff15d004a400         call dword ptr [0xa404d0]
// 00650b4a  83c604               add esi, 4
// 00650b4d  83ed01               sub ebp, 1
// 00650b50  75be                 jne 0x650b10
// 00650b52  836c244401           sub dword ptr [esp + 0x44], 1
// 00650b57  75a7                 jne 0x650b00
// 00650b59  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 00650b5d  8bc7                 mov eax, edi
// 00650b5f  5f                   pop edi
// 00650b60  5e                   pop esi
// 00650b61  5d                   pop ebp
// 00650b62  5b                   pop ebx
// 00650b63  64890d00000000       mov dword ptr fs:[0], ecx
// 00650b6a  83c42c               add esp, 0x2c
// 00650b6d  c3                   ret 
// copied from an identical function in another client (function ?serializeMatrix@ns_ROCX000005@@YA?AUString@1@PBM@Z)

namespace ns_ROCX000005 {
struct String
{
    unsigned char storage[28];

    String(const String&);
    ~String();
    String& operator+=(const char*);
    String& operator+=(const String&);
};

extern String __cdecl formatFloat(const float&);
extern String __cdecl formatVector(const float*);
extern String& (__thiscall *appendText)(String*, const char*);
extern String& (__thiscall *appendString)(String*, const String&);
extern void (__thiscall *destroyString)(String*);

inline String::~String()
{
    destroyString(this);
}

inline String& String::operator+=(const char* text)
{
    return appendText(this, text);
}

inline String& String::operator+=(const String& text)
{
    return appendString(this, text);
}

String __cdecl serializeMatrix(const float* values)
{
    String result = formatVector(values + 9);
    for (int r = 0; r < 3; ++r)
        for (int c = 0; c < 3; ++c)
        {
            result += ", ";
            result += formatFloat(values[r * 3 + c]);
        }
    return result;
}
}
