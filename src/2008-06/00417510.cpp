// from server: 100% by user
// from server: 98% by king_originala
// roc 2008-06 00417510  unit: std::D::DU?$char_traits::V?$basic_string::?$holder  size: 182 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00417510
//
// 00417510  6aff                 push -1
// 00417512  6818047c00           push 0x7c0418
// 00417517  64a100000000         mov eax, dword ptr fs:[0]
// 0041751d  50                   push eax
// 0041751e  64892500000000       mov dword ptr fs:[0], esp
// 00417525  51                   push ecx
// 00417526  53                   push ebx
// 00417527  56                   push esi
// 00417528  57                   push edi
// 00417529  8bf1                 mov esi, ecx
// 0041752b  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0041752f  33db                 xor ebx, ebx
// 00417531  83ec08               sub esp, 8
// 00417534  891e                 mov dword ptr [esi], ebx
// 00417536  8bc4                 mov eax, esp
// 00417538  895e04               mov dword ptr [esi + 4], ebx
// 0041753b  895e08               mov dword ptr [esi + 8], ebx
// 0041753e  8908                 mov dword ptr [eax], ecx
// 00417540  8b542430             mov edx, dword ptr [esp + 0x30]
// 00417544  895004               mov dword ptr [eax + 4], edx
// 00417547  8b442430             mov eax, dword ptr [esp + 0x30]
// 0041754b  895c2420             mov dword ptr [esp + 0x20], ebx
// 0041754f  89642414             mov dword ptr [esp + 0x14], esp
// 00417553  3bc3                 cmp eax, ebx
// 00417555  740c                 je 0x417563
// 00417557  83c004               add eax, 4
// 0041755a  b901000000           mov ecx, 1
// 0041755f  f00fc108             lock xadd dword ptr [eax], ecx
// 00417563  8b542428             mov edx, dword ptr [esp + 0x28]
// 00417567  52                   push edx
// 00417568  8d4e10               lea ecx, [esi + 0x10]
// 0041756b  e830fdffff           call 0x4172a0
// 00417570  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 00417574  895e20               mov dword ptr [esi + 0x20], ebx
// 00417577  895e24               mov dword ptr [esi + 0x24], ebx
// 0041757a  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 00417582  3bfb                 cmp edi, ebx
// 00417584  742a                 je 0x4175b0
// 00417586  8d4704               lea eax, [edi + 4]
// 00417589  83c9ff               or ecx, 0xffffffff
// 0041758c  f00fc108             lock xadd dword ptr [eax], ecx
// 00417590  751e                 jne 0x4175b0
// 00417592  8b17                 mov edx, dword ptr [edi]
// 00417594  8b4204               mov eax, dword ptr [edx + 4]
// 00417597  8bcf                 mov ecx, edi
// 00417599  ffd0                 call eax
// 0041759b  8d4f08               lea ecx, [edi + 8]
// 0041759e  83caff               or edx, 0xffffffff
// 004175a1  f00fc111             lock xadd dword ptr [ecx], edx
// 004175a5  7509                 jne 0x4175b0
// 004175a7  8b07                 mov eax, dword ptr [edi]
// 004175a9  8b5008               mov edx, dword ptr [eax + 8]
// 004175ac  8bcf                 mov ecx, edi
// 004175ae  ffd2                 call edx
// 004175b0  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004175b4  5f                   pop edi
// 004175b5  8bc6                 mov eax, esi
// 004175b7  5e                   pop esi
// 004175b8  64890d00000000       mov dword ptr fs:[0], ecx
// 004175bf  5b                   pop ebx
// 004175c0  83c410               add esp, 0x10
// 004175c3  c20c00               ret 0xc

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control {
    virtual ~Control();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
};

struct Shared {
    void* pointer;
    Control* control;

    Shared(const Shared&);
    ~Shared();
};

inline Shared::Shared(const Shared& other)
    : pointer(other.pointer), control(other.control)
{
    if (control)
        _InterlockedIncrement(&control->strong);
}

inline Shared::~Shared()
{
    Control* p = control;
    if (p && _InterlockedDecrement(&p->strong) == 0) {
        p->dispose();
        if (_InterlockedDecrement(&p->weak) == 0)
            p->destroy();
    }
}

template<typename T>
class Sibling {
    T* next;
public:
    Sibling() : next(0) {}
};

template<typename T>
class Parent {
    T* first;
    T* last;
public:
    Parent() : first(0), last(0) {}
};

struct __declspec(align(8)) Member {
    char storage[16];
    Member(void*, Shared);
};

struct XmlAttribute;

class XmlElement : public Sibling<XmlElement>, public Parent<XmlElement>, public Member {
    Parent<XmlAttribute> attributes;
public:
    XmlElement(void* tag, Shared handle);
};

XmlElement::XmlElement(void* tag, Shared handle)
    : Member(tag, handle)
{
}
