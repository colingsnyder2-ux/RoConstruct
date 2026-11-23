#pragma once
#include <G3D/CoordinateFrame.h>
#include "util/Quaternion.h"

namespace RBX
{
	class RunningAverageState
	{
	private:
		G3D::Vector3 position;
		Quaternion angles;

	public:
		//RunningAverageState(const RunningAverageState&);
		RunningAverageState()
			: position(),
			  angles()
		{
		}
		void update(const G3D::CoordinateFrame& cofm, float radius);
		bool withinTolerance(const G3D::CoordinateFrame& cofm, float radius, float tolerance);
		//RunningAverageState& operator=(const RunningAverageState&);

	private:
		static float weight();
	public:
		static int stepsToSleep();
	};
}
// 2008-06 native header port of rbxgs App/include/util/RunningAverage.h (2007 text). Kept only because every dependent exact native unit
// compiles to an identical object with it in native-headers (proof: work/donorfree-route/header_port_proof.json).
