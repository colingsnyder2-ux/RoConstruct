// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0040e130  unit: CBrowserView  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0040e130
//
// 0040e130  56                   push esi
// 0040e131  8b742408             mov esi, dword ptr [esp + 8]
// 0040e135  57                   push edi
// 0040e136  8b3e                 mov edi, dword ptr [esi]
// 0040e138  81c1cc020000         add ecx, 0x2cc
// 0040e13e  ff15d82f8000         call dword ptr [0x802fd8]
// 0040e144  8b17                 mov edx, dword ptr [edi]
// 0040e146  33c9                 xor ecx, ecx
// 0040e148  84c0                 test al, al
// 0040e14a  0f94c1               sete cl
// 0040e14d  51                   push ecx
// 0040e14e  8bce                 mov ecx, esi
// 0040e150  ffd2                 call edx
// 0040e152  5f                   pop edi
// 0040e153  5e                   pop esi
// 0040e154  c20400               ret 4

struct P {};

extern bool (__thiscall *check)(P*);

struct Command;
struct CommandTable {
    void (__thiscall *setEnabled)(Command*, int);
};

struct Command {
    CommandTable* table;
};

struct CBrowserView {
    char padding[0x2b0];
    P p;

    void update(Command*);
};

void CBrowserView::update(Command* command)
{
    CommandTable* table = command->table;
    bool result = check(&p);
    table->setEnabled(command, !result);
}
