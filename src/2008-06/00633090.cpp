// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs roc_unit_68d8f4cfa4d371f8.cpp

// Candidate translation unit (score above; library headers required).
#pragma include_alias("v8tree/Instance.h", "roc_unit_b34763c2f3d3f398.cpp")
#pragma include_alias("v8datamodel/JointInstance.h", "roc_unit_ffc89e90dbae649c.cpp")
#pragma include_alias("v8datamodel/Gyro.h", "roc_unit_49d5cd98eaed3b87.cpp")
#pragma include_alias("util/IRenderable.h", "roc_unit_b8671ae8d3010f90.cpp")
#include "v8datamodel/Gyro.h"
namespace RBX {
	const char* sBodyPosition = "BodyPosition";
	const char* sBodyVelocity = "BodyVelocity";
	const char* sBodyGyro = "BodyGyro";
	const char* sBodyForce = "BodyForce";
	const char* sBodyThrust = "BodyThrust";
	const char* sRocket = "Rocket";
	Reflection::RefPropDescriptor<Rocket, PartInstance> Rocket::prop_Target("Target", "Goals", &Rocket::getTarget, &Rocket::setTarget, Reflection::PropertyDescriptor::STANDARD);
	Reflection::BoundProp<G3D::Vector3, 1> Rocket::prop_targetOffset("TargetOffset", "Goals", &Rocket::targetOffset, &Rocket::onGoalChanged, Reflection::PropertyDescriptor::STANDARD);
	Reflection::BoundProp<float, 1> Rocket::prop_targetRadius("TargetRadius", "Goals", &Rocket::targetRadius, &Rocket::onGoalChanged, Reflection::PropertyDescriptor::STANDARD);
	Reflection::BoundProp<float, 1> Rocket::prop_MaxSpeed("MaxSpeed", "Thrust", &Rocket::maxSpeed, Reflection::PropertyDescriptor::STANDARD);
	Reflection::BoundProp<float, 1> Rocket::prop_MaxThrust("MaxThrust", "Thrust", &Rocket::maxThrust, Reflection::PropertyDescriptor::STANDARD);
	Reflection::BoundProp<float, 1> Rocket::prop_ThrustP("ThrustP", "Thrust", &Rocket::kThrustP, Reflection::PropertyDescriptor::STANDARD);
	Reflection::BoundProp<float, 1> Rocket::prop_ThrustD("ThrustD", "Thrust", &Rocket::kThrustD, Reflection::PropertyDescriptor::STANDARD);
	Reflection::BoundProp<float, 1> Rocket::prop_TurnP("TurnP", "Turn", &Rocket::kTurnP, Reflection::PropertyDescriptor::STANDARD);
	Reflection::BoundProp<float, 1> Rocket::prop_TurnD("TurnD", "Turn", &Rocket::kTurnD, Reflection::PropertyDescriptor::STANDARD);
	Reflection::BoundProp<G3D::Vector3, 1> Rocket::prop_MaxTorque("MaxTorque", "Turn", &Rocket::maxTorque, Reflection::PropertyDescriptor::STANDARD);
	Reflection::BoundProp<float, 1> Rocket::prop_CartoonFactor("CartoonFactor", "Goals", &Rocket::cartoonFactor, Reflection::PropertyDescriptor::STANDARD);
	Reflection::BoundFuncDesc<Rocket, void(void), 0> Rocket::func_Fire(&Rocket::fire, "Fire", Reflection::FunctionDescriptor::AnyCaller);
	Reflection::BoundFuncDesc<Rocket, void(void), 0> Rocket::func_Abort(&Rocket::abort, "Abort", Reflection::FunctionDescriptor::AnyCaller);
	Reflection::SignalDesc<Rocket, void(void)> Rocket::event_ReachedTarget("ReachedTarget");
	Reflection::BoundProp<float, 1> BodyGyro::prop_kP("P", "Goals", &BodyGyro::kP, Reflection::PropertyDescriptor::STANDARD);
	Reflection::BoundProp<float, 1> BodyGyro::prop_kD("D", "Goals", &BodyGyro::kD, Reflection::PropertyDescriptor::STANDARD);
	Reflection::BoundProp<G3D::Vector3, 1> BodyGyro::prop_maxTorque("maxTorque", "Goals", &BodyGyro::maxTorque, Reflection::PropertyDescriptor::STANDARD);
	Reflection::BoundProp<G3D::CoordinateFrame, 1> BodyGyro::prop_cframe("cframe", "Goals", &BodyGyro::cframe, Reflection::PropertyDescriptor::STANDARD);
	Reflection::BoundProp<float, 1> BodyPosition::prop_kP("P", "Goals", &BodyPosition::kP, Reflection::PropertyDescriptor::STANDARD);
	Reflection::BoundProp<float, 1> BodyPosition::prop_kD("D", "Goals", &BodyPosition::kD, Reflection::PropertyDescriptor::STANDARD);
	Reflection::BoundProp<G3D::Vector3, 1> BodyPosition::prop_maxForce("maxForce", "Goals", &BodyPosition::maxForce, Reflection::PropertyDescriptor::STANDARD);
	Reflection::BoundProp<G3D::Vector3, 1> BodyPosition::prop_position("position", "Goals", &BodyPosition::position, Reflection::PropertyDescriptor::STANDARD);
	Reflection::BoundProp<float, 1> BodyVelocity::prop_kP("P", "Goals", &BodyVelocity::kP, Reflection::PropertyDescriptor::STANDARD);
	Reflection::BoundProp<G3D::Vector3, 1> BodyVelocity::prop_maxForce("maxForce", "Goals", &BodyVelocity::maxForce, Reflection::PropertyDescriptor::STANDARD);
	Reflection::BoundProp<G3D::Vector3, 1> BodyVelocity::prop_velocity("velocity", "Goals", &BodyVelocity::velocity, Reflection::PropertyDescriptor::STANDARD);
	Reflection::BoundProp<G3D::Vector3, 1> BodyForce::prop_Force("force", "Goals", &BodyForce::force, Reflection::PropertyDescriptor::STANDARD);
	Reflection::BoundProp<G3D::Vector3, 1> BodyThrust::prop_force("force", "Goals", &BodyThrust::force, Reflection::PropertyDescriptor::STANDARD);
	Reflection::BoundProp<G3D::Vector3, 1> BodyThrust::prop_location("location", "Goals", &BodyThrust::location, Reflection::PropertyDescriptor::STANDARD);
}
