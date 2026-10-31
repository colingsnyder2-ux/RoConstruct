// from server: 100% by EspClaude
// roc 2009-06 0064bb40  unit: std::D::DU?$char_traits::DV?$basic_streambuf::?$lexical_stream_limited_src  size: 168 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0064bb40
//
// 0064bb40  6aff                 push -1
// 0064bb42  68a3ad8600           push 0x86ada3
// 0064bb47  64a100000000         mov eax, dword ptr fs:[0]
// 0064bb4d  50                   push eax
// 0064bb4e  64892500000000       mov dword ptr fs:[0], esp
// 0064bb55  83ec24               sub esp, 0x24
// 0064bb58  53                   push ebx
// 0064bb59  56                   push esi
// 0064bb5a  33db                 xor ebx, ebx
// 0064bb5c  895c2408             mov dword ptr [esp + 8], ebx
// 0064bb60  8b74243c             mov esi, dword ptr [esp + 0x3c]
// 0064bb64  57                   push edi
// 0064bb65  8b7c2444             mov edi, dword ptr [esp + 0x44]
// 0064bb69  0fbf07               movsx eax, word ptr [edi]
// 0064bb6c  8d4c2444             lea ecx, [esp + 0x44]
// 0064bb70  51                   push ecx
// 0064bb71  56                   push esi
// 0064bb72  895c2440             mov dword ptr [esp + 0x40], ebx
// 0064bb76  8944244c             mov dword ptr [esp + 0x4c], eax
// 0064bb7a  e811f8ffff           call 0x64b390
// 0064bb7f  83c408               add esp, 8
// 0064bb82  68f0338b00           push 0x8b33f0
// 0064bb87  8bce                 mov ecx, esi
// 0064bb89  895c243c             mov dword ptr [esp + 0x3c], ebx
// 0064bb8d  c744241001000000     mov dword ptr [esp + 0x10], 1
// 0064bb95  ff15a4e48900         call dword ptr [0x89e4a4]
// 0064bb9b  0fbf5702             movsx edx, word ptr [edi + 2]
// 0064bb9f  8d442410             lea eax, [esp + 0x10]
// 0064bba3  50                   push eax
// 0064bba4  8d4c2418             lea ecx, [esp + 0x18]
// 0064bba8  51                   push ecx
// 0064bba9  89542418             mov dword ptr [esp + 0x18], edx
// 0064bbad  e8def7ffff           call 0x64b390
// 0064bbb2  83c408               add esp, 8
// 0064bbb5  50                   push eax
// 0064bbb6  8bce                 mov ecx, esi
// 0064bbb8  c744243c01000000     mov dword ptr [esp + 0x3c], 1
// 0064bbc0  ff15ace48900         call dword ptr [0x89e4ac]
// 0064bbc6  8d4c2414             lea ecx, [esp + 0x14]
// 0064bbca  885c2438             mov byte ptr [esp + 0x38], bl
// 0064bbce  ff15c4e48900         call dword ptr [0x89e4c4]
// 0064bbd4  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 0064bbd8  5f                   pop edi
// 0064bbd9  8bc6                 mov eax, esi
// 0064bbdb  5e                   pop esi
// 0064bbdc  5b                   pop ebx
// 0064bbdd  64890d00000000       mov dword ptr fs:[0], ecx
// 0064bbe4  83c430               add esp, 0x30
// 0064bbe7  c3                   ret 
// copied from an identical function in another client (function ?formatPair@ns_ROCX000001@@YA?AUString@1@PBF@Z)

namespace ns_ROCX000001 {
struct String
{
    unsigned char storage[28];

    String(const String&);
    ~String();
    String& operator+=(const char*);
    String& operator+=(const String&);
};

typedef void (__thiscall *StringDestructor)(String*);
typedef String& (__thiscall *StringAppendText)(String*, const char*);
typedef String& (__thiscall *StringAppendString)(String*, const String&);

extern StringDestructor destroyString;
extern StringAppendText appendText;
extern StringAppendString appendString;

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

String __cdecl stringFromNumber(const int&);

String __cdecl formatPair(const short* values)
{
    String result = stringFromNumber(static_cast<int>(values[0]));
    result += ", ";
    result += stringFromNumber(static_cast<int>(values[1]));
    return result;
}
}
