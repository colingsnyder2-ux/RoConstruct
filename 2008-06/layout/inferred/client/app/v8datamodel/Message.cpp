#include "v8datamodel/Message.h"
#include "util/Object.h"

namespace RBX
{
	template<typename Class, typename DerivedClass, const char* ClassName>
	boost::shared_ptr<Object> FactoryProduct<Class, DerivedClass, ClassName>::Creator::create() const
	{
		return Creatable<Instance>::create<Class>();
	}
}

template boost::shared_ptr<RBX::Message> RBX::Creatable<RBX::Instance>::create<RBX::Message>();
template boost::shared_ptr<RBX::Hint> RBX::Creatable<RBX::Instance>::create<RBX::Hint>();
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::Message, RBX::Instance, RBX::sMessage>::Creator::create() const;
