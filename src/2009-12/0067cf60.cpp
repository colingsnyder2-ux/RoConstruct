// from server: 85% by atomic.potato
struct StopCommand
{
    int f();
};

StopCommand* __stdcall GetState(StopCommand*);

int StopCommand::f()
{
    StopCommand* p = GetState((StopCommand*)((char*)this + 0x10));
    return *(int*)((char*)p + 0xA8) == 1;
}
