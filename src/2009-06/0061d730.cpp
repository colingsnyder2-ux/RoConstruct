// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0058c8b0  unit: RBX::ChangeHistoryService  size: 97 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0058c8b0
//
// 0058c8b0  56                   push esi
// 0058c8b1  6850198300           push 0x831950
// 0058c8b6  6a01                 push 1
// 0058c8b8  8bf1                 mov esi, ecx
// 0058c8ba  e8a16ef0ff           call 0x493760
// 0058c8bf  8bc8                 mov ecx, eax
// 0058c8c1  e84acfefff           call 0x489810
// 0058c8c6  8a442408             mov al, byte ptr [esp + 8]
// 0058c8ca  3a8665010000         cmp al, byte ptr [esi + 0x165]
// 0058c8d0  743b                 je 0x58c90d
// 0058c8d2  888665010000         mov byte ptr [esi + 0x165], al
// 0058c8d8  8bce                 mov ecx, esi
// 0058c8da  84c0                 test al, al
// 0058c8dc  7409                 je 0x58c8e7
// 0058c8de  e83dfdffff           call 0x58c620
// 0058c8e3  5e                   pop esi
// 0058c8e4  c20400               ret 4
// 0058c8e7  e8d4faffff           call 0x58c3c0
// 0058c8ec  8d8e68010000         lea ecx, [esi + 0x168]
// 0058c8f2  e839890000           call 0x595230
// 0058c8f7  8d8e7c010000         lea ecx, [esi + 0x17c]
// 0058c8fd  e82e890000           call 0x595230
// 0058c902  8d8e90010000         lea ecx, [esi + 0x190]
// 0058c908  e823890000           call 0x595230
// 0058c90d  5e                   pop esi
// 0058c90e  c20400               ret 4

struct Check {
    void verify();
};

extern char enabledName[];
extern "C" Check* __stdcall getCheck(int, const char*);

struct State {
    char storage[8];
    void clear();
};

struct S {
    char padding[0xc1];
    bool enabled;
    char alignment[2];
    State first;
    State second;
    State third;

    void start();
    void stop();
    void setEnabled(bool value);
};

void S::setEnabled(bool value)
{
    getCheck(1, enabledName)->verify();

    if (value != enabled) {
        enabled = value;
        if (value) {
            start();
        } else {
            stop();
            first.clear();
            second.clear();
            third.clear();
        }
    }
}
