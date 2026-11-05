// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: atl-9.0-dll-rtm roc_espclaude_6baccc4b01dbd792.cpp

// Candidate translation unit (score above; library headers required).
#ifndef _CPPUNWIND
#define _CPPUNWIND 1
#endif
#ifndef _AFXDLL
#define _AFXDLL
#endif
#include <new>
#include <afx.h>
#include <atlbase.h>
#include <mshtml.h>
#include <intrin.h>

namespace boost {
namespace detail {
class sp_counted_base {
	long use_count_;
	long weak_count_;
public:
	virtual ~sp_counted_base() {}
	virtual void dispose() = 0;
	virtual void destroy() { delete this; }
	void weak_release()
	{
		if (_InterlockedDecrement(&weak_count_) == 0)
			destroy();
	}
};
class weak_count {
	sp_counted_base* pi_;
public:
	~weak_count() { if (pi_ != 0) pi_->weak_release(); }
};
}
template<class T> class weak_ptr {
	T* px;
	detail::weak_count pn;
};
template<class Sig> class function;
template<> class function<void()> {
	void* vtable;
	void* pad;
	void* functor;
public:
	function& operator=(void (*f)());
};
}

void nothing();

class EventSink : public IDispatch {
	long refCount;
public:
	boost::function<void()> onEvent;
};

struct Storage {
	unsigned char data[32];
	~Storage();
};

class View;

class ViewBinder {
	boost::weak_ptr<View> owner;
	Storage storage;
	CComPtr<EventSink> sink;
	CComPtr<IHTMLElement> element;
public:
	virtual ~ViewBinder();
};

ViewBinder::~ViewBinder()
{
	sink->onEvent = &nothing;
	CComQIPtr<IHTMLElement2> element2(element);
	element2->detachEvent(CComBSTR("onchange"), sink);
}
