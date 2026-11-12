// from server: 100% by EspClaude
// roc-flags: /O2 /GS- /EHsc /MD
// from server: 55% by colin
// roc 2007-08 0055eac0  unit: RBX::StatsCommand  size: 168 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0055eac0
//
// 0055eac0  6aff                 push -1
// 0055eac2  6879be7500           push 0x75be79
// 0055eac7  64a100000000         mov eax, dword ptr fs:[0]
// 0055eacd  50                   push eax
// 0055eace  64892500000000       mov dword ptr fs:[0], esp
// 0055ead5  83ec1c               sub esp, 0x1c
// 0055ead8  8b410c               mov eax, dword ptr [ecx + 0xc]
// 0055eadb  56                   push esi
// 0055eadc  8bb0a0010000         mov esi, dword ptr [eax + 0x1a0]
// 0055eae2  68bc917a00           push 0x7a91bc
// 0055eae7  8d4c2408             lea ecx, [esp + 8]
// 0055eaeb  ff1598e67700         call dword ptr [0x77e698]
// 0055eaf1  6a00                 push 0
// 0055eaf3  683cdf8900           push 0x89df3c
// 0055eaf8  684c1f8800           push 0x881f4c
// 0055eafd  6a00                 push 0
// 0055eaff  8d4c2414             lea ecx, [esp + 0x14]
// 0055eb03  51                   push ecx
// 0055eb04  8bce                 mov ecx, esi
// 0055eb06  c744243c00000000     mov dword ptr [esp + 0x3c], 0
// 0055eb0e  e88dfcfdff           call 0x53e7a0
// 0055eb13  50                   push eax
// 0055eb14  e81d220d00           call 0x630d36
// 0055eb19  83c414               add esp, 0x14
// 0055eb1c  8d4c2404             lea ecx, [esp + 4]
// 0055eb20  8bf0                 mov esi, eax
// 0055eb22  c7442428ffffffff     mov dword ptr [esp + 0x28], 0xffffffff
// 0055eb2a  ff15ace67700         call dword ptr [0x77e6ac]
// 0055eb30  85f6                 test esi, esi
// 0055eb32  7422                 je 0x55eb56
// 0055eb34  8b16                 mov edx, dword ptr [esi]
// 0055eb36  8b4258               mov eax, dword ptr [edx + 0x58]
// 0055eb39  8bce                 mov ecx, esi
// 0055eb3b  ffd0                 call eax
// 0055eb3d  84c0                 test al, al
// 0055eb3f  7415                 je 0x55eb56
// 0055eb41  b801000000           mov eax, 1
// 0055eb46  5e                   pop esi
// 0055eb47  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0055eb4b  64890d00000000       mov dword ptr fs:[0], ecx
// 0055eb52  83c428               add esp, 0x28
// 0055eb55  c3                   ret 
// 0055eb56  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0055eb5a  33c0                 xor eax, eax
// 0055eb5c  5e                   pop esi
// 0055eb5d  64890d00000000       mov dword ptr fs:[0], ecx
// 0055eb64  83c428               add esp, 0x28
// 0055eb67  c3                   ret 
#include <string>
namespace RBX {
class Instance {
public:
    virtual ~Instance();
    Instance* findFirstChildByName(const std::string& name);
};
class TopMenuBar : public Instance {
public:
    virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10();
    virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20();
    virtual void v21();
    virtual bool getVisible() const;
};
class DataModel { public: char pad[0x1a0]; Instance* guiRoot; };
class StatsCommand {
public:
    char pad[0xc];
    DataModel* dataModel;
    int isChecked() const;
};
int StatsCommand::isChecked() const
{
    Instance* root = dataModel->guiRoot;
    TopMenuBar* hud = dynamic_cast<TopMenuBar*>(root->findFirstChildByName("StatsHud1"));
    if (hud && hud->getVisible())
        return 1;
    return 0;
}
}
