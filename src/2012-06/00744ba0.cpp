// from server: 100% by Xemicl
// roc 2012-06 00744ba0  unit: boost::Vbad_lexical_cast::U?$error_info_injector::?$clone_impl  size: 168 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00744ba0
//
// 00744ba0  6aff                 push -1
// 00744ba2  680315ac00           push 0xac1503
// 00744ba7  64a100000000         mov eax, dword ptr fs:[0]
// 00744bad  50                   push eax
// 00744bae  64892500000000       mov dword ptr fs:[0], esp
// 00744bb5  83ec24               sub esp, 0x24
// 00744bb8  53                   push ebx
// 00744bb9  56                   push esi
// 00744bba  33db                 xor ebx, ebx
// 00744bbc  895c2408             mov dword ptr [esp + 8], ebx
// 00744bc0  8b74243c             mov esi, dword ptr [esp + 0x3c]
// 00744bc4  57                   push edi
// 00744bc5  8b7c2444             mov edi, dword ptr [esp + 0x44]
// 00744bc9  0fbf07               movsx eax, word ptr [edi]
// 00744bcc  8d4c2444             lea ecx, [esp + 0x44]
// 00744bd0  51                   push ecx
// 00744bd1  56                   push esi
// 00744bd2  895c2440             mov dword ptr [esp + 0x40], ebx
// 00744bd6  8944244c             mov dword ptr [esp + 0x4c], eax
// 00744bda  e881f2ffff           call 0x743e60
// 00744bdf  83c408               add esp, 8
// 00744be2  68402fb500           push 0xb52f40
// 00744be7  8bce                 mov ecx, esi
// 00744be9  895c243c             mov dword ptr [esp + 0x3c], ebx
// 00744bed  c744241001000000     mov dword ptr [esp + 0x10], 1
// 00744bf5  ff155c26b200         call dword ptr [0xb2265c]
// 00744bfb  0fbf5702             movsx edx, word ptr [edi + 2]
// 00744bff  8d442410             lea eax, [esp + 0x10]
// 00744c03  50                   push eax
// 00744c04  8d4c2418             lea ecx, [esp + 0x18]
// 00744c08  51                   push ecx
// 00744c09  89542418             mov dword ptr [esp + 0x18], edx
// 00744c0d  e84ef2ffff           call 0x743e60
// 00744c12  83c408               add esp, 8
// 00744c15  50                   push eax
// 00744c16  8bce                 mov ecx, esi
// 00744c18  c744243c01000000     mov dword ptr [esp + 0x3c], 1
// 00744c20  ff15e026b200         call dword ptr [0xb226e0]
// 00744c26  8d4c2414             lea ecx, [esp + 0x14]
// 00744c2a  885c2438             mov byte ptr [esp + 0x38], bl
// 00744c2e  ff153c26b200         call dword ptr [0xb2263c]
// 00744c34  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 00744c38  5f                   pop edi
// 00744c39  8bc6                 mov eax, esi
// 00744c3b  5e                   pop esi
// 00744c3c  5b                   pop ebx
// 00744c3d  64890d00000000       mov dword ptr fs:[0], ecx
// 00744c44  83c430               add esp, 0x30
// 00744c47  c3                   ret 
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