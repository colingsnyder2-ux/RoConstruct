// from server: 100% by Yeetserama
// roc 2007-08 00460230  unit: CScriptEditor  size: 144 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00460230
//
// 00460230  6aff                 push -1
// 00460232  6849d87300           push 0x73d849
// 00460237  64a100000000         mov eax, dword ptr fs:[0]
// 0046023d  50                   push eax
// 0046023e  51                   push ecx
// 0046023f  56                   push esi
// 00460240  57                   push edi
// 00460241  a188518b00           mov eax, dword ptr [0x8b5188]
// 00460246  33c4                 xor eax, esp
// 00460248  50                   push eax
// 00460249  8d442410             lea eax, [esp + 0x10]
// 0046024d  64a300000000         mov dword ptr fs:[0], eax
// 00460253  8bf1                 mov esi, ecx
// 00460255  8d4c240c             lea ecx, [esp + 0xc]
// 00460259  ff15acdd7700         call dword ptr [0x77ddac]
// 0046025f  6a01                 push 1
// 00460261  8bce                 mov ecx, esi
// 00460263  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 0046026b  e8c0cfffff           call 0x45d230
// 00460270  8bc8                 mov ecx, eax
// 00460272  e8d9caffff           call 0x45cd50
// 00460277  85c0                 test eax, eax
// 00460279  740f                 je 0x46028a
// 0046027b  6804e70000           push 0xe704
// 00460280  8d4c2410             lea ecx, [esp + 0x10]
// 00460284  ff159cd57700         call dword ptr [0x77d59c]
// 0046028a  8b742420             mov esi, dword ptr [esp + 0x20]
// 0046028e  8b3e                 mov edi, dword ptr [esi]
// 00460290  8d4c240c             lea ecx, [esp + 0xc]
// 00460294  ff1598dd7700         call dword ptr [0x77dd98]
// 0046029a  50                   push eax
// 0046029b  8b470c               mov eax, dword ptr [edi + 0xc]
// 0046029e  8bce                 mov ecx, esi
// 004602a0  ffd0                 call eax
// 004602a2  8d4c240c             lea ecx, [esp + 0xc]
// 004602a6  ff15bcdd7700         call dword ptr [0x77ddbc]
// 004602ac  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004602b0  64890d00000000       mov dword ptr fs:[0], ecx
// 004602b7  59                   pop ecx
// 004602b8  5f                   pop edi
// 004602b9  5e                   pop esi
// 004602ba  83c410               add esp, 0x10
// 004602bd  c20400               ret 4
// copied from an identical function in another client (function ?update@CScriptEditor@ns_ROCX00000d@@QAEXPAUCommand@2@@Z)

namespace ns_ROCX00000d {
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
