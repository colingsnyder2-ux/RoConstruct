// from server: 100% by EspClaude
// from server: 49% by colin
// roc 2007-08 00562640  unit: RBX::GroupSelectionVerb  size: 244 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00562640
//
// 00562640  83ec10               sub esp, 0x10
// 00562643  56                   push esi
// 00562644  57                   push edi
// 00562645  8bf9                 mov edi, ecx
// 00562647  8b7720               mov esi, dword ptr [edi + 0x20]
// 0056264a  897c240c             mov dword ptr [esp + 0xc], edi
// 0056264e  e83dbcffff           call 0x55e290
// 00562653  8b4f20               mov ecx, dword ptr [edi + 0x20]
// 00562656  85c9                 test ecx, ecx
// 00562658  740d                 je 0x562667
// 0056265a  e8e1e6eaff           call 0x410d40
// 0056265f  8bf8                 mov edi, eax
// 00562661  897c2408             mov dword ptr [esp + 8], edi
// 00562665  eb0c                 jmp 0x562673
// 00562667  c744240800000000     mov dword ptr [esp + 8], 0
// 0056266f  8b7c2408             mov edi, dword ptr [esp + 8]
// 00562673  8bb704010000         mov esi, dword ptr [edi + 0x104]
// 00562679  53                   push ebx
// 0056267a  55                   push ebp
// 0056267b  8b6e08               mov ebp, dword ptr [esi + 8]
// 0056267e  396e04               cmp dword ptr [esi + 4], ebp
// 00562681  7606                 jbe 0x562689
// 00562683  ff15d8e67700         call dword ptr [0x77e6d8]
// 00562689  8bbf04010000         mov edi, dword ptr [edi + 0x104]
// 0056268f  8b5f04               mov ebx, dword ptr [edi + 4]
// 00562692  3b5f08               cmp ebx, dword ptr [edi + 8]
// 00562695  7606                 jbe 0x56269d
// 00562697  ff15d8e67700         call dword ptr [0x77e6d8]
// 0056269d  55                   push ebp
// 0056269e  56                   push esi
// 0056269f  53                   push ebx
// 005626a0  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 005626a4  8b4b0c               mov ecx, dword ptr [ebx + 0xc]
// 005626a7  57                   push edi
// 005626a8  8d442428             lea eax, [esp + 0x28]
// 005626ac  50                   push eax
// 005626ad  e8fedaffff           call 0x5601b0
// 005626b2  8b30                 mov esi, dword ptr [eax]
// 005626b4  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005626b8  85c0                 test eax, eax
// 005626ba  742c                 je 0x5626e8
// 005626bc  8bf8                 mov edi, eax
// 005626be  83c004               add eax, 4
// 005626c1  83c9ff               or ecx, 0xffffffff
// 005626c4  f00fc108             lock xadd dword ptr [eax], ecx
// 005626c8  751e                 jne 0x5626e8
// 005626ca  8b17                 mov edx, dword ptr [edi]
// 005626cc  8b4204               mov eax, dword ptr [edx + 4]
// 005626cf  8bcf                 mov ecx, edi
// 005626d1  ffd0                 call eax
// 005626d3  8d4f08               lea ecx, [edi + 8]
// 005626d6  83caff               or edx, 0xffffffff
// 005626d9  f00fc111             lock xadd dword ptr [ecx], edx
// 005626dd  7509                 jne 0x5626e8
// 005626df  8b07                 mov eax, dword ptr [edi]
// 005626e1  8b5008               mov edx, dword ptr [eax + 8]
// 005626e4  8bcf                 mov ecx, edi
// 005626e6  ffd2                 call edx
// 005626e8  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005626ec  56                   push esi
// 005626ed  e85e0bfdff           call 0x533250
// 005626f2  8b4b20               mov ecx, dword ptr [ebx + 0x20]
// 005626f5  85c9                 test ecx, ecx
// 005626f7  5d                   pop ebp
// 005626f8  5b                   pop ebx
// 005626f9  7407                 je 0x562702
// 005626fb  e82082ffff           call 0x55a920
// 00562700  eb02                 jmp 0x562704
// 00562702  33c0                 xor eax, eax
// 00562704  6a08                 push 8
// 00562706  8bc8                 mov ecx, eax
// 00562708  e803a10200           call 0x58c810
// 0056270d  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 00562711  6aff                 push -1
// 00562713  8bce                 mov ecx, esi
// 00562715  e896e1eaff           call 0x4108b0
// 0056271a  8b06                 mov eax, dword ptr [esi]
// 0056271c  8b5004               mov edx, dword ptr [eax + 4]
// 0056271f  6a01                 push 1
// 00562721  8bce                 mov ecx, esi
// 00562723  c74604ffffffff       mov dword ptr [esi + 4], 0xffffffff
// 0056272a  ffd2                 call edx
// 0056272c  5f                   pop edi
// 0056272d  5e                   pop esi
// 0056272e  83c410               add esp, 0x10
// 00562731  c20400               ret 4

#include <vector>

extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

namespace RBX {

class Instance;

struct sp_counted_base {
    virtual ~sp_counted_base();
    virtual void dispose();
    virtual void destroy();
    long use_count;
    long weak_count;
    void release()
    {
        if (_InterlockedDecrement(&use_count) == 0) {
            dispose();
            if (_InterlockedDecrement(&weak_count) == 0)
                destroy();
        }
    }
};

template<class T> struct shared_ptr {
    T* px;
    sp_counted_base* pn;
    ~shared_ptr() { if (pn != 0) pn->release(); }
    T* get() const { return px; }
};

typedef std::vector<Instance*> Instances;

class Workspace {
public:
    char pad0[0x104];
    const Instances* selection;                  // +0x104
    void setSelection(Instance* i);              // 00533250
};

class ChangeHistory {
public:
    void requestWaypoint(int kind);              // 0058c810
};

class DataModel {
public:
    Workspace* getWorkspace();                   // 00410d40
    ChangeHistory* getChangeHistory();           // 0055a920
};

class IDataState {
public:
    virtual void v0();
    virtual void setDirty(bool dirty);           // vtable +4
    void setSaveIndex(int i);                    // 004108b0
    int saveIndex;                               // +4
};

class Grouper {
public:
    shared_ptr<Instance> group(Instances::const_iterator begin, Instances::const_iterator end); // 005601b0
};

bool hasSecurity(DataModel* dataModel, int level);      // 004915a0
bool hasPermission(DataModel* dataModel, int level);    // 004915b0
void throwPermissionError(const char* message);
static __declspec(noinline) void checkLocked(DataModel* dataModel)  // 0055e290
{
    if (hasSecurity(dataModel, 1) && !hasPermission(dataModel, 1))
        throwPermissionError("Insufficinet permissions");
}

class GroupSelectionVerb {
public:
    void doIt(IDataState* dataState);
private:
    char pad0[0xc];
    Grouper* grouper;                            // +0xc
    char pad10[0x10];
    DataModel* dataModel;                        // +0x20
};

void GroupSelectionVerb::doIt(IDataState* dataState)
{
    checkLocked(dataModel);
    Workspace* workspace = dataModel ? dataModel->getWorkspace() : 0;
    Instance* g = grouper->group(workspace->selection->begin(), workspace->selection->end()).get();
    workspace->setSelection(g);
    (dataModel ? dataModel->getChangeHistory() : 0)->requestWaypoint(8);
    dataState->setSaveIndex(-1);
    dataState->saveIndex = -1;
    dataState->setDirty(true);
}
}
