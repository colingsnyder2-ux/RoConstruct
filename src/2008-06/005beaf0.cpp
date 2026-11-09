// from server: 100% by EspClaude
// from server: 93% by king_originala
// roc 2008-06 005beaf0  unit: RBX::Soundscape::SoundService  size: 190 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005beaf0
//
// 005beaf0  6aff                 push -1
// 005beaf2  68c33f7d00           push 0x7d3fc3
// 005beaf7  64a100000000         mov eax, dword ptr fs:[0]
// 005beafd  50                   push eax
// 005beafe  64892500000000       mov dword ptr fs:[0], esp
// 005beb05  83ec20               sub esp, 0x20
// 005beb08  53                   push ebx
// 005beb09  55                   push ebp
// 005beb0a  56                   push esi
// 005beb0b  8b742440             mov esi, dword ptr [esp + 0x40]
// 005beb0f  57                   push edi
// 005beb10  33db                 xor ebx, ebx
// 005beb12  8d4624               lea eax, [esi + 0x24]
// 005beb15  895c2410             mov dword ptr [esp + 0x10], ebx
// 005beb19  8b7c2440             mov edi, dword ptr [esp + 0x40]
// 005beb1d  50                   push eax
// 005beb1e  57                   push edi
// 005beb1f  895c2440             mov dword ptr [esp + 0x40], ebx
// 005beb23  e8e8feffff           call 0x5bea10
// 005beb28  83c408               add esp, 8
// 005beb2b  895c2438             mov dword ptr [esp + 0x38], ebx
// 005beb2f  c744241001000000     mov dword ptr [esp + 0x10], 1
// 005beb37  c744244403000000     mov dword ptr [esp + 0x44], 3
// 005beb3f  90                   nop 
// 005beb40  bd03000000           mov ebp, 3
// 005beb45  eb09                 jmp 0x5beb50
// 005beb47  8da42400000000       lea esp, [esp]
// 005beb4e  8bff                 mov edi, edi
// 005beb50  68502e8100           push 0x812e50
// 005beb55  8bcf                 mov ecx, edi
// 005beb57  ff1548248000         call dword ptr [0x802448]
// 005beb5d  8d4c2414             lea ecx, [esp + 0x14]
// 005beb61  56                   push esi
// 005beb62  51                   push ecx
// 005beb63  e8d8f4ffff           call 0x5be040
// 005beb68  83c408               add esp, 8
// 005beb6b  50                   push eax
// 005beb6c  8bcf                 mov ecx, edi
// 005beb6e  c744243c01000000     mov dword ptr [esp + 0x3c], 1
// 005beb76  ff1550248000         call dword ptr [0x802450]
// 005beb7c  8d4c2414             lea ecx, [esp + 0x14]
// 005beb80  885c2438             mov byte ptr [esp + 0x38], bl
// 005beb84  ff1568248000         call dword ptr [0x802468]
// 005beb8a  83c604               add esi, 4
// 005beb8d  83ed01               sub ebp, 1
// 005beb90  75be                 jne 0x5beb50
// 005beb92  836c244401           sub dword ptr [esp + 0x44], 1
// 005beb97  75a7                 jne 0x5beb40
// 005beb99  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 005beb9d  8bc7                 mov eax, edi
// 005beb9f  5f                   pop edi
// 005beba0  5e                   pop esi
// 005beba1  5d                   pop ebp
// 005beba2  5b                   pop ebx
// 005beba3  64890d00000000       mov dword ptr fs:[0], ecx
// 005bebaa  83c42c               add esp, 0x2c
// 005bebad  c3                   ret 

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
