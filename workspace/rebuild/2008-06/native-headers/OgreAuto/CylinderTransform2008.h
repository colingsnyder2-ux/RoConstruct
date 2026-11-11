// 2008-06 native CylinderTransform (inactive), converted from server-exact analogs: 004fdbd0.
// INFERRED (owner rule 2026-11-11): class/member names come from the analog author unless the identity registry
// proves them; the layout is the analog's, pinned by its offsetof checks (kept in the source).
#pragma once
// >>> native-status (generated) -- do not edit >>>
// CylinderTransform2008 | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 4c351d32 | roc native-status --write
#undef OGRE_NONCLIENT_BUILD
#include <OgreVector2.h>
#include <OgreVector3.h>
#include "G3D/Vector2.h"
#include "G3D/Vector2int16.h"
#include "G3D/Vector3.h"
#include <string>
#include <vector>

struct Vector2int16 {short x,y;};

struct CylinderTransform {
 const float bevel;const int steps;
 void operator()(G3D::Vector3&,G3D::Vector3&,G3D::Vector2&,const G3D::Vector3&,const G3D::Vector2int16&)const;
};
