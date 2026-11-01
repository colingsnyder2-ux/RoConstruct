// from server: 73% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 004a4760  unit: VDHTMLWindow::?$BoundFuncDesc  size: 193 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004a4760
//
// 004a4760  6aff                 push -1
// 004a4762  6843797c00           push 0x7c7943
// 004a4767  64a100000000         mov eax, dword ptr fs:[0]
// 004a476d  50                   push eax
// 004a476e  64892500000000       mov dword ptr fs:[0], esp
// 004a4775  51                   push ecx
// 004a4776  8b442428             mov eax, dword ptr [esp + 0x28]
// 004a477a  53                   push ebx
// 004a477b  56                   push esi
// 004a477c  57                   push edi
// 004a477d  8bf1                 mov esi, ecx
// 004a477f  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 004a4783  50                   push eax
// 004a4784  51                   push ecx
// 004a4785  89742414             mov dword ptr [esp + 0x14], esi
// 004a4789  e812a4ffff           call 0x49eba0
// 004a478e  50                   push eax
// 004a478f  8bce                 mov ecx, esi
// 004a4791  e8fa0f0f00           call 0x595790
// 004a4796  8b542420             mov edx, dword ptr [esp + 0x20]
// 004a479a  8b442424             mov eax, dword ptr [esp + 0x24]
// 004a479e  c744241800000000     mov dword ptr [esp + 0x18], 0
// 004a47a6  c706e4398200         mov dword ptr [esi], 0x8239e4
// 004a47ac  895638               mov dword ptr [esi + 0x38], edx
// 004a47af  89463c               mov dword ptr [esi + 0x3c], eax
// 004a47b2  8d7e40               lea edi, [esi + 0x40]
// 004a47b5  e806840c00           call 0x56cbc0
// 004a47ba  6a08                 push 8
// 004a47bc  8907                 mov dword ptr [edi], eax
// 004a47be  e85dc11f00           call 0x6a0920
// 004a47c3  83c404               add esp, 4
// 004a47c6  85c0                 test eax, eax
// 004a47c8  740f                 je 0x4a47d9
// 004a47ca  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 004a47ce  c700cc068100         mov dword ptr [eax], 0x8106cc
// 004a47d4  894804               mov dword ptr [eax + 4], ecx
// 004a47d7  eb02                 jmp 0x4a47db
// 004a47d9  33c0                 xor eax, eax
// 004a47db  894704               mov dword ptr [edi + 4], eax
// 004a47de  c644241801           mov byte ptr [esp + 0x18], 1
// 004a47e3  8d5e14               lea ebx, [esi + 0x14]
// 004a47e6  e865020f00           call 0x594a50
// 004a47eb  57                   push edi
// 004a47ec  8903                 mov dword ptr [ebx], eax
// 004a47ee  e8cd830c00           call 0x56cbc0
// 004a47f3  8b542430             mov edx, dword ptr [esp + 0x30]
// 004a47f7  50                   push eax
// 004a47f8  6aff                 push -1
// 004a47fa  52                   push edx
// 004a47fb  e890f70a00           call 0x553f90
// 004a4800  83c408               add esp, 8
// 004a4803  50                   push eax
// 004a4804  8bcb                 mov ecx, ebx
// 004a4806  e835030f00           call 0x594b40
// 004a480b  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004a480f  5f                   pop edi
// 004a4810  8bc6                 mov eax, esi
// 004a4812  5e                   pop esi
// 004a4813  5b                   pop ebx
// 004a4814  64890d00000000       mov dword ptr fs:[0], ecx
// 004a481b  83c410               add esp, 0x10
// 004a481e  c21800               ret 0x18

typedef unsigned int uint;

void* __cdecl operator new(uint);
extern void* __stdcall getBaseType(uint, uint);
extern void* __cdecl getHolderType();
extern void* __cdecl getMemberType();
extern void* __cdecl makeValue(uint, int);

struct Member {
    void* type;
    void set(void*, void*, void*);
};

struct Base {
    unsigned char reserved0[16];
    Member member;
    unsigned char reserved1[32];

    Base(void*);
    virtual ~Base();
};

struct Callback {
    uint value;

    Callback(uint);
    virtual ~Callback();
};

inline Callback::Callback(uint v) : value(v) {}

struct Holder {
    void* type;
    Callback* callback;

    Holder(uint);
    ~Holder();
};

inline Holder::Holder(uint v)
    : type(getHolderType()), callback(new Callback(v)) {}

struct S : Base {
    uint first;
    uint second;
    Holder holder;

    S(uint, uint, uint, uint, uint, uint);
    virtual ~S();
};

S::S(uint a, uint b, uint c, uint d, uint e, uint f)
    : Base(getBaseType(c, f)), first(a), second(b), holder(e)
{
    member.type = getMemberType();
    member.set(makeValue(d, -1), getHolderType(), &holder);
}
