// from server: 100% by EspClaude
// from server: 60% by colin
// roc 2007-08 004a4ad0  unit: RBX::VNetworkSettings::?$BoundPropGetSet  size: 192 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004a4ad0
//
// 004a4ad0  6aff                 push -1
// 004a4ad2  6851987400           push 0x749851
// 004a4ad7  64a100000000         mov eax, dword ptr fs:[0]
// 004a4add  50                   push eax
// 004a4ade  83ec20               sub esp, 0x20
// 004a4ae1  56                   push esi
// 004a4ae2  a188518b00           mov eax, dword ptr [0x8b5188]
// 004a4ae7  33c4                 xor eax, esp
// 004a4ae9  50                   push eax
// 004a4aea  8d442428             lea eax, [esp + 0x28]
// 004a4aee  64a300000000         mov dword ptr fs:[0], eax
// 004a4af4  8bf1                 mov esi, ecx
// 004a4af6  89742408             mov dword ptr [esp + 8], esi
// 004a4afa  e8d1feffff           call 0x4a49d0
// 004a4aff  68c0cc7900           push 0x79ccc0
// 004a4b04  8d4c2410             lea ecx, [esp + 0x10]
// 004a4b08  c744243400000000     mov dword ptr [esp + 0x34], 0
// 004a4b10  c706c4cf7900         mov dword ptr [esi], 0x79cfc4
// 004a4b16  c74604bccf7900       mov dword ptr [esi + 4], 0x79cfbc
// 004a4b1d  c74610b4cf7900       mov dword ptr [esi + 0x10], 0x79cfb4
// 004a4b24  c74614a4cf7900       mov dword ptr [esi + 0x14], 0x79cfa4
// 004a4b2b  c7462c94cf7900       mov dword ptr [esi + 0x2c], 0x79cf94
// 004a4b32  c7464484cf7900       mov dword ptr [esi + 0x44], 0x79cf84
// 004a4b39  c7465c74cf7900       mov dword ptr [esi + 0x5c], 0x79cf74
// 004a4b40  c7467464cf7900       mov dword ptr [esi + 0x74], 0x79cf64
// 004a4b47  c7868c00000054cf7900 mov dword ptr [esi + 0x8c], 0x79cf54
// 004a4b51  ff1598e67700         call dword ptr [0x77e698]
// 004a4b57  8d44240c             lea eax, [esp + 0xc]
// 004a4b5b  50                   push eax
// 004a4b5c  8bce                 mov ecx, esi
// 004a4b5e  c644243401           mov byte ptr [esp + 0x34], 1
// 004a4b63  e888d00900           call 0x541bf0
// 004a4b68  8d4c240c             lea ecx, [esp + 0xc]
// 004a4b6c  c644243000           mov byte ptr [esp + 0x30], 0
// 004a4b71  ff15ace67700         call dword ptr [0x77e6ac]
// 004a4b77  8935f8e28b00         mov dword ptr [0x8be2f8], esi
// 004a4b7d  8bc6                 mov eax, esi

#include <string>

// polymorphic subobjects at the vptr offsets the target writes:
// 0, 4, 0x10, 0x14, 0x2c, 0x44, 0x5c, 0x74, 0x8c
struct S00 { virtual void f00(); };
struct S04 { virtual void f04(); int pad[2]; };
struct S10 { virtual void f10(); };
struct S14 { virtual void f14(); int pad[5]; };
struct S2c { virtual void f2c(); int pad[5]; };
struct S44 { virtual void f44(); int pad[5]; };
struct S5c { virtual void f5c(); int pad[5]; };
struct S74 { virtual void f74(); int pad[5]; };
struct S8c { virtual void f8c(); };

namespace RBX {

class Base : public S00, public S04, public S10, public S14, public S2c,
             public S44, public S5c, public S74, public S8c {
public:
    Base();
    virtual ~Base();
    void setName(const std::string& name);
};

class NetworkSettings : public Base {
public:
    NetworkSettings();
    static NetworkSettings* singleton;
};

NetworkSettings::NetworkSettings()
{
    setName("NetworkSettings");
    singleton = this;
}

}
