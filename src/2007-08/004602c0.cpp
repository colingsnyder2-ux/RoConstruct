// from server: 100% by Yeetserama
// roc 2007-08 004602c0  unit: CScriptEditor  size: 155 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004602c0
//
// 004602c0  6aff                 push -1
// 004602c2  6849d87300           push 0x73d849
// 004602c7  64a100000000         mov eax, dword ptr fs:[0]
// 004602cd  50                   push eax
// 004602ce  51                   push ecx
// 004602cf  56                   push esi
// 004602d0  57                   push edi
// 004602d1  a188518b00           mov eax, dword ptr [0x8b5188]
// 004602d6  33c4                 xor eax, esp
// 004602d8  50                   push eax
// 004602d9  8d442410             lea eax, [esp + 0x10]
// 004602dd  64a300000000         mov dword ptr fs:[0], eax
// 004602e3  e848cfffff           call 0x45d230
// 004602e8  8bf0                 mov esi, eax
// 004602ea  6a01                 push 1
// 004602ec  8bce                 mov ecx, esi
// 004602ee  e86dbcffff           call 0x45bf60
// 004602f3  6a01                 push 1
// 004602f5  50                   push eax
// 004602f6  8bce                 mov ecx, esi
// 004602f8  e893bcffff           call 0x45bf90
// 004602fd  8d4c240c             lea ecx, [esp + 0xc]
// 00460301  8bf0                 mov esi, eax
// 00460303  ff15acdd7700         call dword ptr [0x77ddac]
// 00460309  56                   push esi
// 0046030a  8d442410             lea eax, [esp + 0x10]
// 0046030e  68c8000000           push 0xc8
// 00460313  50                   push eax
// 00460314  c744242400000000     mov dword ptr [esp + 0x24], 0
// 0046031c  ff15a4d57700         call dword ptr [0x77d5a4]
// 00460322  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 00460326  8b3e                 mov edi, dword ptr [esi]
// 00460328  83c40c               add esp, 0xc
// 0046032b  8d4c240c             lea ecx, [esp + 0xc]
// 0046032f  ff1598dd7700         call dword ptr [0x77dd98]
// 00460335  8b570c               mov edx, dword ptr [edi + 0xc]
// 00460338  50                   push eax
// 00460339  8bce                 mov ecx, esi
// 0046033b  ffd2                 call edx
// 0046033d  8d4c240c             lea ecx, [esp + 0xc]
// 00460341  ff15bcdd7700         call dword ptr [0x77ddbc]
// 00460347  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0046034b  64890d00000000       mov dword ptr fs:[0], ecx
// 00460352  59                   pop ecx
// 00460353  5f                   pop edi
// 00460354  5e                   pop esi
// 00460355  83c410               add esp, 0x10
// 00460358  c20400               ret 4
// copied from an identical function in another client (function ?fn_ROCX00000e_00464270@CScriptEditor@ns_ROCX00000e@@QAEXPAUCommand@2@@Z)

namespace ns_ROCX00000e {
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
    void fn_ROCX00000e_00464270(Command*);
};

void CScriptEditor::fn_ROCX00000e_00464270(Command* command)
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
