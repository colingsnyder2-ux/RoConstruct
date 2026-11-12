// from server: 93% by EspClaude
// from server: 44% by colin
// roc 2007-08 00562f20  unit: RBX::MoveUpSelectionVerb  size: 273 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00562f20
//
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// 00562f20  64a100000000         mov eax, dword ptr fs:[0]
// 00562f26  6aff                 push -1
// 00562f28  68683f7500           push 0x753f68
// 00562f2d  50                   push eax
// 00562f2e  64892500000000       mov dword ptr fs:[0], esp
// 00562f35  83ec40               sub esp, 0x40
// 00562f38  56                   push esi
// 00562f39  57                   push edi
// 00562f3a  8bf9                 mov edi, ecx
// 00562f3c  8b7720               mov esi, dword ptr [edi + 0x20]
// 00562f3f  e84cb3ffff           call 0x55e290
// 00562f44  8b4f20               mov ecx, dword ptr [edi + 0x20]
// 00562f47  85c9                 test ecx, ecx
// 00562f49  7407                 je 0x562f52
// 00562f4b  e890e9ffff           call 0x5618e0
// 00562f50  eb02                 jmp 0x562f54
// 00562f52  33c0                 xor eax, eax
// 00562f54  8b88f8000000         mov ecx, dword ptr [eax + 0xf8]
// 00562f5a  05f4000000           add eax, 0xf4
// 00562f5f  85c9                 test ecx, ecx
// 00562f61  0f84b7000000         je 0x56301e
// 00562f67  8b5008               mov edx, dword ptr [eax + 8]
// 00562f6a  2bd1                 sub edx, ecx
// 00562f6c  c1fa02               sar edx, 2
// 00562f6f  0f84a9000000         je 0x56301e
// 00562f75  8b4f0c               mov ecx, dword ptr [edi + 0xc]
// 00562f78  51                   push ecx
// 00562f79  50                   push eax
// 00562f7a  6a00                 push 0
// 00562f7c  8d4c2430             lea ecx, [esp + 0x30]
// 00562f80  e8cbdd0700           call 0x5e0d50
// 00562f85  8d4c2424             lea ecx, [esp + 0x24]
// 00562f89  c744245000000000     mov dword ptr [esp + 0x50], 0
// 00562f91  e8cad60700           call 0x5e0660
// 00562f96  d94724               fld dword ptr [edi + 0x24]
// 00562f99  d9ee                 fldz 
// 00562f9b  8d44240c             lea eax, [esp + 0xc]
// 00562f9f  d954240c             fst dword ptr [esp + 0xc]
// 00562fa3  50                   push eax
// 00562fa4  8d4c241c             lea ecx, [esp + 0x1c]
// 00562fa8  d95c2418             fstp dword ptr [esp + 0x18]
// 00562fac  51                   push ecx
// 00562fad  8d4c242c             lea ecx, [esp + 0x2c]
// 00562fb1  d95c2418             fstp dword ptr [esp + 0x18]
// 00562fb5  e826da0700           call 0x5e09e0
// 00562fba  8d4c2424             lea ecx, [esp + 0x24]
// 00562fbe  e8dddf0700           call 0x5e0fa0
// 00562fc3  8b4f20               mov ecx, dword ptr [edi + 0x20]
// 00562fc6  85c9                 test ecx, ecx
// 00562fc8  7407                 je 0x562fd1
// 00562fca  e85179ffff           call 0x55a920
// 00562fcf  eb02                 jmp 0x562fd3
// 00562fd1  33c0                 xor eax, eax
// 00562fd3  6a04                 push 4
// 00562fd5  8bc8                 mov ecx, eax
// 00562fd7  e834980200           call 0x58c810
// 00562fdc  8b7f0c               mov edi, dword ptr [edi + 0xc]
// 00562fdf  c644240800           mov byte ptr [esp + 8], 0
// 00562fe4  8b542408             mov edx, dword ptr [esp + 8]
// 00562fe8  52                   push edx
// 00562fe9  8d8fd4020000         lea ecx, [edi + 0x2d4]
// 00562fef  e86c5bffff           call 0x558b60
// 00562ff4  8b742458             mov esi, dword ptr [esp + 0x58]
// 00562ff8  83cfff               or edi, 0xffffffff
// 00562ffb  57                   push edi
// 00562ffc  8bce                 mov ecx, esi
// 00562ffe  e8add8eaff           call 0x4108b0
// 00563003  8b06                 mov eax, dword ptr [esi]
// 00563005  8b5004               mov edx, dword ptr [eax + 4]
// 00563008  6a01                 push 1
// 0056300a  8bce                 mov ecx, esi
// 0056300c  897e04               mov dword ptr [esi + 4], edi
// 0056300f  ffd2                 call edx
// 00563011  8d4c2424             lea ecx, [esp + 0x24]
// 00563015  897c2450             mov dword ptr [esp + 0x50], edi
// 00563019  e8d2de0700           call 0x5e0ef0
// 0056301e  8b4c2448             mov ecx, dword ptr [esp + 0x48]
// 00563022  5f                   pop edi
// 00563023  5e                   pop esi
// 00563024  64890d00000000       mov dword ptr fs:[0], ecx
// 0056302b  83c44c               add esp, 0x4c
// 0056302e  c20400               ret 4

#include <vector>

namespace RBX {

class Instance;
typedef std::vector<Instance*> Instances;

struct Vector3 {
    float x, y, z;
    Vector3(float x, float y, float z) : x(x), y(y), z(z) {}
};

class SelectionService {
public:
    char pad0[0xf4];
    Instances selection;                          // +0xf4
};

class ChangeHistory {
public:
    void requestWaypoint(int kind);               // 0058c810
};

class DataModel {
public:
    SelectionService* getSelection();             // 005618e0
    ChangeHistory* getChangeHistory();            // 0055a920
};

class IDataState {
public:
    virtual void v0();
    virtual void setDirty(bool dirty);            // vtable +4
    void setSaveIndex(int i);                     // 004108b0
    int saveIndex;                                // +4
};

struct UpdateMode {};                             // 1-byte by-value tag

class Dragger {
public:
    class Workspace;
    Dragger(int mode, const Instances* instances, void* workspace);   // 005e0d50
    ~Dragger();                                   // 005e0ef0
    void begin();                                 // 005e0660
    Vector3 move(const Vector3& delta);           // 005e09e0
    void end();                                   // 005e0fa0
private:
    char data[0x24];
};

class PartQueue {
public:
    void update(UpdateMode mode);                 // 00558b60
};

class View {
public:
    char pad0[0x2d4];
    PartQueue queue;                              // +0x2d4
};

bool hasSecurity(DataModel* dataModel, int level);      // 004915a0
bool hasPermission(DataModel* dataModel, int level);    // 004915b0
void throwPermissionError(const char* message);
static __declspec(noinline) void checkLocked(DataModel* dataModel)  // 0055e290
{
    if (hasSecurity(dataModel, 1) && !hasPermission(dataModel, 1))
        throwPermissionError("Insufficinet permissions");
}

class MoveUpSelectionVerb {
public:
    void doIt(IDataState* dataState);
private:
    char pad0[0xc];
    View* view;                                   // +0xc
    char pad10[0x10];
    DataModel* dataModel;                         // +0x20
    float height;                                 // +0x24
};

void MoveUpSelectionVerb::doIt(IDataState* dataState)
{
    checkLocked(dataModel);
    SelectionService* selection = dataModel ? dataModel->getSelection() : 0;
    if (selection->selection.size() != 0) {
        Dragger dragger(0, &selection->selection, view);
        dragger.begin();
        dragger.move(Vector3(0.0f, height, 0.0f));
        dragger.end();
        (dataModel ? dataModel->getChangeHistory() : 0)->requestWaypoint(4);
        view->queue.update(UpdateMode());
        dataState->setSaveIndex(-1);
        dataState->saveIndex = -1;
        dataState->setDirty(true);
    }
}
}
