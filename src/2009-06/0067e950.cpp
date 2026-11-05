// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
class Primitive;
class IStage {
public:
    enum StageType { S2 = 2 };
    virtual ~IStage();
    virtual StageType getStageType() = 0;
    IStage* findStage(StageType stageType)
    {
        IStage* idownstream = this;
        while (idownstream->getStageType() != stageType)
            idownstream = idownstream->downstream;
        return idownstream;
    }
protected:
    IStage* upstream;
    IStage* downstream;
};
class TargetStage : public IStage {
public:
    void onB(Primitive* p);
};
class World {
public:
    void onB(Primitive* p);
    TargetStage* getTargetStage() { return static_cast<TargetStage*>(jointStage->findStage(IStage::S2)); }
private:
    char pad[0xb8];
    IStage* jointStage;
};
void World::onB(Primitive* p)
{
    getTargetStage()->onB(p);
}
}
