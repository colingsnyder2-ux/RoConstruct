// from server: 82% by atomic.potato
struct PlayerCamera
{
    void Set(void *);
};

void Function_0040c080(void *);

void PlayerCamera::Set(void *value)
{
    if (*(unsigned char *)((char *)this + 0x138) != 0)
        return;

    if (*(void **)((char *)this + 0x124) == value)
        return;

    if (*(unsigned char *)((char *)this + 0x139) == 0)
    {
        *(void **)((char *)this + 0x124) = value;
        return;
    }

    *(void **)((char *)this + 0x124) = value;
    Function_0040c080((void *)0x00b93254);
}
