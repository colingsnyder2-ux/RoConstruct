// from server: 100% by Yeetserama
// roc 2011-06 006507c0  unit: std::D::DU?$char_traits::DV?$basic_streambuf::?$lexical_stream_limited_src  size: 168 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 006507c0
//
// 006507c0  6aff                 push -1
// 006507c2  6853c69e00           push 0x9ec653
// 006507c7  64a100000000         mov eax, dword ptr fs:[0]
// 006507cd  50                   push eax
// 006507ce  64892500000000       mov dword ptr fs:[0], esp
// 006507d5  83ec24               sub esp, 0x24
// 006507d8  53                   push ebx
// 006507d9  56                   push esi
// 006507da  33db                 xor ebx, ebx
// 006507dc  895c2408             mov dword ptr [esp + 8], ebx
// 006507e0  8b74243c             mov esi, dword ptr [esp + 0x3c]
// 006507e4  57                   push edi
// 006507e5  8b7c2444             mov edi, dword ptr [esp + 0x44]
// 006507e9  0fbf07               movsx eax, word ptr [edi]
// 006507ec  8d4c2444             lea ecx, [esp + 0x44]
// 006507f0  51                   push ecx
// 006507f1  56                   push esi
// 006507f2  895c2440             mov dword ptr [esp + 0x40], ebx
// 006507f6  8944244c             mov dword ptr [esp + 0x4c], eax
// 006507fa  e8b1f8ffff           call 0x6500b0
// 006507ff  83c408               add esp, 8
// 00650802  68e888a600           push 0xa688e8
// 00650807  8bce                 mov ecx, esi
// 00650809  895c243c             mov dword ptr [esp + 0x3c], ebx
// 0065080d  c744241001000000     mov dword ptr [esp + 0x10], 1
// 00650815  ff15b004a400         call dword ptr [0xa404b0]
// 0065081b  0fbf5702             movsx edx, word ptr [edi + 2]
// 0065081f  8d442410             lea eax, [esp + 0x10]
// 00650823  50                   push eax
// 00650824  8d4c2418             lea ecx, [esp + 0x18]
// 00650828  51                   push ecx
// 00650829  89542418             mov dword ptr [esp + 0x18], edx
// 0065082d  e87ef8ffff           call 0x6500b0
// 00650832  83c408               add esp, 8
// 00650835  50                   push eax
// 00650836  8bce                 mov ecx, esi
// 00650838  c744243c01000000     mov dword ptr [esp + 0x3c], 1
// 00650840  ff15b804a400         call dword ptr [0xa404b8]
// 00650846  8d4c2414             lea ecx, [esp + 0x14]
// 0065084a  885c2438             mov byte ptr [esp + 0x38], bl
// 0065084e  ff15d004a400         call dword ptr [0xa404d0]
// 00650854  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 00650858  5f                   pop edi
// 00650859  8bc6                 mov eax, esi
// 0065085b  5e                   pop esi
// 0065085c  5b                   pop ebx
// 0065085d  64890d00000000       mov dword ptr fs:[0], ecx
// 00650864  83c430               add esp, 0x30
// 00650867  c3                   ret 
// copied from an identical function in another client (function ?formatPair@ns_ROCX000003@@YA?AUString@1@PBF@Z)

namespace ns_ROCX000003 {
// from server: 100% by king_originala
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
