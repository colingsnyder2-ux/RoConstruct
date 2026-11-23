#pragma once
#include "v8world/Geometry.h"

namespace RBX
{
	class Ball : public Geometry
	{
	private:
		float realRadius;
	private:
		G3D::Matrix3 getMomentSolid(float mass) const;
		G3D::Matrix3 getMomentHollow(float mass) const;
		virtual void onSetSize();
	public:
		Ball(const Ball& other);
		Ball() : realRadius(0.0f) {}
		virtual ~Ball() {}
		virtual bool hitTest(const G3D::Ray& rayInMe, G3D::Vector3& localHitPoint, bool& inside);
		virtual GeometryType getGeometryType() const
		{
			return GEOMETRY_BALL;
		}
		virtual float getRadius() const
		{
			return this->realRadius;
		}
		virtual G3D::Vector3 getCenterToCorner(const G3D::Matrix3& rotation) const
		{
			return G3D::Vector3(this->realRadius, this->realRadius, this->realRadius);
		}
		virtual G3D::Matrix3 getMoment(float mass) const
		{
			return this->getMomentSolid(mass);
		}
		virtual float getGridVolume() const;
		//Ball& operator=(const Ball& other);
	};
}
// 2008-06 native header port of rbxgs App/include/v8world/Ball.h (2007 text). Kept only because every dependent exact native unit
// compiles to an identical object with it in native-headers (proof: work/donorfree-route/header_port_proof.json).
