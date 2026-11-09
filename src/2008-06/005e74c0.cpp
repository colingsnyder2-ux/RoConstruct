// from server: 100% by EspClaude
namespace RBX {
class Primitive;
class World { public: void onPrimitiveTouched(Primitive* touchP, Primitive* touchOtherP); };
namespace Sim { enum SleepStatus { NONE = 0, AWAKE_1 = 1, AWAKE_2 = 2, AWAKE = 3 }; }
struct SleepInfo { Sim::SleepStatus state; };
class Assembly { char pad[0x18]; SleepInfo* sleepInfo; public:
    Sim::SleepStatus getSleepStatus() const { return sleepInfo ? sleepInfo->state : Sim::NONE; } };
class Clump {
    char pad[0x24]; Assembly* assembly;
public:
    Assembly* getAssembly() const { return assembly; }
    Sim::SleepStatus getSleepStatus() const { return assembly->getSleepStatus(); }
};
static inline bool awake(Sim::SleepStatus s) { return s == Sim::AWAKE || s == Sim::AWAKE_1 || s == Sim::AWAKE_2; }
class IMoving { public: virtual ~IMoving(); virtual bool reportTouches() const; };
class Primitive {
    char pad0[0x58];
    World* world;
    Clump* clump;
    char pad1[0x44];
    IMoving* owner;
public:
    World* getWorld() const { return world; }
    Clump* getClump() const { return clump; }
    IMoving* getOwner() const { return owner; }
};

void newTouch(Primitive* touch, Primitive* touchOther)
{
    Clump* clumpTouch = touch->getClump();
    Clump* clumpOTouch = touchOther->getClump();

    if (touch->getOwner()->reportTouches() &&
        (awake(clumpTouch->getSleepStatus()) || awake(clumpOTouch->getSleepStatus())))
    {
        touch->getWorld()->onPrimitiveTouched(touch, touchOther);
    }
}
}
