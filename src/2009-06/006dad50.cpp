// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
class Body;
class IStage { public: void onBody(Body* b); };
class Body { public: void setStage(IStage* s); };
class Stage : public IStage { public: void onBodyChanged(Body* b); };
void Stage::onBodyChanged(Body* b)
{
    IStage::onBody(b);
    b->setStage(this);
}
}
