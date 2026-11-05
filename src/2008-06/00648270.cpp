// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espeon_blockboundsradius3eae10ea04f97fdc8.cpp

// Candidate translation unit (score above; library headers required).
#pragma float_control(precise,off)
#include "v8world/Block.h"
#include <G3D/vectorMath.h>
G3D::Vector3 RBX::Block::getCenterToCorner(const G3D::Matrix3& rotation)const{if(cornerRadius<3.0f)return G3D::Vector3(cornerRadius,cornerRadius,cornerRadius);G3D::Vector3 maxValue=G3D::abs(rotation*vertices[0]);for(int i=1;i<4;i++)maxValue=maxValue.max(G3D::abs(rotation*vertices[i]));return maxValue;}
