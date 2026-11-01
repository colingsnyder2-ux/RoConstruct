// from server: 100% by king_originala
struct Primary {
    virtual void update();
};

struct Secondary {
    virtual void update();
    char reserved[152];
};

struct Tertiary {
    virtual void update();
};

struct Base : Primary, Secondary, Tertiary {
    Base(void*);
    ~Base();
};

struct Value {
    int value;
    Value();
    Value(const Value&);
};

struct State {
    Value set(float);
};

struct Result {
    char reserved[16];
    State state;
};

struct Registry {
    Result* find(void*);
};

extern Registry registry;

struct RunningNoPhysics : Base {
    RunningNoPhysics(void*);
    virtual void update();
};

RunningNoPhysics::RunningNoPhysics(void* owner) : Base(owner)
{
    Result* result = registry.find(
        owner ? static_cast<char*>(owner) + 20 : 0);

    if (result)
        result->state.set(0.0f);
}
