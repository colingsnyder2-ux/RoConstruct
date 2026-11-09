// from server: 100% by EspClaude
// roc 2009-06 004387c0  unit: ScriptItem  size: 329 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004387c0
//
// 004387c0  83ec24               sub esp, 0x24
// 004387c3  837c242800           cmp dword ptr [esp + 0x28], 0
// 004387c8  53                   push ebx
// 004387c9  55                   push ebp
// 004387ca  56                   push esi
// 004387cb  8bd9                 mov ebx, ecx
// 004387cd  57                   push edi
// 004387ce  895c2410             mov dword ptr [esp + 0x10], ebx
// 004387d2  7506                 jne 0x4387da
// 004387d4  ff15ace98900         call dword ptr [0x89e9ac]
// 004387da  8b7310               mov esi, dword ptr [ebx + 0x10]
// 004387dd  3b7314               cmp esi, dword ptr [ebx + 0x14]
// 004387e0  7606                 jbe 0x4387e8
// 004387e2  ff15ace98900         call dword ptr [0x89e9ac]
// 004387e8  8b7b04               mov edi, dword ptr [ebx + 4]
// 004387eb  8bee                 mov ebp, esi
// 004387ed  8b7314               mov esi, dword ptr [ebx + 0x14]
// 004387f0  897c2424             mov dword ptr [esp + 0x24], edi
// 004387f4  89742418             mov dword ptr [esp + 0x18], esi
// 004387f8  397310               cmp dword ptr [ebx + 0x10], esi
// 004387fb  7606                 jbe 0x438803
// 004387fd  ff15ace98900         call dword ptr [0x89e9ac]
// 00438803  8b4304               mov eax, dword ptr [ebx + 4]
// 00438806  8944242c             mov dword ptr [esp + 0x2c], eax
// 0043880a  8d9b00000000         lea ebx, [ebx]
// 00438810  85ff                 test edi, edi
// 00438812  7406                 je 0x43881a
// 00438814  3b7c242c             cmp edi, dword ptr [esp + 0x2c]
// 00438818  7406                 je 0x438820
// 0043881a  ff15ace98900         call dword ptr [0x89e9ac]
// 00438820  3bee                 cmp ebp, esi
// 00438822  0f84ca000000         je 0x4388f2
// 00438828  85ff                 test edi, edi
// 0043882a  0f8595000000         jne 0x4388c5
// 00438830  ff15ace98900         call dword ptr [0x89e9ac]
// 00438836  33c0                 xor eax, eax
// 00438838  3b6810               cmp ebp, dword ptr [eax + 0x10]
// 0043883b  7206                 jb 0x438843
// 0043883d  ff15ace98900         call dword ptr [0x89e9ac]
// 00438843  8b4d00               mov ecx, dword ptr [ebp]
// 00438846  8b742438             mov esi, dword ptr [esp + 0x38]
// 0043884a  8d542414             lea edx, [esp + 0x14]
// 0043884e  52                   push edx
// 0043884f  8d442420             lea eax, [esp + 0x20]
// 00438853  894c2418             mov dword ptr [esp + 0x18], ecx
// 00438857  50                   push eax
// 00438858  8bce                 mov ecx, esi
// 0043885a  e801beffff           call 0x434660
// 0043885f  8b7e18               mov edi, dword ptr [esi + 0x18]
// 00438862  8b06                 mov eax, dword ptr [esi]
// 00438864  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 00438868  85f6                 test esi, esi
// 0043886a  7404                 je 0x438870
// 0043886c  3bf0                 cmp esi, eax
// 0043886e  7406                 je 0x438876
// 00438870  ff15ace98900         call dword ptr [0x89e9ac]
// 00438876  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 0043887a  3bdf                 cmp ebx, edi
// 0043887c  8b3dace98900         mov edi, dword ptr [0x89e9ac]
// 00438882  741a                 je 0x43889e
// 00438884  85f6                 test esi, esi
// 00438886  7544                 jne 0x4388cc
// 00438888  ffd7                 call edi
// 0043888a  3b5e18               cmp ebx, dword ptr [esi + 0x18]
// 0043888d  7502                 jne 0x438891
// 0043888f  ffd7                 call edi
// 00438891  8b4320               mov eax, dword ptr [ebx + 0x20]
// 00438894  2b431c               sub eax, dword ptr [ebx + 0x1c]
// 00438897  c1f803               sar eax, 3
// 0043889a  85c0                 test eax, eax
// 0043889c  7736                 ja 0x4388d4
// 0043889e  8b442424             mov eax, dword ptr [esp + 0x24]
// 004388a2  85c0                 test eax, eax
// 004388a4  752a                 jne 0x4388d0
// 004388a6  ffd7                 call edi
// 004388a8  33c0                 xor eax, eax
// 004388aa  3b6810               cmp ebp, dword ptr [eax + 0x10]
// 004388ad  7202                 jb 0x4388b1
// 004388af  ffd7                 call edi
// 004388b1  8b742418             mov esi, dword ptr [esp + 0x18]
// 004388b5  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 004388b9  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 004388bd  83c504               add ebp, 4
// 004388c0  e94bffffff           jmp 0x438810
// 004388c5  8b07                 mov eax, dword ptr [edi]
// 004388c7  e96cffffff           jmp 0x438838
// 004388cc  8b36                 mov esi, dword ptr [esi]
// 004388ce  ebba                 jmp 0x43888a
// 004388d0  8b00                 mov eax, dword ptr [eax]
// 004388d2  ebd6                 jmp 0x4388aa
// 004388d4  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004388d8  5f                   pop edi
// 004388d9  5e                   pop esi
// 004388da  5d                   pop ebp
// 004388db  5b                   pop ebx
// 004388dc  83c424               add esp, 0x24
// 004388df  c744240400000000     mov dword ptr [esp + 4], 0
// 004388e7  81c1f4feffff         add ecx, 0xfffffef4
// 004388ed  e9de0f3500           jmp 0x7898d0
// 004388f2  6a01                 push 1
// 004388f4  8d8bf4feffff         lea ecx, [ebx - 0x10c]
// 004388fa  e8d10f3500           call 0x7898d0
// 004388ff  5f                   pop edi
// 00438900  5e                   pop esi
// 00438901  5d                   pop ebp
// 00438902  5b                   pop ebx
// 00438903  83c424               add esp, 0x24
// 00438906  c20400               ret 4
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