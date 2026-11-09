// from server: 100% by atomic.potato
struct ManualGlueJoint
{
    virtual void* First() = 0;
    virtual void* GetJoint(int index) = 0;
    virtual void* Third() = 0;
    virtual void* Fourth() = 0;
    virtual void* Fifth() = 0;
    virtual void* Sixth(int index) = 0;
    bool f();
};

bool ManualGlueJoint::f()
{
    int i = 0;
    while (i < 2)
    {
        void* p = Sixth(i);
        if (p != 0 && *(ManualGlueJoint**)((char*)p + 0x28) == this)
            return true;
        ++i;
    }
    return false;
}
