// from server: 94% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00588780  unit: RBX::VChangeHistoryService::?$FactoryProduct  size: 357 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00588780
//
// 00588780  64a100000000         mov eax, dword ptr fs:[0]
// 00588786  6aff                 push -1
// 00588788  688c147d00           push 0x7d148c
// 0058878d  50                   push eax
// 0058878e  64892500000000       mov dword ptr fs:[0], esp
// 00588795  81ec90000000         sub esp, 0x90
// 0058879b  55                   push ebp
// 0058879c  56                   push esi
// 0058879d  8bf1                 mov esi, ecx
// 0058879f  80be6401000000       cmp byte ptr [esi + 0x164], 0
// 005887a6  8dae64010000         lea ebp, [esi + 0x164]
// 005887ac  7437                 je 0x5887e5
// 005887ae  6818178300           push 0x831718
// 005887b3  8d4c2414             lea ecx, [esp + 0x14]
// 005887b7  ff1558248000         call dword ptr [0x802458]
// 005887bd  8d442410             lea eax, [esp + 0x10]
// 005887c1  50                   push eax
// 005887c2  8d4c2430             lea ecx, [esp + 0x30]
// 005887c6  c78424a400000000000000 mov dword ptr [esp + 0xa4], 0
// 005887d1  e87a15e8ff           call 0x409d50
// 005887d6  68c81b8d00           push 0x8d1bc8
// 005887db  8d4c2430             lea ecx, [esp + 0x30]
// 005887df  51                   push ecx
// 005887e0  e8a78d1100           call 0x6a158c
// 005887e5  80be6501000000       cmp byte ptr [esi + 0x165], 0
// 005887ec  7537                 jne 0x588825
// 005887ee  68f4168300           push 0x8316f4
// 005887f3  8d4c2414             lea ecx, [esp + 0x14]
// 005887f7  ff1558248000         call dword ptr [0x802458]
// 005887fd  8d542410             lea edx, [esp + 0x10]
// 00588801  52                   push edx
// 00588802  8d4c2430             lea ecx, [esp + 0x30]
// 00588806  c78424a400000001000000 mov dword ptr [esp + 0xa4], 1
// 00588811  e83a15e8ff           call 0x409d50
// 00588816  68c81b8d00           push 0x8d1bc8
// 0058881b  8d442430             lea eax, [esp + 0x30]
// 0058881f  50                   push eax
// 00588820  e8678d1100           call 0x6a158c
// 00588825  8b8654010000         mov eax, dword ptr [esi + 0x154]
// 0058882b  8b8e38010000         mov ecx, dword ptr [esi + 0x138]
// 00588831  53                   push ebx
// 00588832  8b9e4c010000         mov ebx, dword ptr [esi + 0x14c]
// 00588838  57                   push edi
// 00588839  8dbe54010000         lea edi, [esi + 0x154]
// 0058883f  85c0                 test eax, eax
// 00588841  7404                 je 0x588847
// 00588843  3bc1                 cmp eax, ecx
// 00588845  7406                 je 0x58884d
// 00588847  ff1590288000         call dword ptr [0x802890]
// 0058884d  395f04               cmp dword ptr [edi + 4], ebx
// 00588850  7537                 jne 0x588889
// 00588852  68cc168300           push 0x8316cc
// 00588857  8d4c2460             lea ecx, [esp + 0x60]
// 0058885b  ff1558248000         call dword ptr [0x802458]
// 00588861  8d4c245c             lea ecx, [esp + 0x5c]
// 00588865  51                   push ecx
// 00588866  8d4c247c             lea ecx, [esp + 0x7c]
// 0058886a  c78424ac00000002000000 mov dword ptr [esp + 0xac], 2
// 00588875  e8d614e8ff           call 0x409d50
// 0058887a  68c81b8d00           push 0x8d1bc8
// 0058887f  8d54247c             lea edx, [esp + 0x7c]
// 00588883  52                   push edx
// 00588884  e8038d1100           call 0x6a158c
// 00588889  8a5d00               mov bl, byte ptr [ebp]
// 0058888c  896c2410             mov dword ptr [esp + 0x10], ebp
// 00588890  885c2414             mov byte ptr [esp + 0x14], bl
// 00588894  c6450001             mov byte ptr [ebp], 1
// 00588898  8bcf                 mov ecx, edi
// 0058889a  c78424a800000003000000 mov dword ptr [esp + 0xa8], 3
// 005888a5  e84620eaff           call 0x42a8f0
// 005888aa  8b08                 mov ecx, dword ptr [eax]
// 005888ac  e85ffeffff           call 0x588710
// 005888b1  8b4f04               mov ecx, dword ptr [edi + 4]
// 005888b4  8b07                 mov eax, dword ptr [edi]
// 005888b6  898e60010000         mov dword ptr [esi + 0x160], ecx
// 005888bc  8bcf                 mov ecx, edi
// 005888be  89865c010000         mov dword ptr [esi + 0x15c], eax
// 005888c4  e807eaffff           call 0x5872d0
// 005888c9  8b8c24a0000000       mov ecx, dword ptr [esp + 0xa0]
// 005888d0  5f                   pop edi
// 005888d1  885d00               mov byte ptr [ebp], bl
// 005888d4  5b                   pop ebx
// 005888d5  5e                   pop esi
// 005888d6  5d                   pop ebp
// 005888d7  64890d00000000       mov dword ptr fs:[0], ecx
// 005888de  81c49c000000         add esp, 0x9c
// 005888e4  c3                   ret 

struct String;

extern void (__thiscall *construct_string)(String *, const char *);
extern void (__cdecl *invalid_parameter_noinfo)();

struct String
{
    char storage[28];
    String(const char *);
    ~String();
};

inline String::String(const char *text)
{
    construct_string(this, text);
}

struct HistoryError
{
    char storage[40];
    HistoryError(const String &);
    HistoryError(const HistoryError &);
    ~HistoryError();
};

struct Change
{
    void play();
};

struct Iterator
{
    void *owner;
    void *position;
    Change **dereference();
    void advance();
    bool equals(const Iterator &) const;
};

inline bool Iterator::equals(const Iterator &other) const
{
    if (!owner || owner != other.owner)
        invalid_parameter_noinfo();
    return position == other.position;
}

struct RestoreFlag
{
    bool *flag;
    bool previous;
    RestoreFlag(bool &);
    ~RestoreFlag();
};

inline RestoreFlag::RestoreFlag(bool &value)
    : flag(&value), previous(value)
{
    value = true;
}

inline RestoreFlag::~RestoreFlag()
{
    *flag = previous;
}

struct History
{
    char padding0[0x138];
    void *owner;
    char padding1[0x10];
    void *end;
    char padding2[4];
    Iterator current;
    Iterator previous;
    bool playing;
    bool enabled;
    void play();
};

void History::play()
{
    if (playing)
        throw HistoryError(String("ChangeHistoryService is currently playing"));

    if (!enabled)
        throw HistoryError(String("ChangeHistoryService is disabled"));

    Iterator finish;
    finish.owner = owner;
    finish.position = end;

    if (current.equals(finish))
        throw HistoryError(String("Attempt to play beyond change history"));

    RestoreFlag restore(playing);
    (*current.dereference())->play();
    previous = current;
    current.advance();
}
