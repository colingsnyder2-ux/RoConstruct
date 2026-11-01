// from server: 100% by Yeetserama
// roc 2012-06 004a0820  unit: CScriptEditor  size: 143 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004a0820
//
// 004a0820  6aff                 push -1
// 004a0822  68d9aea900           push 0xa9aed9
// 004a0827  64a100000000         mov eax, dword ptr fs:[0]
// 004a082d  50                   push eax
// 004a082e  64892500000000       mov dword ptr fs:[0], esp
// 004a0835  51                   push ecx
// 004a0836  56                   push esi
// 004a0837  57                   push edi
// 004a0838  e853340500           call 0x4f3c90
// 004a083d  8bf0                 mov esi, eax
// 004a083f  6a01                 push 1
// 004a0841  8bce                 mov ecx, esi
// 004a0843  e8e8c1ffff           call 0x49ca30
// 004a0848  6a01                 push 1
// 004a084a  50                   push eax
// 004a084b  8bce                 mov ecx, esi
// 004a084d  e80ec2ffff           call 0x49ca60
// 004a0852  8d4c2408             lea ecx, [esp + 8]
// 004a0856  8bf0                 mov esi, eax
// 004a0858  ff158447b200         call dword ptr [0xb24784]
// 004a085e  56                   push esi
// 004a085f  8d44240c             lea eax, [esp + 0xc]
// 004a0863  68c8000000           push 0xc8
// 004a0868  50                   push eax
// 004a0869  c744242000000000     mov dword ptr [esp + 0x20], 0
// 004a0871  ff150043b200         call dword ptr [0xb24300]
// 004a0877  8b742428             mov esi, dword ptr [esp + 0x28]
// 004a087b  8b3e                 mov edi, dword ptr [esi]
// 004a087d  83c40c               add esp, 0xc
// 004a0880  8d4c2408             lea ecx, [esp + 8]
// 004a0884  ff159847b200         call dword ptr [0xb24798]
// 004a088a  8b570c               mov edx, dword ptr [edi + 0xc]
// 004a088d  50                   push eax
// 004a088e  8bce                 mov ecx, esi
// 004a0890  ffd2                 call edx
// 004a0892  8d4c2408             lea ecx, [esp + 8]
// 004a0896  ff15d047b200         call dword ptr [0xb247d0]
// 004a089c  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004a08a0  5f                   pop edi
// 004a08a1  5e                   pop esi
// 004a08a2  64890d00000000       mov dword ptr fs:[0], ecx
// 004a08a9  83c410               add esp, 0x10
// 004a08ac  c20400               ret 4
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
