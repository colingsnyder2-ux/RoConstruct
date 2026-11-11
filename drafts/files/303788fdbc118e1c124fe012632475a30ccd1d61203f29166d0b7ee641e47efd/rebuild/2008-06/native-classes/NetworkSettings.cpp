// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 native RBX::NetworkSettings (inactive); evidence in native-headers/Network/NetworkSettings.h.
// Verified by tests/record_native_services.py (unit profile: document-swap flags).
// >>> native-status (generated) -- do not edit >>>
// NetworkSettings | 2008-06 | 3 byte-exact, inactive (not link-selected)
// 3/3 mapped addresses byte-exact | 0 unproved | no mapped strings | by king_originala (mixed 2)
// <<< native-status | src 95ecf722 | roc native-status --write
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

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class RBX::AbstractFactoryProduct<RBX::Instance>;
template class RBX::Reflection::TypedPropertyDescriptor<enum RBX::NetworkSettings::PhysicsReceiveMethod>;
template class RBX::Reflection::TypedPropertyDescriptor<enum RBX::NetworkSettings::PhysicsSendMethod>;
template class boost::_bi::value<int>;
template class boost::enable_shared_from_this<RBX::Instance>;
template class boost::function2<bool,boost::signals::detail::stored_group,boost::signals::detail::stored_group,std::allocator<boost::function_base> >;
template class boost::mpl::int_<10>;
template class boost::mpl::int_<11>;
template class boost::mpl::int_<12>;
template class boost::mpl::int_<1>;
template class boost::mpl::int_<2>;
template class boost::mpl::int_<3>;
template class boost::mpl::int_<4>;
template class boost::mpl::int_<5>;
template class boost::mpl::int_<6>;
template class boost::mpl::int_<7>;
template class boost::mpl::int_<8>;
template class boost::mpl::int_<9>;
template class boost::mpl::integral_c<unsigned int,1>;
template class boost::mpl::integral_c<unsigned int,8>;
template class std::_Container_base_aux_alloc_real<std::allocator<RBX::Name const *> >;
template class std::_Container_base_aux_alloc_real<std::allocator<RBX::Reflection::ClassDescriptor *> >;
template class std::_Container_base_aux_alloc_real<std::allocator<RBX::Reflection::EnumDescriptor::Item const *> >;
template class std::_Container_base_aux_alloc_real<std::allocator<RBX::Reflection::FunctionDescriptor *> >;
template class std::_Container_base_aux_alloc_real<std::allocator<RBX::Reflection::MemberDescriptorContainer<RBX::Reflection::FunctionDescriptor> *> >;
template class std::_Container_base_aux_alloc_real<std::allocator<RBX::Reflection::MemberDescriptorContainer<RBX::Reflection::PropertyDescriptor> *> >;
template class std::_Container_base_aux_alloc_real<std::allocator<RBX::Reflection::MemberDescriptorContainer<RBX::Reflection::SignalDescriptor> *> >;
template class std::_Container_base_aux_alloc_real<std::allocator<RBX::Reflection::PropertyDescriptor *> >;
template class std::_Container_base_aux_alloc_real<std::allocator<RBX::Reflection::SignalDescriptor *> >;
template class std::_Container_base_aux_alloc_real<std::allocator<enum RBX::NetworkSettings::PhysicsReceiveMethod> >;
template class std::_Container_base_aux_alloc_real<std::allocator<enum RBX::NetworkSettings::PhysicsSendMethod> >;
template class std::_Container_base_aux_alloc_real<std::allocator<std::basic_string<char,std::char_traits<char>,std::allocator<char> > > >;
template class std::_Container_base_aux_alloc_real<std::allocator<std::pair<RBX::Name const * const,enum RBX::NetworkSettings::PhysicsReceiveMethod> > >;
template class std::_Container_base_aux_alloc_real<std::allocator<std::pair<RBX::Name const * const,enum RBX::NetworkSettings::PhysicsSendMethod> > >;
template class std::_Container_base_aux_alloc_real<std::allocator<unsigned int> >;
template class std::_Tmap_traits<RBX::Name const *,enum RBX::NetworkSettings::PhysicsReceiveMethod,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,enum RBX::NetworkSettings::PhysicsReceiveMethod> >,0>;
template class std::_Tmap_traits<RBX::Name const *,enum RBX::NetworkSettings::PhysicsSendMethod,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,enum RBX::NetworkSettings::PhysicsSendMethod> >,0>;
template class std::_Tree<std::_Tmap_traits<RBX::Name const *,enum RBX::NetworkSettings::PhysicsReceiveMethod,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,enum RBX::NetworkSettings::PhysicsReceiveMethod> >,0> >;
template class std::_Tree<std::_Tmap_traits<RBX::Name const *,enum RBX::NetworkSettings::PhysicsSendMethod,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,enum RBX::NetworkSettings::PhysicsSendMethod> >,0> >;
template class std::_Vector_const_iterator<RBX::Name const *,std::allocator<RBX::Name const *> >;
template class std::_Vector_const_iterator<RBX::Reflection::EnumDescriptor::Item const *,std::allocator<RBX::Reflection::EnumDescriptor::Item const *> >;
template class std::_Vector_const_iterator<enum RBX::NetworkSettings::PhysicsReceiveMethod,std::allocator<enum RBX::NetworkSettings::PhysicsReceiveMethod> >;
template class std::_Vector_const_iterator<enum RBX::NetworkSettings::PhysicsSendMethod,std::allocator<enum RBX::NetworkSettings::PhysicsSendMethod> >;
template class std::_Vector_const_iterator<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,std::allocator<std::basic_string<char,std::char_traits<char>,std::allocator<char> > > >;
template class std::_Vector_const_iterator<unsigned int,std::allocator<unsigned int> >;
template class std::_Vector_iterator<RBX::Name const *,std::allocator<RBX::Name const *> >;
template class std::_Vector_iterator<RBX::Reflection::EnumDescriptor::Item const *,std::allocator<RBX::Reflection::EnumDescriptor::Item const *> >;
template class std::_Vector_iterator<enum RBX::NetworkSettings::PhysicsReceiveMethod,std::allocator<enum RBX::NetworkSettings::PhysicsReceiveMethod> >;
template class std::_Vector_iterator<enum RBX::NetworkSettings::PhysicsSendMethod,std::allocator<enum RBX::NetworkSettings::PhysicsSendMethod> >;
template class std::_Vector_iterator<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,std::allocator<std::basic_string<char,std::char_traits<char>,std::allocator<char> > > >;
template class std::_Vector_iterator<unsigned int,std::allocator<unsigned int> >;
template class std::_Vector_val<RBX::Reflection::ClassDescriptor *,std::allocator<RBX::Reflection::ClassDescriptor *> >;
template class std::_Vector_val<RBX::Reflection::FunctionDescriptor *,std::allocator<RBX::Reflection::FunctionDescriptor *> >;
template class std::_Vector_val<RBX::Reflection::MemberDescriptorContainer<RBX::Reflection::FunctionDescriptor> *,std::allocator<RBX::Reflection::MemberDescriptorContainer<RBX::Reflection::FunctionDescriptor> *> >;
template class std::_Vector_val<RBX::Reflection::MemberDescriptorContainer<RBX::Reflection::PropertyDescriptor> *,std::allocator<RBX::Reflection::MemberDescriptorContainer<RBX::Reflection::PropertyDescriptor> *> >;
template class std::_Vector_val<RBX::Reflection::MemberDescriptorContainer<RBX::Reflection::SignalDescriptor> *,std::allocator<RBX::Reflection::MemberDescriptorContainer<RBX::Reflection::SignalDescriptor> *> >;
template class std::_Vector_val<RBX::Reflection::PropertyDescriptor *,std::allocator<RBX::Reflection::PropertyDescriptor *> >;
template class std::_Vector_val<RBX::Reflection::SignalDescriptor *,std::allocator<RBX::Reflection::SignalDescriptor *> >;
template class std::allocator<std::_Tree_nod<std::_Tmap_traits<RBX::Name const *,enum RBX::NetworkSettings::PhysicsReceiveMethod,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,enum RBX::NetworkSettings::PhysicsReceiveMethod> >,0> >::_Node *>;
template class std::allocator<std::_Tree_nod<std::_Tmap_traits<RBX::Name const *,enum RBX::NetworkSettings::PhysicsSendMethod,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,enum RBX::NetworkSettings::PhysicsSendMethod> >,0> >::_Node *>;
template class std::allocator<std::pair<RBX::Name const * const,enum RBX::NetworkSettings::PhysicsReceiveMethod> >;
template class std::allocator<std::pair<RBX::Name const * const,enum RBX::NetworkSettings::PhysicsSendMethod> >;
template class std::deque<char,std::allocator<char> >;
template class std::vector<RBX::Name const *,std::allocator<RBX::Name const *> >;
template class std::vector<RBX::Reflection::ClassDescriptor *,std::allocator<RBX::Reflection::ClassDescriptor *> >;
template class std::vector<RBX::Reflection::EnumDescriptor::Item const *,std::allocator<RBX::Reflection::EnumDescriptor::Item const *> >;
template class std::vector<RBX::Reflection::FunctionDescriptor *,std::allocator<RBX::Reflection::FunctionDescriptor *> >;
template class std::vector<RBX::Reflection::MemberDescriptorContainer<RBX::Reflection::FunctionDescriptor> *,std::allocator<RBX::Reflection::MemberDescriptorContainer<RBX::Reflection::FunctionDescriptor> *> >;
template class std::vector<RBX::Reflection::MemberDescriptorContainer<RBX::Reflection::PropertyDescriptor> *,std::allocator<RBX::Reflection::MemberDescriptorContainer<RBX::Reflection::PropertyDescriptor> *> >;
template class std::vector<RBX::Reflection::MemberDescriptorContainer<RBX::Reflection::SignalDescriptor> *,std::allocator<RBX::Reflection::MemberDescriptorContainer<RBX::Reflection::SignalDescriptor> *> >;
template class std::vector<RBX::Reflection::PropertyDescriptor *,std::allocator<RBX::Reflection::PropertyDescriptor *> >;
template class std::vector<RBX::Reflection::SignalDescriptor *,std::allocator<RBX::Reflection::SignalDescriptor *> >;
template class std::vector<enum RBX::NetworkSettings::PhysicsReceiveMethod,std::allocator<enum RBX::NetworkSettings::PhysicsReceiveMethod> >;
template class std::vector<enum RBX::NetworkSettings::PhysicsSendMethod,std::allocator<enum RBX::NetworkSettings::PhysicsSendMethod> >;
template class std::vector<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,std::allocator<std::basic_string<char,std::char_traits<char>,std::allocator<char> > > >;
template class std::vector<unsigned int,std::allocator<unsigned int> >;

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class std::_Container_base_aux_alloc_real<std::allocator<char> >;
template class std::_Deque_const_iterator<char,std::allocator<char>,0>;
template class std::_Deque_iterator<char,std::allocator<char>,0>;
template class std::_Revranit<std::_Deque_const_iterator<char,std::allocator<char>,1>,std::iterator<std::random_access_iterator_tag,char,int,char const *,char const &> >;
template class std::_Revranit<std::_Deque_iterator<char,std::allocator<char>,1>,std::iterator<std::random_access_iterator_tag,char,int,char *,char &> >;
template class std::_Revranit<std::_Vector_const_iterator<RBX::Name const *,std::allocator<RBX::Name const *> >,std::iterator<std::random_access_iterator_tag,RBX::Name const *,int,RBX::Name const * const *,RBX::Name const * const &> >;
template class std::_Revranit<std::_Vector_const_iterator<RBX::Reflection::ClassDescriptor *,std::allocator<RBX::Reflection::ClassDescriptor *> >,std::iterator<std::random_access_iterator_tag,RBX::Reflection::ClassDescriptor *,int,RBX::Reflection::ClassDescriptor * const *,RBX::Reflection::ClassDescriptor * const &> >;
template class std::_Revranit<std::_Vector_const_iterator<RBX::Reflection::EnumDescriptor::Item const *,std::allocator<RBX::Reflection::EnumDescriptor::Item const *> >,std::iterator<std::random_access_iterator_tag,RBX::Reflection::EnumDescriptor::Item const *,int,RBX::Reflection::EnumDescriptor::Item const * const *,RBX::Reflection::EnumDescriptor::Item const * const &> >;
template class std::_Revranit<std::_Vector_const_iterator<RBX::Reflection::FunctionDescriptor *,std::allocator<RBX::Reflection::FunctionDescriptor *> >,std::iterator<std::random_access_iterator_tag,RBX::Reflection::FunctionDescriptor *,int,RBX::Reflection::FunctionDescriptor * const *,RBX::Reflection::FunctionDescriptor * const &> >;
template class std::_Revranit<std::_Vector_const_iterator<RBX::Reflection::MemberDescriptorContainer<RBX::Reflection::FunctionDescriptor> *,std::allocator<RBX::Reflection::MemberDescriptorContainer<RBX::Reflection::FunctionDescriptor> *> >,std::iterator<std::random_access_iterator_tag,RBX::Reflection::MemberDescriptorContainer<RBX::Reflection::FunctionDescriptor> *,int,RBX::Reflection::MemberDescriptorContainer<RBX::Reflection::FunctionDescriptor> * const *,RBX::Reflection::MemberDescriptorContainer<RBX::Reflection::FunctionDescriptor> * const &> >;
template class std::_Revranit<std::_Vector_const_iterator<RBX::Reflection::MemberDescriptorContainer<RBX::Reflection::PropertyDescriptor> *,std::allocator<RBX::Reflection::MemberDescriptorContainer<RBX::Reflection::PropertyDescriptor> *> >,std::iterator<std::random_access_iterator_tag,RBX::Reflection::MemberDescriptorContainer<RBX::Reflection::PropertyDescriptor> *,int,RBX::Reflection::MemberDescriptorContainer<RBX::Reflection::PropertyDescriptor> * const *,RBX::Reflection::MemberDescriptorContainer<RBX::Reflection::PropertyDescriptor> * const &> >;
template class std::_Revranit<std::_Vector_const_iterator<RBX::Reflection::MemberDescriptorContainer<RBX::Reflection::SignalDescriptor> *,std::allocator<RBX::Reflection::MemberDescriptorContainer<RBX::Reflection::SignalDescriptor> *> >,std::iterator<std::random_access_iterator_tag,RBX::Reflection::MemberDescriptorContainer<RBX::Reflection::SignalDescriptor> *,int,RBX::Reflection::MemberDescriptorContainer<RBX::Reflection::SignalDescriptor> * const *,RBX::Reflection::MemberDescriptorContainer<RBX::Reflection::SignalDescriptor> * const &> >;
template class std::_Revranit<std::_Vector_const_iterator<RBX::Reflection::PropertyDescriptor *,std::allocator<RBX::Reflection::PropertyDescriptor *> >,std::iterator<std::random_access_iterator_tag,RBX::Reflection::PropertyDescriptor *,int,RBX::Reflection::PropertyDescriptor * const *,RBX::Reflection::PropertyDescriptor * const &> >;
template class std::_Revranit<std::_Vector_const_iterator<RBX::Reflection::SignalDescriptor *,std::allocator<RBX::Reflection::SignalDescriptor *> >,std::iterator<std::random_access_iterator_tag,RBX::Reflection::SignalDescriptor *,int,RBX::Reflection::SignalDescriptor * const *,RBX::Reflection::SignalDescriptor * const &> >;
template class std::_Revranit<std::_Vector_const_iterator<enum RBX::NetworkSettings::PhysicsReceiveMethod,std::allocator<enum RBX::NetworkSettings::PhysicsReceiveMethod> >,std::iterator<std::random_access_iterator_tag,enum RBX::NetworkSettings::PhysicsReceiveMethod,int,enum RBX::NetworkSettings::PhysicsReceiveMethod const *,enum RBX::NetworkSettings::PhysicsReceiveMethod const &> >;
template class std::_Revranit<std::_Vector_const_iterator<enum RBX::NetworkSettings::PhysicsSendMethod,std::allocator<enum RBX::NetworkSettings::PhysicsSendMethod> >,std::iterator<std::random_access_iterator_tag,enum RBX::NetworkSettings::PhysicsSendMethod,int,enum RBX::NetworkSettings::PhysicsSendMethod const *,enum RBX::NetworkSettings::PhysicsSendMethod const &> >;
template class std::_Revranit<std::_Vector_const_iterator<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,std::allocator<std::basic_string<char,std::char_traits<char>,std::allocator<char> > > >,std::iterator<std::random_access_iterator_tag,std::basic_string<char,std::char_traits<char>,std::allocator<char> >,int,std::basic_string<char,std::char_traits<char>,std::allocator<char> > const *,std::basic_string<char,std::char_traits<char>,std::allocator<char> > const &> >;
template class std::_Revranit<std::_Vector_const_iterator<unsigned int,std::allocator<unsigned int> >,std::iterator<std::random_access_iterator_tag,unsigned int,int,unsigned int const *,unsigned int const &> >;
template class std::_Revranit<std::_Vector_iterator<RBX::Name const *,std::allocator<RBX::Name const *> >,std::iterator<std::random_access_iterator_tag,RBX::Name const *,int,RBX::Name const * *,RBX::Name const * &> >;
template class std::_Revranit<std::_Vector_iterator<RBX::Reflection::ClassDescriptor *,std::allocator<RBX::Reflection::ClassDescriptor *> >,std::iterator<std::random_access_iterator_tag,RBX::Reflection::ClassDescriptor *,int,RBX::Reflection::ClassDescriptor * *,RBX::Reflection::ClassDescriptor * &> >;
template class std::_Revranit<std::_Vector_iterator<RBX::Reflection::EnumDescriptor::Item const *,std::allocator<RBX::Reflection::EnumDescriptor::Item const *> >,std::iterator<std::random_access_iterator_tag,RBX::Reflection::EnumDescriptor::Item const *,int,RBX::Reflection::EnumDescriptor::Item const * *,RBX::Reflection::EnumDescriptor::Item const * &> >;
template class std::_Revranit<std::_Vector_iterator<RBX::Reflection::FunctionDescriptor *,std::allocator<RBX::Reflection::FunctionDescriptor *> >,std::iterator<std::random_access_iterator_tag,RBX::Reflection::FunctionDescriptor *,int,RBX::Reflection::FunctionDescriptor * *,RBX::Reflection::FunctionDescriptor * &> >;
template class std::_Revranit<std::_Vector_iterator<RBX::Reflection::MemberDescriptorContainer<RBX::Reflection::FunctionDescriptor> *,std::allocator<RBX::Reflection::MemberDescriptorContainer<RBX::Reflection::FunctionDescriptor> *> >,std::iterator<std::random_access_iterator_tag,RBX::Reflection::MemberDescriptorContainer<RBX::Reflection::FunctionDescriptor> *,int,RBX::Reflection::MemberDescriptorContainer<RBX::Reflection::FunctionDescriptor> * *,RBX::Reflection::MemberDescriptorContainer<RBX::Reflection::FunctionDescriptor> * &> >;
template class std::_Revranit<std::_Vector_iterator<RBX::Reflection::MemberDescriptorContainer<RBX::Reflection::PropertyDescriptor> *,std::allocator<RBX::Reflection::MemberDescriptorContainer<RBX::Reflection::PropertyDescriptor> *> >,std::iterator<std::random_access_iterator_tag,RBX::Reflection::MemberDescriptorContainer<RBX::Reflection::PropertyDescriptor> *,int,RBX::Reflection::MemberDescriptorContainer<RBX::Reflection::PropertyDescriptor> * *,RBX::Reflection::MemberDescriptorContainer<RBX::Reflection::PropertyDescriptor> * &> >;
template class std::_Revranit<std::_Vector_iterator<RBX::Reflection::MemberDescriptorContainer<RBX::Reflection::SignalDescriptor> *,std::allocator<RBX::Reflection::MemberDescriptorContainer<RBX::Reflection::SignalDescriptor> *> >,std::iterator<std::random_access_iterator_tag,RBX::Reflection::MemberDescriptorContainer<RBX::Reflection::SignalDescriptor> *,int,RBX::Reflection::MemberDescriptorContainer<RBX::Reflection::SignalDescriptor> * *,RBX::Reflection::MemberDescriptorContainer<RBX::Reflection::SignalDescriptor> * &> >;
template class std::_Revranit<std::_Vector_iterator<RBX::Reflection::PropertyDescriptor *,std::allocator<RBX::Reflection::PropertyDescriptor *> >,std::iterator<std::random_access_iterator_tag,RBX::Reflection::PropertyDescriptor *,int,RBX::Reflection::PropertyDescriptor * *,RBX::Reflection::PropertyDescriptor * &> >;
template class std::_Revranit<std::_Vector_iterator<RBX::Reflection::SignalDescriptor *,std::allocator<RBX::Reflection::SignalDescriptor *> >,std::iterator<std::random_access_iterator_tag,RBX::Reflection::SignalDescriptor *,int,RBX::Reflection::SignalDescriptor * *,RBX::Reflection::SignalDescriptor * &> >;
template class std::_Revranit<std::_Vector_iterator<enum RBX::NetworkSettings::PhysicsReceiveMethod,std::allocator<enum RBX::NetworkSettings::PhysicsReceiveMethod> >,std::iterator<std::random_access_iterator_tag,enum RBX::NetworkSettings::PhysicsReceiveMethod,int,enum RBX::NetworkSettings::PhysicsReceiveMethod *,enum RBX::NetworkSettings::PhysicsReceiveMethod &> >;
template class std::_Revranit<std::_Vector_iterator<enum RBX::NetworkSettings::PhysicsSendMethod,std::allocator<enum RBX::NetworkSettings::PhysicsSendMethod> >,std::iterator<std::random_access_iterator_tag,enum RBX::NetworkSettings::PhysicsSendMethod,int,enum RBX::NetworkSettings::PhysicsSendMethod *,enum RBX::NetworkSettings::PhysicsSendMethod &> >;
template class std::_Revranit<std::_Vector_iterator<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,std::allocator<std::basic_string<char,std::char_traits<char>,std::allocator<char> > > >,std::iterator<std::random_access_iterator_tag,std::basic_string<char,std::char_traits<char>,std::allocator<char> >,int,std::basic_string<char,std::char_traits<char>,std::allocator<char> > *,std::basic_string<char,std::char_traits<char>,std::allocator<char> > &> >;
template class std::_Revranit<std::_Vector_iterator<unsigned int,std::allocator<unsigned int> >,std::iterator<std::random_access_iterator_tag,unsigned int,int,unsigned int *,unsigned int &> >;
template class std::_Vector_iterator<RBX::Reflection::ClassDescriptor *,std::allocator<RBX::Reflection::ClassDescriptor *> >;
template class std::pair<std::_Tree<std::_Tmap_traits<RBX::Name const *,enum RBX::NetworkSettings::PhysicsReceiveMethod,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,enum RBX::NetworkSettings::PhysicsReceiveMethod> >,0> >::const_iterator,std::_Tree<std::_Tmap_traits<RBX::Name const *,enum RBX::NetworkSettings::PhysicsReceiveMethod,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,enum RBX::NetworkSettings::PhysicsReceiveMethod> >,0> >::const_iterator>;
template class std::pair<std::_Tree<std::_Tmap_traits<RBX::Name const *,enum RBX::NetworkSettings::PhysicsReceiveMethod,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,enum RBX::NetworkSettings::PhysicsReceiveMethod> >,0> >::iterator,std::_Tree<std::_Tmap_traits<RBX::Name const *,enum RBX::NetworkSettings::PhysicsReceiveMethod,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,enum RBX::NetworkSettings::PhysicsReceiveMethod> >,0> >::iterator>;
template class std::pair<std::_Tree<std::_Tmap_traits<RBX::Name const *,enum RBX::NetworkSettings::PhysicsSendMethod,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,enum RBX::NetworkSettings::PhysicsSendMethod> >,0> >::const_iterator,std::_Tree<std::_Tmap_traits<RBX::Name const *,enum RBX::NetworkSettings::PhysicsSendMethod,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,enum RBX::NetworkSettings::PhysicsSendMethod> >,0> >::const_iterator>;
template class std::pair<std::_Tree<std::_Tmap_traits<RBX::Name const *,enum RBX::NetworkSettings::PhysicsSendMethod,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,enum RBX::NetworkSettings::PhysicsSendMethod> >,0> >::iterator,std::_Tree<std::_Tmap_traits<RBX::Name const *,enum RBX::NetworkSettings::PhysicsSendMethod,std::less<RBX::Name const *>,std::allocator<std::pair<RBX::Name const * const,enum RBX::NetworkSettings::PhysicsSendMethod> >,0> >::iterator>;
template class std::reverse_iterator<std::_Deque_const_iterator<char,std::allocator<char>,1> >;
template class std::reverse_iterator<std::_Deque_iterator<char,std::allocator<char>,1> >;
template class std::reverse_iterator<std::_Vector_const_iterator<RBX::Name const *,std::allocator<RBX::Name const *> > >;
template class std::reverse_iterator<std::_Vector_const_iterator<RBX::Reflection::ClassDescriptor *,std::allocator<RBX::Reflection::ClassDescriptor *> > >;
template class std::reverse_iterator<std::_Vector_const_iterator<RBX::Reflection::EnumDescriptor::Item const *,std::allocator<RBX::Reflection::EnumDescriptor::Item const *> > >;
template class std::reverse_iterator<std::_Vector_const_iterator<RBX::Reflection::FunctionDescriptor *,std::allocator<RBX::Reflection::FunctionDescriptor *> > >;
template class std::reverse_iterator<std::_Vector_const_iterator<RBX::Reflection::MemberDescriptorContainer<RBX::Reflection::FunctionDescriptor> *,std::allocator<RBX::Reflection::MemberDescriptorContainer<RBX::Reflection::FunctionDescriptor> *> > >;
template class std::reverse_iterator<std::_Vector_const_iterator<RBX::Reflection::MemberDescriptorContainer<RBX::Reflection::PropertyDescriptor> *,std::allocator<RBX::Reflection::MemberDescriptorContainer<RBX::Reflection::PropertyDescriptor> *> > >;
template class std::reverse_iterator<std::_Vector_const_iterator<RBX::Reflection::MemberDescriptorContainer<RBX::Reflection::SignalDescriptor> *,std::allocator<RBX::Reflection::MemberDescriptorContainer<RBX::Reflection::SignalDescriptor> *> > >;
template class std::reverse_iterator<std::_Vector_const_iterator<RBX::Reflection::PropertyDescriptor *,std::allocator<RBX::Reflection::PropertyDescriptor *> > >;
template class std::reverse_iterator<std::_Vector_const_iterator<RBX::Reflection::SignalDescriptor *,std::allocator<RBX::Reflection::SignalDescriptor *> > >;
template class std::reverse_iterator<std::_Vector_const_iterator<enum RBX::NetworkSettings::PhysicsReceiveMethod,std::allocator<enum RBX::NetworkSettings::PhysicsReceiveMethod> > >;
template class std::reverse_iterator<std::_Vector_const_iterator<enum RBX::NetworkSettings::PhysicsSendMethod,std::allocator<enum RBX::NetworkSettings::PhysicsSendMethod> > >;
template class std::reverse_iterator<std::_Vector_const_iterator<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,std::allocator<std::basic_string<char,std::char_traits<char>,std::allocator<char> > > > >;
template class std::reverse_iterator<std::_Vector_const_iterator<unsigned int,std::allocator<unsigned int> > >;
template class std::reverse_iterator<std::_Vector_iterator<RBX::Name const *,std::allocator<RBX::Name const *> > >;
template class std::reverse_iterator<std::_Vector_iterator<RBX::Reflection::ClassDescriptor *,std::allocator<RBX::Reflection::ClassDescriptor *> > >;
template class std::reverse_iterator<std::_Vector_iterator<RBX::Reflection::EnumDescriptor::Item const *,std::allocator<RBX::Reflection::EnumDescriptor::Item const *> > >;
template class std::reverse_iterator<std::_Vector_iterator<RBX::Reflection::FunctionDescriptor *,std::allocator<RBX::Reflection::FunctionDescriptor *> > >;
template class std::reverse_iterator<std::_Vector_iterator<RBX::Reflection::MemberDescriptorContainer<RBX::Reflection::FunctionDescriptor> *,std::allocator<RBX::Reflection::MemberDescriptorContainer<RBX::Reflection::FunctionDescriptor> *> > >;
template class std::reverse_iterator<std::_Vector_iterator<RBX::Reflection::MemberDescriptorContainer<RBX::Reflection::PropertyDescriptor> *,std::allocator<RBX::Reflection::MemberDescriptorContainer<RBX::Reflection::PropertyDescriptor> *> > >;
template class std::reverse_iterator<std::_Vector_iterator<RBX::Reflection::MemberDescriptorContainer<RBX::Reflection::SignalDescriptor> *,std::allocator<RBX::Reflection::MemberDescriptorContainer<RBX::Reflection::SignalDescriptor> *> > >;
template class std::reverse_iterator<std::_Vector_iterator<RBX::Reflection::PropertyDescriptor *,std::allocator<RBX::Reflection::PropertyDescriptor *> > >;
template class std::reverse_iterator<std::_Vector_iterator<RBX::Reflection::SignalDescriptor *,std::allocator<RBX::Reflection::SignalDescriptor *> > >;
template class std::reverse_iterator<std::_Vector_iterator<enum RBX::NetworkSettings::PhysicsReceiveMethod,std::allocator<enum RBX::NetworkSettings::PhysicsReceiveMethod> > >;
template class std::reverse_iterator<std::_Vector_iterator<enum RBX::NetworkSettings::PhysicsSendMethod,std::allocator<enum RBX::NetworkSettings::PhysicsSendMethod> > >;
template class std::reverse_iterator<std::_Vector_iterator<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,std::allocator<std::basic_string<char,std::char_traits<char>,std::allocator<char> > > > >;
template class std::reverse_iterator<std::_Vector_iterator<unsigned int,std::allocator<unsigned int> > >;

// Name registrations emitted by this unit (bytes and sX relocation identity proven against the 2008-06 client).
template void RBX::Name::callDoDeclare<RBX::sNetworkSettings>();
