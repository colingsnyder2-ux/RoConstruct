// roc 2012-06 004d50e0  unit: Ogre::RbxSceneManager  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004d50e0
//
// 004d50e0  b880c9e100           mov eax, 0xe1c980
// 004d50e5  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_004d50e0()
{
    return &G;
}
