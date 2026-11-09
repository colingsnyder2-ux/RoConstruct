// from server: 100% by Yeetserama
// roc 2007-08 00441bd0  unit: RBX::VSoundId::?$XItem  size: 145 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00441bd0
//
// 00441bd0  6aff                 push -1
// 00441bd2  68a1f17300           push 0x73f1a1
// 00441bd7  64a100000000         mov eax, dword ptr fs:[0]
// 00441bdd  50                   push eax
// 00441bde  83ec24               sub esp, 0x24
// 00441be1  56                   push esi
// 00441be2  a188518b00           mov eax, dword ptr [0x8b5188]
// 00441be7  33c4                 xor eax, esp
// 00441be9  50                   push eax
// 00441bea  8d44242c             lea eax, [esp + 0x2c]
// 00441bee  64a300000000         mov dword ptr fs:[0], eax
// 00441bf4  8bf1                 mov esi, ecx
// 00441bf6  51                   push ecx
// 00441bf7  8d442440             lea eax, [esp + 0x40]
// 00441bfb  8bcc                 mov ecx, esp
// 00441bfd  8964240c             mov dword ptr [esp + 0xc], esp
// 00441c01  50                   push eax
// 00441c02  c744243c00000000     mov dword ptr [esp + 0x3c], 0
// 00441c0a  ff1574dd7700         call dword ptr [0x77dd74]
// 00441c10  8bce                 mov ecx, esi
// 00441c12  e8e96a2500           call 0x698700
// 00441c17  8b16                 mov edx, dword ptr [esi]
// 00441c19  8b92e4000000         mov edx, dword ptr [edx + 0xe4]
// 00441c1f  8d44240c             lea eax, [esp + 0xc]
// 00441c23  50                   push eax
// 00441c24  8bce                 mov ecx, esi
// 00441c26  ffd2                 call edx
// 00441c28  50                   push eax
// 00441c29  8bce                 mov ecx, esi
// 00441c2b  c644243801           mov byte ptr [esp + 0x38], 1
// 00441c30  e80be8ffff           call 0x440440
// 00441c35  8d4c240c             lea ecx, [esp + 0xc]
// 00441c39  c644243400           mov byte ptr [esp + 0x34], 0
// 00441c3e  ff15ace67700         call dword ptr [0x77e6ac]
// 00441c44  8d4c243c             lea ecx, [esp + 0x3c]
// 00441c48  ff15bcdd7700         call dword ptr [0x77ddbc]
// 00441c4e  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00441c52  64890d00000000       mov dword ptr fs:[0], ecx
// 00441c59  59                   pop ecx
// 00441c5a  5e                   pop esi
// 00441c5b  83c430               add esp, 0x30
// 00441c5e  c20400               ret 4
// copied from an identical function in another client (function ?fn_ROCX000008_004416e0@S@ns_ROCX000008@@QAEXUCString@2@@Z)

namespace ns_ROCX000008 {
struct CString;
struct String;

extern void (__thiscall *copyCString)(CString *, const CString *);
extern void (__thiscall *destroyCString)(CString *);
extern void (__thiscall *destroyString)(String *);

struct CString
{
    char *data;
    __declspec(dllimport) CString(const CString &other);
    __declspec(dllimport) ~CString() throw();
};

struct String
{
    unsigned char storage[32];
    ~String();
};

inline String::~String()
{
    destroyString(this);
}

struct S
{
#define SLOT(n) virtual void slot##n();
    SLOT(0) SLOT(1) SLOT(2) SLOT(3) SLOT(4) SLOT(5)
    SLOT(6) SLOT(7) SLOT(8) SLOT(9) SLOT(10) SLOT(11)
    SLOT(12) SLOT(13) SLOT(14) SLOT(15) SLOT(16) SLOT(17)
    SLOT(18) SLOT(19) SLOT(20) SLOT(21) SLOT(22) SLOT(23)
    SLOT(24) SLOT(25) SLOT(26) SLOT(27) SLOT(28) SLOT(29)
    SLOT(30) SLOT(31) SLOT(32) SLOT(33) SLOT(34) SLOT(35)
    SLOT(36) SLOT(37) SLOT(38) SLOT(39) SLOT(40) SLOT(41)
    SLOT(42) SLOT(43) SLOT(44) SLOT(45) SLOT(46) SLOT(47)
    SLOT(48) SLOT(49) SLOT(50) SLOT(51) SLOT(52) SLOT(53)
    SLOT(54) SLOT(55) SLOT(56)
#undef SLOT
    virtual String getValue();
    void setValue(CString value);
    void updateValue(const String &value);
    void fn_ROCX000008_004416e0(CString value);
};

void S::fn_ROCX000008_004416e0(CString value)
{
    setValue(value);
    updateValue(getValue());
}
}
