// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <utility>
#include <string>
namespace boost {
	class any {
		struct placeholder { virtual ~placeholder() {} };
		template<class V> struct holder : placeholder { holder(const V& v) : held(v) {} V held; };
	public:
		any() : content(0) {}
		template<class V> any(const V& v);
		~any() { delete content; }
		any& swap(any& rhs) { std::swap(content, rhs.content); return *this; }
		template<class V> any& operator=(const V& rhs) { any(rhs).swap(*this); return *this; }
		placeholder* content;
	};
}
namespace RBX {
	class Instance;
	class ContentId { public: std::string id; int extra; };
	namespace Reflection {
		class Type {
		public:
			template<typename T> static const Type& singleton();
		};
		template<class T> struct ExeCounter { static int n; };
		class Value {
			const Type* _type;
			boost::any value;
		public:
			template<typename T>
			Value& operator=(const T& rhs)
			{
				++ExeCounter<T>::n;
				this->_type = &Type::singleton<T>();
				this->value = rhs;
				return *this;
			}
		};
		template<class V> class GetSet {
		public:
			virtual ~GetSet();
			virtual void v1();
			virtual V get(const Instance* instance) const = 0;
		};
		class StringPropDescriptor {
		public:
			char pad[0x18];
			GetSet<ContentId>* getset;
			void getValue(const Instance* instance, Value& value) const;
		};
		void StringPropDescriptor::getValue(const Instance* instance, Value& value) const
		{
			value = getset->get(instance);
		}
}}
