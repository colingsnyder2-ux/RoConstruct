// from server: 100% by EspClaude
// from server: 43% by colin
// roc 2007-08 00463830  unit: RBX::VRunService::?$Listener  size: 139 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00463830
//
// 00463830  6aff                 push -1
// 00463832  682b2e7400           push 0x742e2b
// 00463837  64a100000000         mov eax, dword ptr fs:[0]
// 0046383d  50                   push eax
// 0046383e  51                   push ecx
// 0046383f  56                   push esi
// 00463840  a188518b00           mov eax, dword ptr [0x8b5188]
// 00463845  33c4                 xor eax, esp
// 00463847  50                   push eax
// 00463848  8d44240c             lea eax, [esp + 0xc]
// 0046384c  64a300000000         mov dword ptr fs:[0], eax
// 00463852  8bf1                 mov esi, ecx
// 00463854  89742408             mov dword ptr [esp + 8], esi
// 00463858  c706745b7900         mov dword ptr [esi], 0x795b74
// 0046385e  8b4624               mov eax, dword ptr [esi + 0x24]
// 00463861  85c0                 test eax, eax
// 00463863  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0046386b  742c                 je 0x463899
// 0046386d  83c004               add eax, 4
// 00463870  50                   push eax
// 00463871  ff15e8d27700         call dword ptr [0x77d2e8]
// 00463877  85c0                 test eax, eax
// 00463879  7517                 jne 0x463892
// 0046387b  8b4e24               mov ecx, dword ptr [esi + 0x24]
// 0046387e  e84d45ffff           call 0x457dd0
// 00463883  8b4e24               mov ecx, dword ptr [esi + 0x24]
// 00463886  85c9                 test ecx, ecx
// 00463888  7408                 je 0x463892
// 0046388a  8b01                 mov eax, dword ptr [ecx]
// 0046388c  8b10                 mov edx, dword ptr [eax]
// 0046388e  6a01                 push 1
// 00463890  ffd2                 call edx
// 00463892  c7462400000000       mov dword ptr [esi + 0x24], 0
// 00463899  8d4e04               lea ecx, [esi + 4]
// 0046389c  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 004638a4  ff15ace67700         call dword ptr [0x77e6ac]
// 004638aa  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004638ae  64890d00000000       mov dword ptr fs:[0], ecx
// 004638b5  59                   pop ecx
// 004638b6  5e                   pop esi
// 004638b7  83c410               add esp, 0x10
// 004638ba  c3                   ret 

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

struct String;
extern void (__thiscall *string_destroy)(String*);

struct String
{
    char storage[0x1c];
    ~String();
};

inline String::~String()
{
    string_destroy(this);
}

struct Counted
{
    virtual ~Counted();
    long refs;
    void onLastRelease();
};

struct Listener
{
    virtual ~Listener();
    String name;
    char pad20[4];
    Counted* counted;
};

Listener::~Listener()
{
    if (counted) {
        if (InterlockedDecrement(&counted->refs) == 0) {
            counted->onLastRelease();
            delete counted;
        }
        counted = 0;
    }
}
