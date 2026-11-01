// from server: 100% by Yeetserama
// roc 2010-06 004419b0  unit: RBX::Soundscape::VSoundId::?$XItem  size: 133 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004419b0
//
// 004419b0  6aff                 push -1
// 004419b2  68b1119800           push 0x9811b1
// 004419b7  64a100000000         mov eax, dword ptr fs:[0]
// 004419bd  50                   push eax
// 004419be  64892500000000       mov dword ptr fs:[0], esp
// 004419c5  83ec24               sub esp, 0x24
// 004419c8  56                   push esi
// 004419c9  8bf1                 mov esi, ecx
// 004419cb  51                   push ecx
// 004419cc  8d44243c             lea eax, [esp + 0x3c]
// 004419d0  8bcc                 mov ecx, esp
// 004419d2  89642408             mov dword ptr [esp + 8], esp
// 004419d6  50                   push eax
// 004419d7  c744243800000000     mov dword ptr [esp + 0x38], 0
// 004419df  ff15c4ce9e00         call dword ptr [0x9ecec4]
// 004419e5  8bce                 mov ecx, esi
// 004419e7  e894783d00           call 0x819280
// 004419ec  8b16                 mov edx, dword ptr [esi]
// 004419ee  8b92e4000000         mov edx, dword ptr [edx + 0xe4]
// 004419f4  8d442408             lea eax, [esp + 8]
// 004419f8  50                   push eax
// 004419f9  8bce                 mov ecx, esi
// 004419fb  ffd2                 call edx
// 004419fd  50                   push eax
// 004419fe  8bce                 mov ecx, esi
// 00441a00  c644243401           mov byte ptr [esp + 0x34], 1
// 00441a05  e816e5ffff           call 0x43ff20
// 00441a0a  8d4c2408             lea ecx, [esp + 8]
// 00441a0e  c644243000           mov byte ptr [esp + 0x30], 0
// 00441a13  ff1500a49e00         call dword ptr [0x9ea400]
// 00441a19  8d4c2438             lea ecx, [esp + 0x38]
// 00441a1d  ff15f0ce9e00         call dword ptr [0x9ecef0]
// 00441a23  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00441a27  64890d00000000       mov dword ptr fs:[0], ecx
// 00441a2e  5e                   pop esi
// 00441a2f  83c430               add esp, 0x30
// 00441a32  c20400               ret 4
// copied from an identical function in another client (function ?fn_ROCX000017_004416e0@S@ns_ROCX000017@@QAEXUCString@2@@Z)

namespace ns_ROCX000017 {
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
    void fn_ROCX000017_004416e0(CString value);
};

void S::fn_ROCX000017_004416e0(CString value)
{
    setValue(value);
    updateValue(getValue());
}
}
