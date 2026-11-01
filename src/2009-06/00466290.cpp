// from server: 72% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 004659a0  unit: CScriptEditor  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004659a0
//
// 004659a0  56                   push esi
// 004659a1  8bf1                 mov esi, ecx
// 004659a3  e8ccaf2300           call 0x6a0974
// 004659a8  85c0                 test eax, eax
// 004659aa  742c                 je 0x4659d8
// 004659ac  8b8644010000         mov eax, dword ptr [esi + 0x144]
// 004659b2  85c0                 test eax, eax
// 004659b4  7507                 jne 0x4659bd
// 004659b6  6816b78000           push 0x80b716
// 004659bb  eb0d                 jmp 0x4659ca
// 004659bd  8d8810010000         lea ecx, [eax + 0x110]
// 004659c3  ff1564248000         call dword ptr [0x802464]
// 004659c9  50                   push eax
// 004659ca  8bce                 mov ecx, esi
// 004659cc  e8a3af2300           call 0x6a0974
// 004659d1  8bc8                 mov ecx, eax
// 004659d3  e842b22300           call 0x6a0c1a
// 004659d8  8bce                 mov ecx, esi
// 004659da  e871fbffff           call 0x465550
// 004659df  33c0                 xor eax, eax
// 004659e1  5e                   pop esi
// 004659e2  c20800               ret 8

extern const char defaultText[];
extern const char* (__thiscall* string_c_str)(const void*);

struct TextTarget
{
    void setText(const char*);
};

struct Document
{
    char padding[0x110];
    char text[1];
};

struct CScriptEditor
{
    char padding[0x144];
    Document* document;

    TextTarget* getTextTarget();
    void refresh();
    int func_004659a0(unsigned int, unsigned int);
};

int CScriptEditor::func_004659a0(unsigned int, unsigned int)
{
    if (getTextTarget())
    {
        if (!document)
            getTextTarget()->setText(defaultText);
        else
            getTextTarget()->setText(string_c_str(document->text));
    }
    refresh();
    return 0;
}
