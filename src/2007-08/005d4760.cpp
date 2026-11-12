// from server: 59% by EspClaude
// from server: 45% by colin
// roc 2007-08 005d4760  unit: RBX::Tool  size: 269 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005d4760
//
// 005d4760  64a100000000         mov eax, dword ptr fs:[0]
// 005d4766  6aff                 push -1
// 005d4768  68509e7500           push 0x759e50
// 005d476d  50                   push eax
// 005d476e  64892500000000       mov dword ptr fs:[0], esp
// 005d4775  53                   push ebx
// 005d4776  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 005d477a  8b4304               mov eax, dword ptr [ebx + 4]
// 005d477d  55                   push ebp
// 005d477e  56                   push esi
// 005d477f  57                   push edi
// 005d4780  50                   push eax
// 005d4781  8bf1                 mov esi, ecx
// 005d4783  e8a820ebff           call 0x486830
// 005d4788  8b4b08               mov ecx, dword ptr [ebx + 8]
// 005d478b  51                   push ecx
// 005d478c  8bf8                 mov edi, eax
// 005d478e  e89d20ebff           call 0x486830
// 005d4793  83c408               add esp, 8
// 005d4796  85ff                 test edi, edi
// 005d4798  8be8                 mov ebp, eax
// 005d479a  0f8496000000         je 0x5d4836
// 005d47a0  6a01                 push 1
// 005d47a2  57                   push edi
// 005d47a3  e848ceebff           call 0x4915f0
// 005d47a8  83c408               add esp, 8
// 005d47ab  84c0                 test al, al
// 005d47ad  740c                 je 0x5d47bb
// 005d47af  57                   push edi
// 005d47b0  6a00                 push 0
// 005d47b2  8bce                 mov ecx, esi
// 005d47b4  e897feffff           call 0x5d4650
// 005d47b9  eb7b                 jmp 0x5d4836
// 005d47bb  83be6c01000006       cmp dword ptr [esi + 0x16c], 6
// 005d47c2  7523                 jne 0x5d47e7
// 005d47c4  8d4604               lea eax, [esi + 4]
// 005d47c7  50                   push eax
// 005d47c8  b914698c00           mov ecx, 0x8c6914
// 005d47cd  e89ebaf9ff           call 0x570270
// 005d47d2  33ff                 xor edi, edi
// 005d47d4  3bc7                 cmp eax, edi
// 005d47d6  7411                 je 0x5d47e9
// 005d47d8  8d542420             lea edx, [esp + 0x20]
// 005d47dc  52                   push edx
// 005d47dd  8d4810               lea ecx, [eax + 0x10]
// 005d47e0  e87bbbedff           call 0x4b0360
// 005d47e5  eb02                 jmp 0x5d47e9
// 005d47e7  33ff                 xor edi, edi
// 005d47e9  83be6c01000005       cmp dword ptr [esi + 0x16c], 5
// 005d47f0  7c3e                 jl 0x5d4830
// 005d47f2  8d4604               lea eax, [esi + 4]
// 005d47f5  50                   push eax
// 005d47f6  b938698c00           mov ecx, 0x8c6938
// 005d47fb  e870baf9ff           call 0x570270
// 005d4800  3bc7                 cmp eax, edi
// 005d4802  740d                 je 0x5d4811
// 005d4804  8d4c2420             lea ecx, [esp + 0x20]
// 005d4808  51                   push ecx
// 005d4809  8d4810               lea ecx, [eax + 0x10]
// 005d480c  e84fbbedff           call 0x4b0360
// 005d4811  39beb0010000         cmp dword ptr [esi + 0x1b0], edi
// 005d4817  7417                 je 0x5d4830
// 005d4819  8b8eb4010000         mov ecx, dword ptr [esi + 0x1b4]
// 005d481f  89beb0010000         mov dword ptr [esi + 0x1b0], edi
// 005d4825  e85686faff           call 0x57ce80
// 005d482a  89beb4010000         mov dword ptr [esi + 0x1b4], edi
// 005d4830  89be6c010000         mov dword ptr [esi + 0x16c], edi
// 005d4836  53                   push ebx
// 005d4837  8bce                 mov ecx, esi
// 005d4839  e822d1f6ff           call 0x541960
// 005d483e  85ed                 test ebp, ebp
// 005d4840  7416                 je 0x5d4858
// 005d4842  6a01                 push 1
// 005d4844  55                   push ebp
// 005d4845  e8a6cdebff           call 0x4915f0
// 005d484a  83c408               add esp, 8
// 005d484d  84c0                 test al, al
// 005d484f  7407                 je 0x5d4858
// 005d4851  8bce                 mov ecx, esi
// 005d4853  e8a8d9ffff           call 0x5d2200
// 005d4858  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005d485c  5f                   pop edi
// 005d485d  5e                   pop esi
// 005d485e  5d                   pop ebp
// 005d485f  64890d00000000       mov dword ptr fs:[0], ecx
// 005d4866  5b                   pop ebx
// 005d4867  83c40c               add esp, 0xc
// 005d486a  c20400               ret 4

// Callees and offsets read from the target: 0x486830 cdecl(ptr)->ptr on event+4/+8;
// 0x4915f0 cdecl(ptr,1)->bool; 0x570270 thiscall on globals 0x8c6914/0x8c6938 taking
// this+4 (second base); 0x4b0360 thiscall on result+0x10 taking &event (param slot);
// state at +0x16c, pair at +0x1b0/+0x1b4; 0x541960 base handler; 0x5d2200 no-arg member.
namespace RBX {

class Instance;
class Workspace;
struct AncestorChanged { int vtbl; Instance* oldParent; Instance* newParent; };

struct Listener {
    void operator()(const AncestorChanged* const& e);
};
struct Entry { int pad[4]; Listener listener; };

struct Base4 { int b; };

struct Registry {
    Entry* find(Base4* key);
};
extern Registry registryA;
extern Registry registryB;

struct Holder { void release(); };

Workspace* findWorkspace(Instance* i);
bool isActive(Workspace* w, bool flag);

class ToolBase {
public:
    int a0;
    void onAncestorChanged(const AncestorChanged& event);
};

class Tool : public ToolBase, public Base4 {
    int pad[0x59];
    int state;          // +0x16c
    int pad2[0x10];
    int holding;        // +0x1b0
    Holder* holder;     // +0x1b4
    void equip(int x, Workspace* w);
    void onActivated();
public:
    void onAncestorChanged(const AncestorChanged& event);
};

void Tool::onAncestorChanged(const AncestorChanged& event)
{
    Workspace* oldWorkspace = findWorkspace(event.oldParent);
    Workspace* newWorkspace = findWorkspace(event.newParent);
    if (oldWorkspace) {
        if (isActive(oldWorkspace, true)) {
            equip(0, oldWorkspace);
        } else {
            if (state == 6) {
                if (Entry* e = registryA.find(this))
                    e->listener(&event);
            }
            if (state >= 5) {
                if (Entry* e = registryB.find(this))
                    e->listener(&event);
                if (holding) {
                    Holder* h = holder;
                    holding = 0;
                    h->release();
                    holder = 0;
                }
            }
            state = 0;
        }
    }
    ToolBase::onAncestorChanged(event);
    if (newWorkspace && isActive(newWorkspace, true))
        onActivated();
}

}
