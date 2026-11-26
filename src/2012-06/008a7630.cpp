// from server: 100% by Xemicl
// from server: 100% by tajop
// roc 2012-06 008a7740  unit: RBX::VGameTool::?$TToolVerb  size: 102 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008a7740
//
// 008a7740  6aff                 push -1
// 008a7742  68eb29ad00           push 0xad29eb
// 008a7747  64a100000000         mov eax, dword ptr fs:[0]
// 008a774d  50                   push eax
// 008a774e  64892500000000       mov dword ptr fs:[0], esp
// 008a7755  51                   push ecx
// 008a7756  56                   push esi
// 008a7757  6a50                 push 0x50
// 008a7759  8bf1                 mov esi, ecx
// 008a775b  e8baa90d00           call 0x98211a
// 008a7760  83c404               add esp, 4
// 008a7763  89442404             mov dword ptr [esp + 4], eax
// 008a7767  c744241000000000     mov dword ptr [esp + 0x10], 0
// 008a776f  85c0                 test eax, eax
// 008a7771  7421                 je 0x8a7794
// 008a7773  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 008a7776  8b89c40a0000         mov ecx, dword ptr [ecx + 0xac4]
// 008a777c  51                   push ecx
// 008a777d  8bc8                 mov ecx, eax
// 008a777f  e8dc070a00           call 0x947f60
// 008a7784  5e                   pop esi
// 008a7785  8b4c2404             mov ecx, dword ptr [esp + 4]
// 008a7789  64890d00000000       mov dword ptr fs:[0], ecx
// 008a7790  83c410               add esp, 0x10
// 008a7793  c3                   ret 
// 008a7794  8b4c2408             mov ecx, dword ptr [esp + 8]
// 008a7798  33c0                 xor eax, eax
// 008a779a  5e                   pop esi
// 008a779b  64890d00000000       mov dword ptr fs:[0], ecx
// 008a77a2  83c410               add esp, 0x10
// 008a77a5  c3                   ret 

struct Workspace;

struct DataModel {
    char pad[0xac4];
    Workspace* workspace;
    Workspace* getWorkspace() const { return workspace; }
};

struct MouseCommandTool {
    char pad[0x34];
    MouseCommandTool(Workspace* workspace);
};

struct TToolVerb {
    char pad[0xc];
    DataModel* dataModel;
    MouseCommandTool* newTool();
};

MouseCommandTool* TToolVerb::newTool() {
    return new MouseCommandTool(dataModel->getWorkspace());
}
