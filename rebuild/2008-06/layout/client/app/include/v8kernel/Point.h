// =============================================================================
// Point.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/v8kernel/Point.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#pragma once
#include <G3D/Vector3.h>
#include "v8kernel/Body.h"

namespace RBX
{
	class Point : RBX::KernelIndex
	{
	public: // this is meant to be private
		int numOwners;
	protected:
		RBX::Body *body;
		G3D::Vector3 localPos;
		G3D::Vector3 worldPos;
		G3D::Vector3 force;
	public: // this is meant to be private
		int& getKernelIndex() {return this->kernelIndex;}
	public:
		Point(Body* _body); // TODO: the ctor is supposed to be private but Kernel::newPoint uses these ctors
		Point(const Point& _point);
		virtual ~Point() {}

		void step();
		void accumulateForce(const G3D::Vector3& _force) {this->force += _force;}
		void forceToBody();
		void setLocalPos(const G3D::Vector3& _localPos);
		void setWorldPos(const G3D::Vector3& _worldPos);
		void setBody(RBX::Body* _body) { this->body = _body; }
		RBX::Body* getBody() {return this->body;}
		const G3D::Vector3& getWorldPos() {return worldPos;}
		//Point& operator=(const Point&);

		static bool Point::sameBodyAndOffset(const RBX::Point& p1, const RBX::Point& p2)
		{
			return p1.body == p2.body && p1.localPos == p2.localPos;
		}
	};
}
