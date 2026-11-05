// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
namespace RBX {
class Controller;
class Instance {
public:
    virtual ~Instance();
    char pad[0x100];
    Instance* parent;
    Instance* getParent() const { return parent; }
};
class PVInstance : public Instance {
public:
    Controller* getTopPVController() const;
};
class ModelInstance : public PVInstance {};
class Primitive { public: void setCanSleep(bool); };
class PartInstance : public PVInstance {
public:
    char ppad[0x228 - 0x108];
    Primitive primitive;
    Primitive* getPrimitive() { return &primitive; }
};
class RunService;
class Stepped {
public:
    const float time;
    const float step;
};
template<class S, class E> class Listener {
public:
    virtual void onEvent(const S* source, E event) = 0;
};
namespace HUMAN { class State; class StateHolder { public: State* state; };
    void stepState(StateHolder* holder, float step, Controller* controller); }
class HBase : public Instance { char hpad[0x1a4 - 0x108]; };
class Humanoid : public HBase, public Listener<RunService, Stepped> {
public:
    char p1[0x1b4 - 0x1a8];
    int walkTimer;
    int walkMode;
    char p2[0x21c - 0x1bc];
    HUMAN::State* currentState;
    HUMAN::StateHolder holder;
    PartInstance* getTorso() const;
    Primitive* getTorsoPrimitive() const
    {
        PartInstance* part = getTorso();
        return part ? part->getPrimitive() : 0;
    }
    void checkForJointDeath();
    virtual void onEvent(const RunService* source, Stepped event);
};
void Humanoid::onEvent(const RunService* source, Stepped event)
{
    if (currentState) {
        if (ModelInstance* model = dynamic_cast<ModelInstance*>(getParent()))
            HUMAN::stepState(&holder, event.step, model->getTopPVController());
        if (getTorsoPrimitive())
            getTorsoPrimitive()->setCanSleep(false);
        checkForJointDeath();
        if (walkTimer > 0) {
            walkTimer--;
            if (walkTimer == 0)
                walkMode = 3;
        }
    }
}
}
