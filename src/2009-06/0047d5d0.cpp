// from server: 100% by atomic.potato
struct Ogre_ManualObject {
    void func_0047d5d0(unsigned int id);
};

void Ogre_ManualObject::func_0047d5d0(unsigned int id)
{
    if (id == 0xa4d4a8 ||
        id == 0xa4c284 ||
        id == 0xa4c268 ||
        id == 0xa4c2a8 ||
        id == 0xa4c2e4 ||
        id == 0xa4c2c4)
    {
        void** vtbl = *(void***)this;
        void (__thiscall *fn)(void*) = (void (__thiscall *)(void*))vtbl[0x1bc / 4];
        fn(this);
    }
}
