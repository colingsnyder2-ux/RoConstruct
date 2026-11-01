// from server: 100% by EspClaude
// roc 2009-06 008481e0  unit: RBX::RbxG3D::Material::Level  size: 113 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 008481e0
//
// 008481e0  64a100000000         mov eax, dword ptr fs:[0]
// 008481e6  6aff                 push -1
// 008481e8  68f8c28600           push 0x86c2f8
// 008481ed  50                   push eax
// 008481ee  64892500000000       mov dword ptr fs:[0], esp
// 008481f5  8b442410             mov eax, dword ptr [esp + 0x10]
// 008481f9  83c10c               add ecx, 0xc
// 008481fc  50                   push eax
// 008481fd  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00848205  e85676c5ff           call 0x49f860
// 0084820a  8b442410             mov eax, dword ptr [esp + 0x10]
// 0084820e  c7442408ffffffff     mov dword ptr [esp + 8], 0xffffffff
// 00848216  85c0                 test eax, eax
// 00848218  7427                 je 0x848241
// 0084821a  83c004               add eax, 4
// 0084821d  50                   push eax
// 0084821e  ff15a4e18900         call dword ptr [0x89e1a4]
// 00848224  85c0                 test eax, eax
// 00848226  7519                 jne 0x848241
// 00848228  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0084822c  e84fcbbfff           call 0x444d80
// 00848231  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00848235  85c9                 test ecx, ecx
// 00848237  7408                 je 0x848241
// 00848239  8b11                 mov edx, dword ptr [ecx]
// 0084823b  8b02                 mov eax, dword ptr [edx]
// 0084823d  6a01                 push 1
// 0084823f  ffd0                 call eax
// 00848241  8b0c24               mov ecx, dword ptr [esp]
// 00848244  64890d00000000       mov dword ptr fs:[0], ecx
// 0084824b  83c40c               add esp, 0xc
// 0084824e  c20400               ret 4
// copied from an identical function in another client (function ?f@S@ns_ROCX000000@@QAEXUPointer@2@@Z)

namespace ns_ROCX000000 {
extern "C" long (__stdcall *InterlockedDecrement)(volatile long*);

struct Object {
    virtual ~Object();
    volatile long references;
    void dispose();
};

struct Pointer {
    Object* value;
    ~Pointer();
    Pointer& assign(Object*);
};

__forceinline Pointer::~Pointer()
{
    if (value && InterlockedDecrement(&value->references) == 0) {
        value->dispose();
        delete value;
    }
}

struct S {
    unsigned char padding[12];
    Pointer member;
    void f(Pointer p);
};

void S::f(Pointer p)
{
    Pointer& destination = member;
    destination.assign(p.value);
}
}
