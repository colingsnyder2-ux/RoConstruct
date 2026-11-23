// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/part-embedded /I{headers}/../../../tools/rbxgs/Client/Network/raknet30/Source
// 2008-06 native RBX::Network::DirectPhysicsReceiver::receivePacket 004c83b0 (inactive), declared in
// Network/PhysicsReplication.h. The body belongs to the physics receiver unit (004c6d30..004c9790: AppUnit4BC_2008Receiver.cpp,
// InterpolatingPhysicsReceiverRecovery_004b6290.cpp); like PhysicsSenderWriteSnapshot.cpp it has its own file because it
// needs the native PartInstance / Clump / Joint headers (part-embedded native-body Primitive, NATIVE_CLUMP_DECL: the clump's
// getAnchored is the out-of-line 005e60e0), so the receiver units' flags and includes stay unchanged.
#define NATIVE_PRIMITIVE_NATIVE_BODY
#define NATIVE_CLUMP_DECL
#define NATIVE_REPLICATOR_NO_STATS_ITEM
#include "Network/PhysicsSenders2008.h"
#include "Network/Replicator2008.h"
#include "Network/NetworkSettings.h"
#include "v8datamodel/PartInstance.h"
#include "v8world/AssemblyLayout.h"
#include "v8world/Joints2008.h"
#include "util/Quaternion.h"
#include "util/Math.h"
#include "util/standardout.h"
#include "util/Object.h"
#include "AppUnit49C_2008/Streaming2008.h"
#include "AppUnit4BC_2008/AssociationTimeStamp.h"
#include <BitStream.h>
#include <stdexcept>
namespace RBX
{
	namespace Network
	{
		// 004c83b0 (1890 bytes, DirectPhysicsReceiver vtable slot 2, thiscall ret 8; registry placeholder
		// func_004c83b0, declared in Network/PhysicsReplication.h). Shape: the 2007 OpenRBX Replicator physics-in loop
		// (Replicator.cpp) without its RakNet framing, with the binary's 2008 differences: an unidentified or rejected
		// part only clears the part (the sample is still read), strings 008266e8 / 008266c0 / 00826694 / 00826670 /
		// 00826658 / 00826638 / 0082661c; part->assoc (+0xec) get<TimeStamp> 004c7ef0 (`cmp [eax], ecx` / jbe: the
		// unsigned time); CoordinateFrame() (Matrix3::identity 00513e20 copied by 00513220, Vector3::zero guard 0096f050);
		// readPosition 004ca5c0; Quaternion(0, 0, 0, 1) then ReadNormQuat 004a5f20 (throw runtime_error on failure);
		// toRotationMatrix 005dd6d0; setPhysics 005997f0 unless the clump (+0x228 + 0x5c) is anchored (005e60e0); the
		// motor angles go to Assembly::getMotor 005e6400 -> setCurrentAngle 005e5da0 when numMotors 005e62d0 matches,
		// otherwise they are only read.
		void DirectPhysicsReceiver::receivePacket(RakNet::BitStream& bitStream, unsigned int timeStamp)
		{
			while (true)
			{
				boost::shared_ptr<PartInstance> part;

				Instance* instance;
				Guid::Data id;
				if (replicator->deserializeInstanceRef(bitStream, instance, id))
				{
					if (!instance)
						return;
					part = shared_from_polymorphic_downcast<PartInstance>(instance);
				}
				else if (NetworkSettings::singleton().printPhysicsErrors)
				{
					StandardOut::singleton()->print(MESSAGE_WARNING, "Physics-in of unidentified %s", id.readableString(4).c_str());
				}

				if (part)
				{
					if (!PartInstance::nonNullInWorkspace(part))
					{
						if (NetworkSettings::singleton().printPhysicsErrors)
							StandardOut::singleton()->print(MESSAGE_INFO, "Physics-in of part not in workspace %s", id.readableString(4).c_str());
						part.reset();
					}
					else if (!part->getPrimitive()->getAssembly())
					{
						if (NetworkSettings::singleton().printPhysicsErrors)
							StandardOut::singleton()->print(MESSAGE_INFO, "Physics-in of primitive with no assembly %s", id.readableString(4).c_str());
						part.reset();
					}
					else if (part->getPrimitive()->getClump()->getAnchored())
					{
						if (NetworkSettings::singleton().printPhysicsErrors)
							StandardOut::singleton()->print(MESSAGE_INFO, "Physics-in of anchored primitive %s", id.readableString(4).c_str());
						part.reset();
					}
					else
					{
						TimeStamp& stamp = part->assoc.get<TimeStamp>();
						if (stamp.time > timeStamp)
						{
							if (NetworkSettings::singleton().printPhysicsErrors)
								StandardOut::singleton()->print(MESSAGE_INFO, "Physics-in old packet");
							part.reset();
						}
						else
						{
							stamp.time = timeStamp;
						}
					}
				}

				G3D::CoordinateFrame cf;
				IPhysicsSender::readPosition(bitStream, cf.translation);

				Quaternion q(0.0f, 0.0f, 0.0f, 1.0f);
				if (!bitStream.ReadNormQuat(q.w, q.x, q.y, q.z))
					throw std::runtime_error("Failed to read Quaternion");
				q.toRotationMatrix(cf.rotation);

				if (part && !part->getPrimitive()->getClump()->getAnchored())
					part->setPhysics(cf);

				unsigned char numMotors;
				bitStream >> numMotors;
				if (numMotors > 50 && NetworkSettings::singleton().printPhysicsErrors)
					StandardOut::singleton()->print(MESSAGE_WARNING, "Physics-in of %s has %d motors", id.readableString(4).c_str(), numMotors);

				int n = numMotors;
				Assembly* assembly;
				if (part && (assembly = part->getPrimitive()->getAssembly()) && assembly->numMotors() == n)
				{
					for (int i = 0; i < n; i++)
					{
						unsigned char value;
						bitStream >> value;
						assembly->getMotor(i)->setCurrentAngle(Math::rotationFromByte(value));
					}
				}
				else
				{
					for (int i = 0; i < n; i++)
					{
						unsigned char value;
						bitStream >> value;
					}
				}
			}
		}
	}
}
