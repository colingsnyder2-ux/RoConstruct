// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_7d4c72817bccd038.cpp

// Candidate translation unit (score above; library headers required).
#undef _RELEASEASSERT
#undef _DEBUG
#define _DLL
#define private public
#define ContentProvider RbxgsContentProvider
#include "util/ContentProvider.h"
#undef ContentProvider
#undef private
#define private public
#include "util/IRenderable.h"
#undef private
#include "util/Object.h"
#define hasListeners() hasListeners() const { return listeners.size() > 0; } bool hasListenersEmpty()
#include "util/Events.h"
#undef hasListeners
namespace RBX { template<class T> class GuidItem { public: virtual ~GuidItem() {} char guidPad[0xc]; }; }
namespace RBX { template<class T> class GuidAFP : public AbstractFactoryProduct<T> { protected: virtual void onGuidChanged() {} }; }
#define AbstractFactoryProduct GuidItem<Instance>, public GuidAFP
#include "util/Guid.h"
namespace RBX { class GuidStub { public: typedef Guid::Data Data; void assign(const Data&) {} operator const Guid&() const { return *(const Guid*)0; } }; }
#define Guid GuidStub
#include "v8tree/Instance.h"
#undef Guid
#undef AbstractFactoryProduct
#include <list>
#include <map>
namespace RBX
{
	extern const char* sContentProvider;
	class ContentProvider : public DescribedNonCreatable<ContentProvider, Instance, &sContentProvider>
	{
	public:
		boost::mutex requestSync;
		std::list<ContentId> requestQueue;
		std::list<RbxgsContentProvider::FailedUrl> failedUrls;
		boost::mutex contentCacheMutex;
		std::map<ContentId, RbxgsContentProvider::CachedContent> contentCache;
		boost::scoped_ptr<worker_thread> requestProcessor;
		ContentProvider();
		worker_thread::work_result processRequests();
	};

}
typedef boost::_bi::bind_t<RBX::worker_thread::work_result, boost::_mfi::mf0<RBX::worker_thread::work_result, RBX::ContentProvider>, boost::_bi::list1<boost::_bi::value<RBX::ContentProvider*> > > ExeContentBind;
namespace boost { template<> template<> function0<RBX::worker_thread::work_result, std::allocator<boost::function_base> >::function0(ExeContentBind f, int) throw(); }
namespace RBX
{
	ContentProvider::ContentProvider()
	{
		requestProcessor.reset(new worker_thread(boost::bind(&ContentProvider::processRequests, this), "rbx_content"));
	}
}
