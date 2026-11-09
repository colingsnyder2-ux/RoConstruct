// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0055bd80  unit: RBX::VInstance::?$SignalDesc  size: 167 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0055bd80
//
// 0055bd80  6aff                 push -1
// 0055bd82  6874e77c00           push 0x7ce774
// 0055bd87  64a100000000         mov eax, dword ptr fs:[0]
// 0055bd8d  50                   push eax
// 0055bd8e  64892500000000       mov dword ptr fs:[0], esp
// 0055bd95  83ec3c               sub esp, 0x3c
// 0055bd98  56                   push esi
// 0055bd99  6868da8200           push 0x82da68
// 0055bd9e  8d4c240c             lea ecx, [esp + 0xc]
// 0055bda2  c744240800000000     mov dword ptr [esp + 8], 0
// 0055bdaa  ff1558248000         call dword ptr [0x802458]
// 0055bdb0  8b442454             mov eax, dword ptr [esp + 0x54]
// 0055bdb4  50                   push eax
// 0055bdb5  8d4c240c             lea ecx, [esp + 0xc]
// 0055bdb9  51                   push ecx
// 0055bdba  8d54242c             lea edx, [esp + 0x2c]
// 0055bdbe  52                   push edx
// 0055bdbf  c744245401000000     mov dword ptr [esp + 0x54], 1
// 0055bdc7  ff15e4238000         call dword ptr [0x8023e4]
// 0055bdcd  83c40c               add esp, 0xc
// 0055bdd0  8b742450             mov esi, dword ptr [esp + 0x50]
// 0055bdd4  50                   push eax
// 0055bdd5  8bce                 mov ecx, esi
// 0055bdd7  c644244c02           mov byte ptr [esp + 0x4c], 2
// 0055bddc  ff155c248000         call dword ptr [0x80245c]
// 0055bde2  c644244803           mov byte ptr [esp + 0x48], 3
// 0055bde7  e88484ffff           call 0x554270
// 0055bdec  89461c               mov dword ptr [esi + 0x1c], eax
// 0055bdef  8d4c2424             lea ecx, [esp + 0x24]
// 0055bdf3  c744240401000000     mov dword ptr [esp + 4], 1
// 0055bdfb  c644244801           mov byte ptr [esp + 0x48], 1
// 0055be00  ff1568248000         call dword ptr [0x802468]
// 0055be06  8d4c2408             lea ecx, [esp + 8]
// 0055be0a  c644244800           mov byte ptr [esp + 0x48], 0
// 0055be0f  ff1568248000         call dword ptr [0x802468]
// 0055be15  8b4c2440             mov ecx, dword ptr [esp + 0x40]
// 0055be19  8bc6                 mov eax, esi
// 0055be1b  5e                   pop esi
// 0055be1c  64890d00000000       mov dword ptr fs:[0], ecx
// 0055be23  83c448               add esp, 0x48
// 0055be26  c3                   ret 

struct String {
    unsigned char storage[28];
    String(const char *);
    String(const String &);
    ~String();
};

extern String *(__thiscall *constructString)(String *, const char *);
extern String *(__thiscall *copyString)(String *, const String &);
extern void (__thiscall *destroyString)(String *);
extern String (__cdecl *concatenateString)(const String &, const char *);

inline String::String(const char *s)
{
    constructString(this, s);
}

inline String::String(const String &s)
{
    copyString(this, s);
}

inline String::~String()
{
    destroyString(this);
}

struct Name;
const Name &__cdecl getLocalScope();

struct Value {
    String text;
    const Name *scope;

    Value(const String &);
};

Value::Value(const String &s)
    : text(s), scope(&getLocalScope())
{
}

Value __cdecl makeValue(const char *path)
{
    String prefix("rbxasset://");
    return Value(concatenateString(prefix, path));
}
