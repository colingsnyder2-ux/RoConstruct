// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <vector>
#include <intrin.h>
struct lua_State;
extern "C" void lua_createtable(lua_State* L, int narr, int nrec);
extern "C" void lua_rawseti(lua_State* L, int idx, int n);
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
		placeholder* content;
	};
}
namespace RBX {
	class Instance;
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
			template<typename ValueType>
			Value(const ValueType& v)
				: _type((++ExeCounter<ValueType>::n, &Type::singleton<ValueType>())),
				  value(v)
			{
			}
		};
	}
	namespace Lua {
		class LuaArguments {
		public:
			static int push(const Reflection::Value& value, lua_State* const L);
			template <typename T>
			static int pushTable(T _First, T _Last, lua_State* const L)
			{
				lua_createtable(L, _Last-_First, 0);
				int i = 0;
				for (; _First != _Last; _First++)
				{
					push(*_First, L);
					lua_rawseti(L, -2, ++i);
				}
				return 1;
			}
		};
	}
}
template int RBX::Lua::LuaArguments::pushTable(std::vector<boost::shared_ptr<RBX::Instance> >::const_iterator, std::vector<boost::shared_ptr<RBX::Instance> >::const_iterator, lua_State* const);
