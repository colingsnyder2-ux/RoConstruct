// from server: 100% by colin
// from server: 93% by king_originala
// roc 2008-06 004416e0  unit: RBX::Soundscape::VSoundId::?$XItem  size: 133 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004416e0
//
// 004416e0  6aff                 push -1
// 004416e2  68110b7c00           push 0x7c0b11
// 004416e7  64a100000000         mov eax, dword ptr fs:[0]
// 004416ed  50                   push eax
// 004416ee  64892500000000       mov dword ptr fs:[0], esp
// 004416f5  83ec24               sub esp, 0x24
// 004416f8  56                   push esi
// 004416f9  8bf1                 mov esi, ecx
// 004416fb  51                   push ecx
// 004416fc  8d44243c             lea eax, [esp + 0x3c]
// 00441700  8bcc                 mov ecx, esp
// 00441702  89642408             mov dword ptr [esp + 8], esp
// 00441706  50                   push eax
// 00441707  c744243800000000     mov dword ptr [esp + 0x38], 0
// 0044170f  ff15d43e8000         call dword ptr [0x803ed4]
// 00441715  8bce                 mov ecx, esi
// 00441717  e8a4032d00           call 0x711ac0
// 0044171c  8b16                 mov edx, dword ptr [esi]
// 0044171e  8b92e4000000         mov edx, dword ptr [edx + 0xe4]
// 00441724  8d442408             lea eax, [esp + 8]
// 00441728  50                   push eax
// 00441729  8bce                 mov ecx, esi
// 0044172b  ffd2                 call edx
// 0044172d  50                   push eax
// 0044172e  8bce                 mov ecx, esi
// 00441730  c644243401           mov byte ptr [esp + 0x34], 1
// 00441735  e886cdffff           call 0x43e4c0
// 0044173a  8d4c2408             lea ecx, [esp + 8]
// 0044173e  c644243000           mov byte ptr [esp + 0x30], 0
// 00441743  ff1568248000         call dword ptr [0x802468]
// 00441749  8d4c2438             lea ecx, [esp + 0x38]
// 0044174d  ff15143f8000         call dword ptr [0x803f14]
// 00441753  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00441757  64890d00000000       mov dword ptr fs:[0], ecx
// 0044175e  5e                   pop esi
// 0044175f  83c430               add esp, 0x30
// 00441762  c20400               ret 4

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
    void func_004416e0(CString value);
};

void S::func_004416e0(CString value)
{
    setValue(value);
    updateValue(getValue());
}
