// from server: 100% by Xemicl
// roc 2012-06 004b0d80  unit: CWebToolbox  size: 138 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004b0d80
//
// 004b0d80  6aff                 push -1
// 004b0d82  68424aaa00           push 0xaa4a42
// 004b0d87  64a100000000         mov eax, dword ptr fs:[0]
// 004b0d8d  50                   push eax
// 004b0d8e  64892500000000       mov dword ptr fs:[0], esp
// 004b0d95  83ec08               sub esp, 8
// 004b0d98  56                   push esi
// 004b0d99  8bf1                 mov esi, ecx
// 004b0d9b  e8c4174d00           call 0x982564
// 004b0da0  8d442408             lea eax, [esp + 8]
// 004b0da4  50                   push eax
// 004b0da5  e82645f6ff           call 0x4152d0
// 004b0daa  68b838b600           push 0xb638b8
// 004b0daf  50                   push eax
// 004b0db0  8d4c2410             lea ecx, [esp + 0x10]
// 004b0db4  51                   push ecx
// 004b0db5  c744242400000000     mov dword ptr [esp + 0x24], 0
// 004b0dbd  e8de4bf6ff           call 0x4159a0
// 004b0dc2  83c410               add esp, 0x10
// 004b0dc5  8d4c2408             lea ecx, [esp + 8]
// 004b0dc9  c644241402           mov byte ptr [esp + 0x14], 2
// 004b0dce  ff15d047b200         call dword ptr [0xb247d0]
// 004b0dd4  6a00                 push 0
// 004b0dd6  6a00                 push 0
// 004b0dd8  6a00                 push 0
// 004b0dda  6a00                 push 0
// 004b0ddc  6a00                 push 0
// 004b0dde  8d4c2418             lea ecx, [esp + 0x18]
// 004b0de2  ff159847b200         call dword ptr [0xb24798]
// 004b0de8  50                   push eax
// 004b0de9  8bce                 mov ecx, esi
// 004b0deb  e806164d00           call 0x9823f6
// 004b0df0  8d4c2404             lea ecx, [esp + 4]
// 004b0df4  ff15d047b200         call dword ptr [0xb247d0]
// 004b0dfa  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004b0dfe  5e                   pop esi
// 004b0dff  64890d00000000       mov dword ptr fs:[0], ecx
// 004b0e06  83c414               add esp, 0x14
// 004b0e09  c3                   ret 
// copied from an identical function in another client (function ?open@CWebToolbox@ns_ROCX000029@@QAEXXZ)

namespace ns_ROCX000029 {
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
}