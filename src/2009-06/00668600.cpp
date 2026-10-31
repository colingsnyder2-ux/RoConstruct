// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005d9bb0  unit: RBX::Humanoid  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005d9bb0
//
// 005d9bb0  8b442404             mov eax, dword ptr [esp + 4]
// 005d9bb4  50                   push eax
// 005d9bb5  e8e610ecff           call 0x49aca0
// 005d9bba  83c404               add esp, 4
// 005d9bbd  85c0                 test eax, eax
// 005d9bbf  7422                 je 0x5d9be3
// 005d9bc1  6a00                 push 0
// 005d9bc3  68402a9300           push 0x932a40
// 005d9bc8  687c909200           push 0x92907c
// 005d9bcd  6a00                 push 0
// 005d9bcf  50                   push eax
// 005d9bd0  e8f17b0c00           call 0x6a17c6
// 005d9bd5  83c414               add esp, 0x14
// 005d9bd8  85c0                 test eax, eax
// 005d9bda  7407                 je 0x5d9be3
// 005d9bdc  8bc8                 mov ecx, eax
// 005d9bde  e9adeaffff           jmp 0x5d8690
// 005d9be3  33c0                 xor eax, eax
// 005d9be5  c3                   ret 

struct Humanoid;

struct ModelInstance
{
    Humanoid* getHumanoid();
};

struct Player;

extern ModelInstance* __cdecl getCharacter(const Player*);
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);

Humanoid* __cdecl findHumanoid(const Player* player)
{
    ModelInstance* character = getCharacter(player);
    if (character)
    {
        ModelInstance* model = static_cast<ModelInstance*>(
            __RTDynamicCast(character, 0,
                reinterpret_cast<void*>(0x92907c),
                reinterpret_cast<void*>(0x932a40), 0));
        if (model)
            return model->getHumanoid();
    }
    return 0;
}
