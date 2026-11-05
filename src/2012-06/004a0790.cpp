// from server: 100% by Yeetserama
// roc 2012-06 004a0790  unit: CScriptEditor  size: 132 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004a0790
//
// 004a0790  6aff                 push -1
// 004a0792  68d9aea900           push 0xa9aed9
// 004a0797  64a100000000         mov eax, dword ptr fs:[0]
// 004a079d  50                   push eax
// 004a079e  64892500000000       mov dword ptr fs:[0], esp
// 004a07a5  51                   push ecx
// 004a07a6  56                   push esi
// 004a07a7  8bf1                 mov esi, ecx
// 004a07a9  57                   push edi
// 004a07aa  8d4c2408             lea ecx, [esp + 8]
// 004a07ae  ff158447b200         call dword ptr [0xb24784]
// 004a07b4  6a01                 push 1
// 004a07b6  8bce                 mov ecx, esi
// 004a07b8  c744241800000000     mov dword ptr [esp + 0x18], 0
// 004a07c0  e8cb340500           call 0x4f3c90
// 004a07c5  8bc8                 mov ecx, eax
// 004a07c7  e894d0ffff           call 0x49d860
// 004a07cc  85c0                 test eax, eax
// 004a07ce  740f                 je 0x4a07df
// 004a07d0  6804e70000           push 0xe704
// 004a07d5  8d4c240c             lea ecx, [esp + 0xc]
// 004a07d9  ff151450b200         call dword ptr [0xb25014]
// 004a07df  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 004a07e3  8b3e                 mov edi, dword ptr [esi]
// 004a07e5  8d4c2408             lea ecx, [esp + 8]
// 004a07e9  ff159847b200         call dword ptr [0xb24798]
// 004a07ef  50                   push eax
// 004a07f0  8b470c               mov eax, dword ptr [edi + 0xc]
// 004a07f3  8bce                 mov ecx, esi
// 004a07f5  ffd0                 call eax
// 004a07f7  8d4c2408             lea ecx, [esp + 8]
// 004a07fb  ff15d047b200         call dword ptr [0xb247d0]
// 004a0801  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004a0805  5f                   pop edi
// 004a0806  5e                   pop esi
// 004a0807  64890d00000000       mov dword ptr fs:[0], ecx
// 004a080e  83c410               add esp, 0x10
// 004a0811  c20400               ret 4
// copied from an identical function in another client (function ?update@CScriptEditor@ns_ROCX000002@@QAEXPAUCommand@2@@Z)

namespace ns_ROCX000002 {
// from server: 100% by colin
struct Text;

extern const char* (__thiscall *textData)(const Text*);

struct Text {
    char* data;
    __declspec(dllimport) Text();
    __declspec(dllimport) ~Text() throw();
    __declspec(dllimport) int load(unsigned int);
    operator const char*() const;
};







inline Text::operator const char*() const
{
    return textData(this);
}

struct Command {
    virtual void enable(int);
    virtual void check(int);
    virtual void radio(int);
    virtual void setText(const char*);
};

struct Control {
    int query(int);
};

struct CScriptEditor {
    int* f();
    void update(Command*);
};

void CScriptEditor::update(Command* command)
{
    Text text;
    if (reinterpret_cast<Control*>(f())->query(1))
        text.load(0xe704);

    typedef void (__thiscall *SetText)(Command*, const char*);
    SetText* table = *reinterpret_cast<SetText**>(command);
    const char* value = text;
    table[3](command, value);
}
}
