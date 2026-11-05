// from server: 96% by atomic.potato
extern "C" void __stdcall SetPlayerCameraGlobal(int value);

struct PlayerCamera
{
    void SetCameraValue(int value);
};

void PlayerCamera::SetCameraValue(int value)
{
    if (*(unsigned char *)((char *)this + 0x138) != 0)
        return;

    if (*(int *)((char *)this + 0x124) == value)
        return;

    if (*(unsigned char *)((char *)this + 0x139) == 0)
        return;

    *(int *)((char *)this + 0x124) = value;
    SetPlayerCameraGlobal(0x00c1bfd4);
}
