#pragma once
#include <boost/shared_ptr.hpp>
#include <map>
#include "util/Name.h"

namespace RBX
{
	template<typename Class>
	boost::shared_ptr<Class> shared_from(Class* r)
	{
		return r ? boost::shared_static_cast<Class>(r->shared_from_this()) : boost::shared_ptr<Class>();
	}

	template<typename To, typename From>
	boost::shared_ptr<To> shared_from_dynamic_cast(boost::enable_shared_from_this<From>* r)
	{
		return r ? boost::shared_dynamic_cast<To, From>(r->shared_from_this()) : boost::shared_ptr<To>();
	}

	template<typename To, typename From>
	boost::shared_ptr<To> shared_from_polymorphic_downcast(boost::enable_shared_from_this<From>* r)
	{
		return r ? boost::shared_polymorphic_downcast<To, From>(r->shared_from_this()) : boost::shared_ptr<To>();
	}

	class Object
	{
	public:
		virtual ~Object()
		{
		}
	};

	class ICreator
	{
	public:
		virtual boost::shared_ptr<Object> create() const = 0;
	};

	template<typename T>
	class Creatable : public Object
	{
	public:
		class Deleter
		{
		public:
			void operator()(T*);
		};

	protected:
		Creatable()
		{
		}
		virtual ~Creatable()
		{
		}

	public:
		template<typename Class>
		static boost::shared_ptr<Class> create()
		{
			return boost::shared_ptr<Class>(new Class(), Deleter());
		}
		template<typename Class, typename Parameter1>
		static boost::shared_ptr<Class> create(Parameter1 p1)
		{
			return boost::shared_ptr<Class>(new Class(p1), Deleter());
		}
		template<typename Class, typename Parameter1, typename Parameter2>
		static boost::shared_ptr<Class> create(Parameter1 p1, Parameter2 p2)
		{
			return boost::shared_ptr<Class>(new Class(p1, p2), Deleter());
		}
		template<typename Class, typename Parameter1, typename Parameter2, typename Parameter3>
		static boost::shared_ptr<Class> create(Parameter1 p1, Parameter2 p2, Parameter3 p3)
		{
			return boost::shared_ptr<Class>(new Class(p1, p2, p3), Deleter());
		}
	private:
		static void* operator new(size_t size)
		{
			return malloc(size);
		}
		static void operator delete(void* ptr)
		{
			free(ptr);
		}
	};

	template<typename T>
	class AbstractFactoryProduct : public Creatable<T>
	{
	public:
		typedef Creatable<T> CreatableBase;
	protected:
		AbstractFactoryProduct()
		{
		}
	public:
		virtual const Name& getClassName() const = 0;
	  
	protected:
		static std::map<const Name*, const ICreator*>& getCreators()
		{
			static std::map<const Name*, const ICreator*> creators;
			return creators;
		}
	public:
		static boost::shared_ptr<T> create(const Name& name)
		{
			std::map<const Name*, const ICreator*>::iterator iter = getCreators().find(&name);
			if (iter == getCreators().end())
			{
				return boost::shared_ptr<T>();
			}
			else
			{
				return boost::shared_dynamic_cast<T>(iter->second->create());
			}
		}
	};

	template<typename Class, typename DerivedClass, const char** ClassName>
	class FactoryProduct : public DerivedClass
	{
	private:
		class Creator : public ICreator
		{
		public:
			virtual boost::shared_ptr<Object> create() const;
			const Name& getClassName() const;

		public:
			Creator();
			~Creator();
		};

	private:
		static const Creator creator;
	  
	protected:
		FactoryProduct()
		{
			(void)&creator;
		}
		template<typename Arg0Type>
		FactoryProduct(Arg0Type arg0)
			: DerivedClass(arg0)
		{
			(void)&creator;
		}
		virtual ~FactoryProduct()
		{
		}

	public:
		const ICreator& getCreator()
		{
			return creator;
		}
		virtual const Name& getClassName() const;
	  
	public:
		static const Name& className();
	};

	template<typename DerivedClass, const char** ClassName>
	class NonFactoryProduct : public DerivedClass
	{
	public:
		NonFactoryProduct()
			: DerivedClass()
		{
		}

		template<typename T0>
		NonFactoryProduct(T0 arg0)
			: DerivedClass(arg0)
		{
		}

		virtual const Name& getClassName() const;

	public:
		static const Name& className();
	};
}

// rebuild overlay: template bodies rbxgs declares but never defines
namespace RBX
{
	template<typename T>
	void Creatable<T>::Deleter::operator()(T* instance)
	{
		T::predelete(instance);
		delete instance;
	}

	template<typename Class, typename DerivedClass, const char** ClassName>
	const Name& FactoryProduct<Class, DerivedClass, ClassName>::className()
	{
		static const Name& n = Name::declare(*ClassName, -1);
		return n;
	}

	template<typename Class, typename DerivedClass, const char** ClassName>
	const Name& FactoryProduct<Class, DerivedClass, ClassName>::getClassName() const
	{
		return className();
	}

	template<typename Class, typename DerivedClass, const char** ClassName>
	FactoryProduct<Class, DerivedClass, ClassName>::Creator::Creator()
	{
		FactoryProduct::getCreators()[&FactoryProduct::className()] = this;
	}

	template<typename Class, typename DerivedClass, const char** ClassName>
	FactoryProduct<Class, DerivedClass, ClassName>::Creator::~Creator()
	{
		FactoryProduct::getCreators().erase(&FactoryProduct::className());
	}

	template<typename Class, typename DerivedClass, const char** ClassName>
	boost::shared_ptr<Object> FactoryProduct<Class, DerivedClass, ClassName>::Creator::create() const
	{
		return Class::CreatableBase::template create<Class>();
	}

	template<typename Class, typename DerivedClass, const char** ClassName>
	const Name& FactoryProduct<Class, DerivedClass, ClassName>::Creator::getClassName() const
	{
		return FactoryProduct::className();
	}

	template<typename Class, typename DerivedClass, const char** ClassName>
	const typename FactoryProduct<Class, DerivedClass, ClassName>::Creator FactoryProduct<Class, DerivedClass, ClassName>::creator;

	template<typename DerivedClass, const char** ClassName>
	const Name& NonFactoryProduct<DerivedClass, ClassName>::className()
	{
		static const Name& n = Name::declare(*ClassName, -1);
		return n;
	}

	template<typename DerivedClass, const char** ClassName>
	const Name& NonFactoryProduct<DerivedClass, ClassName>::getClassName() const
	{
		return className();
	}
}
