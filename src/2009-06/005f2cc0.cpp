// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
class Primitive { public: void setState(int s); };
class PartInstance { public: char pad[0x118]; Primitive* primitive; void onAncestorChanged(int e); };
class DerivedPart : public PartInstance { public: void onAncestorChanged(int e); };
void DerivedPart::onAncestorChanged(int e)
{
    PartInstance::onAncestorChanged(e);
    primitive->setState(2);
}
}
