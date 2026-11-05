// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs roc_espeon_signalthreefire45ec9c1fc2b73290.cpp

// Candidate translation unit (score above; library headers required).
#include "G3D/Color3.h"
#include "G3D/Vector3.h"
#include "G3D/CoordinateFrame.h"
#include "v8datamodel/BrickColor.h"
#undef _RELEASEASSERT
#include "reflection/object.h"
#include "reflection/signal.h"
namespace RBX { namespace Reflection {
class SignalDescThree : public TSignalDesc<void(std::string,int,std::string)> {
public: void fire(SignalSource* source,std::string a,int b,std::string c);
};
void SignalDescThree::fire(SignalSource* source,std::string a,int b,std::string c){
 TSignalInstance* instance=findSig(source);if(instance)(*instance)(a,b,c);
}
}}
