// from server: 75% by atomic.potato
extern "C" void __cdecl Notify(unsigned long *);

struct PlayerCamera
{
    void setValue(unsigned char value);
};

void PlayerCamera::setValue(unsigned char value)
{
    if (*(unsigned char *)((char *)this + 0x139) == value)
        return;

    *(unsigned char *)((char *)this + 0x139) = value;
    Notify((unsigned long *)0x00b93210);
}
