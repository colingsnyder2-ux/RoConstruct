// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005d9a20  unit: RBX::Humanoid  size: 45 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005d9a20
//
// 005d9a20  8b442404             mov eax, dword ptr [esp + 4]
// 005d9a24  85c0                 test eax, eax
// 005d9a26  7422                 je 0x5d9a4a
// 005d9a28  6a00                 push 0
// 005d9a2a  68402a9300           push 0x932a40
// 005d9a2f  687c909200           push 0x92907c
// 005d9a34  6a00                 push 0
// 005d9a36  50                   push eax
// 005d9a37  e88a7d0c00           call 0x6a17c6
// 005d9a3c  83c414               add esp, 0x14
// 005d9a3f  85c0                 test eax, eax
// 005d9a41  7407                 je 0x5d9a4a
// 005d9a43  8bc8                 mov ecx, eax
// 005d9a45  e946ecffff           jmp 0x5d8690
// 005d9a4a  33c0                 xor eax, eax
// 005d9a4c  c3                   ret 

namespace RBX {
    class Instance {
    public:
        virtual ~Instance();
    };

    struct Humanoid;

    class ModelInstance : public Instance {
    public:
        Humanoid* getHumanoid();
    };

    struct Humanoid {
        static Humanoid* fromInstance(Instance*);
    };
}

RBX::Humanoid* RBX::Humanoid::fromInstance(RBX::Instance* instance)
{
    if (instance) {
        ModelInstance* model = dynamic_cast<ModelInstance*>(instance);
        if (model)
            return model->getHumanoid();
    }
    return 0;
}
