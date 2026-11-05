// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>
namespace boost {
	struct sp_counted_base {
		virtual ~sp_counted_base() {}
		virtual void dispose() = 0;
		long use_count_;
		long weak_count_;
		void add_ref_copy() { _InterlockedIncrement(&use_count_); }
		void release();
	};
	template<class T> class shared_ptr {
	public:
		shared_ptr(const shared_ptr& r) : px(r.px), pi_(r.pi_) { if (pi_ != 0) pi_->add_ref_copy(); }
		~shared_ptr() { if (pi_ != 0) pi_->release(); }
		T* px;
		sp_counted_base* pi_;
	};
	namespace detail {
		struct tss_cleanup_function;
		void* get_tss_data(void const* key);
		void set_tss_data(void const* key, boost::shared_ptr<tss_cleanup_function> func, void* tss_data, bool cleanup_existing);
	}
	template<typename T> class thread_specific_ptr {
		boost::shared_ptr<detail::tss_cleanup_function> cleanup;
	public:
		T* get() const { return static_cast<T*>(detail::get_tss_data(this)); }
		void reset(T* new_value = 0)
		{
			T* const current_value = get();
			if (current_value != new_value)
				detail::set_tss_data(this, cleanup, new_value, true);
		}
	};
}
struct TlsValue : boost::thread_specific_ptr<int> {
	void set(int v);
};
void TlsValue::set(int v) { reset(new int(v)); }
