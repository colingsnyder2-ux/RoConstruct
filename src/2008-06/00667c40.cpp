// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {

struct EventSource {
};

struct HumanoidPrefix {
    char pad[0x14];
};

class Humanoid : public HumanoidPrefix, public EventSource {
};

struct Unusable {
    Unusable() {}
};

struct Signal {
    Unusable operator()(bool value);
};

struct SignalEntry {
    char pad[0x10];
    Signal signal;
};

struct Event {
    SignalEntry* find(EventSource* source);
    void fire(EventSource* source, bool value)
    {
        if (SignalEntry* entry = find(source))
            entry->signal(value);
    }
};

struct State {
    virtual ~State();
};

struct StateHelper {
    virtual void helper();
};

class Flying : public State, public StateHelper {
protected:
    Humanoid* humanoid;
public:
    Flying(Humanoid* humanoid);
    virtual ~Flying();
};

extern Event event_Jumping;

class Jumping : public Flying {
    float timeout;
public:
    Jumping(Humanoid* humanoid);
    virtual ~Jumping();
    virtual void helper();
};

Jumping::Jumping(Humanoid* humanoid)
    : Flying(humanoid),
      timeout(0.5f)
{
    event_Jumping.fire(humanoid, true);
}

}
