// from server: 100% by king_originala
struct Action {
    virtual void slot00(); virtual void slot01();
    virtual void slot02(); virtual void slot03();
    virtual void slot04(); virtual void slot05();
    virtual void slot06(); virtual void slot07();
    virtual void slot08(); virtual void slot09();
    virtual void slot10(); virtual void slot11();
    virtual void slot12(); virtual void slot13();
    virtual void slot14(); virtual void slot15();
    virtual void slot16(); virtual void slot17();
    virtual void slot18(); virtual void slot19();
    virtual void slot20(); virtual void slot21();
    virtual void slot22(); virtual void slot23();
    virtual void slot24(); virtual void slot25();
    virtual void slot26(); virtual void slot27();
    virtual void slot28(); virtual void slot29();
    virtual void slot30(); virtual void slot31();
    virtual void slot32(); virtual void slot33();
    virtual void slot34();
    virtual bool allowed();
};

struct Equipped {
    Action* getAction();
};

struct Owner {
    char padding[0x170];
    Equipped* equipped;
    void* getValue();
};

struct Tool {
    char padding[0x104];
    void* value;
    void setValue(void*);
    void update();
};

extern "C" void* __cdecl findOwner(void*);
extern "C" int __cdecl checkEquipped(Equipped*);

void Tool::update()
{
    Owner* owner = static_cast<Owner*>(findOwner(this));
    if (owner) {
        Equipped* equipped = owner->equipped;
        Action* action;
        if (!equipped ||
            !checkEquipped(equipped) ||
            !(action = equipped->getAction()) ||
            action->allowed()) {
            void* previous = value;
            if (previous != owner->getValue())
                setValue(owner->getValue());
        }
    }
}
