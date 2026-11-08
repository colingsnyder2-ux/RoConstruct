// 2008-06 native RBX::RotateJoint / DynamicRotateJoint / RotatePJoint / RotateVJoint (inactive); evidence in
// native-headers/v8world/Joints2008.h. Verified by tests/record_native_world_joints.py. Rows of the RotateJoint unit
// (00645a70..00646550): both RotateJoint constructors, the destructor, removeFromKernel, the RotateP / RotateV
// stepWorld bodies and constructors, the RotateJoint scalar deleting destructor (vtable 0084adc4 is emitted here) and
// surfaceTypeToJoint. getChannelValue 00645af0, canBuildJoint 00645f60, getTorqueArmLength and putInKernel 00646550
// need the native Primitive / Body; DynamicRotateJoint::stepUi 006463f0 needs World::ticklePrimitive (see
// NATIVE_WORLD_JOINTS_PENDING_WORLD and the recorder's PROPOSALS).
// >>> native-status (generated) -- do not edit >>>
// WorldJointRotate | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src c6bfa8d2 | roc native-status --write
#include "v8world/Joints2008.h"
#include "v8kernel/Kernel.h"
#include "v8kernel/Connector.h"
#include "v8kernel/Constants.h"

namespace RBX
{
	// 00645a90
	RotateJoint::RotateJoint(Primitive* axlePrim, Primitive* holePrim, const G3D::CoordinateFrame& c0,
	                         const G3D::CoordinateFrame& c1)
		: MultiJoint(axlePrim, holePrim, c0, c1, 2),
		  rotateConnector(NULL)
	{
	}

	// 00645a70
	RotateJoint::RotateJoint()
		: MultiJoint(2),
		  rotateConnector(NULL)
	{
	}

	// 00645ad0 (vtable store, tail jump to ~MultiJoint 00646960)
	RotateJoint::~RotateJoint()
	{
	}

	// 00645ae0 (tail jump to MultiJoint::removeFromKernel 006469e0)
	void RotateJoint::removeFromKernel()
	{
		rotateConnector = NULL;
		MultiJoint::removeFromKernel();
	}

	// 00645cb0: KernelInput::setGoalCalc on the connector's input (+0x24 of RotateConnector 00606170); the step count
	// is the call at 00645ce4 (006492d0, `mov eax, 0x13`).
	inline float calculateIncrementRotatePJoint(float value, float currentGoal, int steps)
	{
		return (value - currentGoal) / steps;
	}

	void RotatePJoint::stepWorld()
	{
		RotateConnector* connector = rotateConnector;
		if (connector)
			connector->getKernelInput()->setGoalCalc(channelValue, calculateIncrementRotatePJoint);
	}

	// 00645d00: Constants::worldStepsPerUiStep (call 00645d11 -> 0063e420, `mov eax, 8`) and
	// Constants::kernelStepsPerWorldStep (call 00645d28 -> 006492d0, `mov eax, 0x13`), then KernelInput::setDelta.
	void RotateVJoint::stepWorld()
	{
		RotateConnector* connector = rotateConnector;
		if (connector)
		{
			float perWorldStep = channelValue / (float)Constants::worldStepsPerUiStep();
			connector->getKernelInput()->setDelta(perWorldStep / (float)Constants::kernelStepsPerWorldStep());
		}
	}

#ifdef NATIVE_WORLD_JOINTS_PENDING_WORLD
	// 006463f0 (slot 14 of RotatePJoint and RotateVJoint): getChannelValue 00645af0, IPipelined::getWorld inline
	// (KERNEL_STAGE 7), World::ticklePrimitive 005e9410 for both primitives. Needs a World declaration reachable
	// without the donor joint headers, and the 2008 IStage (see PROPOSALS).
	void DynamicRotateJoint::stepUi(int uiStepId)
	{
		channelValue = getChannelValue(uiStepId);
		if (channelValue != 0.0f)
		{
			World* world = getWorld();
			world->ticklePrimitive(getPrimitive(0), true);
			world->ticklePrimitive(getPrimitive(1), true);
		}
	}
#endif

	// 00645d90
	RotatePJoint::RotatePJoint(Primitive* axlePrim, Primitive* holePrim, const G3D::CoordinateFrame& c0,
	                           const G3D::CoordinateFrame& c1)
		: DynamicRotateJoint(axlePrim, holePrim, c0, c1)
	{
	}

	// 00645dd0
	RotateVJoint::RotateVJoint(Primitive* axlePrim, Primitive* holePrim, const G3D::CoordinateFrame& c0,
	                           const G3D::CoordinateFrame& c1)
		: DynamicRotateJoint(axlePrim, holePrim, c0, c1)
	{
	}

	// 00645e40: news 0xc4 (ROTATE), 0xc8 (ROTATE_P -> 00645d90, EH state 1; ROTATE_V -> 00645dd0, EH state 2).
	RotateJoint* RotateJoint::surfaceTypeToJoint(SurfaceType surfaceType, Primitive* axlePrim, Primitive* holePrim,
	                                             const G3D::CoordinateFrame& c0, const G3D::CoordinateFrame& c1)
	{
		switch (surfaceType)
		{
		case ROTATE:
			return new RotateJoint(axlePrim, holePrim, c0, c1);
		case ROTATE_P:
			return new RotatePJoint(axlePrim, holePrim, c0, c1);
		case ROTATE_V:
			return new RotateVJoint(axlePrim, holePrim, c0, c1);
		default:
			return NULL;
		}
	}
}
