// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct lua_State;
extern "C" int lua_type(lua_State* L, int idx);
#include <intrin.h>
namespace boost {
	struct sp_counted_base {
		virtual ~sp_counted_base() {}
		virtual void dispose() = 0;
		long use_count_;
		long weak_count_;
		void add_ref_copy() { _InterlockedIncrement(&use_count_); }
		void release()
		{
			if (_InterlockedDecrement(&use_count_) == 0) { dispose(); weak_release(); }
		}
		void weak_release();
	};
	template<class T> class shared_ptr {
	public:
		shared_ptr() : px(0), pi_(0) {}
		shared_ptr(const shared_ptr& r) : px(r.px), pi_(r.pi_) { if (pi_ != 0) pi_->add_ref_copy(); }
		~shared_ptr() { if (pi_ != 0) pi_->release(); }
		T* px;
		sp_counted_base* pi_;
	};
	class any {
		struct placeholder { virtual ~placeholder() {} };
		template<class V> struct holder : placeholder { holder(const V& v) : held(v) {} V held; };
	public:
		any() : content(0) {}
		template<class V> any(const V& v) : content(new holder<V>(v)) {}
		~any() { delete content; }
		any& swap(any& rhs) { placeholder* t = content; content = rhs.content; rhs.content = t; return *this; }
		template<class V> any& operator=(const V& rhs) { any(rhs).swap(*this); return *this; }
		placeholder* content;
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
	}
	namespace Lua {
		template<class T> class SharedPtrBridge {
		public:
			template<typename ValueType>
			static bool getValue(lua_State* L, unsigned int index, ValueType& value);
			template<typename ValueType>
			static bool getPtr(lua_State* L, unsigned int index, ValueType& value)
			{
				if (lua_type(L, static_cast<int>(index)) == 0)
				{
					value = boost::shared_ptr<T>();
					return 1;
				}
				return getValue(L, index, value);
			}
		};
		template bool SharedPtrBridge<Reflection::DescribedBase>::getPtr<Reflection::Value>(lua_State*, unsigned int, Reflection::Value&);
	}
}
