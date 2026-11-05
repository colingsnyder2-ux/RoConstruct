// from server: 69% by atomic.potato
struct ManualGlueJoint
{
    int Check();
};

int ManualGlueJoint::Check()
{
    int i = 0;
    do
    {
        struct VTable
        {
            int (__thiscall *func)(ManualGlueJoint *, int);
        };

        VTable *vtable = *(VTable **)this;
        int result = vtable->func(this, 0);
        if (result != 0 && *(ManualGlueJoint **)((char *)result + 0x28) == this)
            return result;
        ++i;
    } while (i < 2);

    return 0;
}
