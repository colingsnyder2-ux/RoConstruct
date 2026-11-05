// from server: 69% by atomic.potato
struct FixedCameraCommand
{
    int IsValid();
    int value;
};

int FixedCameraCommand::IsValid()
{
    struct VTable
    {
        int (*fn)(void *);
    };

    VTable **object = (VTable **)((char *)this->value + 0x118);
    int result = (*object)->fn((char *)this->value + 0x118);
    return *(int *)((char *)result + 0x13c) == 0;
}
