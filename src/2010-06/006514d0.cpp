// from server: 100% by atomic.potato
struct PlayerCamera
{
    void SetCameraMode(unsigned char value);
};

extern "C" void __stdcall SetCameraModeGlobal(unsigned int value);

void PlayerCamera::SetCameraMode(unsigned char value)
{
    if (*(unsigned char *)((char *)this + 0x139) == value)
        return;

    *(unsigned char *)((char *)this + 0x139) = value;
    SetCameraModeGlobal(0x00c1bf90);
}
