// from server: 100% by king_originala
struct Result {
    int finish();
};

struct Interface {
    virtual void slot0();
    virtual Result* get();
};

struct Object {
    char padding[0x288];
    Interface interfaceObject;
};

struct Owner {
    char padding[0x204];
    Object* object;
};

struct FirstPersonCommand {
    char padding[0x0c];
    Owner* owner;
    int execute();
};

int FirstPersonCommand::execute()
{
    return owner->object->interfaceObject.get()->finish();
}
