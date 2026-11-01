// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005827c0  unit: RBX::ResetCommand  size: 56 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005827c0
//
// 005827c0  56                   push esi
// 005827c1  8bf1                 mov esi, ecx
// 005827c3  6a01                 push 1
// 005827c5  8d4e10               lea ecx, [esi + 0x10]
// 005827c8  e833f4ffff           call 0x581c00
// 005827cd  8b80b4010000         mov eax, dword ptr [eax + 0x9c]
// 005827d3  83f801               cmp eax, 1
// 005827d6  7405                 je 0x5827dd
// 005827d8  83f802               cmp eax, 2
// 005827db  7517                 jne 0x5827f4
// 005827dd  8b460c               mov eax, dword ptr [esi + 0xc]
// 005827e0  50                   push eax
// 005827e1  e89a84f1ff           call 0x49ac80
// 005827e6  83c404               add esp, 4
// 005827e9  85c0                 test eax, eax
// 005827eb  7507                 jne 0x5827f4
// 005827ed  b801000000           mov eax, 1
// 005827f2  5e                   pop esi
// 005827f3  c3                   ret 
// 005827f4  33c0                 xor eax, eax
// 005827f6  5e                   pop esi
// 005827f7  c3                   ret 

struct State {
    char pad[0x9c];
    int value;
};

struct Helper {
    State* get(int);
};

void* func(void*);

struct ResetCommand {
    char pad[0x0c];
    void* object;
    Helper helper;

    int enabled();
};

int ResetCommand::enabled()
{
    int value = helper.get(1)->value;
    if (value == 1 || value == 2) {
        if (!func(object))
            return 1;
    }
    return 0;
}
