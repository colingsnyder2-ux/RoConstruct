// from server: 100% by Yeetserama
// roc 2010-06 00471720  unit: CScriptEditor  size: 143 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00471720
//
// 00471720  6aff                 push -1
// 00471722  68a9fe9700           push 0x97fea9
// 00471727  64a100000000         mov eax, dword ptr fs:[0]
// 0047172d  50                   push eax
// 0047172e  64892500000000       mov dword ptr fs:[0], esp
// 00471735  51                   push ecx
// 00471736  56                   push esi
// 00471737  57                   push edi
// 00471738  e8b3cfffff           call 0x46e6f0
// 0047173d  8bf0                 mov esi, eax
// 0047173f  6a01                 push 1
// 00471741  8bce                 mov ecx, esi
// 00471743  e8e8bcffff           call 0x46d430
// 00471748  6a01                 push 1
// 0047174a  50                   push eax
// 0047174b  8bce                 mov ecx, esi
// 0047174d  e80ebdffff           call 0x46d460
// 00471752  8d4c2408             lea ecx, [esp + 8]
// 00471756  8bf0                 mov esi, eax
// 00471758  ff15a4ce9e00         call dword ptr [0x9ecea4]
// 0047175e  56                   push esi
// 0047175f  8d44240c             lea eax, [esp + 0xc]
// 00471763  68c8000000           push 0xc8
// 00471768  50                   push eax
// 00471769  c744242000000000     mov dword ptr [esp + 0x20], 0
// 00471771  ff1550c39e00         call dword ptr [0x9ec350]
// 00471777  8b742428             mov esi, dword ptr [esp + 0x28]
// 0047177b  8b3e                 mov edi, dword ptr [esi]
// 0047177d  83c40c               add esp, 0xc
// 00471780  8d4c2408             lea ecx, [esp + 8]
// 00471784  ff15b0ce9e00         call dword ptr [0x9eceb0]
// 0047178a  8b570c               mov edx, dword ptr [edi + 0xc]
// 0047178d  50                   push eax
// 0047178e  8bce                 mov ecx, esi
// 00471790  ffd2                 call edx
// 00471792  8d4c2408             lea ecx, [esp + 8]
// 00471796  ff15f0ce9e00         call dword ptr [0x9ecef0]
// 0047179c  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004717a0  5f                   pop edi
// 004717a1  5e                   pop esi
// 004717a2  64890d00000000       mov dword ptr fs:[0], ecx
// 004717a9  83c410               add esp, 0x10
// 004717ac  c20400               ret 4
// copied from an identical function in another client (function ?fn_ROCX000003_00464270@CScriptEditor@ns_ROCX000003@@QAEXPAUCommand@2@@Z)

namespace ns_ROCX000003 {
struct __declspec(dllimport) Text {
    char* data;
    Text();
    ~Text() throw();
    const char* get() const;
    static void __cdecl format(Text*, unsigned int, ...);
};

struct Control {
    int position(bool);
    int line(int, bool);
};

struct Command;
typedef void (__thiscall *SetText)(Command*, const char*);

struct CommandTable {
    void* slots[3];
    SetText setText;
};

struct Command {
    CommandTable* table;
};

struct CScriptEditor {
    int* control();
    void fn_ROCX000003_00464270(Command*);
};

void CScriptEditor::fn_ROCX000003_00464270(Command* command)
{
    Control* p = reinterpret_cast<Control*>(control());
    int position = p->position(true);
    int line = p->line(position, true);
    Text text;
    Text::format(&text, 200, line);
    CommandTable* table = command->table;
    const char* value = text.get();
    table->setText(command, value);
}
}
