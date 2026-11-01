// from server: 100% by colin
// from server: 94% by king_originala
// roc 2008-06 0046a710  unit: CWebToolbox  size: 138 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0046a710
//
// 0046a710  6aff                 push -1
// 0046a712  6842387c00           push 0x7c3842
// 0046a717  64a100000000         mov eax, dword ptr fs:[0]
// 0046a71d  50                   push eax
// 0046a71e  64892500000000       mov dword ptr fs:[0], esp
// 0046a725  83ec08               sub esp, 8
// 0046a728  56                   push esi
// 0046a729  8bf1                 mov esi, ecx
// 0046a72b  e8a0632300           call 0x6a0ad0
// 0046a730  8d442408             lea eax, [esp + 8]
// 0046a734  50                   push eax
// 0046a735  e896b9f9ff           call 0x4060d0
// 0046a73a  6824c78100           push 0x81c724
// 0046a73f  50                   push eax
// 0046a740  8d4c2410             lea ecx, [esp + 0x10]
// 0046a744  51                   push ecx
// 0046a745  c744242400000000     mov dword ptr [esp + 0x24], 0
// 0046a74d  e80e3afaff           call 0x40e160
// 0046a752  83c410               add esp, 0x10
// 0046a755  8d4c2408             lea ecx, [esp + 8]
// 0046a759  c644241402           mov byte ptr [esp + 0x14], 2
// 0046a75e  ff15143f8000         call dword ptr [0x803f14]
// 0046a764  6a00                 push 0
// 0046a766  6a00                 push 0
// 0046a768  6a00                 push 0
// 0046a76a  6a00                 push 0
// 0046a76c  6a00                 push 0
// 0046a76e  8d4c2418             lea ecx, [esp + 0x18]
// 0046a772  ff15e03e8000         call dword ptr [0x803ee0]
// 0046a778  50                   push eax
// 0046a779  8bce                 mov ecx, esi
// 0046a77b  e8fa612300           call 0x6a097a
// 0046a780  8d4c2404             lea ecx, [esp + 4]
// 0046a784  ff15143f8000         call dword ptr [0x803f14]
// 0046a78a  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0046a78e  5e                   pop esi
// 0046a78f  64890d00000000       mov dword ptr fs:[0], ecx
// 0046a796  83c414               add esp, 0x14
// 0046a799  c3                   ret 

typedef void (__thiscall *StringDestructor)(void*);
typedef const char* (__thiscall *StringConversion)(const void*);

extern StringDestructor destroyString;
extern StringConversion convertString;

struct String
{
    void* data;

    ~String();
    operator const char*() const;
};

inline String::~String()
{
    destroyString(this);
}

inline String::operator const char*() const
{
    return convertString(this);
}

struct ImportedString
{
    void* data;

    __declspec(dllimport) ~ImportedString() throw();
    operator const char*() const;
};

inline ImportedString::operator const char*() const
{
    return convertString(this);
}

extern String __cdecl makeString();
extern ImportedString __cdecl concatenate(const String&, const char*);

struct CWebToolbox
{
    void prepare();
    void navigate(const char*, int, int, int, int, int);
    void open();
};

void CWebToolbox::open()
{
    prepare();
    const ImportedString& address = concatenate(makeString(), "/IDE/ClientToolbox.aspx");
    navigate(address, 0, 0, 0, 0, 0);
}
