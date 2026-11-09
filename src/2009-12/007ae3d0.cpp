// from server: 57% by atomic.potato
struct HumanoidState
{
    void construct(int flag);
};

extern float g_9b15a8;
extern int g_9eddf4;

void HumanoidState::construct(int flag)
{
    if (flag != 0)
        *(int*)((char*)this + 4) = (int)&g_9eddf4;
    *(float*)((char*)this + 0x10) = g_9b15a8;
    *(char*)((char*)this + 8) = 0;
    *(float*)((char*)this + 0x14) = 0.0f;
    *(float*)((char*)this + 0x18) = 0.0f;
    *(float*)((char*)this + 0x1c) = 0.0f;
    *(char*)((char*)this + 0x20) = 0;
}
