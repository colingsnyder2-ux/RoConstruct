// from server: 100% by Yeetserama
// roc 2012-06 004a0960  unit: CScriptEditor  size: 161 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004a0960
//
// 004a0960  6aff                 push -1
// 004a0962  68d9aea900           push 0xa9aed9
// 004a0967  64a100000000         mov eax, dword ptr fs:[0]
// 004a096d  50                   push eax
// 004a096e  64892500000000       mov dword ptr fs:[0], esp
// 004a0975  51                   push ecx
// 004a0976  53                   push ebx
// 004a0977  56                   push esi
// 004a0978  57                   push edi
// 004a0979  e812330500           call 0x4f3c90
// 004a097e  8bf0                 mov esi, eax
// 004a0980  6a01                 push 1
// 004a0982  8bce                 mov ecx, esi
// 004a0984  e8a7c0ffff           call 0x49ca30
// 004a0989  8bf8                 mov edi, eax
// 004a098b  6a01                 push 1
// 004a098d  57                   push edi
// 004a098e  8bce                 mov ecx, esi
// 004a0990  e8cbcbffff           call 0x49d560
// 004a0995  6a01                 push 1
// 004a0997  57                   push edi
// 004a0998  8bce                 mov ecx, esi
// 004a099a  8bd8                 mov ebx, eax
// 004a099c  e8ffc8ffff           call 0x49d2a0
// 004a09a1  8d4c240c             lea ecx, [esp + 0xc]
// 004a09a5  8bf0                 mov esi, eax
// 004a09a7  ff158447b200         call dword ptr [0xb24784]
// 004a09ad  57                   push edi
// 004a09ae  56                   push esi
// 004a09af  53                   push ebx
// 004a09b0  8d442418             lea eax, [esp + 0x18]
// 004a09b4  68c7000000           push 0xc7
// 004a09b9  50                   push eax
// 004a09ba  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 004a09c2  ff150043b200         call dword ptr [0xb24300]
// 004a09c8  8b742434             mov esi, dword ptr [esp + 0x34]
// 004a09cc  8b3e                 mov edi, dword ptr [esi]
// 004a09ce  83c414               add esp, 0x14
// 004a09d1  8d4c240c             lea ecx, [esp + 0xc]
// 004a09d5  ff159847b200         call dword ptr [0xb24798]
// 004a09db  8b570c               mov edx, dword ptr [edi + 0xc]
// 004a09de  50                   push eax
// 004a09df  8bce                 mov ecx, esi
// 004a09e1  ffd2                 call edx
// 004a09e3  8d4c240c             lea ecx, [esp + 0xc]
// 004a09e7  ff15d047b200         call dword ptr [0xb247d0]
// 004a09ed  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004a09f1  5f                   pop edi
// 004a09f2  5e                   pop esi
// 004a09f3  5b                   pop ebx
// 004a09f4  64890d00000000       mov dword ptr fs:[0], ecx
// 004a09fb  83c410               add esp, 0x10
// 004a09fe  c20400               ret 4
// copied from an identical function in another client (function ?update@S@ns_ROCX000005@@QAEXPAUTarget@2@@Z)

namespace ns_ROCX000005 {
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
