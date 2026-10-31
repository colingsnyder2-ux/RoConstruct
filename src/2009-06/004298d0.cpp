// from server: 100% by EspClaude
// roc 2009-06 004298d0  unit: CSelectionPropGrid  size: 448 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004298d0
//
// 004298d0  83ec08               sub esp, 8
// 004298d3  53                   push ebx
// 004298d4  56                   push esi
// 004298d5  8bd9                 mov ebx, ecx
// 004298d7  8bb3ec000000         mov esi, dword ptr [ebx + 0xec]
// 004298dd  6880000000           push 0x80
// 004298e2  6890178b00           push 0x8b1790
// 004298e7  8bce                 mov ecx, esi
// 004298e9  e8e20d3000           call 0x72a6d0
// 004298ee  85c0                 test eax, eax
// 004298f0  750a                 jne 0x4298fc
// 004298f2  5e                   pop esi
// 004298f3  32c0                 xor al, al
// 004298f5  5b                   pop ebx
// 004298f6  83c408               add esp, 8
// 004298f9  c20400               ret 4
// 004298fc  57                   push edi
// 004298fd  6a00                 push 0
// 004298ff  6800170000           push 0x1700
// 00429904  8bc8                 mov ecx, eax
// 00429906  e8053d3000           call 0x72d610
// 0042990b  6a00                 push 0
// 0042990d  6a00                 push 0
// 0042990f  6884178b00           push 0x8b1784
// 00429914  8bce                 mov ecx, esi
// 00429916  e8b50f3000           call 0x72a8d0
// 0042991b  8944240c             mov dword ptr [esp + 0xc], eax
// 0042991f  85c0                 test eax, eax
// 00429921  0f845e010000         je 0x429a85
// 00429927  0fb67c2418           movzx edi, byte ptr [esp + 0x18]
// 0042992c  8b10                 mov edx, dword ptr [eax]
// 0042992e  57                   push edi
// 0042992f  8bc8                 mov ecx, eax
// 00429931  8b8254010000         mov eax, dword ptr [edx + 0x154]
// 00429937  6880000000           push 0x80
// 0042993c  ffd0                 call eax
// 0042993e  85c0                 test eax, eax
// 00429940  0f843f010000         je 0x429a85
// 00429946  6a00                 push 0
// 00429948  6a00                 push 0
// 0042994a  687c178b00           push 0x8b177c
// 0042994f  8bce                 mov ecx, esi
// 00429951  e87a0f3000           call 0x72a8d0
// 00429956  89442410             mov dword ptr [esp + 0x10], eax
// 0042995a  85c0                 test eax, eax
// 0042995c  0f8423010000         je 0x429a85
// 00429962  8b10                 mov edx, dword ptr [eax]
// 00429964  57                   push edi
// 00429965  8bc8                 mov ecx, eax
// 00429967  8b8254010000         mov eax, dword ptr [edx + 0x154]
// 0042996d  6887000000           push 0x87
// 00429972  ffd0                 call eax
// 00429974  85c0                 test eax, eax
// 00429976  0f8409010000         je 0x429a85
// 0042997c  55                   push ebp
// 0042997d  6a00                 push 0
// 0042997f  6a00                 push 0
// 00429981  6874178b00           push 0x8b1774
// 00429986  8bce                 mov ecx, esi
// 00429988  e8430f3000           call 0x72a8d0
// 0042998d  8be8                 mov ebp, eax
// 0042998f  85ed                 test ebp, ebp
// 00429991  0f84e2000000         je 0x429a79
// 00429997  8b5500               mov edx, dword ptr [ebp]
// 0042999a  8b8254010000         mov eax, dword ptr [edx + 0x154]
// 004299a0  57                   push edi
// 004299a1  6889000000           push 0x89
// 004299a6  8bcd                 mov ecx, ebp
// 004299a8  ffd0                 call eax
// 004299aa  85c0                 test eax, eax
// 004299ac  0f84c7000000         je 0x429a79
// 004299b2  6a00                 push 0
// 004299b4  6a00                 push 0
// 004299b6  686c178b00           push 0x8b176c
// 004299bb  8bce                 mov ecx, esi
// 004299bd  e80e0f3000           call 0x72a8d0
// 004299c2  85c0                 test eax, eax
// 004299c4  0f84af000000         je 0x429a79
// 004299ca  8b10                 mov edx, dword ptr [eax]
// 004299cc  57                   push edi
// 004299cd  8bc8                 mov ecx, eax
// 004299cf  8b8254010000         mov eax, dword ptr [edx + 0x154]
// 004299d5  6891000000           push 0x91
// 004299da  ffd0                 call eax
// 004299dc  85c0                 test eax, eax
// 004299de  0f8495000000         je 0x429a79
// 004299e4  6a00                 push 0
// 004299e6  6a01                 push 1
// 004299e8  6864178b00           push 0x8b1764
// 004299ed  8bce                 mov ecx, esi
// 004299ef  e8dc0e3000           call 0x72a8d0
// 004299f4  8bf8                 mov edi, eax
// 004299f6  85ff                 test edi, edi
// 004299f8  747f                 je 0x429a79
// 004299fa  0fb644241c           movzx eax, byte ptr [esp + 0x1c]
// 004299ff  8b17                 mov edx, dword ptr [edi]
// 00429a01  50                   push eax
// 00429a02  8b8254010000         mov eax, dword ptr [edx + 0x154]
// 00429a08  6896000000           push 0x96
// 00429a0d  8bcf                 mov ecx, edi
// 00429a0f  ffd0                 call eax
// 00429a11  85c0                 test eax, eax
// 00429a13  7464                 je 0x429a79
// 00429a15  6a73                 push 0x73
// 00429a17  8bcf                 mov ecx, edi
// 00429a19  e8b2093100           call 0x73a3d0
// 00429a1e  8b17                 mov edx, dword ptr [edi]
// 00429a20  8b8264010000         mov eax, dword ptr [edx + 0x164]
// 00429a26  6a00                 push 0
// 00429a28  8bcf                 mov ecx, edi
// 00429a2a  ffd0                 call eax
// 00429a2c  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00429a30  51                   push ecx
// 00429a31  55                   push ebp
// 00429a32  8bcb                 mov ecx, ebx
// 00429a34  e817faffff           call 0x429450
// 00429a39  8b542414             mov edx, dword ptr [esp + 0x14]
// 00429a3d  55                   push ebp
// 00429a3e  52                   push edx
// 00429a3f  8bcb                 mov ecx, ebx
// 00429a41  e80afaffff           call 0x429450
// 00429a46  6a1a                 push 0x1a
// 00429a48  6850099e00           push 0x9e0950
// 00429a4d  8bce                 mov ecx, esi
// 00429a4f  e86c353000           call 0x72cfc0
// 00429a54  8b4e74               mov ecx, dword ptr [esi + 0x74]
// 00429a57  b801000000           mov eax, 1
// 00429a5c  5d                   pop ebp
// 00429a5d  894120               mov dword ptr [ecx + 0x20], eax
// 00429a60  c705d053a20094110000 mov dword ptr [0xa253d0], 0x1194
// 00429a6a  8b5674               mov edx, dword ptr [esi + 0x74]
// 00429a6d  5f                   pop edi
// 00429a6e  5e                   pop esi
// 00429a6f  89422c               mov dword ptr [edx + 0x2c], eax
// 00429a72  5b                   pop ebx
// 00429a73  83c408               add esp, 8
// 00429a76  c20400               ret 4
// 00429a79  5d                   pop ebp
// 00429a7a  5f                   pop edi
// 00429a7b  5e                   pop esi
// 00429a7c  32c0                 xor al, al
// 00429a7e  5b                   pop ebx
// 00429a7f  83c408               add esp, 8
// 00429a82  c20400               ret 4
// 00429a85  5f                   pop edi
// 00429a86  5e                   pop esi
// 00429a87  32c0                 xor al, al
// 00429a89  5b                   pop ebx
// 00429a8a  83c408               add esp, 8
// 00429a8d  c20400               ret 4
// copied from an identical function in another client (function ?f@S@ns_ROCX000006@@QAE_NE@Z)

namespace ns_ROCX000006 {
struct Bar
{
#define V(n) virtual void v##n();
    V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9)
    V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19)
    V(20) V(21) V(22) V(23) V(24) V(25) V(26) V(27) V(28) V(29)
    V(30) V(31) V(32) V(33) V(34) V(35) V(36) V(37) V(38) V(39)
    V(40) V(41) V(42) V(43) V(44) V(45) V(46) V(47) V(48) V(49)
    V(50) V(51) V(52) V(53) V(54) V(55) V(56) V(57) V(58) V(59)
    V(60) V(61) V(62) V(63) V(64) V(65) V(66) V(67) V(68) V(69)
    V(70) V(71) V(72) V(73) V(74) V(75) V(76) V(77) V(78) V(79)
    V(80) V(81) V(82) V(83) V(84)
    virtual int Load(unsigned int, int);
    V(86) V(87) V(88)
    virtual void SetVisible(int);
#undef V
    void ApplyFlags(unsigned int, unsigned int);
    void SetPosition(int);
};

struct Options
{
    char pad0[0x20];
    int a;
    char pad1[8];
    int b;
};

struct Bars
{
    char pad[0x74];
    Options* options;

    Bar* SetMenu(const char*, unsigned int);
    Bar* Add(const char*, int, int);
    void f(unsigned int*, int);
};

extern char menuName[];
extern char standardName[];
extern char cameraName[];
extern char mouseName[];
extern char testName[];
extern char commandName[];
extern unsigned int values[];
extern int globalValue;

struct S
{
    char pad[0xec];
    Bars* bars;

    void Link(Bar*, Bar*);
    bool f(unsigned char);
};

bool S::f(unsigned char enabled)
{
    Bars* p = bars;
    Bar* menu = p->SetMenu(menuName, 0x80);
    if (!menu)
        return false;

    menu->ApplyFlags(0x1700, 0);

    Bar* standard = p->Add(standardName, 0, 0);
    if (!standard || !standard->Load(0x80, enabled))
        return false;

    Bar* camera = p->Add(cameraName, 0, 0);
    if (!camera || !camera->Load(0x87, enabled))
        return false;

    Bar* mouse = p->Add(mouseName, 0, 0);
    if (!mouse || !mouse->Load(0x89, enabled))
        return false;

    Bar* test = p->Add(testName, 0, 0);
    if (!test || !test->Load(0x91, enabled))
        return false;

    Bar* command = p->Add(commandName, 1, 0);
    if (!command || !command->Load(0x96, enabled))
        return false;

    command->SetPosition(0x73);
    command->SetVisible(0);
    Link(mouse, standard);
    Link(camera, mouse);
    p->f(values, 0x1a);
    p->options->a = 1;
    globalValue = 0x1194;
    p->options->b = 1;
    return true;
}
}
