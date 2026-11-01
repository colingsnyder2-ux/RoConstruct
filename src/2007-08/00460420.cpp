// from server: 100% by Yeetserama
// roc 2007-08 00460420  unit: CScriptEditor  size: 173 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00460420
//
// 00460420  6aff                 push -1
// 00460422  68e9907600           push 0x7690e9
// 00460427  64a100000000         mov eax, dword ptr fs:[0]
// 0046042d  50                   push eax
// 0046042e  51                   push ecx
// 0046042f  53                   push ebx
// 00460430  56                   push esi
// 00460431  57                   push edi
// 00460432  a188518b00           mov eax, dword ptr [0x8b5188]
// 00460437  33c4                 xor eax, esp
// 00460439  50                   push eax
// 0046043a  8d442414             lea eax, [esp + 0x14]
// 0046043e  64a300000000         mov dword ptr fs:[0], eax
// 00460444  e8e7cdffff           call 0x45d230
// 00460449  8bf0                 mov esi, eax
// 0046044b  6a01                 push 1
// 0046044d  8bce                 mov ecx, esi
// 0046044f  e80cbbffff           call 0x45bf60
// 00460454  8bf8                 mov edi, eax
// 00460456  6a01                 push 1
// 00460458  57                   push edi
// 00460459  8bce                 mov ecx, esi
// 0046045b  e8f0c5ffff           call 0x45ca50
// 00460460  6a01                 push 1
// 00460462  57                   push edi
// 00460463  8bce                 mov ecx, esi
// 00460465  8bd8                 mov ebx, eax
// 00460467  e824c3ffff           call 0x45c790
// 0046046c  8d4c2410             lea ecx, [esp + 0x10]
// 00460470  8bf0                 mov esi, eax
// 00460472  ff15acdd7700         call dword ptr [0x77ddac]
// 00460478  57                   push edi
// 00460479  56                   push esi
// 0046047a  53                   push ebx
// 0046047b  8d44241c             lea eax, [esp + 0x1c]
// 0046047f  68c7000000           push 0xc7
// 00460484  50                   push eax
// 00460485  c744243000000000     mov dword ptr [esp + 0x30], 0
// 0046048d  ff15a4d57700         call dword ptr [0x77d5a4]
// 00460493  8b742438             mov esi, dword ptr [esp + 0x38]
// 00460497  8b3e                 mov edi, dword ptr [esi]
// 00460499  83c414               add esp, 0x14
// 0046049c  8d4c2410             lea ecx, [esp + 0x10]
// 004604a0  ff1598dd7700         call dword ptr [0x77dd98]
// 004604a6  8b570c               mov edx, dword ptr [edi + 0xc]
// 004604a9  50                   push eax
// 004604aa  8bce                 mov ecx, esi
// 004604ac  ffd2                 call edx
// 004604ae  8d4c2410             lea ecx, [esp + 0x10]
// 004604b2  ff15bcdd7700         call dword ptr [0x77ddbc]
// 004604b8  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004604bc  64890d00000000       mov dword ptr fs:[0], ecx
// 004604c3  59                   pop ecx
// 004604c4  5f                   pop edi
// 004604c5  5e                   pop esi
// 004604c6  5b                   pop ebx
// 004604c7  83c410               add esp, 0x10
// 004604ca  c20400               ret 4
// copied from an identical function in another client (function ?update@S@ns_ROCX000010@@QAEXPAUTarget@2@@Z)

namespace ns_ROCX000010 {
// from server: 100% by colin
struct Text;

extern void (__cdecl *formatText)(Text*, unsigned int, ...);

struct Text {
    char* data;
    __declspec(dllimport) Text();
    __declspec(dllimport) ~Text() throw();
    __declspec(dllimport) const char* get() const;
};







struct Control {
    int query(int);
    int column(int, int);
    int line(int, int);
};

struct Target;

struct TargetTable {
    void (__thiscall *slot0)(Target*);
    void (__thiscall *slot1)(Target*);
    void (__thiscall *slot2)(Target*);
    void (__thiscall *setText)(Target*, const char*);
};

struct Target {
    TargetTable* table;
};

struct S {
    int* f();
    void update(Target*);
};

void S::update(Target* target)
{
    Control* control = reinterpret_cast<Control*>(f());
    int position = control->query(1);
    int column = control->column(position, 1);
    int line = control->line(position, 1);
    Text text;
    formatText(&text, 199, column, line, position);
    TargetTable* table = target->table;
    const char* value = text.get();
    table->setText(target, value);
}
}
