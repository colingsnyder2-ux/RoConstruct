// from server: 100% by Yeetserama
// roc 2010-06 00483530  unit: RBX::LDraw2Lua::LDrawParser  size: 362 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00483530
//
// 00483530  51                   push ecx
// 00483531  53                   push ebx
// 00483532  55                   push ebp
// 00483533  56                   push esi
// 00483534  57                   push edi
// 00483535  8bf9                 mov edi, ecx
// 00483537  8b4730               mov eax, dword ptr [edi + 0x30]
// 0048353a  2b472c               sub eax, dword ptr [edi + 0x2c]
// 0048353d  8d6f20               lea ebp, [edi + 0x20]
// 00483540  c1f802               sar eax, 2
// 00483543  896c2410             mov dword ptr [esp + 0x10], ebp
// 00483547  85c0                 test eax, eax
// 00483549  0f8643010000         jbe 0x483692
// 0048354f  8b742418             mov esi, dword ptr [esp + 0x18]
// 00483553  686431a100           push 0xa13164
// 00483558  68e431a100           push 0xa131e4
// 0048355d  686031a100           push 0xa13160
// 00483562  56                   push esi
// 00483563  e8b8a9fcff           call 0x44df20
// 00483568  83c408               add esp, 8
// 0048356b  50                   push eax
// 0048356c  e8afa9fcff           call 0x44df20
// 00483571  83c408               add esp, 8
// 00483574  50                   push eax
// 00483575  e8a6a9fcff           call 0x44df20
// 0048357a  83c408               add esp, 8
// 0048357d  686431a100           push 0xa13164
// 00483582  68c031a100           push 0xa131c0
// 00483587  56                   push esi
// 00483588  e893a9fcff           call 0x44df20
// 0048358d  83c408               add esp, 8
// 00483590  50                   push eax
// 00483591  e88aa9fcff           call 0x44df20
// 00483596  686431a100           push 0xa13164
// 0048359b  56                   push esi
// 0048359c  e87fa9fcff           call 0x44df20
// 004835a1  83c410               add esp, 0x10
// 004835a4  686431a100           push 0xa13164
// 004835a9  68ac31a100           push 0xa131ac
// 004835ae  686031a100           push 0xa13160
// 004835b3  56                   push esi
// 004835b4  e867a9fcff           call 0x44df20
// 004835b9  83c408               add esp, 8
// 004835bc  50                   push eax
// 004835bd  e85ea9fcff           call 0x44df20
// 004835c2  83c408               add esp, 8
// 004835c5  50                   push eax
// 004835c6  e855a9fcff           call 0x44df20
// 004835cb  83c408               add esp, 8
// 004835ce  686431a100           push 0xa13164
// 004835d3  689031a100           push 0xa13190
// 004835d8  56                   push esi
// 004835d9  e842a9fcff           call 0x44df20
// 004835de  83c408               add esp, 8
// 004835e1  50                   push eax
// 004835e2  e839a9fcff           call 0x44df20
// 004835e7  83c408               add esp, 8
// 004835ea  686431a100           push 0xa13164
// 004835ef  682830a100           push 0xa13028
// 004835f4  8d4f04               lea ecx, [edi + 4]
// 004835f7  ff1508a49e00         call dword ptr [0x9ea408]
// 004835fd  50                   push eax
// 004835fe  688431a100           push 0xa13184
// 00483603  56                   push esi
// 00483604  e817a9fcff           call 0x44df20
// 00483609  83c408               add esp, 8
// 0048360c  50                   push eax
// 0048360d  e80ea9fcff           call 0x44df20
// 00483612  83c408               add esp, 8
// 00483615  50                   push eax
// 00483616  e805a9fcff           call 0x44df20
// 0048361b  83c408               add esp, 8
// 0048361e  50                   push eax
// 0048361f  e8fca8fcff           call 0x44df20
// 00483624  83c408               add esp, 8
// 00483627  686431a100           push 0xa13164
// 0048362c  687431a100           push 0xa13174
// 00483631  56                   push esi
// 00483632  e8e9a8fcff           call 0x44df20
// 00483637  83c408               add esp, 8
// 0048363a  50                   push eax
// 0048363b  e8e0a8fcff           call 0x44df20
// 00483640  686431a100           push 0xa13164
// 00483645  56                   push esi
// 00483646  e8d5a8fcff           call 0x44df20
// 0048364b  8b7d10               mov edi, dword ptr [ebp + 0x10]
// 0048364e  2b7d0c               sub edi, dword ptr [ebp + 0xc]
// 00483651  83c410               add esp, 0x10
// 00483654  c1ff02               sar edi, 2
// 00483657  33db                 xor ebx, ebx
// 00483659  85ff                 test edi, edi
// 0048365b  7635                 jbe 0x483692
// 0048365d  eb05                 jmp 0x483664
// 0048365f  90                   nop 
// 00483660  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 00483664  53                   push ebx
// 00483665  8bcd                 mov ecx, ebp
// 00483667  e8b4fdffff           call 0x483420
// 0048366c  8b28                 mov ebp, dword ptr [eax]
// 0048366e  83ec1c               sub esp, 0x1c
// 00483671  8bcc                 mov ecx, esp
// 00483673  89642434             mov dword ptr [esp + 0x34], esp
// 00483677  687031a100           push 0xa13170
// 0048367c  ff1510a49e00         call dword ptr [0x9ea410]
// 00483682  8b5500               mov edx, dword ptr [ebp]
// 00483685  8b4204               mov eax, dword ptr [edx + 4]
// 00483688  56                   push esi
// 00483689  8bcd                 mov ecx, ebp
// 0048368b  ffd0                 call eax
// 0048368d  43                   inc ebx
// 0048368e  3bdf                 cmp ebx, edi
// 00483690  72ce                 jb 0x483660
// 00483692  5f                   pop edi
// 00483693  5e                   pop esi
// 00483694  5d                   pop ebp
// 00483695  5b                   pop ebx
// 00483696  59                   pop ecx
// 00483697  c20400               ret 4
// copied from an identical function in another client (function ?writeLua@LDrawParser@LDraw2Lua@RBX@@QBEXAAV?$basic_ostream@DU?$char_traits@D@std@@@std@@@Z)

// from server: 100% by EspClaude
// roc 2008-06 0046f6b0  unit: RBX::LDraw2Lua::LDrawParser
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>
#include <vector>
#include <ostream>

namespace RBX {
namespace LDraw2Lua {

class LDrawItem {
public:
    virtual ~LDrawItem();
    virtual void writeLua(std::ostream& out, std::string parent) const;
};

class LDrawParser {
    void* vtbl_pad;
    struct Name { __declspec(dllimport) const char* c_str() const; char pad[0x1c]; } name;
    std::vector<LDrawItem*> items;
public:
    void writeLua(std::ostream& out) const;
};

void LDrawParser::writeLua(std::ostream& out) const
{
    if (items.size() > 0) {
        out << "-- " << "Get the current workspace" << "\n";
        out << "local w = game:service(\"Workspace\")" << "\n";
        out << "\n";
        out << "-- " << "Create a new model" << "\n";
        out << "m = Instance.new(\"Model\")" << "\n";
        out << "m.Name = \"" << name.c_str() << "\"" << "\n";
        out << "m.Parent = w" << "\n";
        out << "\n";
        size_t count = items.size();
        for (size_t i = 0; i < count; ++i)
            items.at(i)->writeLua(out, "m");
    }
}

}
}