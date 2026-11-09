// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace boost {
	template<class T> class shared_ptr { public: T* px; void* pi_; };
	class any {
	public:
		template<class V> any& operator=(const V& rhs);
		void* content;
	};
}
namespace RBX {
	namespace Reflection {
		class DescribedBase;
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
		template Value& Value::operator=(const boost::shared_ptr<DescribedBase>&);
	}
}
