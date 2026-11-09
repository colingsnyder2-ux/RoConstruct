// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0064e020  unit: RBX::ToolMouseCommand  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0064e020
//
// 0064e020  56                   push esi
// 0064e021  8bf1                 mov esi, ecx
// 0064e023  e8e84effff           call 0x642f10
// 0064e028  8b8e64010000         mov ecx, dword ptr [esi + 0x164]
// 0064e02e  85c9                 test ecx, ecx
// 0064e030  7415                 je 0x64e047
// 0064e032  68e0be9700           push 0x97bee0
// 0064e037  6a00                 push 0
// 0064e039  81c630010000         add esi, 0x130
// 0064e03f  56                   push esi
// 0064e040  e84b7dfcff           call 0x615d90
// 0064e045  5e                   pop esi
// 0064e046  c3                   ret 
// 0064e047  33c0                 xor eax, eax
// 0064e049  5e                   pop esi
// 0064e04a  c3                   ret 

extern char globalData;

struct Helper {
    int invoke(void *, int, void *);
};

struct ToolMouseCommand {
    char padding[0x8c];
    char storage[0x34];
    Helper *helper;

    void update();
    int execute();
};

int ToolMouseCommand::execute()
{
    update();
    if (helper)
        return helper->invoke(storage, 0, &globalData);
    return 0;
}
