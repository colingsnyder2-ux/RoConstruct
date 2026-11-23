// =============================================================================
// Kernel.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/v8kernel/Kernel.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#define NATIVE_PRIMITIVE_NATIVE_BODY
#include <G3D/Array.h>
#include "v8kernel/Connector2008.h"
#include "v8kernel/Constants.h"
#include "util/Profiling.h"
#include "v8kernel/Kernel2008.h"
#include "v8kernel/KernelData2008.h"

namespace RBX
{
	float Kernel::bodyKineticEnergy() const
	{
		float totalEnergy = 0.0;

		for (int i = 0; i < kernelData->bodies.size(); i++)
			totalEnergy += kernelData->bodies[i]->kineticEnergy();

		return totalEnergy;
	}

	void Kernel::insertConnector(Connector* c)
	{
		kernelData->connectors.fastAppend(c);
		kernelData->onConnectorAdded(c);
	}

	void Kernel::removeConnector(Connector* c)
	{
		kernelData->onConnectorRemoved(c);
		realTimeConnectors.resize(0, false);
		kernelData->connectors.fastRemove(c);
	}

	void Kernel::removePoint(Point* point)
	{
		kernelData->points.fastRemove(point);
	}

	Point* Kernel::newPoint(Body* _body, const G3D::Vector3& worldPos)
	{
		Point* nPoint = new Point(_body);

		nPoint->setWorldPos(worldPos);

		for (int i = 0; i < kernelData->points.size(); i++)
		{
			if (Point::sameBodyAndOffset(*nPoint, *kernelData->points[i]))
			{
				kernelData->points[i]->numOwners++;
				delete nPoint;
				return kernelData->points[i];
			}
		}
		kernelData->points.fastAppend(nPoint);
		return nPoint;
	}

	void Kernel::deletePoint(Point* point)
	{
		if (point)
		{
			point->numOwners--;
			if (point->numOwners == 0)
			{
				removePoint(point);
				delete point;
			}
		}
	}

#ifdef NATIVE_KERNEL_STEP_PENDING
	void Kernel::stepWorld(int worldStepId, int uiStepId, bool throttling, bool moveBodiesTest)
	{
		if (moveBodiesTest)
		{
			stepMoveBodiesTest(worldStepId);
			return;
		}

		KernelData* data = kernelData;
		inStepCode = true;
		{
			Profiling::Mark mark(*profilingKernel.get(), false);

			if (throttling)
			{
				realTimeConnectors.resize(0, false);

				for (int i = 0; i < data->connectors.size(); i++)
				{
					if (!data->connectors[i]->canThrottle())
					{
						realTimeConnectors.append(data->connectors[i]);
					}
				}
			}

			float kernelDt = Constants::kernelDt();
			int kernelSteps = Constants::kernelStepsPerWorldStep();

			for (int i = 0; i < kernelSteps; i++)
			{
				for (int j = 0; j < data->points.size(); j++)
				{
					data->points[j]->step();
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
					for (int j = 0; j < data->connectors.size(); j++)
					{
						data->connectors[j]->computeForce(kernelDt, throttling);
					}
				}

				for (int j = 0; j < data->points.size(); j++)
				{
					data->points[j]->forceToBody();
				}

				for (int j = 0; j < data->connectors2ndPass.size(); j++)
				{
					data->connectors2ndPass[j]->computeForce(kernelDt, throttling);
				}

				for (int j = 0; j < data->bodies.size(); j++)
				{
					data->bodies[j]->step(throttling);
				}

				for (int j = 0; j < data->leafBodies.size(); j++)
				{
					data->leafBodies[j]->getPV();
				}
			}
			inStepCode = false;
		}
	}
#endif
}

#define NATIVE_PRIMITIVE_NATIVE_BODY

void RBX::Kernel::removeConnector2ndPass(Connector* connector)
{
	kernelData->connectors2ndPass.fastRemove(connector);
}
