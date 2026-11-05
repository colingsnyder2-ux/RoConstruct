// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 004a7000  unit: RBX::VHint::?$FactoryProduct::Creator  size: 167 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004a7000
//
// 004a7000  6aff                 push -1
// 004a7002  68b9fe7c00           push 0x7cfeb9
// 004a7007  64a100000000         mov eax, dword ptr fs:[0]
// 004a700d  50                   push eax
// 004a700e  64892500000000       mov dword ptr fs:[0], esp
// 004a7015  83ec48               sub esp, 0x48
// 004a7018  53                   push ebx
// 004a7019  8b5c245c             mov ebx, dword ptr [esp + 0x5c]
// 004a701d  56                   push esi
// 004a701e  6a01                 push 1
// 004a7020  6a05                 push 5
// 004a7022  8d442410             lea eax, [esp + 0x10]
// 004a7026  33f6                 xor esi, esi
// 004a7028  50                   push eax
// 004a7029  8bcb                 mov ecx, ebx
// 004a702b  89742414             mov dword ptr [esp + 0x14], esi
// 004a702f  e8dce1ffff           call 0x4a5210
// 004a7034  84c0                 test al, al
// 004a7036  7530                 jne 0x4a7068
// 004a7038  68703e8200           push 0x823e70
// 004a703d  8d4c2410             lea ecx, [esp + 0x10]
// 004a7041  ff1558248000         call dword ptr [0x802458]
// 004a7047  8d4c240c             lea ecx, [esp + 0xc]
// 004a704b  51                   push ecx
// 004a704c  8d4c242c             lea ecx, [esp + 0x2c]
// 004a7050  8974245c             mov dword ptr [esp + 0x5c], esi
// 004a7054  e8f72cf6ff           call 0x409d50
// 004a7059  68c81b8d00           push 0x8d1bc8
// 004a705e  8d54242c             lea edx, [esp + 0x2c]
// 004a7062  52                   push edx
// 004a7063  e824a51f00           call 0x6a158c
// 004a7068  57                   push edi
// 004a7069  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 004a706d  e80eec1000           call 0x5b5c80
// 004a7072  8bf0                 mov esi, eax
// 004a7074  8b4610               mov eax, dword ptr [esi + 0x10]
// 004a7077  2b460c               sub eax, dword ptr [esi + 0xc]
// 004a707a  c1f802               sar eax, 2
// 004a707d  3bf8                 cmp edi, eax
// 004a707f  7206                 jb 0x4a7087
// 004a7081  ff1590288000         call dword ptr [0x802890]
// 004a7087  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 004a708a  8b14b9               mov edx, dword ptr [ecx + edi*4]
// 004a708d  8b442468             mov eax, dword ptr [esp + 0x68]
// 004a7091  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 004a7095  5f                   pop edi
// 004a7096  8910                 mov dword ptr [eax], edx
// 004a7098  5e                   pop esi
// 004a7099  8bc3                 mov eax, ebx
// 004a709b  5b                   pop ebx
// 004a709c  64890d00000000       mov dword ptr fs:[0], ecx
// 004a70a3  83c454               add esp, 0x54
// 004a70a6  c3                   ret 

typedef void (__thiscall *StringConstructor)(void*, const char*);
extern StringConstructor constructString;

namespace std {
    template<class T> struct char_traits;
    template<class T> class allocator;

    template<class T, class Traits, class Allocator>
    class basic_string {
        char storage[28];
    public:
        basic_string(const T*);
        ~basic_string();
    };

    template<class T, class Traits, class Allocator>
    inline basic_string<T, Traits, Allocator>::basic_string(const T* text)
    {
        constructString(this, text);
    }

    typedef basic_string<char, char_traits<char>, allocator<char> > string;

    class exception {
        char* message;
        bool owned;
    public:
        virtual ~exception();
    };

    class runtime_error : public exception {
        string message;
    public:
        runtime_error(const string&);
        virtual ~runtime_error();
    };
}

struct BitStream {
    bool readBits(unsigned char*, int, bool);
};

struct BrickColor {
    int value;
};

struct Palette {
    char storage[12];
    BrickColor* first;
    BrickColor* last;
    BrickColor* limit;
};

extern const Palette& __cdecl colorPalette();

typedef void (__cdecl *InvalidParameterHandler)();
extern InvalidParameterHandler invalidParameter;

BitStream& __cdecl readBrickColor(BitStream& stream, BrickColor& color)
{
    unsigned int index = 0;
    if (!stream.readBits(reinterpret_cast<unsigned char*>(&index), 6, true))
        throw std::runtime_error(std::string("BitStream >> BrickColor failed"));

    const unsigned int selected = index;
    const Palette& palette = colorPalette();
    if (selected >= static_cast<unsigned int>(palette.last - palette.first))
        invalidParameter();

    color.value = palette.first[selected].value;
    return stream;
}
