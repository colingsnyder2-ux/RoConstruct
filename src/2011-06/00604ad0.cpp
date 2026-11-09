// from server: 65% by atomic.potato
struct FollowCameraCommand
{
    int GetState();
    int value;
};

int FollowCameraCommand::GetState()
{
    struct State
    {
        int pad[70];
        int value;
    };

    State* state = *(State**)((char*)this + 0xc);
    State* object = (State*)((char*)state + 0x118);
    int result = ((int (__thiscall *)(State*))(*(int**)((char*)state)[0x118 / 4] + 4))(object);
    return ((int*)result)[0x13c / 4] == 4;
}
