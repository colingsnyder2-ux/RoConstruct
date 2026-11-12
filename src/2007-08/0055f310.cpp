// from server: 100% by EspClaude
// from server: 47% by colin
// roc-flags: /O2 /GS- /EHsc /MD
// roc 2007-08 0055f310  unit: RBX::ClearBackpack  size: 146 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0055f310
//
// 0055f310  64a100000000         mov eax, dword ptr fs:[0]
// 0055f316  6aff                 push -1
// 0055f318  68a9c97500           push 0x75c9a9
// 0055f31d  50                   push eax
// 0055f31e  64892500000000       mov dword ptr fs:[0], esp
// 0055f325  53                   push ebx
// 0055f326  56                   push esi
// 0055f327  57                   push edi
// 0055f328  8bf1                 mov esi, ecx
// 0055f32a  8b7c2438             mov edi, dword ptr [esp + 0x38]
// 0055f32e  85ff                 test edi, edi
// 0055f330  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0055f338  7408                 je 0x55f342
// 0055f33a  8d9f84020000         lea ebx, [edi + 0x284]
// 0055f340  eb02                 jmp 0x55f344
// 0055f342  33db                 xor ebx, ebx
// 0055f344  83ec1c               sub esp, 0x1c
// 0055f347  8d442438             lea eax, [esp + 0x38]
// 0055f34b  8bcc                 mov ecx, esp
// 0055f34d  89642454             mov dword ptr [esp + 0x54], esp
// 0055f351  50                   push eax
// 0055f352  ff159ce67700         call dword ptr [0x77e69c]
// 0055f358  53                   push ebx
// 0055f359  8bce                 mov ecx, esi
// 0055f35b  e8f0580000           call 0x564c50
// 0055f360  c706fc917a00         mov dword ptr [esi], 0x7a91fc
// 0055f366  897e0c               mov dword ptr [esi + 0xc], edi
// 0055f369  897e10               mov dword ptr [esi + 0x10], edi
// 0055f36c  c7461400000000       mov dword ptr [esi + 0x14], 0
// 0055f373  8d4c241c             lea ecx, [esp + 0x1c]
// 0055f377  c7461800000000       mov dword ptr [esi + 0x18], 0
// 0055f37e  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 0055f386  ff15ace67700         call dword ptr [0x77e6ac]
// 0055f38c  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0055f390  5f                   pop edi
// 0055f391  8bc6                 mov eax, esi
// 0055f393  5e                   pop esi
// 0055f394  64890d00000000       mov dword ptr fs:[0], ecx
// 0055f39b  5b                   pop ebx
// 0055f39c  83c40c               add esp, 0xc
// 0055f39f  c22000               ret 0x20

#include <string>

// Verb::Verb(VerbContainer*, std::string) is 0x564c50 (thiscall, string by value).
// Verb is 0xc bytes (vptr, name, container); derived fields at 0xc..0x18.
// The container argument is a null-checked base at +0x284 of the owner.
namespace RBX {

class VerbContainer {
    int field_0;
};

class Verb {
public:
    Verb(VerbContainer* container, std::string text);
    virtual ~Verb();
    virtual bool isEnabled() const;
private:
    int name;
    VerbContainer* container;
};

struct DataModelHead {
    char pad[0x284];
};

class DataModel : public DataModelHead, public VerbContainer {
};

struct ZeroCount {
    int field_0;
    ZeroCount() : field_0(0) {}
};

struct ZeroPair {
    int field_0;
    ZeroCount count;
    ZeroPair() : field_0(0) {}
};

struct OwnerRef {
    DataModel* owner;
    ZeroPair pair;
    OwnerRef(DataModel* d) : owner(d) {}
};

class ClearBackpack : public Verb {
    DataModel* dataModel;
    OwnerRef ref;
public:
    ClearBackpack(std::string text, DataModel* dm);
    virtual bool isEnabled() const;
};

ClearBackpack::ClearBackpack(std::string text, DataModel* dm)
    : Verb(dm, text), dataModel(dm), ref(dm)
{
}

}
