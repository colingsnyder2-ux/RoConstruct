// Implementation: C:\Users\colin\RoConstruct\src\2008-06\005bc480.cpp
// Build pointer preserved: C:\Users\colin\RoConstruct\src\2008-06\005bc480.cpp
// from server: 100% by king_originala
// roc 2008-06 005bc480  unit: RBX::Soundscape::SoundService  size: 299 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005bc480
//
// 005bc480  6aff                 push -1
// 005bc482  68763d7d00           push 0x7d3d76
// 005bc487  64a100000000         mov eax, dword ptr fs:[0]
// 005bc48d  50                   push eax
// 005bc48e  64892500000000       mov dword ptr fs:[0], esp
// 005bc495  83ec24               sub esp, 0x24
// 005bc498  53                   push ebx
// 005bc499  56                   push esi
// 005bc49a  8bf1                 mov esi, ecx
// 005bc49c  57                   push edi
// 005bc49d  8974240c             mov dword ptr [esp + 0xc], esi
// 005bc4a1  e80afbffff           call 0x5bbfb0
// 005bc4a6  33db                 xor ebx, ebx
// 005bc4a8  c706fc768300         mov dword ptr [esi], 0x8376fc
// 005bc4ae  c74610ec768300       mov dword ptr [esi + 0x10], 0x8376ec
// 005bc4b5  c74614e4768300       mov dword ptr [esi + 0x14], 0x8376e4
// 005bc4bc  c74620dc768300       mov dword ptr [esi + 0x20], 0x8376dc
// 005bc4c3  c74624cc768300       mov dword ptr [esi + 0x24], 0x8376cc
// 005bc4ca  c74644bc768300       mov dword ptr [esi + 0x44], 0x8376bc
// 005bc4d1  c74664ac768300       mov dword ptr [esi + 0x64], 0x8376ac
// 005bc4d8  c786840000009c768300 mov dword ptr [esi + 0x84], 0x83769c
// 005bc4e2  c786a40000008c768300 mov dword ptr [esi + 0xa4], 0x83768c
// 005bc4ec  c786c40000007c768300 mov dword ptr [esi + 0xc4], 0x83767c
// 005bc4f6  c7863001000070768300 mov dword ptr [esi + 0x130], 0x837670
// 005bc500  899e34010000         mov dword ptr [esi + 0x134], ebx
// 005bc506  895c2438             mov dword ptr [esp + 0x38], ebx
// 005bc50a  899e38010000         mov dword ptr [esi + 0x138], ebx
// 005bc510  8dbe40010000         lea edi, [esi + 0x140]
// 005bc516  8bcf                 mov ecx, edi
// 005bc518  c644243801           mov byte ptr [esp + 0x38], 1
// 005bc51d  899e3c010000         mov dword ptr [esi + 0x13c], ebx
// 005bc523  897c2410             mov dword ptr [esp + 0x10], edi
// 005bc527  ff1560248000         call dword ptr [0x802460]
// 005bc52d  c644243802           mov byte ptr [esp + 0x38], 2
// 005bc532  e8397df9ff           call 0x554270
// 005bc537  89471c               mov dword ptr [edi + 0x1c], eax
// 005bc53a  d905ac9b8100         fld dword ptr [0x819bac]
// 005bc540  80a665010000f8       and byte ptr [esi + 0x165], 0xf8
// 005bc547  d99e60010000         fstp dword ptr [esi + 0x160]
// 005bc54d  6848878100           push 0x818748
// 005bc552  8d4c2418             lea ecx, [esp + 0x18]
// 005bc556  c644243c03           mov byte ptr [esp + 0x3c], 3
// 005bc55b  889e64010000         mov byte ptr [esi + 0x164], bl
// 005bc561  c78668010000ffffffff mov dword ptr [esi + 0x168], 0xffffffff
// 005bc56b  899e6c010000         mov dword ptr [esi + 0x16c], ebx
// 005bc571  ff1558248000         call dword ptr [0x802458]
// 005bc577  8d442414             lea eax, [esp + 0x14]
// 005bc57b  50                   push eax
// 005bc57c  8bce                 mov ecx, esi
// 005bc57e  c644243c04           mov byte ptr [esp + 0x3c], 4
// 005bc583  e808eaf9ff           call 0x55af90
// 005bc588  8d4c2414             lea ecx, [esp + 0x14]
// 005bc58c  c644243803           mov byte ptr [esp + 0x38], 3
// 005bc591  ff1568248000         call dword ptr [0x802468]
// 005bc597  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 005bc59b  5f                   pop edi
// 005bc59c  8bc6                 mov eax, esi
// 005bc59e  5e                   pop esi
// 005bc59f  5b                   pop ebx
// 005bc5a0  64890d00000000       mov dword ptr fs:[0], ecx
// 005bc5a7  83c430               add esp, 0x30
// 005bc5aa  c3                   ret 

struct String;
extern String* (__thiscall *constructString)(String*);
extern String* (__thiscall *constructStringText)(String*, const char*);
extern void (__thiscall *destroyString)(String*);

struct String {
    char storage[28];
    String();
    String(const char*);
    ~String();
};

inline String::String() { constructString(this); }
inline String::String(const char* text) { constructStringText(this, text); }
inline String::~String() { destroyString(this); }

struct Name;
extern const Name& __cdecl getLocalScope();
extern const float initialVolume;
extern const char soundName[];

extern char table00[], table10[], table14[], table20[];
extern char table24[], table44[], table64[], table84[];
extern char tableA4[], tableC4[], table130[];

struct Base {
    char storage[0x130];
    Base();
    ~Base();
    void setValue(const String&);
};

struct Shared {
    void* count;
    Shared();
    ~Shared();
};

inline Shared::Shared() : count(0) {}

struct Guid {
    String value;
    const Name* scope;
    Guid();
};

inline Guid::Guid() : scope(&getLocalScope()) {}

struct SoundService : Base {
    void* table;
    void* object;
    Shared shared;
    void* system;
    Guid guid;
    float volume;
    unsigned char enabled;
    unsigned char flags;
    unsigned short padding;
    int identifier;
    void* context;

    SoundService();
};

SoundService::SoundService()
    : table((
          *reinterpret_cast<void**>(storage) = table00,
          *reinterpret_cast<void**>(storage + 0x10) = table10,
          *reinterpret_cast<void**>(storage + 0x14) = table14,
          *reinterpret_cast<void**>(storage + 0x20) = table20,
          *reinterpret_cast<void**>(storage + 0x24) = table24,
          *reinterpret_cast<void**>(storage + 0x44) = table44,
          *reinterpret_cast<void**>(storage + 0x64) = table64,
          *reinterpret_cast<void**>(storage + 0x84) = table84,
          *reinterpret_cast<void**>(storage + 0xA4) = tableA4,
          *reinterpret_cast<void**>(storage + 0xC4) = tableC4,
          table130)),
      object(0),
      system(0),
      volume(initialVolume),
      enabled(0),
      identifier(-1),
      context(0)
{
    flags &= 0xF8;
    setValue(String(soundName));
}
