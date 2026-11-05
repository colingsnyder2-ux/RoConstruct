// from server: 54% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/v8kernel/Kernel.cpp

// Candidate translation unit (score above; library headers required).
#include "v8kernel/Kernel.h"

#include "util/Profiling.h"
#include "v8kernel/Body.h"
#include "v8kernel/Connector.h"
#include "v8kernel/Constants.h"
#include "v8kernel/KernelData.h"
#include "v8kernel/Point.h"

#include <cstddef>

namespace RBX {

// GLOBAL: WEBSERVICE 0x102e54c4
int Kernel::numKernels = 0;

// FUNCTION: WEBSERVICE 0x100d4f20
int Kernel::numConnectors() const
{
	return kernelData->connectors.size();
}

// FUNCTION: WEBSERVICE 0x100d4f30
float Kernel::connectorSpringEnergy() const
{
	float springPotential = 0.0f;

	for (int i = 0; i < kernelData->connectors.size(); ++i) {
		springPotential += kernelData->connectors[i]->potentialEnergy();
	}

	return springPotential;
}

// FUNCTION: WEBSERVICE 0x100d5310
int Kernel::numBodies() const
{
	return kernelData->bodies.size();
}

// FUNCTION: WEBSERVICE 0x100d5320
int Kernel::numPoints() const
{
	return kernelData->points.size();
}

// FUNCTION: WEBSERVICE 0x100d5330
float Kernel::bodyKineticEnergy() const
{
	float answer = 0.0f;

	for (int i = 0; i < kernelData->bodies.size(); ++i) {
		answer += kernelData->bodies[i]->kineticEnergy();
	}

	return answer;
}

// FUNCTION: WEBSERVICE 0x100d54c0
void Kernel::insertConnector(Connector* c)
{
	kernelData->connectors.fastAppend(c);
}

// FUNCTION: WEBSERVICE 0x100d54f0
void Kernel::insertConnector2ndPass(Connector* c)
{
	kernelData->connectors2ndPass.fastAppend(c);
}

// FUNCTION: WEBSERVICE 0x100d5520
void Kernel::removeConnector(Connector* c)
{
	realTimeConnectors.resize(0, false);

	kernelData->connectors.fastRemove(c);
}

// FUNCTION: WEBSERVICE 0x100d5580
void Kernel::removeConnector2ndPass(Connector* c)
{
	kernelData->connectors2ndPass.fastRemove(c);
}

// FUNCTION: WEBSERVICE 0x100d55d0
void Kernel::stepWorld(int worldStepId, int uiStepId, bool throttling)
{
	KernelData* data = kernelData;

	inStepCode = true;

	Profiling::Mark mark(*profilingKernel, false);

	float dt = Constants::kernelDt();
	int kernelSteps = Constants::kernelStepsPerWorldStep();

	if (throttling) {
		realTimeConnectors.resize(0, false);

		for (int i = 0; i < data->connectors.size(); ++i) {
			if (!data->connectors[i]->canThrottle()) {
				realTimeConnectors.append(data->connectors[i]);
			}
		}
	}

	for (int step = 0; step < kernelSteps; ++step) {
		for (int i = 0; i < data->points.size(); ++i) {
			data->points[i]->step();
		}

		if (throttling) {
			for (int i = 0; i < realTimeConnectors.size(); ++i) {
				realTimeConnectors[i]->computeForce(dt, throttling);
			}
		}
		else {
			for (int i = 0; i < data->connectors.size(); ++i) {
				data->connectors[i]->computeForce(dt, false);
			}
		}

		for (int i = 0; i < data->points.size(); ++i) {
			data->points[i]->forceToBody();
		}

		for (int i = 0; i < data->connectors2ndPass.size(); ++i) {
			data->connectors2ndPass[i]->computeForce(dt, throttling);
		}

		for (int i = 0; i < data->bodies.size(); ++i) {
			data->bodies[i]->step(dt, throttling);
		}
	}

	inStepCode = false;
}

// FUNCTION: WEBSERVICE 0x100d57e0
void Kernel::insertBody(Body* b)
{
	kernelData->bodies.fastAppend(b);
}

// FUNCTION: WEBSERVICE 0x100d5800
void Kernel::removeBody(Body* b)
{
	kernelData->bodies.fastRemove(b);
}

// FUNCTION: WEBSERVICE 0x100d5840
void Kernel::removePoint(Point* p)
{
	kernelData->points.fastRemove(p);
}

// FUNCTION: WEBSERVICE 0x100d5890
Point* Kernel::newPoint(Body* _body, const Vector3& worldPos)
{
	Point* point = new Point(_body);

	point->setWorldPos(worldPos);

	for (int i = 0; i < kernelData->points.size(); ++i) {
		Point* other = kernelData->points[i];

		if (Point::sameBodyAndOffset(point, other)) {
			kernelData->points[i]->numOwners++;
			delete point;

			return kernelData->points[i];
		}
	}

	kernelData->points.fastAppend(point);

	return point;
}

// FUNCTION: WEBSERVICE 0x100d59f0
void Kernel::deletePoint(Point* _point)
{
	if (_point != NULL) {

		if (--_point->numOwners == 0) {
			removePoint(_point);
			delete _point;
		}
	}
}

// FUNCTION: WEBSERVICE 0x100d5a20
Kernel::~Kernel()
{
	numKernels--;

	delete kernelData;
}

// FUNCTION: WEBSERVICE 0x100d5ad0 FOLDED
Kernel* Kernel::getKernel()
{
	return this;
}

// FUNCTION: WEBSERVICE 0x100d5ae0
Kernel::Kernel(IStage* upstream)
	: IStage(upstream, NULL), inStepCode(false), kernelData(new KernelData()), maxBodies(0), maxPoints(0),
	  maxConnectors(0), profilingKernel(new Profiling::CodeProfiler("Kernel"))
{
	numKernels++;
}

} // namespace RBX
