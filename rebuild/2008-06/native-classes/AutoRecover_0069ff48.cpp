// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 0069ff48 is an import thunk (jmp [0x8042e0]) into rgmain.dll's Ogre::SceneNode::getAutoTrackTarget.
// INFERRED: the exe has no body for this function. Ogre 1.4.5 defines it inline in OgreSceneNode.h
// (return mAutoTrackTarget;), so a second out-of-line definition fails with C2084.
// Nothing is defined here. The thunk comes from the rgmain.dll import, not from native source.
#include "../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include/OgreSceneNode.h"
