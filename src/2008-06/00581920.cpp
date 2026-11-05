// from server: 100% by colin
// from server: 88% by king_originala
// roc 2008-06 00581920  unit: RBX::PrimaryControllerCommand  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00581920
//
// 00581920  56                   push esi
// 00581921  6a01                 push 1
// 00581923  8bf1                 mov esi, ecx
// 00581925  e866ffffff           call 0x581890
// 0058192a  8b4604               mov eax, dword ptr [esi + 4]
// 0058192d  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00581930  83c004               add eax, 4
// 00581933  83781810             cmp dword ptr [eax + 0x18], 0x10
// 00581937  5e                   pop esi
// 00581938  7205                 jb 0x58193f
// 0058193a  8b4004               mov eax, dword ptr [eax + 4]
// 0058193d  eb03                 jmp 0x581942
// 0058193f  83c004               add eax, 4
// 00581942  51                   push ecx
// 00581943  50                   push eax
// 00581944  e877ac0000           call 0x58c5c0
// 00581949  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0058194d  8b01                 mov eax, dword ptr [ecx]
// 0058194f  8b10                 mov edx, dword ptr [eax]
// 00581951  83c408               add esp, 8
// 00581954  c744240401000000     mov dword ptr [esp + 4], 1
// 0058195c  ffe2                 jmp edx

namespace RBX {
    void handle(int a, int b);
}

struct Text {
    unsigned int reserved;
    union {
        char local[16];
        char* heap;
    } storage;
    unsigned int size;
    unsigned int capacity;
};

struct TextHolder {
    unsigned int reserved;
    Text text;
};

struct Callback {
    virtual void invoke(int value);
};

struct S {
    unsigned int reserved0;
    TextHolder* holder;
    unsigned int reserved8;
    int value;

    void prepare(int mode);
    void f(Callback* callback);
};

void S::f(Callback* callback)
{
    prepare(1);
    int argument = value;
    Text* text = &holder->text;
    char* data = text->capacity >= 16
        ? text->storage.heap
        : text->storage.local;
    RBX::handle((int)data, argument);
    callback->invoke(1);
}
