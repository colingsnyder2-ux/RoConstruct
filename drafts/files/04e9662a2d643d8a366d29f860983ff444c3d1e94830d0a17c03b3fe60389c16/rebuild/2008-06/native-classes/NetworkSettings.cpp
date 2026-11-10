// 2008-06 native RBX::NetworkSettings (inactive); evidence in native-headers/Network/NetworkSettings.h.
// Verified by tests/record_native_services.py (unit profile: document-swap flags).
#include "Network/NetworkSettings.h"
#include "reflection/enumconverter.h"
#include <G3D/format.h>
#include <stdexcept>

namespace RBX
{
	const char sNetworkSettings[] = "NetworkSettings"; // 00823ec0

	// Template members the shared headers only declare.
	template<class C, class D, const char* N>
	FactoryProduct<C, D, N>::FactoryProduct() : D() {}

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::className() { return Name::declare<N>(); }

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::getClassName() const { return className(); }

	template<class C, class D, const char* N>
	DescribedCreatable<C, D, N>::DescribedCreatable()
		: Reflection::Described<C, N, FactoryProduct<C, D, N> >() {}

	template<typename Class, const char* ClassName>
	GlobalSettingsItem<Class, ClassName>* GlobalSettingsItem<Class, ClassName>::sing = NULL; // 009706d0

	// 004aa8a0: the 2008 item names itself after its class and refuses a second instance.
	template<typename Class, const char* ClassName>
	GlobalSettingsItem<Class, ClassName>::GlobalSettingsItem()
	{
		setName(ClassName);
		if (sing)
			throw std::runtime_error(G3D::format("singleton %s already exists", ClassName));
		sing = this;
	}

	// 004a9d00 (deleting 004aa880).
	template<typename Class, const char* ClassName>
	GlobalSettingsItem<Class, ClassName>::~GlobalSettingsItem()
	{
		sing = NULL;
	}

	Reflection::EnumDesc<NetworkSettings::PhysicsSendMethod>::EnumDesc()     // 004aa150
		: EnumDescriptor("PhysicsSendMethod", typeid(NetworkSettings::PhysicsSendMethod))
	{
		addPair(NetworkSettings::ErrorComputation, "ErrorComputation");
		addPair(NetworkSettings::RoundRobin, "RoundRobin");
	}

	Reflection::EnumDesc<NetworkSettings::PhysicsReceiveMethod>::EnumDesc()  // 004aa2c0
		: EnumDescriptor("PhysicsReceiveMethod", typeid(NetworkSettings::PhysicsReceiveMethod))
	{
		addPair(NetworkSettings::Direct, "Direct");
		addPair(NetworkSettings::Interpolation, "Interpolation");
	}

	// Dynamic initializers 007f1df0..007f2140, in this order (Functionality 5 = STANDARD).
	static Reflection::BoundProp<bool, 1> prop_PrintInstances("PrintInstances", "Diagnostics", &NetworkSettings::printInstances, Reflection::PropertyDescriptor::STANDARD);
	static Reflection::BoundProp<bool, 1> prop_PrintProperties("PrintProperties", "Diagnostics", &NetworkSettings::printProperties, Reflection::PropertyDescriptor::STANDARD);
	static Reflection::BoundProp<bool, 1> prop_PrintPacketBuffer("PrintPacketBuffer", "Diagnostics", &NetworkSettings::printPacketBuffer, Reflection::PropertyDescriptor::STANDARD);
	static Reflection::BoundProp<bool, 1> prop_PrintPhysicsErrors("PrintPhysicsErrors", "Diagnostics", &NetworkSettings::printPhysicsErrors, Reflection::PropertyDescriptor::STANDARD);
	static Reflection::BoundProp<bool, 1> prop_Test1("Test1", "Diagnostics", &NetworkSettings::test1, Reflection::PropertyDescriptor::STANDARD);
	static Reflection::BoundProp<bool, 1> prop_Test2("Test2", "Diagnostics", &NetworkSettings::test2, Reflection::PropertyDescriptor::STANDARD);
	static Reflection::BoundProp<bool, 1> prop_Test3("Test3", "Diagnostics", &NetworkSettings::test3, Reflection::PropertyDescriptor::STANDARD);
	static Reflection::BoundProp<bool, 1> prop_Test4("Test4", "Diagnostics", &NetworkSettings::test4, Reflection::PropertyDescriptor::STANDARD);
	static Reflection::BoundProp<int, 1> prop_MaxSendBPS("MaxSendBPS", "Simulator", &NetworkSettings::maxSendBPS, Reflection::PropertyDescriptor::STANDARD);
	static Reflection::BoundProp<int, 1> prop_MinExtraPing("MinExtraPing", "Simulator", &NetworkSettings::minExtraPing, Reflection::PropertyDescriptor::STANDARD);
	static Reflection::BoundProp<int, 1> prop_ExtraPingVariance("ExtraPingVariance", "Simulator", &NetworkSettings::extraPingVariance, Reflection::PropertyDescriptor::STANDARD);
	static Reflection::EnumPropDescriptor<NetworkSettings, NetworkSettings::PhysicsSendMethod> prop_PhysicsSend("PhysicsSend", "Replication", &NetworkSettings::getPhysicsSendMethod, &NetworkSettings::setPhysicsSendMethod, Reflection::PropertyDescriptor::STANDARD);
	static Reflection::EnumPropDescriptor<NetworkSettings, NetworkSettings::PhysicsReceiveMethod> prop_PhysicsReceive("PhysicsReceive", "Replication", &NetworkSettings::getPhysicsReceiveMethod, &NetworkSettings::setPhysicsReceiveMethod, Reflection::PropertyDescriptor::STANDARD);
	static Reflection::BoundProp<int, 1> prop_PhysicsReplicationUpdateRate("PhysicsReplicationUpdateRate", "Replication", &NetworkSettings::physicsReplicationUpdateRate, Reflection::PropertyDescriptor::STANDARD);
	static Reflection::BoundProp<int, 1> prop_MaxSendBuffer("MaxSendBuffer", "Replication", &NetworkSettings::maxSendBuffer, Reflection::PropertyDescriptor::STANDARD);
	static Reflection::BoundProp<int, 1> prop_PhysicsMtuAdjust("PhysicsMtuAdjust", "Replication", &NetworkSettings::physicsMtuAdjust, Reflection::PropertyDescriptor::STANDARD);
	static Reflection::BoundProp<int, 1> prop_ReplicationMtuAdjust("ReplicationMtuAdjust", "Replication", &NetworkSettings::replicationMtuAdjust, Reflection::PropertyDescriptor::STANDARD);
	static Reflection::BoundProp<float, 1> prop_SendRate("SendRate", "Replication", &NetworkSettings::sendRate, Reflection::PropertyDescriptor::STANDARD);

	NetworkSettings::NetworkSettings()
		: printPhysicsErrors(false),
		  printInstances(false),
		  printProperties(false),
		  printPacketBuffer(false),
		  physicsSendMethod(ErrorComputation),
		  physicsReceiveMethod(Interpolation),
		  physicsReplicationUpdateRate(3000),
		  test1(false),
		  test2(false),
		  test3(false),
		  test4(false),
		  physicsMtuAdjust(-80),
		  replicationMtuAdjust(-200),
		  maxSendBuffer(1),
		  sendRate(90.0f),
		  maxSendBPS(0),
		  minExtraPing(0),
		  extraPingVariance(0)
	{
		setName("Network");
	}

	void NetworkSettings::setPhysicsSendMethod(const PhysicsSendMethod& value)
	{
		if (value != physicsSendMethod)
		{
			physicsSendMethod = value;
			raisePropertyChanged(prop_PhysicsSend);
		}
	}

	void NetworkSettings::setPhysicsReceiveMethod(const PhysicsReceiveMethod& value)
	{
		if (value != physicsReceiveMethod)
		{
			physicsReceiveMethod = value;
			raisePropertyChanged(prop_PhysicsReceive);
		}
	}
}
