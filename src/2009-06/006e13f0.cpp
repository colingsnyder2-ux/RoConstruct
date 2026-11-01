// from server: 100% by EspClaude
// from server: 100% by colin
// roc 2008-06 00650560  unit: RBX::ChatOutput  size: 246 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00650560
//
// 00650560  6aff                 push -1
// 00650562  6898b57d00           push 0x7db598
// 00650567  64a100000000         mov eax, dword ptr fs:[0]
// 0065056d  50                   push eax
// 0065056e  64892500000000       mov dword ptr fs:[0], esp
// 00650575  83ec10               sub esp, 0x10
// 00650578  53                   push ebx
// 00650579  55                   push ebp
// 0065057a  56                   push esi
// 0065057b  8bf1                 mov esi, ecx
// 0065057d  57                   push edi
// 0065057e  8d7e0c               lea edi, [esi + 0xc]
// 00650581  8bcf                 mov ecx, edi
// 00650583  89742410             mov dword ptr [esp + 0x10], esi
// 00650587  ff1560248000         call dword ptr [0x802460]
// 0065058d  8b442434             mov eax, dword ptr [esp + 0x34]
// 00650591  50                   push eax
// 00650592  8d4e28               lea ecx, [esi + 0x28]
// 00650595  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 0065059d  ff155c248000         call dword ptr [0x80245c]
// 006505a3  d9442438             fld dword ptr [esp + 0x38]
// 006505a7  8b6c2430             mov ebp, dword ptr [esp + 0x30]
// 006505ab  d95e44               fstp dword ptr [esi + 0x44]
// 006505ae  8d8d10010000         lea ecx, [ebp + 0x110]
// 006505b4  51                   push ecx
// 006505b5  8bcf                 mov ecx, edi
// 006505b7  c644242c01           mov byte ptr [esp + 0x2c], 1
// 006505bc  c6464800             mov byte ptr [esi + 0x48], 0
// 006505c0  ff150c248000         call dword ptr [0x80240c]
// 006505c6  55                   push ebp
// 006505c7  e884a5e4ff           call 0x49ab50
// 006505cc  8bd8                 mov ebx, eax
// 006505ce  83c404               add esp, 4
// 006505d1  85db                 test ebx, ebx
// 006505d3  7448                 je 0x65061d
// 006505d5  8bcb                 mov ecx, ebx
// 006505d7  e8945af8ff           call 0x5d6070
// 006505dc  84c0                 test al, al
// 006505de  743d                 je 0x65061d
// 006505e0  80bd7c01000000       cmp byte ptr [ebp + 0x17c], 0
// 006505e7  752d                 jne 0x650616
// 006505e9  55                   push ebp
// 006505ea  8bcb                 mov ecx, ebx
// 006505ec  e8af58f8ff           call 0x5d5ea0
// 006505f1  85c0                 test eax, eax
// 006505f3  741a                 je 0x65060f
// 006505f5  8d542414             lea edx, [esp + 0x14]
// 006505f9  52                   push edx
// 006505fa  8d4c2438             lea ecx, [esp + 0x38]
// 006505fe  51                   push ecx
// 006505ff  8bc8                 mov ecx, eax
// 00650601  e83a58f1ff           call 0x565e40
// 00650606  8bc8                 mov ecx, eax
// 00650608  e8635cf6ff           call 0x5b6270
// 0065060d  eb20                 jmp 0x65062f
// 0065060f  e8dc43ecff           call 0x5149f0
// 00650614  eb19                 jmp 0x65062f
// 00650616  e84544ecff           call 0x514a60
// 0065061b  eb12                 jmp 0x65062f
// 0065061d  57                   push edi
// 0065061e  e83d990100           call 0x669f60
// 00650623  83e007               and eax, 7
// 00650626  50                   push eax
// 00650627  e804f2ffff           call 0x64f830
// 0065062c  83c408               add esp, 8
// 0065062f  d900                 fld dword ptr [eax]
// 00650631  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00650635  d91e                 fstp dword ptr [esi]
// 00650637  5f                   pop edi
// 00650638  d94004               fld dword ptr [eax + 4]
// 0065063b  d95e04               fstp dword ptr [esi + 4]
// 0065063e  d94008               fld dword ptr [eax + 8]
// 00650641  8bc6                 mov eax, esi
// 00650643  d95e08               fstp dword ptr [esi + 8]
// 00650646  5e                   pop esi
// 00650647  5d                   pop ebp
// 00650648  5b                   pop ebx
// 00650649  64890d00000000       mov dword ptr fs:[0], ecx
// 00650650  83c41c               add esp, 0x1c
// 00650653  c20c00               ret 0xc

struct String;

extern String& (__thiscall* stringAssign)(String*, const String&);

struct String {
    unsigned int proxy;
    union {
        char buffer[16];
        char* pointer;
    };
    unsigned int length;
    unsigned int capacity;

    __declspec(dllimport) String();
    __declspec(dllimport) String(const String&);
    ~String();
    String& operator=(const String&);
};





__forceinline String& String::operator=(const String& other)
{
    return stringAssign(this, other);
}

struct Color {
    float r, g, b;
};

struct BrickColor {
    int value;
    Color* color(Color*) const;
};

struct Team {
    BrickColor getTeamColor() const;
};

struct Player {
    char padding[0x54];
    String name;
    char padding2[0x28];
    bool neutral;
};

struct ServiceProvider {
    bool teamsEnabled();
    Team* getTeamFromPlayer(Player*);
};

extern ServiceProvider* __cdecl func_0049ab50(Player*);
extern const Color& __cdecl func_005149f0();
extern const Color& __cdecl func_00514a60();
extern unsigned int __cdecl func_00669f60(const String&);
extern const Color& __cdecl func_0064f830(unsigned int);

struct ChatOutput {
    Color color;
    String name;
    String text;
    float time;
    bool flag;

    ChatOutput(Player*, const String&, float);
};

ChatOutput::ChatOutput(Player* player, const String& message, float timestamp)
    : name(), text(message), time(timestamp), flag(false)
{
    name = player->name;

    Color temporary;
    const Color* result;
    ServiceProvider* service = func_0049ab50(player);

    if (service && service->teamsEnabled()) {
        if (!player->neutral) {
            Team* team = service->getTeamFromPlayer(player);
            if (team)
                result = team->getTeamColor().color(&temporary);
            else
                result = &func_005149f0();
        } else {
            result = &func_00514a60();
        }
    } else {
        result = &func_0064f830(func_00669f60(name) & 7);
    }

    color.r = result->r;
    color.g = result->g;
    color.b = result->b;
}
