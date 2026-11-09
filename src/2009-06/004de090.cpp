// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 004a70b0  unit: RBX::VHint::?$FactoryProduct::Creator  size: 159 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004a70b0
//
// 004a70b0  64a100000000         mov eax, dword ptr fs:[0]
// 004a70b6  6aff                 push -1
// 004a70b8  68b9fe7c00           push 0x7cfeb9
// 004a70bd  50                   push eax
// 004a70be  64892500000000       mov dword ptr fs:[0], esp
// 004a70c5  83ec44               sub esp, 0x44
// 004a70c8  56                   push esi
// 004a70c9  8b74245c             mov esi, dword ptr [esp + 0x5c]
// 004a70cd  57                   push edi
// 004a70ce  8b7c245c             mov edi, dword ptr [esp + 0x5c]
// 004a70d2  56                   push esi
// 004a70d3  57                   push edi
// 004a70d4  81c1540f0000         add ecx, 0xf54
// 004a70da  e891feffff           call 0x4a6f70
// 004a70df  e88cd10a00           call 0x554270
// 004a70e4  3906                 cmp dword ptr [esi], eax
// 004a70e6  744d                 je 0x4a7135
// 004a70e8  6a01                 push 1
// 004a70ea  8d4604               lea eax, [esi + 4]
// 004a70ed  6a18                 push 0x18
// 004a70ef  50                   push eax
// 004a70f0  8bcf                 mov ecx, edi
// 004a70f2  c70000000000         mov dword ptr [eax], 0
// 004a70f8  e813e1ffff           call 0x4a5210
// 004a70fd  84c0                 test al, al
// 004a70ff  753b                 jne 0x4a713c
// 004a7101  68903e8200           push 0x823e90
// 004a7106  8d4c240c             lea ecx, [esp + 0xc]
// 004a710a  ff1558248000         call dword ptr [0x802458]
// 004a7110  8d442408             lea eax, [esp + 8]
// 004a7114  50                   push eax
// 004a7115  8d4c2428             lea ecx, [esp + 0x28]
// 004a7119  c744245800000000     mov dword ptr [esp + 0x58], 0
// 004a7121  e82a2cf6ff           call 0x409d50
// 004a7126  68c81b8d00           push 0x8d1bc8
// 004a712b  8d4c2428             lea ecx, [esp + 0x28]
// 004a712f  51                   push ecx
// 004a7130  e857a41f00           call 0x6a158c
// 004a7135  c7460400000000       mov dword ptr [esi + 4], 0
// 004a713c  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 004a7140  5f                   pop edi
// 004a7141  5e                   pop esi
// 004a7142  64890d00000000       mov dword ptr fs:[0], ecx
// 004a7149  83c450               add esp, 0x50
// 004a714c  c20800               ret 8

extern void (__thiscall *stringConstruct)(void*, const char*);

namespace std {
template<class T> struct char_traits;
template<class T> class allocator;

template<class T, class Traits, class Alloc> class basic_string {
    char storage[28];
public:
    basic_string(const T*);
    ~basic_string();
};

template<class T, class Traits, class Alloc>
__forceinline basic_string<T, Traits, Alloc>::basic_string(const T* text)
{
    stringConstruct(this, text);
}

typedef basic_string<char, char_traits<char>, allocator<char> > string;

class exception {
    const char* message;
    bool owned;
public:
    virtual ~exception();
    virtual const char* what() const;
};

class runtime_error : public exception {
    string message;
public:
    runtime_error(const string&);
    virtual ~runtime_error();
    virtual const char* what() const;
};
}

struct Data {
    const void* scope;
    unsigned int value;
};

struct BitStream {
    bool readBits(void*, int, bool);
};

struct Decoder {
    void read(BitStream*, Data*);
};

extern const void* __cdecl getLocalScope();

struct S {
    char padding[0xEB0];
    Decoder decoder;
    void read(BitStream*, Data*);
};

void S::read(BitStream* stream, Data* data)
{
    decoder.read(stream, data);
    if (data->scope != getLocalScope()) {
        data->value = 0;
        if (!stream->readBits(&data->value, 24, true))
            throw std::runtime_error(
                std::string("BitStream >> RBX::Guid::Data failed"));
    } else {
        data->value = 0;
    }
}
