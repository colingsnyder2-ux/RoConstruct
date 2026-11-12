// from server: 68% by EspClaude
// from server: 43% by colin
// roc 2007-08 00563d90  unit: RBX::WeldSelectionVerb  size: 202 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00563d90
//
// 00563d90  83ec0c               sub esp, 0xc
// 00563d93  53                   push ebx
// 00563d94  8bd9                 mov ebx, ecx
// 00563d96  56                   push esi
// 00563d97  8b7320               mov esi, dword ptr [ebx + 0x20]
// 00563d9a  e8f1a4ffff           call 0x55e290
// 00563d9f  8b4b20               mov ecx, dword ptr [ebx + 0x20]
// 00563da2  85c9                 test ecx, ecx
// 00563da4  7405                 je 0x563dab
// 00563da6  e895cfeaff           call 0x410d40
// 00563dab  8a442418             mov al, byte ptr [esp + 0x18]
// 00563daf  55                   push ebp
// 00563db0  57                   push edi
// 00563db1  8d7b14               lea edi, [ebx + 0x14]
// 00563db4  6a01                 push 1
// 00563db6  8bcf                 mov ecx, edi
// 00563db8  8844241c             mov byte ptr [esp + 0x1c], al
// 00563dbc  e83fe5ffff           call 0x562300
// 00563dc1  8bb004010000         mov esi, dword ptr [eax + 0x104]
// 00563dc7  8b6e08               mov ebp, dword ptr [esi + 8]
// 00563dca  396e04               cmp dword ptr [esi + 4], ebp
// 00563dcd  7606                 jbe 0x563dd5
// 00563dcf  ff15d8e67700         call dword ptr [0x77e6d8]
// 00563dd5  6a01                 push 1
// 00563dd7  8bcf                 mov ecx, edi
// 00563dd9  e822e5ffff           call 0x562300
// 00563dde  8bb804010000         mov edi, dword ptr [eax + 0x104]
// 00563de4  8b4704               mov eax, dword ptr [edi + 4]
// 00563de7  3b4708               cmp eax, dword ptr [edi + 8]
// 00563dea  89442410             mov dword ptr [esp + 0x10], eax
// 00563dee  760a                 jbe 0x563dfa
// 00563df0  ff15d8e67700         call dword ptr [0x77e6d8]
// 00563df6  8b442410             mov eax, dword ptr [esp + 0x10]
// 00563dfa  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00563dfe  51                   push ecx
// 00563dff  b960025600           mov ecx, 0x560260
// 00563e04  51                   push ecx
// 00563e05  55                   push ebp
// 00563e06  56                   push esi
// 00563e07  50                   push eax
// 00563e08  8d542428             lea edx, [esp + 0x28]
// 00563e0c  57                   push edi
// 00563e0d  52                   push edx
// 00563e0e  e8edb5ffff           call 0x55f400
// 00563e13  8b5b20               mov ebx, dword ptr [ebx + 0x20]
// 00563e16  83c41c               add esp, 0x1c
// 00563e19  85db                 test ebx, ebx
// 00563e1b  5f                   pop edi
// 00563e1c  5d                   pop ebp
// 00563e1d  7409                 je 0x563e28
// 00563e1f  8bcb                 mov ecx, ebx
// 00563e21  e8fa6affff           call 0x55a920
// 00563e26  eb02                 jmp 0x563e2a
// 00563e28  33c0                 xor eax, eax
// 00563e2a  6a08                 push 8
// 00563e2c  8bc8                 mov ecx, eax
// 00563e2e  e8dd890200           call 0x58c810
// 00563e33  8b742418             mov esi, dword ptr [esp + 0x18]
// 00563e37  6aff                 push -1
// 00563e39  8bce                 mov ecx, esi
// 00563e3b  e870caeaff           call 0x4108b0
// 00563e40  8b06                 mov eax, dword ptr [esi]
// 00563e42  8b5004               mov edx, dword ptr [eax + 4]
// 00563e45  6a01                 push 1
// 00563e47  8bce                 mov ecx, esi
// 00563e49  c74604ffffffff       mov dword ptr [esi + 4], 0xffffffff
// 00563e50  ffd2                 call edx
// 00563e52  5e                   pop esi
// 00563e53  5b                   pop ebx
// 00563e54  83c40c               add esp, 0xc
// 00563e57  c20400               ret 4

#include <vector>
#include <algorithm>

namespace RBX {

class Instance;

class IDataState {
public:
    virtual ~IDataState();
    virtual void setDirty(bool dirty);
    int changeCount;
    void notify(int n);
};

class Selection {
public:
    char pad[0x104];
    std::vector<Instance*>* parts;
};

class SelectionOwner {
public:
    Selection* getSelection(bool create);
};

class ChangeHistoryService {
public:
    void requestWaypoint(int kind);
};

class DataModel {
public:
    void checkLock();
    ChangeHistoryService* getChangeHistory();
};

void lockDataModel(DataModel* dm);

struct WeldFunctor {
    void (*fn)(Instance*, char);
    char value;
    void operator()(Instance* i) const { fn(i, value); }
};

void weldPart(Instance* part, char value);

class WeldSelectionVerb {
public:
    char pad0[0x14];
    SelectionOwner owner;
    char pad15[0x20 - 0x15];
    DataModel* dataModel;
    void doIt(IDataState* dataState);
};

void WeldSelectionVerb::doIt(IDataState* dataState)
{
    lockDataModel(dataModel);
    if (dataModel)
        dataModel->checkLock();

    WeldFunctor f;
    f.fn = &weldPart;
    f.value = (char)(size_t)dataState;
    std::for_each(owner.getSelection(true)->parts->begin(), owner.getSelection(true)->parts->end(), f);

    (dataModel ? dataModel->getChangeHistory() : 0)->requestWaypoint(8);
    dataState->notify(-1);
    dataState->changeCount = -1;
    dataState->setDirty(true);
}

}
