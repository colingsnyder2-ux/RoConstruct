// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <utility>
namespace boost {
	class any {
		struct placeholder { virtual ~placeholder() {} };
		template<class V> struct holder : placeholder { holder(const V& v) : held(v) {} V held; };
	public:
		any() : content(0) {}
		template<class V> any(const V& v) : content(new holder<V>(v)) {}
		~any() { delete content; }
		any& swap(any& rhs) { std::swap(content, rhs.content); return *this; }
		template<class V> any& operator=(const V& rhs) { any(rhs).swap(*this); return *this; }
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
			Value& operator=(const T& rhs)
			{
				++ExeCounter<T>::n;
				this->_type = &Type::singleton<T>();
				this->value = rhs;
				return *this;
			}
		};
		}}
namespace G3D { class Vector2int16 { public: short x, y; }; }
namespace RBX { namespace Reflection {
template Value& Value::operator=<G3D::Vector2int16>(const G3D::Vector2int16&);
	}
}
