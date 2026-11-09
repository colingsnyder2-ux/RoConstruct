// from server: 100% by atomic.potato
struct RbxEntity
{
    void Initialize(int);
    unsigned char padding[0x284];
    unsigned char initialized;
    void* vtable;
};

void RbxEntity::Initialize(int value)
{
    if (!initialized)
    {
        ((void (__thiscall *)(RbxEntity*, int))(*(void***)this)[60])(this, value);
        initialized = 1;
    }
}
