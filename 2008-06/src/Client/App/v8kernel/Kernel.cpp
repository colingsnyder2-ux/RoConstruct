#pragma float_control(precise, off)
#include "v8kernel/Kernel.h"
#include "util/Debug.h"
#include "v8kernel/Constants.h"
#include "v8kernel/Connector.h"
using namespace RBX;

int Kernel::numKernels;

Kernel::Kernel(RBX::IStage* upstream) 
			:IStage(upstream, NULL),
			inStepCode(0),
			profilingKernel(new Profiling::CodeProfiler("Kernel")),
			kernelData(new KernelData()),
			maxBodies(0),
			maxPoints(0),
			maxConnectors(0){numKernels++;}

Kernel::~Kernel()
{
	Kernel::numKernels--;
	RBXASSERT(!inStepCode);
	delete kernelData;

}

void Kernel::insertBody(RBX::Body *b)
{
	kernelData->bodies.fastAppend(b);
}

inline void Kernel::insertPoint(RBX::Point *p)
{
	RBXASSERT(!inStepCode);
	kernelData->points.fastAppend(p);
}

void Kernel::insertConnector(RBX::Connector *c)
{
	RBXASSERT(!inStepCode);
	kernelData->connectors.fastAppend(c);
}

void Kernel::insertConnector2ndPass(RBX::Connector *c)
{
	RBXASSERT(!inStepCode);
	kernelData->connectors2ndPass.fastAppend(c);
}

void Kernel::removeBody(Body *b) 
{
	RBXASSERT(!inStepCode);
	kernelData->bodies.fastRemove(b);
}

inline void Kernel::removePoint(RBX::Point *p)
{
	RBXASSERT(!inStepCode);
	kernelData->points.fastRemove(p);
}

void Kernel::removeConnector(RBX::Connector *c)
{
	RBXASSERT(!inStepCode);
	realTimeConnectors.resize(0, false);
	kernelData->connectors.fastRemove(c);
}

void Kernel::removeConnector2ndPass(RBX::Connector *c) 
{
	RBXASSERT(!inStepCode);
	kernelData->connectors2ndPass.fastRemove(c);
}

int Kernel::numBodies() const { return kernelData->bodies.size(); }
int Kernel::numPoints() const { return kernelData->points.size(); }
int Kernel::numConnectors() const { return kernelData->connectors.size(); }

Point* Kernel::newPoint(Body* _body, const G3D::Vector3& worldPos)
{
	RBXASSERT(!inStepCode);
	Point* nPoint = new Point(_body);

	nPoint->setWorldPos(worldPos);

	//find any pre-existing point
	for (int i = 0; i < kernelData->points.size(); i++)
	{
		if (Point::sameBodyAndOffset(*nPoint, *kernelData->points[i]))
		{
			kernelData->points[i]->numOwners++;
			delete nPoint;
			return kernelData->points[i];
		}
	}
	insertPoint(nPoint);
	return nPoint;
}

void Kernel::deletePoint(RBX::Point* _point)
{
	RBXASSERT(!inStepCode);

	if (_point) 
	{
		_point->numOwners--;
		if (_point->numOwners == 0) 
		{
			removePoint(_point);
			delete _point;
		}
	}
}

void Kernel::stepWorld(int worldStepId, int uiStepId, bool throttling) 
{
	IndexArray<Body, &Body::getKernelIndex>& bodies = kernelData->bodies;
	IndexArray<Point, &Point::getKernelIndex>& points = kernelData->points;
	IndexArray<Connector, &Connector::getKernelIndex>& connectors = kernelData->connectors;
	IndexArray<Connector, &Connector::getKernelIndex>& connectors2ndPass = kernelData->connectors2ndPass;

	RBXASSERT(!inStepCode);
	inStepCode = true;
	Profiling::Mark mark = Profiling::Mark(*profilingKernel.get(), false);
	float kernelDt = Constants::kernelDt();
	int kernelSteps = Constants::kernelStepsPerWorldStep();

	if (throttling) {
		realTimeConnectors.resize(0, false);

		for (int i = 0; i < connectors.size(); i++){
			if (!connectors[i]->canThrottle())
			{
				realTimeConnectors.append(connectors[i]);
			}
		}
	}

	for (int i = 0; i < kernelSteps; i++)
	{
		for (int j = 0; j < points.size(); j++)
		{
			points[j]->step();
		}

		if (throttling)
		{
			for (int j = 0; j < realTimeConnectors.size(); j++)
			{
				realTimeConnectors[j]->computeForce(kernelDt, throttling);
			}
		}
		else
		{
			for (int j = 0; j < connectors.size(); j++)
			{
				connectors[j]->computeForce(kernelDt, throttling);
			}
		}

		for (int j = 0; j < points.size(); j++)
		{
			points[j]->forceToBody();
		}

		for (int j = 0; j < connectors2ndPass.size(); j++)
		{
			connectors2ndPass[j]->computeForce(kernelDt, throttling);
		}

		for (int j = 0; j < bodies.size(); j++)
		{
			bodies[j]->step(kernelDt, throttling);
		}
	}
	inStepCode = false;
}

float Kernel::connectorSpringEnergy() const
{
	float totalEnergy = 0.0;

	for (int i = 0; i < kernelData->connectors.size(); i++)
		totalEnergy += kernelData->connectors[i]->potentialEnergy();

	return totalEnergy;
}

float Kernel::bodyKineticEnergy() const
{
	float totalEnergy = 0.0;

	for (int i = 0; i < kernelData->bodies.size(); i++)
		totalEnergy += kernelData->bodies[i]->kineticEnergy();

	return totalEnergy;
}

//in original source this was in kernel.h
float Kernel::totalKineticEnergy() const
{
	return connectorSpringEnergy() + bodyKineticEnergy();
}

//hack to make compiler not to optimize out findStage
void Kernel::matchDummy()
{
	maxBodies = *(int*)findStage(SLEEP_STAGE);
}