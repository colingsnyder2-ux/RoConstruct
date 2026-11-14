// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/partchunk-profile /I{headers}/part-embedded /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
// Original descriptor initializer 007f4b90; signal dispatcher 0059e3a0.
#include "v8datamodel/PartInstance.h"
namespace RBX {
Reflection::SignalDesc<PartInstance, void()> PartInstance::event_OutfitChanged("OutfitChanged");
void PartInstance::outfitChanged() { event_OutfitChanged.fire(this); }
}
