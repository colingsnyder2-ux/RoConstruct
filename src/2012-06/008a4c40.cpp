// from server: 100% by Xemicl
// from server: 100% by tajop
// roc 2012-06 008a4dc0  unit: RBX::VAxisRotateTool::?$TToolVerb  size: 104 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008a4dc0
//
// 008a4dc0  6aff                 push -1
// 008a4dc2  68eb29ad00           push 0xad29eb
// 008a4dc7  64a100000000         mov eax, dword ptr fs:[0]
// 008a4dcd  50                   push eax
// 008a4dce  64892500000000       mov dword ptr fs:[0], esp
// 008a4dd5  51                   push ecx
// 008a4dd6  56                   push esi
// 008a4dd7  57                   push edi
// 008a4dd8  688c000000           push 0x8c
// 008a4ddd  8bf9                 mov edi, ecx
// 008a4ddf  e836d30d00           call 0x98211a
// 008a4de4  8bf0                 mov esi, eax
// 008a4de6  83c404               add esp, 4
// 008a4de9  89742408             mov dword ptr [esp + 8], esi
// 008a4ded  33c0                 xor eax, eax
// 008a4def  89442414             mov dword ptr [esp + 0x14], eax
// 008a4df3  3bf0                 cmp esi, eax
// 008a4df5  7420                 je 0x8a4e17
// 008a4df7  8b470c               mov eax, dword ptr [edi + 0xc]
// 008a4dfa  8b88c40a0000         mov ecx, dword ptr [eax + 0xac4]
// 008a4e00  51                   push ecx
// 008a4e01  8bce                 mov ecx, esi
// 008a4e03  e858340a00           call 0x948260
// 008a4e08  c7069cecbd00         mov dword ptr [esi], 0xbdec9c
// 008a4e0e  c7460470ecbd00       mov dword ptr [esi + 4], 0xbdec70
// 008a4e15  8bc6                 mov eax, esi
// 008a4e17  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 008a4e1b  5f                   pop edi
// 008a4e1c  5e                   pop esi
// 008a4e1d  64890d00000000       mov dword ptr fs:[0], ecx
// 008a4e24  83c410               add esp, 0x10
// 008a4e27  c3                   ret 

struct Workspace;

struct DataModel {
    char pad[0xac4];
    Workspace* workspace;
};

struct MouseCommand {
    virtual void f();
};

struct MouseCommandSecondary {
    virtual void g();
};

struct AxisToolBase : MouseCommand, MouseCommandSecondary {
    AxisToolBase(Workspace* workspace);
    char pad[0x84];
};

struct AxisRotateTool : AxisToolBase {
    AxisRotateTool(Workspace* workspace) : AxisToolBase(workspace) {}
    virtual void f();
    virtual void g();
};

struct TToolVerb {
    char pad[0xc];
    DataModel* dataModel;
    MouseCommand* createCommand();
};

MouseCommand* TToolVerb::createCommand() {
    return new AxisRotateTool(dataModel->workspace);
}
