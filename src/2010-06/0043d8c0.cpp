// from server: 100% by Yeetserama
// roc 2010-06 0043d8c0  unit: ScriptItem  size: 329 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0043d8c0
//
// 0043d8c0  83ec24               sub esp, 0x24
// 0043d8c3  837c242800           cmp dword ptr [esp + 0x28], 0
// 0043d8c8  53                   push ebx
// 0043d8c9  55                   push ebp
// 0043d8ca  56                   push esi
// 0043d8cb  8bd9                 mov ebx, ecx
// 0043d8cd  57                   push edi
// 0043d8ce  895c2410             mov dword ptr [esp + 0x10], ebx
// 0043d8d2  7506                 jne 0x43d8da
// 0043d8d4  ff150ca99e00         call dword ptr [0x9ea90c]
// 0043d8da  8b7310               mov esi, dword ptr [ebx + 0x10]
// 0043d8dd  3b7314               cmp esi, dword ptr [ebx + 0x14]
// 0043d8e0  7606                 jbe 0x43d8e8
// 0043d8e2  ff150ca99e00         call dword ptr [0x9ea90c]
// 0043d8e8  8b7b04               mov edi, dword ptr [ebx + 4]
// 0043d8eb  8bee                 mov ebp, esi
// 0043d8ed  8b7314               mov esi, dword ptr [ebx + 0x14]
// 0043d8f0  897c2424             mov dword ptr [esp + 0x24], edi
// 0043d8f4  89742418             mov dword ptr [esp + 0x18], esi
// 0043d8f8  397310               cmp dword ptr [ebx + 0x10], esi
// 0043d8fb  7606                 jbe 0x43d903
// 0043d8fd  ff150ca99e00         call dword ptr [0x9ea90c]
// 0043d903  8b4304               mov eax, dword ptr [ebx + 4]
// 0043d906  8944242c             mov dword ptr [esp + 0x2c], eax
// 0043d90a  8d9b00000000         lea ebx, [ebx]
// 0043d910  85ff                 test edi, edi
// 0043d912  7406                 je 0x43d91a
// 0043d914  3b7c242c             cmp edi, dword ptr [esp + 0x2c]
// 0043d918  7406                 je 0x43d920
// 0043d91a  ff150ca99e00         call dword ptr [0x9ea90c]
// 0043d920  3bee                 cmp ebp, esi
// 0043d922  0f84ca000000         je 0x43d9f2
// 0043d928  85ff                 test edi, edi
// 0043d92a  0f8595000000         jne 0x43d9c5
// 0043d930  ff150ca99e00         call dword ptr [0x9ea90c]
// 0043d936  33c0                 xor eax, eax
// 0043d938  3b6810               cmp ebp, dword ptr [eax + 0x10]
// 0043d93b  7206                 jb 0x43d943
// 0043d93d  ff150ca99e00         call dword ptr [0x9ea90c]
// 0043d943  8b4d00               mov ecx, dword ptr [ebp]
// 0043d946  8b742438             mov esi, dword ptr [esp + 0x38]
// 0043d94a  8d542414             lea edx, [esp + 0x14]
// 0043d94e  52                   push edx
// 0043d94f  8d442420             lea eax, [esp + 0x20]
// 0043d953  894c2418             mov dword ptr [esp + 0x18], ecx
// 0043d957  50                   push eax
// 0043d958  8bce                 mov ecx, esi
// 0043d95a  e84182ffff           call 0x435ba0
// 0043d95f  8b7e18               mov edi, dword ptr [esi + 0x18]
// 0043d962  8b06                 mov eax, dword ptr [esi]
// 0043d964  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 0043d968  85f6                 test esi, esi
// 0043d96a  7404                 je 0x43d970
// 0043d96c  3bf0                 cmp esi, eax
// 0043d96e  7406                 je 0x43d976
// 0043d970  ff150ca99e00         call dword ptr [0x9ea90c]
// 0043d976  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 0043d97a  3bdf                 cmp ebx, edi
// 0043d97c  8b3d0ca99e00         mov edi, dword ptr [0x9ea90c]
// 0043d982  741a                 je 0x43d99e
// 0043d984  85f6                 test esi, esi
// 0043d986  7544                 jne 0x43d9cc
// 0043d988  ffd7                 call edi
// 0043d98a  3b5e18               cmp ebx, dword ptr [esi + 0x18]
// 0043d98d  7502                 jne 0x43d991
// 0043d98f  ffd7                 call edi
// 0043d991  8b4320               mov eax, dword ptr [ebx + 0x20]
// 0043d994  2b431c               sub eax, dword ptr [ebx + 0x1c]
// 0043d997  c1f803               sar eax, 3
// 0043d99a  85c0                 test eax, eax
// 0043d99c  7736                 ja 0x43d9d4
// 0043d99e  8b442424             mov eax, dword ptr [esp + 0x24]
// 0043d9a2  85c0                 test eax, eax
// 0043d9a4  752a                 jne 0x43d9d0
// 0043d9a6  ffd7                 call edi
// 0043d9a8  33c0                 xor eax, eax
// 0043d9aa  3b6810               cmp ebp, dword ptr [eax + 0x10]
// 0043d9ad  7202                 jb 0x43d9b1
// 0043d9af  ffd7                 call edi
// 0043d9b1  8b742418             mov esi, dword ptr [esp + 0x18]
// 0043d9b5  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 0043d9b9  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0043d9bd  83c504               add ebp, 4
// 0043d9c0  e94bffffff           jmp 0x43d910
// 0043d9c5  8b07                 mov eax, dword ptr [edi]
// 0043d9c7  e96cffffff           jmp 0x43d938
// 0043d9cc  8b36                 mov esi, dword ptr [esi]
// 0043d9ce  ebba                 jmp 0x43d98a
// 0043d9d0  8b00                 mov eax, dword ptr [eax]
// 0043d9d2  ebd6                 jmp 0x43d9aa
// 0043d9d4  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0043d9d8  5f                   pop edi
// 0043d9d9  5e                   pop esi
// 0043d9da  5d                   pop ebp
// 0043d9db  5b                   pop ebx
// 0043d9dc  83c424               add esp, 0x24
// 0043d9df  c744240400000000     mov dword ptr [esp + 4], 0
// 0043d9e7  81c1f4feffff         add ecx, 0xfffffef4
// 0043d9ed  e9beae3d00           jmp 0x8188b0
// 0043d9f2  6a01                 push 1
// 0043d9f4  8d8bf4feffff         lea ecx, [ebx - 0x10c]
// 0043d9fa  e8b1ae3d00           call 0x8188b0
// 0043d9ff  5f                   pop edi
// 0043da00  5e                   pop esi
// 0043da01  5d                   pop ebp
// 0043da02  5b                   pop ebx
// 0043da03  83c424               add esp, 0x24
// 0043da06  c20400               ret 4
// copied from an identical function in another client (function ?update@ScriptItem@@UAEXAAV?$map@PBUClassDescriptor@@V?$vector@UInstancePtr@@V?$allocator@UInstancePtr@@@std@@@std@@U?$less@PBUClassDescriptor@@@3@V?$allocator@U?$pair@QBUClassDescriptor@@V?$vector@UInstancePtr@@V?$allocator@UInstancePtr@@@std@@@std@@@std@@@3@@std@@@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <map>
#include <vector>

struct Instance;
struct ClassDescriptor;
struct InstancePtr { Instance* px; void* pn; };
typedef std::vector<InstancePtr> Instances;
typedef std::map<const ClassDescriptor*, Instances> Selection;

class CXTPPropertyGridItem {
public:
    virtual ~CXTPPropertyGridItem();
    void SetHidden(int bHidden);
    char pad[0x108];
};

struct UpdateBase {
    virtual void update(Selection& selection);
    std::vector<const ClassDescriptor*> classes;
};

struct ScriptItem : CXTPPropertyGridItem, UpdateBase {
    void update(Selection& selection);
};

void ScriptItem::update(Selection& selection)
{
    Selection::iterator selectionEnd = selection.end();
    for (std::vector<const ClassDescriptor*>::const_iterator c = classes.begin(), ce = classes.end(); c != ce; ++c) {
        const ClassDescriptor* key = *c;
        Selection::iterator selected = selection.find(key);
        size_t n = selected != selection.end() ? selected->second.size() : 0;
        if (n > 0) {
            SetHidden(0);
            return;
        }
    }
    SetHidden(1);
}