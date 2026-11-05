// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espeon_partuisizenativeded3156a32394782.cpp

// Candidate translation unit (score above; library headers required).
#pragma float_control(precise,off)
#include <G3D/Vector3.h>
#include "util/Math.h"
struct Part{char prefix[0x1e0];int formFactor;G3D::Vector3 uiToXmlSize(const G3D::Vector3&) const;};
G3D::Vector3 Part::uiToXmlSize(const G3D::Vector3& uiSize)const{G3D::Vector3 gridUiSize=RBX::Math::iRoundVector3(uiSize.max(G3D::Vector3(1.0f,1.0f,1.0f)));G3D::Vector3 xmlSize=gridUiSize;switch(formFactor){case 1:xmlSize.y*=1.2f;break;case 2:xmlSize.y*=0.4f;break;}return xmlSize;}
