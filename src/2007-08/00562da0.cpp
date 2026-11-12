// from server: 100% by EspClaude
// from server: 59% by tester
// roc 2007-08 00562da0  unit: RBX::FollowCameraCommand  size: 178 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00562da0
//
// 00562da0  51                   push ecx
// 00562da1  56                   push esi
// 00562da2  57                   push edi
// 00562da3  8bf9                 mov edi, ecx
// 00562da5  8b4f20               mov ecx, dword ptr [edi + 0x20]
// 00562da8  85c9                 test ecx, ecx
// 00562daa  7409                 je 0x562db5
// 00562dac  e82febffff           call 0x5618e0
// 00562db1  8bf0                 mov esi, eax
// 00562db3  eb02                 jmp 0x562db7
// 00562db5  33f6                 xor esi, esi
// 00562db7  8b86f8000000         mov eax, dword ptr [esi + 0xf8]
// 00562dbd  85c0                 test eax, eax
// 00562dbf  7431                 je 0x562df2
// 00562dc1  8b8efc000000         mov ecx, dword ptr [esi + 0xfc]
// 00562dc7  2bc8                 sub ecx, eax
// 00562dc9  c1f902               sar ecx, 2
// 00562dcc  7424                 je 0x562df2
// 00562dce  53                   push ebx
// 00562dcf  8bd8                 mov ebx, eax
// 00562dd1  3b9efc000000         cmp ebx, dword ptr [esi + 0xfc]
// 00562dd7  55                   push ebp
// 00562dd8  8b2dd8e67700         mov ebp, dword ptr [0x77e6d8]
// 00562dde  7608                 jbe 0x562de8
// 00562de0  ffd5                 call ebp
// 00562de2  3b9efc000000         cmp ebx, dword ptr [esi + 0xfc]
// 00562de8  7202                 jb 0x562dec
// 00562dea  ffd5                 call ebp
// 00562dec  8b33                 mov esi, dword ptr [ebx]
// 00562dee  5d                   pop ebp
// 00562def  5b                   pop ebx
// 00562df0  eb02                 jmp 0x562df4
// 00562df2  33f6                 xor esi, esi
// 00562df4  8b470c               mov eax, dword ptr [edi + 0xc]
// 00562df7  8b9028020000         mov edx, dword ptr [eax + 0x228]
// 00562dfd  8d8828020000         lea ecx, [eax + 0x228]
// 00562e03  8b4204               mov eax, dword ptr [edx + 4]
// 00562e06  6a04                 push 4
// 00562e08  ffd0                 call eax
// 00562e0a  8bc8                 mov ecx, eax
// 00562e0c  e8af880300           call 0x59b6c0
// 00562e11  8b470c               mov eax, dword ptr [edi + 0xc]
// 00562e14  8b9028020000         mov edx, dword ptr [eax + 0x228]
// 00562e1a  8d8828020000         lea ecx, [eax + 0x228]
// 00562e20  8b4204               mov eax, dword ptr [edx + 4]
// 00562e23  56                   push esi
// 00562e24  ffd0                 call eax
// 00562e26  8bc8                 mov ecx, eax
// 00562e28  e8d3880300           call 0x59b700
// 00562e2d  8b742410             mov esi, dword ptr [esp + 0x10]
// 00562e31  6aff                 push -1
// 00562e33  8bce                 mov ecx, esi
// 00562e35  e876daeaff           call 0x4108b0
// 00562e3a  8b16                 mov edx, dword ptr [esi]
// 00562e3c  8b4204               mov eax, dword ptr [edx + 4]
// 00562e3f  6a01                 push 1
// 00562e41  8bce                 mov ecx, esi
// 00562e43  c74604ffffffff       mov dword ptr [esi + 4], 0xffffffff
// 00562e4a  ffd0                 call eax
// 00562e4c  5f                   pop edi
// 00562e4d  5e                   pop esi
// 00562e4e  59                   pop ecx
// 00562e4f  c20400               ret 4

#include <vector>

struct Item;

struct Settable {
    void setInt(int);            // 0x59b6c0 (thiscall, 1 arg)
    void setItem(Item*);         // 0x59b700 (thiscall, 1 arg)
};

struct Iface228 {
    virtual void v0();
    virtual Settable* get();     // vtable slot 1
};

struct Owner {
    char pad[0x228];
    Iface228 iface;              // at +0x228
};

struct Inner {
    char pad[0xf4];
    std::vector<Item*> items;    // _Myfirst at +0xf8, _Mylast at +0xfc
};

struct Holder {
    Inner* get();                // 0x5618e0 (thiscall)
};

struct Arg {
    virtual void v0();
    virtual void v1(int);       // vtable slot 1
    int field_4;
    void reset(int);            // 0x4108b0 (thiscall)
};

namespace RBX {
struct FollowCameraCommand {
    char pad[0xc];
    Owner* owner;                // +0xc
    char pad2[0x10];
    Holder* holder;              // +0x20
    void func(Arg* arg);
};

void FollowCameraCommand::func(Arg* arg)
{
    Inner* inner = holder ? holder->get() : 0;
    Item* item = !inner->items.empty() ? inner->items.front() : 0;
    owner->iface.get()->setInt(4);
    owner->iface.get()->setItem(item);
    arg->reset(-1);
    arg->field_4 = -1;
    arg->v1(1);
}
}
