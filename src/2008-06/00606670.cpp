// from server: 100% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_king_originala_normal_force_8fd37584ce892fc0.cpp

// Candidate translation unit (score above; library headers required).
#include "util/PV.h"
#include "util/Math.h"
namespace RBX {
class Body { char prefix[0x94]; PV pv; public: void updatePV() const; const PV& getPV() const {updatePV();return pv;} };
class KernelIndex { public: int kernelIndex; KernelIndex():kernelIndex(-1){} };
// Borrowed Point view: native getBody(int) dereferences point+0xc.
class Point : KernelIndex { public: int numOwners; protected: Body* body; G3D::Vector3 localPos,worldPos,force; public: virtual ~Point() {} Body* getBody(){return body;} const G3D::Vector3& getWorldPos(){return worldPos;} void accumulateForce(const G3D::Vector3& f){force+=f;} };
class Kernel { public: Point* newPoint(Body*,const G3D::Vector3&); };
	class Connector : public RBX::KernelIndex
	{
	public: // this is meant to be private
		__declspec(noinline) int& getKernelIndex() {return kernelIndex;}
	public:
		Connector(const Connector&);
		Connector() {};
		virtual ~Connector() {}
		virtual void computeForce(const float dt, bool throttling) = 0;
		virtual bool canThrottle() const {return true;}
		virtual bool getBroken() {return false;}
		virtual Body* getBody(int) = 0;
		//RBX::Connector& operator=(const RBX::Connector&);
	};

	class PointToPointBreakConnector : public Connector
	{
	protected:
		Point* point0;
		Point* point1;
		float k;
		float breakForce;
		bool broken;
	protected:
		void forceToPoints(const G3D::Vector3&);
	public:
		//PointToPointBreakConnector(const PointToPointBreakConnector&);
		// TODO:: check if the ctor matches
		PointToPointBreakConnector(Point* _point0, Point* _point1, float _k, float _breakForce)
			: point0(_point0),
			  point1(_point1),
			  k(_k),
			  breakForce(_breakForce),
			  broken(false)
		{}

		virtual void computeForce(const float dt, bool throttling);
		virtual bool getBroken() {return this->broken;}
		virtual Body* getBody(int i) { if (i == 0) return point0->getBody(); return point1->getBody(); }
		void setBroken() {this->broken = true;}
		virtual ~PointToPointBreakConnector() {};
		//PointToPointBreakConnector& operator=(const PointToPointBreakConnector&);
	};

	class NormalBreakConnector : public PointToPointBreakConnector
	{
	private:
		NormalId normalIdBody0;

	public:
		//NormalBreakConnector(const NormalBreakConnector&);
		NormalBreakConnector(Point* _point0, Point* _point1, float _k, float _breakForce, NormalId _normalIdBody0)
			: PointToPointBreakConnector(_point0, _point1, _k, _breakForce),
			  normalIdBody0(_normalIdBody0)
		{
		}
		virtual ~NormalBreakConnector() {}
	public:
		virtual void computeForce(const float dt, bool throttling);
		//NormalBreakConnector& operator=(const NormalBreakConnector&);
	};

}
namespace RBX {
void PointToPointBreakConnector::forceToPoints(const G3D::Vector3& force) { point0->accumulateForce(-force); point1->accumulateForce(force); }
void NormalBreakConnector::computeForce(const float dt,bool throttling) {
 if(!broken) {
  const G3D::Vector3& worldNormal=Math::getWorldNormal(normalIdBody0,point0->getBody()->getPV().position);
  const G3D::Vector3& force=-k*(point1->getWorldPos()-point0->getWorldPos());
  float forceDot=force.dot(worldNormal);
  broken=-forceDot>breakForce;
  forceToPoints(force);
 }
}
}
