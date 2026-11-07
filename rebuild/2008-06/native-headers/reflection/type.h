#pragma once
// >>> native-status (generated) -- do not edit >>>
// type | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src 94de0f25 | roc native-status --write
#include <boost/any.hpp>
#include <typeinfo>
#include <list>
#include <vector>
#include "reflection/descriptor.h"

namespace RBX
{
	namespace Reflection
	{
        typedef std::vector<class Value> ValueCollection;

		class Type : public Descriptor
		{
		public:
			const type_info& type;
			const Name& tag;

		public:
			bool operator==(const Type& other) const
			{
				return this == &other;
			}
			bool operator!=(const Type& other) const
			{
				return this != &other;
			}

		protected:
			Type(const char* name, const type_info& type, const char* tag) // TODO: check if matches (will only match in a /GS project)
				: Descriptor(name),
				  type(type),
				  tag(Name::declare(tag, -1))
			{
			}
			Type(const char* name, const type_info& type)
				: Descriptor(name),
				  type(type),
				  tag(Name::lookup(name))
			{
			}

		public:
			template<typename T>
			static const Type& singleton();
		};

		class RefType : public Type
		{
		private:
			RefType(const char* name, const type_info& type)
				: Type(name, type, "Ref")
			{
			}

		public:
			template<typename T>
			static const RefType& singleton()
			{
				static RefType type("Object", typeid(RefType));
				return type;
			}
		};

		class Value
		{
		private:
			const Type* _type;
			boost::any value;

		public:
			Value();

			// Value constructors 0042d200/0042d240/0042d280 take const references.
			template<typename ValueType>
			Value(const ValueType& value)
				: _type(&Type::singleton<typename ValueType>()),
				  value(value)
			{
			}

		public:
			const Type& type() const
			{
				return *_type;
			}
			bool isVoid() const
			{
				// this is a guess
				return isType<void>();
			}

		public:
			template<typename T>
			T cast() const
			{
				return boost::any_cast<T>(value);
			}

			template<typename T>
			const T& asRef() const
			{
				return boost::any_cast<const T&>(value);
			}

			// not in resym but it might exist
			template<typename T>
			T cast()
			{
				return boost::any_cast<T>(value);
			}

			template<typename T>
			T& convert();

			template<typename T>
			T& genericConvert();

			template<typename T>
			T get() const;

			template<typename T>
			bool isType() const
			{
				return typeid(T) == type().type;
			}

			template<typename T>
			Value& operator=(const T& rhs)
			{
				this->_type = &Type::singleton<T>();
				this->value = rhs;
				return *this;
			}

			// TODO: replace all mentions with operator=?
			template<typename T>
			void set(const T& value)
			{
				this->_type = &Type::singleton<T>();
				this->value = value;
			}
		};

		class SignatureDescriptor
		{
		public:
			struct Item
			{
				const Name* name;
				const Type* type;
				const Value defaultValue;
			};

		public:
			const Type* resultType;
			std::list<Item> arguments;

		public:
			void addArgument(const Name& name, const Type& type, const Value& defaultValue);

		public:
			SignatureDescriptor();
		};
	}
}
