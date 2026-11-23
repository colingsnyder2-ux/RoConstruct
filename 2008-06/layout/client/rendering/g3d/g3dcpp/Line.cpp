// =============================================================================
// Line.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/rendering/g3d/g3dcpp/Line.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#line 1 ".\\G3Dcpp\\Line.cpp"
/**
  @file Line.cpp

  Line class

  @maintainer Morgan McGuire, graphics3d.com

  @created 2001-06-02
  @edited  2006-01-28
 */

#include "G3D/Line.h"
#include "G3D/Plane.h"

namespace G3D
{

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
