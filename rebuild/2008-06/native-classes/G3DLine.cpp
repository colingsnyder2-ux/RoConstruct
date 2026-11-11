// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// 2008-06 native G3DLine (inactive): upstream tools/libs/g3d-6.09/source/G3Dcpp/Line.cpp, verbatim.
// >>> native-status (generated) -- do not edit >>>
// G3DLine | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 4fcd944c | roc native-status --write
/**
  @file Line.cpp
 
  Line class
 
  @maintainer Morgan McGuire, graphics3d.com
 
  @created 2001-06-02
  @edited  2006-01-28
 */

#include "G3D/Line.h"
#include "G3D/Plane.h"

namespace G3D {

Vector3 Line::intersection(const Plane& plane) const {
    float d;
    Vector3 normal = plane.normal();
    plane.getEquation(normal, d);
    float rate = _direction.dot(normal);

    if (rate == 0) {

        return Vector3::inf();

    } else {
        float t = -(d + _point.dot(normal)) / rate;

        return _point + _direction * t;
    }
}


Line::Line(class BinaryInput& b) {
	deserialize(b);
}


void Line::serialize(class BinaryOutput& b) const {
	_point.serialize(b);
	_direction.serialize(b);
}


void Line::deserialize(class BinaryInput& b) {
	_point.deserialize(b);
	_direction.deserialize(b);
}


Vector3 Line::closestPoint(const Vector3& pt) const {
    float t = _direction.dot(pt - _point);
    return _point + _direction * t;
}


Vector3 Line::point() const {
    return _point;
}


Vector3 Line::direction() const {
    return _direction;
}

}

