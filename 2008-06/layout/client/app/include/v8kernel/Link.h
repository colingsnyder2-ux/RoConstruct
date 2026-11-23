// =============================================================================
// Link.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/v8kernel/Link.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#pragma once
#include <G3D/CoordinateFrame.h>
//#include "v8kernel/Body.h"

namespace RBX
{
	class Body;
	class __declspec(novtable) Link
	{
		protected:
			RBX::Body *body;
			G3D::CoordinateFrame parentCoord;
			G3D::CoordinateFrame childCoord;
			G3D::CoordinateFrame childCoordInverse;
			mutable G3D::CoordinateFrame childInParent;
			mutable int stateIndex;
			virtual void computeChildInParent(G3D::CoordinateFrame& answer) const = 0;
			void dirty();
			//void setBody(RBX::Body* _body){ body = _body;}
		public:
			Link();
			~Link();
			const G3D::CoordinateFrame& getChildInParent() const;
			Body* getBody() const;
			void reset(const G3D::CoordinateFrame&, const G3D::CoordinateFrame&);
			void setBody(RBX::Body* _body){ body = _body;} // this isn't suppose to be in public but then i can't access it in Body::setParent()
	};

	class RevoluteLink : public Link
	{
	private:
		float jointAngle;

	private:
		virtual void computeChildInParent(G3D::CoordinateFrame& answer) const;
	public:
		RevoluteLink() : jointAngle(0.0f) {}
	public:
		void setJointAngle(float value)
		{
			jointAngle = value;
			dirty();
		}
	};
}
