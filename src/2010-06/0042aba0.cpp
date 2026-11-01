// from server: 100% by Yeetserama
// roc 2010-06 0042aba0  unit: CSelectionPropGrid  size: 448 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0042aba0
//
// 0042aba0  83ec08               sub esp, 8
// 0042aba3  53                   push ebx
// 0042aba4  56                   push esi
// 0042aba5  8bd9                 mov ebx, ecx
// 0042aba7  8bb3ec000000         mov esi, dword ptr [ebx + 0xec]
// 0042abad  6880000000           push 0x80
// 0042abb2  680052a000           push 0xa05200
// 0042abb7  8bce                 mov ecx, esi
// 0042abb9  e892e83900           call 0x7c9450
// 0042abbe  85c0                 test eax, eax
// 0042abc0  750a                 jne 0x42abcc
// 0042abc2  5e                   pop esi
// 0042abc3  32c0                 xor al, al
// 0042abc5  5b                   pop ebx
// 0042abc6  83c408               add esp, 8
// 0042abc9  c20400               ret 4
// 0042abcc  57                   push edi
// 0042abcd  6a00                 push 0
// 0042abcf  6800170000           push 0x1700
// 0042abd4  8bc8                 mov ecx, eax
// 0042abd6  e875dc3800           call 0x7b8850
// 0042abdb  6a00                 push 0
// 0042abdd  6a00                 push 0
// 0042abdf  68f451a000           push 0xa051f4
// 0042abe4  8bce                 mov ecx, esi
// 0042abe6  e865ea3900           call 0x7c9650
// 0042abeb  8944240c             mov dword ptr [esp + 0xc], eax
// 0042abef  85c0                 test eax, eax
// 0042abf1  0f845e010000         je 0x42ad55
// 0042abf7  0fb67c2418           movzx edi, byte ptr [esp + 0x18]
// 0042abfc  8b10                 mov edx, dword ptr [eax]
// 0042abfe  57                   push edi
// 0042abff  8bc8                 mov ecx, eax
// 0042ac01  8b8254010000         mov eax, dword ptr [edx + 0x154]
// 0042ac07  6880000000           push 0x80
// 0042ac0c  ffd0                 call eax
// 0042ac0e  85c0                 test eax, eax
// 0042ac10  0f843f010000         je 0x42ad55
// 0042ac16  6a00                 push 0
// 0042ac18  6a00                 push 0
// 0042ac1a  68ec51a000           push 0xa051ec
// 0042ac1f  8bce                 mov ecx, esi
// 0042ac21  e82aea3900           call 0x7c9650
// 0042ac26  89442410             mov dword ptr [esp + 0x10], eax
// 0042ac2a  85c0                 test eax, eax
// 0042ac2c  0f8423010000         je 0x42ad55
// 0042ac32  8b10                 mov edx, dword ptr [eax]
// 0042ac34  57                   push edi
// 0042ac35  8bc8                 mov ecx, eax
// 0042ac37  8b8254010000         mov eax, dword ptr [edx + 0x154]
// 0042ac3d  6887000000           push 0x87
// 0042ac42  ffd0                 call eax
// 0042ac44  85c0                 test eax, eax
// 0042ac46  0f8409010000         je 0x42ad55
// 0042ac4c  55                   push ebp
// 0042ac4d  6a00                 push 0
// 0042ac4f  6a00                 push 0
// 0042ac51  68e451a000           push 0xa051e4
// 0042ac56  8bce                 mov ecx, esi
// 0042ac58  e8f3e93900           call 0x7c9650
// 0042ac5d  8be8                 mov ebp, eax
// 0042ac5f  85ed                 test ebp, ebp
// 0042ac61  0f84e2000000         je 0x42ad49
// 0042ac67  8b5500               mov edx, dword ptr [ebp]
// 0042ac6a  8b8254010000         mov eax, dword ptr [edx + 0x154]
// 0042ac70  57                   push edi
// 0042ac71  6889000000           push 0x89
// 0042ac76  8bcd                 mov ecx, ebp
// 0042ac78  ffd0                 call eax
// 0042ac7a  85c0                 test eax, eax
// 0042ac7c  0f84c7000000         je 0x42ad49
// 0042ac82  6a00                 push 0
// 0042ac84  6a00                 push 0
// 0042ac86  68dc51a000           push 0xa051dc
// 0042ac8b  8bce                 mov ecx, esi
// 0042ac8d  e8bee93900           call 0x7c9650
// 0042ac92  85c0                 test eax, eax
// 0042ac94  0f84af000000         je 0x42ad49
// 0042ac9a  8b10                 mov edx, dword ptr [eax]
// 0042ac9c  57                   push edi
// 0042ac9d  8bc8                 mov ecx, eax
// 0042ac9f  8b8254010000         mov eax, dword ptr [edx + 0x154]
// 0042aca5  6891000000           push 0x91
// 0042acaa  ffd0                 call eax
// 0042acac  85c0                 test eax, eax
// 0042acae  0f8495000000         je 0x42ad49
// 0042acb4  6a00                 push 0
// 0042acb6  6a01                 push 1
// 0042acb8  68d451a000           push 0xa051d4
// 0042acbd  8bce                 mov ecx, esi
// 0042acbf  e88ce93900           call 0x7c9650
// 0042acc4  8bf8                 mov edi, eax
// 0042acc6  85ff                 test edi, edi
// 0042acc8  747f                 je 0x42ad49
// 0042acca  0fb644241c           movzx eax, byte ptr [esp + 0x1c]
// 0042accf  8b17                 mov edx, dword ptr [edi]
// 0042acd1  50                   push eax
// 0042acd2  8b8254010000         mov eax, dword ptr [edx + 0x154]
// 0042acd8  6896000000           push 0x96
// 0042acdd  8bcf                 mov ecx, edi
// 0042acdf  ffd0                 call eax
// 0042ace1  85c0                 test eax, eax
// 0042ace3  7464                 je 0x42ad49
// 0042ace5  6a73                 push 0x73
// 0042ace7  8bcf                 mov ecx, edi
// 0042ace9  e872a83900           call 0x7c5560
// 0042acee  8b17                 mov edx, dword ptr [edi]
// 0042acf0  8b8264010000         mov eax, dword ptr [edx + 0x164]
// 0042acf6  6a00                 push 0
// 0042acf8  8bcf                 mov ecx, edi
// 0042acfa  ffd0                 call eax
// 0042acfc  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0042ad00  51                   push ecx
// 0042ad01  55                   push ebp
// 0042ad02  8bcb                 mov ecx, ebx
// 0042ad04  e827faffff           call 0x42a730
// 0042ad09  8b542414             mov edx, dword ptr [esp + 0x14]
// 0042ad0d  55                   push ebp
// 0042ad0e  52                   push edx
// 0042ad0f  8bcb                 mov ecx, ebx
// 0042ad11  e81afaffff           call 0x42a730
// 0042ad16  6a1a                 push 0x1a
// 0042ad18  6868dab700           push 0xb7da68
// 0042ad1d  8bce                 mov ecx, esi
// 0042ad1f  e81c103a00           call 0x7cbd40
// 0042ad24  8b4e74               mov ecx, dword ptr [esi + 0x74]
// 0042ad27  b801000000           mov eax, 1
// 0042ad2c  5d                   pop ebp
// 0042ad2d  894120               mov dword ptr [ecx + 0x20], eax
// 0042ad30  c705d462be0094110000 mov dword ptr [0xbe62d4], 0x1194
// 0042ad3a  8b5674               mov edx, dword ptr [esi + 0x74]
// 0042ad3d  5f                   pop edi
// 0042ad3e  5e                   pop esi
// 0042ad3f  89422c               mov dword ptr [edx + 0x2c], eax
// 0042ad42  5b                   pop ebx
// 0042ad43  83c408               add esp, 8
// 0042ad46  c20400               ret 4
// 0042ad49  5d                   pop ebp
// 0042ad4a  5f                   pop edi
// 0042ad4b  5e                   pop esi
// 0042ad4c  32c0                 xor al, al
// 0042ad4e  5b                   pop ebx
// 0042ad4f  83c408               add esp, 8
// 0042ad52  c20400               ret 4
// 0042ad55  5f                   pop edi
// 0042ad56  5e                   pop esi
// 0042ad57  32c0                 xor al, al
// 0042ad59  5b                   pop ebx
// 0042ad5a  83c408               add esp, 8
// 0042ad5d  c20400               ret 4
// copied from an identical function in another client (function ?f@S@ns_ROCX000003@@QAE_NE@Z)

namespace ns_ROCX000003 {
// from server: 100% by king_originala
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
