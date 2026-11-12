// from server: 100% by EspClaude
// from server: 59% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs roc_claude_b4a10b5192c82067.cpp

// Candidate translation unit (score above; library headers required).
// 2007-08 0x58bad0 Stats::TypedStatsItem<unsigned int>::TypedStatsItem(const unsigned int*):
// self-contained codegen analog. Target-proven layout: the derived vptrs are written at
// +0x00,+0x04,+0x10,+0x14,+0x2c,+0x44,+0x5c,+0x74,+0x8c (subobject sizes follow from them),
// Item() is called out of line, the function member starts at +0x110 and is three zeroed
// words (boost 1.33 function: manager, functor, invoker) followed by an out-of-line
// assign_to(bind_t) taking the 8-byte functor {&deref, v}; deref (0x5b9940) returns its argument.
#include <boost/bind.hpp>
namespace RBX
{
	namespace Stats
	{
		struct Sub00 { virtual void s00(); };
		struct Sub04 { virtual void s04(); int pad[2]; };
		struct Sub10 { virtual void s10(); };
		struct Sub14 { virtual void s14(); int pad[5]; };
		struct Sub2c { virtual void s2c(); int pad[5]; };
		struct Sub44 { virtual void s44(); int pad[5]; };
		struct Sub5c { virtual void s5c(); int pad[5]; };
		struct Sub74 { virtual void s74(); int pad[5]; };
		struct Sub8c { virtual void s8c(); int pad[(0x110 - 0x8c - 4) / 4]; };

		class Item : public Sub00, public Sub04, public Sub10, public Sub14, public Sub2c,
					 public Sub44, public Sub5c, public Sub74, public Sub8c
		{
		protected:
			virtual void update();
		public:
			Item();
			virtual ~Item();
		};

		class function_base
		{
		public:
			function_base() : manager(0)
			{
				functor = 0;
			}
			void* manager;
			void* functor;
		};

		template<typename R>
		class function0 : public function_base
		{
			void* invoker;
		public:
			template<typename Functor>
			function0(Functor f)
				: function_base(), invoker(0)
			{
				this->assign_to(f);
			}
			~function0();
			template<typename Functor>
			void assign_to(Functor f);
		};

		template<typename T>
		class TypedStatsItem : public Item
		{
		protected:
			const function0<T> func;
		public:
			TypedStatsItem(const T*);
			virtual void update();
		private:
			static const T& deref(const T*);
		};

		template<typename T>
		const T& TypedStatsItem<T>::deref(const T* v)
		{
			return *v;
		}

		template<typename T>
		TypedStatsItem<T>::TypedStatsItem(const T* v)
			: Item(),
			  func(boost::bind(&TypedStatsItem<T>::deref, v))
		{
		}

		template TypedStatsItem<unsigned int>::TypedStatsItem(const unsigned int*);
	}
}
