// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client roc_espclaude_2389c4f105995135.cpp

// Candidate translation unit (score above; library headers required).
#include "util/RunStateOwner.h"
#include "reflection/signal.h"
#include <string>
namespace RBX {
namespace Reflection {
template <class Signature>
class __declspec(novtable) SignalDescImpl<3, Signature> : public TSignalDesc<Signature>
{
protected:
	class GenericSlotAdapter
	{
	public:
		GenericSlotAdapter(GenericSlotWrapper* wrapper) : wrapper(wrapper) {}
		void operator()(
			typename boost::function_traits<Signature>::arg1_type arg1,
			typename boost::function_traits<Signature>::arg2_type arg2,
			typename boost::function_traits<Signature>::arg3_type arg3
		) const
		{
			std::vector<boost::any> arguments(3);
			arguments[0] = arg1;
			arguments[1] = arg2;
			arguments[2] = arg3;
			wrapper->execute(arguments);
		}
	private:
		boost::shared_ptr<GenericSlotWrapper> wrapper;
	};
	virtual boost::signals::connection connectGeneric(
		SignalInstance* instance,
		GenericSlotWrapper* wrapper,
		boost::signals::connect_position position
	) const
	{
		return static_cast<typename TSignalDesc<Signature>::TSignalInstance*>(instance)->connect(
			GenericSlotAdapter(wrapper),
			position
		);
	}
	virtual SignalInstance* newSignalInstance(SignalSource& source) const
	{
		return new typename TSignalDesc<Signature>::TSignalInstance(&source, *this);
	}
	SignalDescImpl(ClassDescriptor& classDescriptor, const char* name) : TSignalDesc<Signature>(classDescriptor, name)
	{
	}
};
template <class Class, class Signature>
class SignalDesc3 : public SignalDescImpl<boost::function_traits<Signature>::arity, Signature>
{
public:
	SignalDesc3(const char* name, const char* arg1name, const char* arg2name, const char* arg3name)
		: SignalDescImpl<boost::function_traits<Signature>::arity, Signature>(Class::classDescriptor(), name)
	{
		SignatureDescriptor::Item arg1 = {
			&Name::declare(arg1name, -1),
			&Type::singleton<typename boost::function_traits<Signature>::arg1_type>(),
			Value()
		};
		this->signature.arguments.push_back(arg1);
		SignatureDescriptor::Item arg2 = {
			&Name::declare(arg2name, -1),
			&Type::singleton<typename boost::function_traits<Signature>::arg2_type>(),
			Value()
		};
		this->signature.arguments.push_back(arg2);
		SignatureDescriptor::Item arg3 = {
			&Name::declare(arg3name, -1),
			&Type::singleton<typename boost::function_traits<Signature>::arg3_type>(),
			Value()
		};
		this->signature.arguments.push_back(arg3);
	}
};
template class SignalDesc3<Instance, void(std::string, int, std::string)>;
}
}
