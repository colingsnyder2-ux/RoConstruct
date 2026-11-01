// from server: 100% by EspClaude
// from server: 100% by coldek
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_b33e8c7ee13b2d86.cpp

// Candidate translation unit (score above; library headers required).
#undef _RELEASEASSERT
#pragma include_alias("reflection/descriptor.h", "roc_sol_resume_native_descriptor_authheader_0acd23dba6f04ff5.cpp")
#pragma include_alias("reflection/enumconverter.h", "roc_sol_resume_native_enumconverter_authheader_297ae1c3351d4ab6.cpp")
#pragma include_alias("reflection/function.h", "roc_sol_resume_native_function_authheader_2f6c7dcf10adead1.cpp")
#pragma include_alias("reflection/member.h", "roc_sol_resume_native_member_authheader_459d66d9acfae4ab.cpp")
#pragma include_alias("reflection/object.h", "roc_sol_resume_native_object_authheader_cadaaebe20af2047.cpp")
#pragma include_alias("reflection/property.h", "roc_sol_resume_native_property_authheader_f11d2ca9d2ef5b41.cpp")
#pragma include_alias("reflection/reflection.h", "roc_sol_resume_native_reflection_authheader_a6fefc64bf3a6f9e.cpp")
#pragma include_alias("reflection/signal.h", "roc_sol_resume_native_signal_authheader_16e657153fe9fb6e.cpp")
#pragma include_alias("reflection/type.h", "roc_sol_resume_native_type_authheader_4aaa2bdeb1c2b6c3.cpp")
#include <boost/scoped_ptr.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/noncopyable.hpp>
#include <boost/signals.hpp>
#include <boost/type_traits.hpp>
#include <boost/any.hpp>
#include <map>
#include <vector>
#include "reflection/function.h"
#include "util/Utilities.h"
#include "util/standardout.h"
namespace RBX { namespace Reflection {} namespace Reflection_unused_ { using namespace Reflection; } }
#define Reflection Reflection_unused_
#include "reflection/signal.h"
#undef Reflection

namespace RBX
{
	namespace Reflection
	{
		typedef std::vector<boost::any> Arguments;

		class __declspec(novtable) GenericSlotWrapper
		{
		public:
			virtual ~GenericSlotWrapper();
			virtual void execute(const std::vector<boost::any>&) = 0;

		public:
			template<typename T>
			static GenericSlotWrapper* create(T slot)
			{
				return new TGenericSlotWrapper<T>(slot);
			}
		};

		template<typename T>
		class TGenericSlotWrapper : public GenericSlotWrapper
		{
			friend class GenericSlotWrapper;

		private:
			T slot;
		
		private:
		  	TGenericSlotWrapper(const T& s)
				: slot(s)
			{
			}

		public:
			virtual void execute(const Arguments& arguments)
			{
				try
				{
					slot(arguments);
				}
				catch (std::exception& e)
				{
					StandardOut::singleton()->print(MESSAGE_ERROR, "Exception caught in TGenericSlotWrapper. %s", e.what());
				}
			}
		};

		class SignalSource;
		class SignalDescriptor;
		class SignalInstance : public boost::noncopyable
		{
		private:
			SignalSource* source;
		public:
			const SignalDescriptor& descriptor;
		  
		protected:
			SignalInstance(SignalSource* source, const SignalDescriptor& descriptor)
				: source(source),
				  descriptor(descriptor)
			{
			}

		public:
			virtual ~SignalInstance();

		public:
			SignalSource* getSource()
			{
				return source;
			}

		public:
			template<typename T>
			boost::signals::connection connectGeneric(T slot, boost::signals::connect_position pos)
			{
				return descriptor.connectGeneric(this, GenericSlotWrapper::create<T>(slot), pos);
			}
		};

		class __declspec(novtable) SignalSource
		{
			friend class SignalDescriptor;

		private:
		  
		public:
			virtual ~SignalSource();
		public:
			void disconnect_all_slots();
		};

		class Signal;
		class __declspec(novtable) SignalDescriptor : public MemberDescriptor
		{
			friend class SignalInstance;

		public:
			typedef Signal Member;
			typedef Signal ConstMember;

		public:
			void (*signalCreatedHook)(SignalSource*);

		protected:
			SignatureDescriptor signature;
		  
		protected:
			SignalDescriptor(ClassDescriptor& classDescriptor, const char* name);

		protected:
			SignalInstance* findSignalInstance(const SignalSource* source) const;

		private:
			virtual boost::signals::connection connectGeneric(SignalInstance*, GenericSlotWrapper*, boost::signals::connect_position) const = 0;
			virtual SignalInstance* newSignalInstance(SignalSource&) const = 0;

		public:
			boost::shared_ptr<SignalInstance> getSignalInstance(SignalSource& source) const;
			const SignatureDescriptor& getSignature() const;
		};

		class Signal
		{
		protected:
			const SignalDescriptor* descriptor;
			DescribedBase* instance;
		  
		public:
			Signal(const Signal&);
			Signal(const SignalDescriptor& descriptor, DescribedBase* instance)
				: descriptor(&descriptor),
				  instance(instance)
			{
			}

		public:
			Signal& operator=(const Signal&);
			const Name& getName() const;
			const SignalDescriptor* getDescriptor() const;
			boost::shared_ptr<SignalInstance> getSignalInstance() const;
		};

		template<typename CallbackSignature>
		class TSignalDesc : public SignalDescriptor
		{
		protected:
			class TSignalInstance : public SignalInstance, public boost::signal<CallbackSignature>
			{
			public:
				TSignalInstance(SignalSource* source, const SignalDescriptor& descriptor)
					: SignalInstance(source, descriptor),
					  boost::signal<CallbackSignature>()
				{
				}
			};

		protected:
			TSignalDesc(ClassDescriptor& classDescriptor, const char* name)
				: SignalDescriptor(classDescriptor, name)
			{
			}

		private:
			virtual SignalInstance* newSignalInstance(SignalSource& source) const
			{
				return new TSignalInstance(&source, *this);
			}

		protected:
			TSignalInstance* findSig(const SignalSource* source) const
			{
				return (TSignalInstance*)findSignalInstance(source);
			}
			TSignalInstance& sig(SignalSource& source) const // TODO: check match
			{
				return *(TSignalInstance*)(getSignalInstance(source).get());
			}

		public:
			boost::signals::connection connect(SignalSource* source, const boost::slot<boost::function<CallbackSignature>>& slot)
			{
				if (source)
					return sig(*source).connect(slot);
				
				return boost::signals::connection();
			}
			bool empty(const SignalSource* source)
			{
				TSignalInstance* instance = findSig(source);
				return !instance || instance->empty();
			}
		};


		template<int ArgCount, typename CallbackSignature>
		class SignalDescImpl : public TSignalDesc<CallbackSignature>
		{
		};

		// Specialised implementations for different argument counts. Keeping it up to two since Roblox signals ever only had up to two arguments in 2007.
		template<typename CallbackSignature>
		class SignalDescImpl<0, CallbackSignature> : public TSignalDesc<CallbackSignature>
		{
		protected:
			class GenericSlotAdapter
			{
			private:
				boost::shared_ptr<GenericSlotWrapper> wrapper;
			  
			public:
				GenericSlotAdapter(GenericSlotWrapper* wrapper)
					: wrapper(wrapper)
				{
				}

			public:
				void operator()()
				{
					wrapper->execute(std::vector<boost::any>());
				}
			};

		protected:
			SignalDescImpl(ClassDescriptor& classDescriptor, const char* name)
				: TSignalDesc(classDescriptor, name)
			{
			}

		public:
			void fire(SignalSource* source)
			{
				TSignalInstance* instance = findSig(source);
				if (instance)
					(*instance)();
			}

		protected:
			virtual boost::signals::connection connectGeneric(SignalInstance* si, GenericSlotWrapper* wrapper, boost::signals::connect_position pos) const
			{
				TSignalInstance* instance = static_cast<TSignalInstance*>(si);
				return instance->connect(GenericSlotAdapter(wrapper), pos);
			}
		};

		template<typename CallbackSignature>
		class SignalDescImpl<1, CallbackSignature> : public TSignalDesc<CallbackSignature>
		{
		public:
			class GenericSlotAdapter
			{
			private:
				boost::shared_ptr<GenericSlotWrapper> wrapper;
			  
			public:
				GenericSlotAdapter(GenericSlotWrapper* wrapper)
					: wrapper(wrapper)
				{
				}

			public:
				void operator()(typename boost::function_traits<CallbackSignature>::arg1_type arg1)
				{
					std::vector<boost::any> args(1);
					args[0] = arg1;

					wrapper->execute(args);
				}
			};

		protected:
			SignalDescImpl(ClassDescriptor& classDescriptor, const char* name)
				: TSignalDesc(classDescriptor, name)
			{
			}

		public:
			void fire(SignalSource* source, typename const boost::function_traits<CallbackSignature>::arg1_type arg1)
			{
				TSignalInstance* instance = findSig(source);
				if (instance)
					(*instance)(arg1);
			}

		protected:
			virtual boost::signals::connection connectGeneric(SignalInstance* si, GenericSlotWrapper* wrapper, boost::signals::connect_position pos) const
			{
				TSignalInstance* instance = static_cast<TSignalInstance*>(si);
				return instance->connect(GenericSlotAdapter(wrapper), pos);
			}
		};

		template<typename CallbackSignature>
		class SignalDescImpl<2, CallbackSignature> : public TSignalDesc<CallbackSignature>
		{
		public:
			class GenericSlotAdapter
			{
			private:
				boost::shared_ptr<GenericSlotWrapper> wrapper;
			  
			public:
				GenericSlotAdapter(GenericSlotWrapper* wrapper)
					: wrapper(wrapper)
				{
				}

			public:
				void operator()(typename boost::function_traits<CallbackSignature>::arg1_type arg1, typename boost::function_traits<CallbackSignature>::arg2_type arg2)
				{
					std::vector<boost::any> args(2);
					args[0] = arg1;
					args[1] = arg2;

					wrapper->execute(args);
				}
			};

		protected:
			SignalDescImpl(ClassDescriptor& classDescriptor, const char* name)
				: TSignalDesc(classDescriptor, name)
			{
			}

		public:
			void fire(SignalSource* source, typename boost::function_traits<CallbackSignature>::arg1_type arg1, typename boost::function_traits<CallbackSignature>::arg2_type arg2)
			{
				TSignalInstance* instance = findSig(source);
				if (instance)
					(*instance)(arg1, arg2);
			}

		protected:
			virtual boost::signals::connection connectGeneric(SignalInstance* si, GenericSlotWrapper* wrapper, boost::signals::connect_position pos) const
			{
				TSignalInstance* instance = static_cast<TSignalInstance*>(si);
				return instance->connect(GenericSlotAdapter(wrapper), pos);
			}
		};

		template<typename Class, typename CallbackSignature>
		class SignalDesc : public SignalDescImpl<boost::function_traits<CallbackSignature>::arity, CallbackSignature>
		{
		public:
			SignalDesc(const char* name, const char* arg1name, const char* arg2name)
				: SignalDescImpl(Class::classDescriptor(), name)
			{
				SignatureDescriptor::Item arg1 = {&Name::declare(arg1name, -1), &Type::singleton<boost::function_traits<typename CallbackSignature>::arg1_type>()};
				signature.arguments.push_back(arg1);

				SignatureDescriptor::Item arg2 = {&Name::declare(arg2name, -1), &Type::singleton<boost::function_traits<typename CallbackSignature>::arg2_type>()};
				signature.arguments.push_back(arg2);
			}
			SignalDesc(const char* name, const char* arg1name)
				: SignalDescImpl(Class::classDescriptor(), name)
			{
				SignatureDescriptor::Item arg1 = {&Name::declare(arg1name, -1), &Type::singleton<boost::function_traits<typename CallbackSignature>::arg1_type>()};
				signature.arguments.push_back(arg1);
			}
			SignalDesc(const char* name)
				: SignalDescImpl(Class::classDescriptor(), name)
			{
			}
		};
	}
}
#include "reflection/reflection.h"
#include "reflection/object.h"
#include "v8xml/XmlElement.h"
#include <vector>
struct Prefix { virtual ~Prefix(); char pad[20]; };
struct Object : Prefix, RBX::Reflection::DescribedBase { void collect(XmlElement*) const; };
void Object::collect(XmlElement* result) const {
 for (RBX::Reflection::ConstPropertyIterator it = properties_begin(); it != properties_end(); ++it) {
  const RBX::Reflection::PropertyDescriptor& descriptor = (*it).getDescriptor();
  XmlElement* node = descriptor.write(this, false);
  if (node) result->addChild(node);
 }
}

