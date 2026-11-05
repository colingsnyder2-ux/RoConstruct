// from server: 90% by atomic.potato
extern int G_009b26ec;
extern int G_00b7cc70;
extern "C" void __stdcall Ogre_SceneManagerFactory_destructor(int);

void func_0097edd0()
{
    G_009b26ec = 0x009b26ec;
    Ogre_SceneManagerFactory_destructor((int)&G_00b7cc70);
}
