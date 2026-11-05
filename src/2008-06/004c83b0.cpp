// from server: 100% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-net-dll roc_physics_receiver_native_part_147a9c5ba3a2a258.cpp

// Candidate translation unit (score above; library headers required).
#pragma include_alias("v8tree/Instance.h", "roc_instance_guid_callback_5e8a3f385d045a38.cpp")
#include <roc_part_primitive_decl_probe_7140c279266668c9.cpp>
#include <roc_part_grouped_tail_decl_25cfdd3b306c5d60.cpp>
// Native004c83b0 full1890B, DirectPhysicsReceiver::receivePacket.
// Typed public SDK values plus binary-backed opaque pointer APIs.
#include <BitStream.h>
#include <G3D/CoordinateFrame.h>
#include "util/Quaternion.h"
#include "util/Guid.h"
#include "util/Association.h"
#include "util/standardout.h"
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <stdexcept>

template<class T> static inline T& physicsField(void* p,unsigned offset) {
    return *reinterpret_cast<T*>(static_cast<char*>(p)+offset);
}
// Actual native Association<Instance>::TItem<TimeStamp> RTTI and8B allocation.
struct TimeStamp { unsigned value; TimeStamp():value(0) {} };
namespace RBX {
class Instance;
class NativePhysicsSettings {
public:
    static NativePhysicsSettings& singleton(); //0049e890
    bool printErrors() const { return physicsField<bool>(const_cast<NativePhysicsSettings*>(this),0x130); }
};
class NativePhysicsMotor {
public:
    void setCurrentAngle(float); //005e5da0 ret4
};
class NativePhysicsAssembly {
public:
    int getNumMotors(); //005e62d0
    NativePhysicsMotor* getMotor(unsigned); //005e6400 ret4
};
class NativePhysicsClump {
public:
    bool getAnchored() const; //005e60e0
};
class NativePhysicsPrimitive {
public:
    NativePhysicsAssembly* getAssembly() const; //005e7570
};
typedef PartInstance NativePhysicsPart;
// 004c7530: cdecl hidden shared_ptr result, one enable_shared_from_this pointer.
// Native helper uses static/polymorphic downcast, no runtime dynamic cast.
boost::shared_ptr<NativePhysicsPart> __cdecl recoverPhysicsPart(boost::enable_shared_from_this<Instance>*);
namespace Network {
class NativePhysicsReplicator {
public:
    bool deserializeInstanceRef(RakNet::BitStream&,Instance*&,Guid::Data&); //004a8b60 ret12
};
class IPhysicsSender {
public:
    static void readPosition(RakNet::BitStream&,G3D::Vector3&); //004ca5c0 cdecl
};
RakNet::BitStream& operator>>(RakNet::BitStream&,unsigned char&); //004a6380 cdecl
float decodePhysicsAngle(unsigned char); //005dda30 cdecl
class DirectPhysicsReceiver {
public:
    void receivePacket(RakNet::BitStream&,unsigned);
};
}}
typedef char NativeGuidDataSize[sizeof(RBX::Guid::Data)==8?1:-1];
typedef char NativeQuaternionSize[sizeof(RBX::Quaternion)==16?1:-1];
typedef char NativeSharedPartSize[sizeof(boost::shared_ptr<RBX::NativePhysicsPart>)==8?1:-1];
typedef char NativeCoordinateFrameSize[sizeof(G3D::CoordinateFrame)==48?1:-1];
typedef char NativeAssociationSize[sizeof(RBX::Association<RBX::Instance>)==24?1:-1];

void RBX::Network::DirectPhysicsReceiver::receivePacket(RakNet::BitStream& stream,unsigned timestamp) {
    while(true) {
        boost::shared_ptr<NativePhysicsPart> part;
        Instance* instance;
        Guid::Data id;
        if(physicsField<NativePhysicsReplicator*>(this,4)->deserializeInstanceRef(stream,instance,id)) {
            if(!instance) return;
            part=recoverPhysicsPart(static_cast<boost::enable_shared_from_this<Instance>*>(instance));
        } else if(NativePhysicsSettings::singleton().printErrors())
            StandardOut::singleton()->print(MESSAGE_WARNING,"Physics-in of unidentified %s",id.readableString(4).c_str());
        if(part) {
            if(!NativePhysicsPart::nonNullInWorkspace(part)) {
                if(NativePhysicsSettings::singleton().printErrors())
                    StandardOut::singleton()->print(MESSAGE_INFO,"Physics-in of part not in workspace %s",id.readableString(4).c_str());
                part.reset();
            } else if(!reinterpret_cast<NativePhysicsPrimitive*>(part->getPrimitive())->getAssembly()) {
                if(NativePhysicsSettings::singleton().printErrors())
                    StandardOut::singleton()->print(MESSAGE_INFO,"Physics-in of primitive with no assembly %s",id.readableString(4).c_str());
                part.reset();
            } else if(reinterpret_cast<NativePhysicsClump*>(part->getPrimitive()->getClump())->getAnchored()) {
                if(NativePhysicsSettings::singleton().printErrors())
                    StandardOut::singleton()->print(MESSAGE_INFO,"Physics-in of anchored primitive %s",id.readableString(4).c_str());
                part.reset();
            } else {
                unsigned& partTime=part->association().get<TimeStamp>().value;
                if(partTime>timestamp) {
                    if(NativePhysicsSettings::singleton().printErrors())
                        StandardOut::singleton()->print(MESSAGE_INFO,"Physics-in old packet");
                    part.reset();
                } else partTime=timestamp;
            }
        }
        G3D::CoordinateFrame frame;
        IPhysicsSender::readPosition(stream,frame.translation);
        Quaternion rotation;
        if(!stream.ReadNormQuat(rotation.w,rotation.x,rotation.y,rotation.z))
            throw std::runtime_error("Failed to read Quaternion");
        rotation.toRotationMatrix(frame.rotation);
        if(part && !reinterpret_cast<NativePhysicsClump*>(part->getPrimitive()->getClump())->getAnchored()) part->setCoordinateFrame(frame);
        unsigned char motorCount;
        stream>>motorCount;
        if(motorCount>50 && NativePhysicsSettings::singleton().printErrors())
            StandardOut::singleton()->print(MESSAGE_WARNING,"Physics-in of %s has %d motors",id.readableString(4).c_str(),motorCount);
        int count=motorCount;
        NativePhysicsAssembly* assembly;
        if(part && (assembly=reinterpret_cast<NativePhysicsPrimitive*>(part->getPrimitive())->getAssembly()) && assembly->getNumMotors()==count) {
            for(int i=0;i<count;++i) {
                unsigned char angle;
                stream>>angle;
                assembly->getMotor(i)->setCurrentAngle(decodePhysicsAngle(angle));
            }
        } else {
            if(count>0) do {
                unsigned char discard;
                stream>>discard;
            } while(--count);
        }
    }
}

typedef char PartSize[sizeof(RBX::PartInstance)==0x404?1:-1];
void* proofPrimitive(RBX::PartInstance*x){return x->getPrimitive();}
void* proofAssociation(RBX::PartInstance*x){return &x->association();}
void* proofWeakOwner(RBX::Instance*x){return static_cast<boost::enable_shared_from_this<RBX::Instance>*>(x);}
