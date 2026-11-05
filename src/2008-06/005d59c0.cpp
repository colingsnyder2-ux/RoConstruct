// from server: 100% by EspClaude
// from server: 59% by colin
// roc 2008-06 005d59c0  unit: RBX::VSkin::?$FactoryProduct  size: 247 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005d59c0
//
// 005d59c0  6aff                 push -1
// 005d59c2  68615b7d00           push 0x7d5b61
// 005d59c7  64a100000000         mov eax, dword ptr fs:[0]
// 005d59cd  50                   push eax
// 005d59ce  64892500000000       mov dword ptr fs:[0], esp
// 005d59d5  83ec20               sub esp, 0x20
// 005d59d8  56                   push esi
// 005d59d9  8bf1                 mov esi, ecx
// 005d59db  89742404             mov dword ptr [esp + 4], esi
// 005d59df  e86cf9ffff           call 0x5d5350
// 005d59e4  c7061ccc8300         mov dword ptr [esi], 0x83cc1c
// 005d59ea  c7461010cc8300       mov dword ptr [esi + 0x10], 0x83cc10
// 005d59f1  c7461408cc8300       mov dword ptr [esi + 0x14], 0x83cc08
// 005d59f8  c7462000cc8300       mov dword ptr [esi + 0x20], 0x83cc00
// 005d59ff  c74624f0cb8300       mov dword ptr [esi + 0x24], 0x83cbf0
// 005d5a06  c74644e0cb8300       mov dword ptr [esi + 0x44], 0x83cbe0
// 005d5a0d  c74664d0cb8300       mov dword ptr [esi + 0x64], 0x83cbd0
// 005d5a14  c78684000000c0cb8300 mov dword ptr [esi + 0x84], 0x83cbc0
// 005d5a1e  c786a4000000b0cb8300 mov dword ptr [esi + 0xa4], 0x83cbb0
// 005d5a28  c786c4000000a0cb8300 mov dword ptr [esi + 0xc4], 0x83cba0
// 005d5a32  c7863001000098cb8300 mov dword ptr [esi + 0x130], 0x83cb98
// 005d5a3c  b8e2000000           mov eax, 0xe2
// 005d5a41  898634010000         mov dword ptr [esi + 0x134], eax
// 005d5a47  898638010000         mov dword ptr [esi + 0x138], eax
// 005d5a4d  89863c010000         mov dword ptr [esi + 0x13c], eax
// 005d5a53  b817000000           mov eax, 0x17
// 005d5a58  c786400100001c000000 mov dword ptr [esi + 0x140], 0x1c
// 005d5a62  898644010000         mov dword ptr [esi + 0x144], eax
// 005d5a68  6888cb8300           push 0x83cb88
// 005d5a6d  8d4c240c             lea ecx, [esp + 0xc]
// 005d5a71  c744243000000000     mov dword ptr [esp + 0x30], 0
// 005d5a79  898648010000         mov dword ptr [esi + 0x148], eax
// 005d5a7f  ff1558248000         call dword ptr [0x802458]
// 005d5a85  8d442408             lea eax, [esp + 8]
// 005d5a89  50                   push eax
// 005d5a8a  8bce                 mov ecx, esi
// 005d5a8c  c644243001           mov byte ptr [esp + 0x30], 1
// 005d5a91  e8fa54f8ff           call 0x55af90
// 005d5a96  8d4c2408             lea ecx, [esp + 8]
// 005d5a9a  c644242c00           mov byte ptr [esp + 0x2c], 0
// 005d5a9f  ff1568248000         call dword ptr [0x802468]
// 005d5aa5  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 005d5aa9  8bc6                 mov eax, esi
// 005d5aab  5e                   pop esi
// 005d5aac  64890d00000000       mov dword ptr fs:[0], ecx
// 005d5ab3  83c42c               add esp, 0x2c
// 005d5ab6  c3                   ret 

// from server: 54% by colin
// roc 2008-06 005d59c0  unit: RBX::VSkin::?$FactoryProduct  size: 247 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005d59c0
//
// 005d59c0  6aff                 push -1
// 005d59c2  68615b7d00           push 0x7d5b61
// 005d59c7  64a100000000         mov eax, dword ptr fs:[0]
// 005d59cd  50                   push eax
// 005d59ce  64892500000000       mov dword ptr fs:[0], esp
// 005d59d5  83ec20               sub esp, 0x20
// 005d59d8  56                   push esi
// 005d59d9  8bf1                 mov esi, ecx
// 005d59db  89742404             mov dword ptr [esp + 4], esi
// 005d59df  e86cf9ffff           call 0x5d5350
// 005d59e4  c7061ccc8300         mov dword ptr [esi], 0x83cc1c
// 005d59ea  c7461010cc8300       mov dword ptr [esi + 0x10], 0x83cc10
// 005d59f1  c7461408cc8300       mov dword ptr [esi + 0x14], 0x83cc08
// 005d59f8  c7462000cc8300       mov dword ptr [esi + 0x20], 0x83cc00
// 005d59ff  c74624f0cb8300       mov dword ptr [esi + 0x24], 0x83cbf0
// 005d5a06  c74644e0cb8300       mov dword ptr [esi + 0x44], 0x83cbe0
// 005d5a0d  c74664d0cb8300       mov dword ptr [esi + 0x64], 0x83cbd0
// 005d5a14  c78684000000c0cb8300 mov dword ptr [esi + 0x84], 0x83cbc0
// 005d5a1e  c786a4000000b0cb8300 mov dword ptr [esi + 0xa4], 0x83cbb0
// 005d5a28  c786c4000000a0cb8300 mov dword ptr [esi + 0xc4], 0x83cba0
// 005d5a32  c7863001000098cb8300 mov dword ptr [esi + 0x130], 0x83cb98
// 005d5a3c  b8e2000000           mov eax, 0xe2
// 005d5a41  898634010000         mov dword ptr [esi + 0x134], eax
// 005d5a47  898638010000         mov dword ptr [esi + 0x138], eax
// 005d5a4d  89863c010000         mov dword ptr [esi + 0x13c], eax
// 005d5a53  b817000000           mov eax, 0x17
// 005d5a58  c786400100001c000000 mov dword ptr [esi + 0x140], 0x1c
// 005d5a62  898644010000         mov dword ptr [esi + 0x144], eax
// 005d5a68  6888cb8300           push 0x83cb88
// 005d5a6d  8d4c240c             lea ecx, [esp + 0xc]
// 005d5a71  c744243000000000     mov dword ptr [esp + 0x30], 0
// 005d5a79  898648010000         mov dword ptr [esi + 0x148], eax
// 005d5a7f  ff1558248000         call dword ptr [0x802458]
// 005d5a85  8d442408             lea eax, [esp + 8]
// 005d5a89  50                   push eax
// 005d5a8a  8bce                 mov ecx, esi
// 005d5a8c  c644243001           mov byte ptr [esp + 0x30], 1
// 005d5a91  e8fa54f8ff           call 0x55af90
// 005d5a96  8d4c2408             lea ecx, [esp + 8]
// 005d5a9a  c644242c00           mov byte ptr [esp + 0x2c], 0
// 005d5a9f  ff1568248000         call dword ptr [0x802468]
// 005d5aa5  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 005d5aa9  8bc6                 mov eax, esi
// 005d5aab  5e                   pop esi
// 005d5aac  64890d00000000       mov dword ptr fs:[0], ecx
// 005d5ab3  83c42c               add esp, 0x2c
// 005d5ab6  c3                   ret 








#include <string>

namespace RBX {

struct A0 { virtual ~A0(); int a[3]; };
struct A1 { virtual void f1(); };
struct A2 { virtual void f2(); int a[2]; };
struct A3 { virtual void f3(); };
struct A4 { virtual void f4(); int a[7]; };
struct A5 { virtual void f5(); int a[7]; };
struct A6 { virtual void f6(); int a[7]; };
struct A7 { virtual void f7(); int a[7]; };
struct A8 { virtual void f8(); int a[7]; };
struct A9 { virtual void f9(); int a[26]; };

class Instance : public A0, public A1, public A2, public A3, public A4,
                 public A5, public A6, public A7, public A8, public A9 {
public:
    Instance();
    void setName(const std::string& name);
};

class __declspec(novtable) IColors {
public:
    virtual void onChanged();
};

class BrickColor {
public:
    int number;
    BrickColor(int n) : number(n) {}
};

class BodyColors : public Instance, public IColors {
public:
    BrickColor headColor;
    BrickColor leftArmColor;
    BrickColor rightArmColor;
    BrickColor torsoColor;
    BrickColor leftLegColor;
    BrickColor rightLegColor;
    BodyColors();
};

BodyColors::BodyColors()
    : headColor(0xe2), leftArmColor(0xe2), rightArmColor(0xe2),
      torsoColor(0x1c), leftLegColor(0x17), rightLegColor(0x17)
{
    setName("Body Colors");
}

}
