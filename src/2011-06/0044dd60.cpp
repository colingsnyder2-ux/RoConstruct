// from server: 100% by Yeetserama
// roc 2011-06 0044dd60  unit: RBX::Soundscape::VSoundId::?$XItem  size: 133 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0044dd60
//
// 0044dd60  6aff                 push -1
// 0044dd62  68911a9d00           push 0x9d1a91
// 0044dd67  64a100000000         mov eax, dword ptr fs:[0]
// 0044dd6d  50                   push eax
// 0044dd6e  64892500000000       mov dword ptr fs:[0], esp
// 0044dd75  83ec24               sub esp, 0x24
// 0044dd78  56                   push esi
// 0044dd79  8bf1                 mov esi, ecx
// 0044dd7b  51                   push ecx
// 0044dd7c  8d44243c             lea eax, [esp + 0x3c]
// 0044dd80  8bcc                 mov ecx, esp
// 0044dd82  89642408             mov dword ptr [esp + 8], esp
// 0044dd86  50                   push eax
// 0044dd87  c744243800000000     mov dword ptr [esp + 0x38], 0
// 0044dd8f  ff15e42da400         call dword ptr [0xa42de4]
// 0044dd95  8bce                 mov ecx, esi
// 0044dd97  e804bd4200           call 0x879aa0
// 0044dd9c  8b16                 mov edx, dword ptr [esi]
// 0044dd9e  8b92e4000000         mov edx, dword ptr [edx + 0xe4]
// 0044dda4  8d442408             lea eax, [esp + 8]
// 0044dda8  50                   push eax
// 0044dda9  8bce                 mov ecx, esi
// 0044ddab  ffd2                 call edx
// 0044ddad  50                   push eax
// 0044ddae  8bce                 mov ecx, esi
// 0044ddb0  c644243401           mov byte ptr [esp + 0x34], 1
// 0044ddb5  e836ecffff           call 0x44c9f0
// 0044ddba  8d4c2408             lea ecx, [esp + 8]
// 0044ddbe  c644243000           mov byte ptr [esp + 0x30], 0
// 0044ddc3  ff15d004a400         call dword ptr [0xa404d0]
// 0044ddc9  8d4c2438             lea ecx, [esp + 0x38]
// 0044ddcd  ff15082ea400         call dword ptr [0xa42e08]
// 0044ddd3  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0044ddd7  64890d00000000       mov dword ptr fs:[0], ecx
// 0044ddde  5e                   pop esi
// 0044dddf  83c430               add esp, 0x30
// 0044dde2  c20400               ret 4
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
