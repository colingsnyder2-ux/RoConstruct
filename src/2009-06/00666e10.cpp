// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
class Primitive;
class PartInstance { char pad[0x118]; public: Primitive* prim; };
class Humanoid {
public:
    PartInstance* getHeadSlow();
    Primitive* getHeadPrimitive();
};
Primitive* Humanoid::getHeadPrimitive()
{
    PartInstance* head = getHeadSlow();
    return head ? head->prim : 0;
}
}
