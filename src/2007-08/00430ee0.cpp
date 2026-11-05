// from server: 98% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 004307e0  unit: CSelectionPropGrid  size: 448 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004307e0
//
// 004307e0  83ec08               sub esp, 8
// 004307e3  53                   push ebx
// 004307e4  56                   push esi
// 004307e5  8bd9                 mov ebx, ecx
// 004307e7  8bb3ec000000         mov esi, dword ptr [ebx + 0xec]
// 004307ed  6880000000           push 0x80
// 004307f2  6808128100           push 0x811208
// 004307f7  8bce                 mov ecx, esi
// 004307f9  e8f2352700           call 0x6a3df0
// 004307fe  85c0                 test eax, eax
// 00430800  750a                 jne 0x43080c
// 00430802  5e                   pop esi
// 00430803  32c0                 xor al, al
// 00430805  5b                   pop ebx
// 00430806  83c408               add esp, 8
// 00430809  c20400               ret 4
// 0043080c  57                   push edi
// 0043080d  6a00                 push 0
// 0043080f  6800170000           push 0x1700
// 00430814  8bc8                 mov ecx, eax
// 00430816  e875482800           call 0x6b5090
// 0043081b  6a00                 push 0
// 0043081d  6a00                 push 0
// 0043081f  68fc118100           push 0x8111fc
// 00430824  8bce                 mov ecx, esi
// 00430826  e8c5372700           call 0x6a3ff0
// 0043082b  8944240c             mov dword ptr [esp + 0xc], eax
// 0043082f  85c0                 test eax, eax
// 00430831  0f845e010000         je 0x430995
// 00430837  0fb67c2418           movzx edi, byte ptr [esp + 0x18]
// 0043083c  8b10                 mov edx, dword ptr [eax]
// 0043083e  57                   push edi
// 0043083f  8bc8                 mov ecx, eax
// 00430841  8b8254010000         mov eax, dword ptr [edx + 0x154]
// 00430847  6880000000           push 0x80
// 0043084c  ffd0                 call eax
// 0043084e  85c0                 test eax, eax
// 00430850  0f843f010000         je 0x430995
// 00430856  6a00                 push 0
// 00430858  6a00                 push 0
// 0043085a  68f4118100           push 0x8111f4
// 0043085f  8bce                 mov ecx, esi
// 00430861  e88a372700           call 0x6a3ff0
// 00430866  89442410             mov dword ptr [esp + 0x10], eax
// 0043086a  85c0                 test eax, eax
// 0043086c  0f8423010000         je 0x430995
// 00430872  8b10                 mov edx, dword ptr [eax]
// 00430874  57                   push edi
// 00430875  8bc8                 mov ecx, eax
// 00430877  8b8254010000         mov eax, dword ptr [edx + 0x154]
// 0043087d  6887000000           push 0x87
// 00430882  ffd0                 call eax
// 00430884  85c0                 test eax, eax
// 00430886  0f8409010000         je 0x430995
// 0043088c  55                   push ebp
// 0043088d  6a00                 push 0
// 0043088f  6a00                 push 0
// 00430891  68ec118100           push 0x8111ec
// 00430896  8bce                 mov ecx, esi
// 00430898  e853372700           call 0x6a3ff0
// 0043089d  8be8                 mov ebp, eax
// 0043089f  85ed                 test ebp, ebp
// 004308a1  0f84e2000000         je 0x430989
// 004308a7  8b5500               mov edx, dword ptr [ebp]
// 004308aa  8b8254010000         mov eax, dword ptr [edx + 0x154]
// 004308b0  57                   push edi
// 004308b1  6889000000           push 0x89
// 004308b6  8bcd                 mov ecx, ebp
// 004308b8  ffd0                 call eax
// 004308ba  85c0                 test eax, eax
// 004308bc  0f84c7000000         je 0x430989
// 004308c2  6a00                 push 0
// 004308c4  6a00                 push 0
// 004308c6  68e4118100           push 0x8111e4
// 004308cb  8bce                 mov ecx, esi
// 004308cd  e81e372700           call 0x6a3ff0
// 004308d2  85c0                 test eax, eax
// 004308d4  0f84af000000         je 0x430989
// 004308da  8b10                 mov edx, dword ptr [eax]
// 004308dc  57                   push edi
// 004308dd  8bc8                 mov ecx, eax
// 004308df  8b8254010000         mov eax, dword ptr [edx + 0x154]
// 004308e5  6891000000           push 0x91
// 004308ea  ffd0                 call eax
// 004308ec  85c0                 test eax, eax
// 004308ee  0f8495000000         je 0x430989
// 004308f4  6a00                 push 0
// 004308f6  6a01                 push 1
// 004308f8  68dc118100           push 0x8111dc
// 004308fd  8bce                 mov ecx, esi
// 004308ff  e8ec362700           call 0x6a3ff0
// 00430904  8bf8                 mov edi, eax
// 00430906  85ff                 test edi, edi
// 00430908  747f                 je 0x430989
// 0043090a  0fb644241c           movzx eax, byte ptr [esp + 0x1c]
// 0043090f  8b17                 mov edx, dword ptr [edi]
// 00430911  50                   push eax
// 00430912  8b8254010000         mov eax, dword ptr [edx + 0x154]
// 00430918  6896000000           push 0x96
// 0043091d  8bcf                 mov ecx, edi
// 0043091f  ffd0                 call eax
// 00430921  85c0                 test eax, eax
// 00430923  7464                 je 0x430989
// 00430925  6a73                 push 0x73
// 00430927  8bcf                 mov ecx, edi
// 00430929  e872152900           call 0x6c1ea0
// 0043092e  8b17                 mov edx, dword ptr [edi]
// 00430930  8b8264010000         mov eax, dword ptr [edx + 0x164]
// 00430936  6a00                 push 0
// 00430938  8bcf                 mov ecx, edi
// 0043093a  ffd0                 call eax
// 0043093c  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00430940  51                   push ecx
// 00430941  55                   push ebp
// 00430942  8bcb                 mov ecx, ebx
// 00430944  e857faffff           call 0x4303a0
// 00430949  8b542414             mov edx, dword ptr [esp + 0x14]
// 0043094d  55                   push ebp
// 0043094e  52                   push edx
// 0043094f  8bcb                 mov ecx, ebx
// 00430951  e84afaffff           call 0x4303a0
// 00430956  6a1a                 push 0x1a
// 00430958  6860ec9200           push 0x92ec60
// 0043095d  8bce                 mov ecx, esi
// 0043095f  e87c5d2700           call 0x6a66e0
// 00430964  8b4e74               mov ecx, dword ptr [esi + 0x74]
// 00430967  b801000000           mov eax, 1
// 0043096c  5d                   pop ebp
// 0043096d  894120               mov dword ptr [ecx + 0x20], eax
// 00430970  c7057c61960094110000 mov dword ptr [0x96617c], 0x1194
// 0043097a  8b5674               mov edx, dword ptr [esi + 0x74]
// 0043097d  5f                   pop edi
// 0043097e  5e                   pop esi
// 0043097f  89422c               mov dword ptr [edx + 0x2c], eax
// 00430982  5b                   pop ebx
// 00430983  83c408               add esp, 8
// 00430986  c20400               ret 4
// 00430989  5d                   pop ebp
// 0043098a  5f                   pop edi
// 0043098b  5e                   pop esi
// 0043098c  32c0                 xor al, al
// 0043098e  5b                   pop ebx
// 0043098f  83c408               add esp, 8
// 00430992  c20400               ret 4
// 00430995  5f                   pop edi
// 00430996  5e                   pop esi
// 00430997  32c0                 xor al, al
// 00430999  5b                   pop ebx
// 0043099a  83c408               add esp, 8
// 0043099d  c20400               ret 4

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
