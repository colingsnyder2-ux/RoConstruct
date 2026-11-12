// from server: 100% by EspClaude
// from server: 51% by colin
// roc 2007-08 0055ea30  unit: RBX::StatsCommand  size: 135 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0055ea30
//
// 0055ea30  6aff                 push -1
// 0055ea32  6879be7500           push 0x75be79
// 0055ea37  64a100000000         mov eax, dword ptr fs:[0]
// 0055ea3d  50                   push eax
// 0055ea3e  64892500000000       mov dword ptr fs:[0], esp
// 0055ea45  83ec1c               sub esp, 0x1c
// 0055ea48  8b410c               mov eax, dword ptr [ecx + 0xc]
// 0055ea4b  53                   push ebx
// 0055ea4c  56                   push esi
// 0055ea4d  8bb0a0010000         mov esi, dword ptr [eax + 0x1a0]
// 0055ea53  68bc917a00           push 0x7a91bc
// 0055ea58  8d4c240c             lea ecx, [esp + 0xc]
// 0055ea5c  ff1598e67700         call dword ptr [0x77e698]
// 0055ea62  6a00                 push 0
// 0055ea64  683cdf8900           push 0x89df3c
// 0055ea69  684c1f8800           push 0x881f4c
// 0055ea6e  6a00                 push 0
// 0055ea70  8d4c2418             lea ecx, [esp + 0x18]
// 0055ea74  51                   push ecx
// 0055ea75  8bce                 mov ecx, esi
// 0055ea77  c744244000000000     mov dword ptr [esp + 0x40], 0
// 0055ea7f  e81cfdfdff           call 0x53e7a0
// 0055ea84  50                   push eax
// 0055ea85  e8ac220d00           call 0x630d36
// 0055ea8a  83c414               add esp, 0x14
// 0055ea8d  85c0                 test eax, eax
// 0055ea8f  8d4c2408             lea ecx, [esp + 8]
// 0055ea93  0f95c3               setne bl
// 0055ea96  c744242cffffffff     mov dword ptr [esp + 0x2c], 0xffffffff
// 0055ea9e  ff15ace67700         call dword ptr [0x77e6ac]
// 0055eaa4  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0055eaa8  5e                   pop esi
// 0055eaa9  8ac3                 mov al, bl
// 0055eaab  5b                   pop ebx
// 0055eaac  64890d00000000       mov dword ptr fs:[0], ecx
// 0055eab3  83c428               add esp, 0x28
// 0055eab6  c3                   ret 

// roc-flags: /O2 /GS- /EHsc /MD
#include <string>

namespace RBX {
class Instance {
public:
    virtual ~Instance();
    Instance* findFirstChildByName(const std::string& name);
};
class TopMenuBar : public Instance {};
class Workspace;
class DataModel : public Instance {
    char pad_[0x1a0 - 4];
public:
    Instance* workspaceOrGui;   // +0x1a0 (read by the target)
};
class StatsCommand {
    char pad_[0xc];
public:
    DataModel* dataModel;       // +0xc
    bool isChecked() const;
};

bool StatsCommand::isChecked() const
{
    Instance* parent = dataModel->workspaceOrGui;
    return dynamic_cast<TopMenuBar*>(parent->findFirstChildByName("StatsHud1")) != 0;
}
}
