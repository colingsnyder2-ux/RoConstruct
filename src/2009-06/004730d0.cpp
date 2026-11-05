// from server: 100% by EspClaude
// roc 2009-06 004730d0  unit: RBX::LDraw2Lua::LDrawParser  size: 362 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004730d0
//
// 004730d0  51                   push ecx
// 004730d1  53                   push ebx
// 004730d2  55                   push ebp
// 004730d3  56                   push esi
// 004730d4  57                   push edi
// 004730d5  8bf9                 mov edi, ecx
// 004730d7  8b4730               mov eax, dword ptr [edi + 0x30]
// 004730da  2b472c               sub eax, dword ptr [edi + 0x2c]
// 004730dd  8d6f20               lea ebp, [edi + 0x20]
// 004730e0  c1f802               sar eax, 2
// 004730e3  896c2410             mov dword ptr [esp + 0x10], ebp
// 004730e7  85c0                 test eax, eax
// 004730e9  0f8643010000         jbe 0x473232
// 004730ef  8b742418             mov esi, dword ptr [esp + 0x18]
// 004730f3  682cdb8b00           push 0x8bdb2c
// 004730f8  68acdb8b00           push 0x8bdbac
// 004730fd  6828db8b00           push 0x8bdb28
// 00473102  56                   push esi
// 00473103  e80836fdff           call 0x446710
// 00473108  83c408               add esp, 8
// 0047310b  50                   push eax
// 0047310c  e8ff35fdff           call 0x446710
// 00473111  83c408               add esp, 8
// 00473114  50                   push eax
// 00473115  e8f635fdff           call 0x446710
// 0047311a  83c408               add esp, 8
// 0047311d  682cdb8b00           push 0x8bdb2c
// 00473122  6888db8b00           push 0x8bdb88
// 00473127  56                   push esi
// 00473128  e8e335fdff           call 0x446710
// 0047312d  83c408               add esp, 8
// 00473130  50                   push eax
// 00473131  e8da35fdff           call 0x446710
// 00473136  682cdb8b00           push 0x8bdb2c
// 0047313b  56                   push esi
// 0047313c  e8cf35fdff           call 0x446710
// 00473141  83c410               add esp, 0x10
// 00473144  682cdb8b00           push 0x8bdb2c
// 00473149  6874db8b00           push 0x8bdb74
// 0047314e  6828db8b00           push 0x8bdb28
// 00473153  56                   push esi
// 00473154  e8b735fdff           call 0x446710
// 00473159  83c408               add esp, 8
// 0047315c  50                   push eax
// 0047315d  e8ae35fdff           call 0x446710
// 00473162  83c408               add esp, 8
// 00473165  50                   push eax
// 00473166  e8a535fdff           call 0x446710
// 0047316b  83c408               add esp, 8
// 0047316e  682cdb8b00           push 0x8bdb2c
// 00473173  6858db8b00           push 0x8bdb58
// 00473178  56                   push esi
// 00473179  e89235fdff           call 0x446710
// 0047317e  83c408               add esp, 8
// 00473181  50                   push eax
// 00473182  e88935fdff           call 0x446710
// 00473187  83c408               add esp, 8
// 0047318a  682cdb8b00           push 0x8bdb2c
// 0047318f  68f0d98b00           push 0x8bd9f0
// 00473194  8d4f04               lea ecx, [edi + 4]
// 00473197  ff15bce48900         call dword ptr [0x89e4bc]
// 0047319d  50                   push eax
// 0047319e  684cdb8b00           push 0x8bdb4c
// 004731a3  56                   push esi
// 004731a4  e86735fdff           call 0x446710
// 004731a9  83c408               add esp, 8
// 004731ac  50                   push eax
// 004731ad  e85e35fdff           call 0x446710
// 004731b2  83c408               add esp, 8
// 004731b5  50                   push eax
// 004731b6  e85535fdff           call 0x446710
// 004731bb  83c408               add esp, 8
// 004731be  50                   push eax
// 004731bf  e84c35fdff           call 0x446710
// 004731c4  83c408               add esp, 8
// 004731c7  682cdb8b00           push 0x8bdb2c
// 004731cc  683cdb8b00           push 0x8bdb3c
// 004731d1  56                   push esi
// 004731d2  e83935fdff           call 0x446710
// 004731d7  83c408               add esp, 8
// 004731da  50                   push eax
// 004731db  e83035fdff           call 0x446710
// 004731e0  682cdb8b00           push 0x8bdb2c
// 004731e5  56                   push esi
// 004731e6  e82535fdff           call 0x446710
// 004731eb  8b7d10               mov edi, dword ptr [ebp + 0x10]
// 004731ee  2b7d0c               sub edi, dword ptr [ebp + 0xc]
// 004731f1  83c410               add esp, 0x10
// 004731f4  c1ff02               sar edi, 2
// 004731f7  33db                 xor ebx, ebx
// 004731f9  85ff                 test edi, edi
// 004731fb  7635                 jbe 0x473232
// 004731fd  eb05                 jmp 0x473204
// 004731ff  90                   nop 
// 00473200  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 00473204  53                   push ebx
// 00473205  8bcd                 mov ecx, ebp
// 00473207  e8b4fdffff           call 0x472fc0
// 0047320c  8b28                 mov ebp, dword ptr [eax]
// 0047320e  83ec1c               sub esp, 0x1c
// 00473211  8bcc                 mov ecx, esp
// 00473213  89642434             mov dword ptr [esp + 0x34], esp
// 00473217  6838db8b00           push 0x8bdb38
// 0047321c  ff15b4e48900         call dword ptr [0x89e4b4]
// 00473222  8b5500               mov edx, dword ptr [ebp]
// 00473225  8b4204               mov eax, dword ptr [edx + 4]
// 00473228  56                   push esi
// 00473229  8bcd                 mov ecx, ebp
// 0047322b  ffd0                 call eax
// 0047322d  43                   inc ebx
// 0047322e  3bdf                 cmp ebx, edi
// 00473230  72ce                 jb 0x473200
// 00473232  5f                   pop edi
// 00473233  5e                   pop esi
// 00473234  5d                   pop ebp
// 00473235  5b                   pop ebx
// 00473236  59                   pop ecx
// 00473237  c20400               ret 4
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