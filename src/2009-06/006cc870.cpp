// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00640280  unit: RBX::GameTool  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00640280
//
// 00640280  6aff                 push -1
// 00640282  68f8a97d00           push 0x7da9f8
// 00640287  64a100000000         mov eax, dword ptr fs:[0]
// 0064028d  50                   push eax
// 0064028e  64892500000000       mov dword ptr fs:[0], esp
// 00640295  51                   push ecx
// 00640296  8b442414             mov eax, dword ptr [esp + 0x14]
// 0064029a  56                   push esi
// 0064029b  8bf1                 mov esi, ecx
// 0064029d  50                   push eax
// 0064029e  89742408             mov dword ptr [esp + 8], esi
// 006402a2  e84957fdff           call 0x6159f0
// 006402a7  8d4e1c               lea ecx, [esi + 0x1c]
// 006402aa  c744241000000000     mov dword ptr [esp + 0x10], 0
// 006402b2  c70644a58400         mov dword ptr [esi], 0x84a544
// 006402b8  c746042ca58400       mov dword ptr [esi + 4], 0x84a52c
// 006402bf  ff1560248000         call dword ptr [0x802460]
// 006402c5  8b4c2408             mov ecx, dword ptr [esp + 8]
// 006402c9  8bc6                 mov eax, esi
// 006402cb  5e                   pop esi
// 006402cc  64890d00000000       mov dword ptr fs:[0], ecx
// 006402d3  83c410               add esp, 0x10
// 006402d6  c20400               ret 4

struct Primary {
    virtual void primary();
};

struct Secondary {
    virtual void secondary();
};

struct Base : Primary, Secondary {
    char storage[20];
    Base(int);
    ~Base();
};

struct String {
    char storage[28];
};

extern String* (__thiscall *constructString)(String*);

struct GameTool : Base {
    String cursor;
    virtual void primary();
    virtual void secondary();
    GameTool(int);
};

GameTool::GameTool(int argument) : Base(argument)
{
    constructString(&cursor);
}
