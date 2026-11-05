// from server: 100% by colin
// from server: 94% by king_originala
// roc 2008-06 00464270  unit: CScriptEditor  size: 143 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00464270
//
// 00464270  6aff                 push -1
// 00464272  68c9107c00           push 0x7c10c9
// 00464277  64a100000000         mov eax, dword ptr fs:[0]
// 0046427d  50                   push eax
// 0046427e  64892500000000       mov dword ptr fs:[0], esp
// 00464285  51                   push ecx
// 00464286  56                   push esi
// 00464287  57                   push edi
// 00464288  e843d1ffff           call 0x4613d0
// 0046428d  8bf0                 mov esi, eax
// 0046428f  6a01                 push 1
// 00464291  8bce                 mov ecx, esi
// 00464293  e888beffff           call 0x460120
// 00464298  6a01                 push 1
// 0046429a  50                   push eax
// 0046429b  8bce                 mov ecx, esi
// 0046429d  e8aebeffff           call 0x460150
// 004642a2  8d4c2408             lea ecx, [esp + 8]
// 004642a6  8bf0                 mov esi, eax
// 004642a8  ff15043f8000         call dword ptr [0x803f04]
// 004642ae  56                   push esi
// 004642af  8d44240c             lea eax, [esp + 0xc]
// 004642b3  68c8000000           push 0xc8
// 004642b8  50                   push eax
// 004642b9  c744242000000000     mov dword ptr [esp + 0x20], 0
// 004642c1  ff15c4328000         call dword ptr [0x8032c4]
// 004642c7  8b742428             mov esi, dword ptr [esp + 0x28]
// 004642cb  8b3e                 mov edi, dword ptr [esi]
// 004642cd  83c40c               add esp, 0xc
// 004642d0  8d4c2408             lea ecx, [esp + 8]
// 004642d4  ff15e03e8000         call dword ptr [0x803ee0]
// 004642da  8b570c               mov edx, dword ptr [edi + 0xc]
// 004642dd  50                   push eax
// 004642de  8bce                 mov ecx, esi
// 004642e0  ffd2                 call edx
// 004642e2  8d4c2408             lea ecx, [esp + 8]
// 004642e6  ff15143f8000         call dword ptr [0x803f14]
// 004642ec  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004642f0  5f                   pop edi
// 004642f1  5e                   pop esi
// 004642f2  64890d00000000       mov dword ptr fs:[0], ecx
// 004642f9  83c410               add esp, 0x10
// 004642fc  c20400               ret 4

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
    void func_00464270(Command*);
};

void CScriptEditor::func_00464270(Command* command)
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
