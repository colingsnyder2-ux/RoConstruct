// from server: 100% by colin
struct StopCommand {
    bool isEnabled() const;
};

struct RunStateOwner {
    char pad[0x14c];
    int state;
};

struct Sub {
    RunStateOwner* method(int);
};

struct StopCommandLayout {
    char pad[0x10];
    Sub sub;
};

bool StopCommand::isEnabled() const
{
    RunStateOwner* owner = ((Sub*)((char*)this + 0x10))->method(1);
    return owner->state == 1;
}
