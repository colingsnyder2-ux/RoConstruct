// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace boost {
	struct arg1_t {};
	extern arg1_t _1;
	struct list1 { list1(arg1_t) {} };
	template<class F> class bind_t { public: bind_t(F f, const list1& l) : f_(f), l_(l) {} F f_; list1 l_; };
	template<class R, class B1> inline bind_t<R (*)(B1)> bind(R (*f)(B1), arg1_t a1) { return bind_t<R (*)(B1)>(f, list1(a1)); }
	class function_base {
	public:
		function_base() : vtable(0) {}
		void* vtable;
		char functor[0x1c];
	};
	template<class Sig> class function : public function_base {
	public:
		template<class F> function(F f) : function_base() { assign_to(f); }
		function(const function& f);
		~function();
		template<class F> void assign_to(F f) throw();
	};
}
void stepA(int);
bool stepB(int);
class Job {
public:
	void start(int a, int b, int c, boost::function<bool(int)> f1, boost::function<void(int)> f2);
	void run(int a, int b, int c);
};
void Job::run(int a, int b, int c)
{
	start(a, b, c, boost::bind(&stepB, boost::_1), boost::bind(&stepA, boost::_1));
}
