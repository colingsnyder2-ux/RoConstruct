// from server: 58% by atomic.potato
// roc 2009-12 00490960  unit: Ogre::RbxEntity  size: 84 bytes

extern "C" void __cdecl sub_7f3860(void*);
extern "C" void __cdecl sub_7f4878(void*, void*);
extern "C" void* __cdecl sub_98b748();

struct RbxEntity {
    void func(unsigned int n);
};

void RbxEntity::func(unsigned int n)
{
    if (n <= 0) {
        sub_7f3860(0);
        return;
    }
    unsigned int q = 0xffffffffu / n;
    if (q >= 1) {
        sub_7f3860(0);
        return;
    }
    void* p = 0;
    sub_98b748();
    sub_7f4878(&p, (void*)0xa8ef38);
}
