// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <new>
namespace boost {
	class any {
		struct placeholder { virtual ~placeholder() {} };
		template<class V> struct holder : placeholder { holder(const V& v) : held(v) {} V held; };
	public:
		any() : content(0) {}
		template<class V> any(const V& v) : content(new holder<V>(v)) {}
		~any() { delete content; }
		placeholder* content;
	};
}
namespace RBX {
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
			Value(const T& v) : _type((++ExeCounter<T>::n, &Type::singleton<T>())), value(v) {}
		};
		template Value::Value(const int&);
	}
}
