// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
// 2008-06 RBX::Render::RenderScene lane draft for 00504b00 / 00504b60 / 00504bf0 (inactive). Its bodies duplicated
// units that now define them, so it defines nothing (never duplicate a body):
//   clearProxyArrays 00504b00   RenderSceneClearProxy_00504b00.cpp
//   computeProxyArrays 00504b60 RenderSceneRecovery_00504b60.cpp (the donor name; this draft called it prepareProxyArrays)
//   render 00504bf0             RenderSceneRecovery_00504b60.cpp
#include "RenderLib/RenderSceneRender2008.h"
