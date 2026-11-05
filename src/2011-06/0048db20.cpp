// from server: 100% by Yeetserama
// roc 2011-06 0048db20  unit: CScriptEditor  size: 143 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0048db20
//
// 0048db20  6aff                 push -1
// 0048db22  68395f9d00           push 0x9d5f39
// 0048db27  64a100000000         mov eax, dword ptr fs:[0]
// 0048db2d  50                   push eax
// 0048db2e  64892500000000       mov dword ptr fs:[0], esp
// 0048db35  51                   push ecx
// 0048db36  56                   push esi
// 0048db37  57                   push edi
// 0048db38  e8b3d4ffff           call 0x48aff0
// 0048db3d  8bf0                 mov esi, eax
// 0048db3f  6a01                 push 1
// 0048db41  8bce                 mov ecx, esi
// 0048db43  e8b8c1ffff           call 0x489d00
// 0048db48  6a01                 push 1
// 0048db4a  50                   push eax
// 0048db4b  8bce                 mov ecx, esi
// 0048db4d  e8dec1ffff           call 0x489d30
// 0048db52  8d4c2408             lea ecx, [esp + 8]
// 0048db56  8bf0                 mov esi, eax
// 0048db58  ff15b42da400         call dword ptr [0xa42db4]
// 0048db5e  56                   push esi
// 0048db5f  8d44240c             lea eax, [esp + 0xc]
// 0048db63  68c8000000           push 0xc8
// 0048db68  50                   push eax
// 0048db69  c744242000000000     mov dword ptr [esp + 0x20], 0
// 0048db71  ff153423a400         call dword ptr [0xa42334]
// 0048db77  8b742428             mov esi, dword ptr [esp + 0x28]
// 0048db7b  8b3e                 mov edi, dword ptr [esi]
// 0048db7d  83c40c               add esp, 0xc
// 0048db80  8d4c2408             lea ecx, [esp + 8]
// 0048db84  ff15c82da400         call dword ptr [0xa42dc8]
// 0048db8a  8b570c               mov edx, dword ptr [edi + 0xc]
// 0048db8d  50                   push eax
// 0048db8e  8bce                 mov ecx, esi
// 0048db90  ffd2                 call edx
// 0048db92  8d4c2408             lea ecx, [esp + 8]
// 0048db96  ff15082ea400         call dword ptr [0xa42e08]
// 0048db9c  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0048dba0  5f                   pop edi
// 0048dba1  5e                   pop esi
// 0048dba2  64890d00000000       mov dword ptr fs:[0], ecx
// 0048dba9  83c410               add esp, 0x10
// 0048dbac  c20400               ret 4
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
