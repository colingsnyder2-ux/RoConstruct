// from server: 100% by colin
// from server: 88% by king_originala
// roc 2008-06 00581960  unit: RBX::SecondaryControllerCommand  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00581960
//
// 00581960  56                   push esi
// 00581961  6a02                 push 2
// 00581963  8bf1                 mov esi, ecx
// 00581965  e826ffffff           call 0x581890
// 0058196a  8b4604               mov eax, dword ptr [esi + 4]
// 0058196d  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00581970  83c004               add eax, 4
// 00581973  83781810             cmp dword ptr [eax + 0x18], 0x10
// 00581977  5e                   pop esi
// 00581978  7205                 jb 0x58197f
// 0058197a  8b4004               mov eax, dword ptr [eax + 4]
// 0058197d  eb03                 jmp 0x581982
// 0058197f  83c004               add eax, 4
// 00581982  51                   push ecx
// 00581983  50                   push eax
// 00581984  e837ac0000           call 0x58c5c0
// 00581989  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0058198d  8b01                 mov eax, dword ptr [ecx]
// 0058198f  8b10                 mov edx, dword ptr [eax]
// 00581991  83c408               add esp, 8
// 00581994  c744240401000000     mov dword ptr [esp + 4], 1
// 0058199c  ffe2                 jmp edx

namespace RBX {
    void handle(int a, int b);
}

struct StringData {
    unsigned int unused;
    union {
        char buffer[16];
        char* pointer;
    } storage;
    unsigned int length;
    unsigned int capacity;
};

struct CommandData {
    unsigned int unused;
    StringData text;
};

struct Receiver {
    virtual void finish(int value);
};

struct S {
    unsigned int unused0;
    CommandData* data;
    unsigned int unused8;
    int context;

    void prepare(int value);
    void execute(Receiver* receiver);
};

void S::execute(Receiver* receiver)
{
    prepare(2);
    int value = context;
    StringData* text = &data->text;
    const char* characters = text->capacity >= 16
        ? text->storage.pointer
        : text->storage.buffer;
    RBX::handle(reinterpret_cast<int>(characters), value);
    receiver->finish(1);
}
