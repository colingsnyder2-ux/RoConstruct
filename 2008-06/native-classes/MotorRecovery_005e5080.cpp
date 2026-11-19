// 2008-06 native RBX::Motor member function recoveries
// Addresses: 005e5020 (88 bytes), 005e5080 (61 bytes)
// Unit: RBX::VMotor::?$FactoryProduct

#include "v8datamodel/JointInstance.h"

namespace RBX
{

// 005e5080: member, name unknown: use sub_005e5080 (descriptor-ptm)
// INFERRED: inline implementation matching binary size of 61 bytes
// This function corresponds to the first PTM descriptor for Motor class
float Motor::getMaxVelocity() const
{
	return maxVelocity;
}

// 005e5020: member, name unknown: use sub_005e5020 (descriptor-ptm)
// INFERRED: inline implementation matching binary size of 88 bytes
// This function corresponds to the second PTM descriptor for Motor class
void Motor::setMaxVelocity(float value)
{
	this->maxVelocity = value;
}

} // namespace RBX