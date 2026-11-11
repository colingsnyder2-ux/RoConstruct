// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// 2008-06 native G3DCone (inactive): upstream tools/libs/g3d-6.09/source/G3Dcpp/Cone.cpp, verbatim.
// >>> native-status (generated) -- do not edit >>>
// G3DCone | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 7a8aaa71 | roc native-status --write
/**
 @file Cone.cpp

 Cone class

 @maintainer Morgan McGuire, matrix@graphics3d.com

 @created 2001-07-09
 @edited  2006-01-29
*/

#include "G3D/platform.h"
#include "G3D/Cone.h"
#include "G3D/Line.h"
#include "G3D/Sphere.h"
#include "G3D/Box.h"

namespace G3D {

Cone::Cone(const Vector3 &tip, const Vector3 &direction, float angle) {
    this->tip = tip;
    this->direction = direction.direction();
    this->angle = angle;

    assert(angle >= 0);
    assert(angle <= G3D_PI);
}

/**
 Forms the smallest cone that contains the box.  Undefined if
 the tip is inside or on the box.
 */
Cone::Cone(const Vector3& tip, const Box& box) {
    this->tip = tip;
    this->direction = (box.getCenter() - tip).direction();

    // Find the biggest angle
    float smallestDotProduct = direction.dot((box.corner(0) - tip).direction());

    for (int i = 1; i < 8; ++i) {
        float dp = direction.dot((box.corner(i) - tip).direction());

        assert(dp > 0);

        if (dp < smallestDotProduct) {
            smallestDotProduct = dp;
        }
    }

    angle = acosf(smallestDotProduct);
}


bool Cone::intersects(const Sphere& b) const {
    // If the bounding sphere contains the tip, then
    // they definitely touch.
    if (b.contains(this->tip)) {
        return true;
    }

    // Move the tip backwards, effectively making the cone bigger
    // to account for the radius of the sphere.

    Vector3 tip = this->tip - direction * b.radius / sinf(angle);

    return Cone(tip, direction, angle).contains(b.center);
}


bool Cone::contains(const Vector3& v) const {

    Vector3 d = (v - tip).direction();

    float x = d.dot(direction);

    return (x > 0) && (x >= cosf(angle));
}

}; // namespace
