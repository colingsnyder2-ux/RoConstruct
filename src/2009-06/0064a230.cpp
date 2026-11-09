// from server: 100% by EspClaude
// roc 2009-06 0064a230  unit: RBX::Soundscape::SoundChannel  size: 125 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0064a230
//
// 0064a230  6aff                 push -1
// 0064a232  6861468600           push 0x864661
// 0064a237  64a100000000         mov eax, dword ptr fs:[0]
// 0064a23d  50                   push eax
// 0064a23e  64892500000000       mov dword ptr fs:[0], esp
// 0064a245  83ec20               sub esp, 0x20
// 0064a248  8b442430             mov eax, dword ptr [esp + 0x30]
// 0064a24c  56                   push esi
// 0064a24d  50                   push eax
// 0064a24e  8d4c2408             lea ecx, [esp + 8]
// 0064a252  ff15b8e48900         call dword ptr [0x89e4b8]
// 0064a258  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 0064a260  e8fb36f8ff           call 0x5cd960
// 0064a265  89442420             mov dword ptr [esp + 0x20], eax
// 0064a269  8b742438             mov esi, dword ptr [esp + 0x38]
// 0064a26d  8d4c2404             lea ecx, [esp + 4]
// 0064a271  51                   push ecx
// 0064a272  8bce                 mov ecx, esi
// 0064a274  c744243001000000     mov dword ptr [esp + 0x30], 1
// 0064a27c  ff1564e48900         call dword ptr [0x89e464]
// 0064a282  8b542420             mov edx, dword ptr [esp + 0x20]
// 0064a286  8d4c2404             lea ecx, [esp + 4]
// 0064a28a  89561c               mov dword ptr [esi + 0x1c], edx
// 0064a28d  c744242cffffffff     mov dword ptr [esp + 0x2c], 0xffffffff
// 0064a295  ff15c4e48900         call dword ptr [0x89e4c4]
// 0064a29b  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0064a29f  b001                 mov al, 1
// 0064a2a1  5e                   pop esi
// 0064a2a2  64890d00000000       mov dword ptr fs:[0], ecx
// 0064a2a9  83c42c               add esp, 0x2c
// 0064a2ac  c3                   ret 
// copied from an identical function in another client (function ?reconstruct@ns_ROCX000005@@YA_NABUString@1@PAUHolder@1@@Z)

namespace ns_ROCX000005 {
struct Name;

struct String {
    unsigned char data[28];

    String(const String&);
    ~String();
    String& operator=(const String&);
};

extern void (__thiscall *copyString)(String*, const String&);
extern void (__thiscall *destroyString)(String*);
extern String& (__thiscall *assignString)(String*, const String&);
extern const Name& __cdecl getLocalScope();

inline String::String(const String& source)
{
    copyString(this, source);
}

inline String::~String()
{
    destroyString(this);
}

inline String& String::operator=(const String& source)
{
    return assignString(this, source);
}

struct Holder {
    String text;
    const Name* scope;
};

bool __cdecl reconstruct(const String& source, Holder* destination)
{
    Holder temporary = { source, &getLocalScope() };
    *destination = temporary;
    return true;
}
}
