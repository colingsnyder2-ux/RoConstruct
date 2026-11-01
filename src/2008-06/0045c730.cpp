// from server: 100% by king_originala
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: mfc-9.0-shared roc_ui_network_window_ee9082b9a35d3d1a.cpp

// Candidate translation unit (score above; library headers required).
#ifndef _CPPUNWIND
#define _CPPUNWIND 1
#endif
#define _AFXDLL 1
#include <afxwin.h>
#include <atlbase.h>
#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h>
#include <intrin.h>
#include <vector>
#include <string>
#include <stddef.h>
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
namespace G3D {
class Vector2 {public:float x,y;
 Vector2():x(0),y(0){}Vector2(float a,float b):x(a),y(b){}
 Vector2(const Vector2&v):x(v.x),y(v.y){}
};
class AtomicInt32 {
 volatile int _value;
public:AtomicInt32(int v=0):_value(v){}
 void increment(){InterlockedIncrement(reinterpret_cast<volatile long*>(&_value));}
 unsigned decrement(){return InterlockedDecrement(reinterpret_cast<volatile long*>(&_value))!=0;}
};
class _WeakPtr {public:virtual~_WeakPtr(){}protected:friend class ReferenceCountedObject;virtual void objectCollected()=0;};
class _WeakPtrLinkedList {public:_WeakPtr*weakPtr;_WeakPtrLinkedList*next;};
class ReferenceCountedObject {public:
 AtomicInt32 ReferenceCountedObject_refCount;
 _WeakPtrLinkedList*ReferenceCountedObject_weakPointer;
protected:ReferenceCountedObject():ReferenceCountedObject_refCount(0),ReferenceCountedObject_weakPointer(0){}
public:
 void ReferenceCountedObject_zeroWeakPointers(){
  _WeakPtrLinkedList*node=ReferenceCountedObject_weakPointer;
  while(node){node->weakPtr->objectCollected();_WeakPtrLinkedList*tmp=node;node=node->next;delete tmp;}
 }
 virtual~ReferenceCountedObject(){}
};
template<class T>class ReferenceCountedPointer {
 T*m_pointer;
 void zeroPointer(){if(m_pointer){if(m_pointer->ReferenceCountedObject_refCount.decrement()==0){m_pointer->ReferenceCountedObject_zeroWeakPointers();delete m_pointer;}m_pointer=0;}}
 void setPointer(T*x){if(x!=m_pointer){zeroPointer();if(x){m_pointer=x;m_pointer->ReferenceCountedObject_refCount.increment();}}}
public:
 ReferenceCountedPointer():m_pointer(0){}
 ReferenceCountedPointer(T*p):m_pointer(0){setPointer(p);}
 ReferenceCountedPointer(const ReferenceCountedPointer&p):m_pointer(0){setPointer(p.m_pointer);}
 ~ReferenceCountedPointer(){zeroPointer();}
 T*pointer()const{return m_pointer;}
};
}
enum SDLKey;
namespace RBX {
class Name {public:static const Name&getNullName();};
class ContentId {
 std::string id;const Name*mimeTypePtr;
public:ContentId():id(),mimeTypePtr(&Name::getNullName()){}
};
class TextureId:public ContentId {};
class TextureProxyBase:public G3D::ReferenceCountedObject {
public:std::string filename;TextureProxyBase(){}virtual~TextureProxyBase(){}
 virtual G3D::Vector2 getSize()=0;
};
class Adorn;
class UserInputBase {
public:enum WrapMode {WRAP_AUTO,WRAP_CENTER};
private:ContentId currentCursorId;G3D::ReferenceCountedPointer<TextureProxyBase>currentCursor;
protected:virtual G3D::Vector2 getCursorPosition()=0;
 virtual G3D::ReferenceCountedPointer<TextureProxyBase>getGameCursor(Adorn*);
public:
 UserInputBase();~UserInputBase();void init(Adorn*);
 virtual void setWrapMode(WrapMode)=0;virtual WrapMode getWrapMode()const=0;
 virtual void centerCursor()=0;virtual bool keyDown(SDLKey)const=0;
 bool altKeyDown()const;bool shiftKeyDown()const;bool ctrlKeyDown()const;
 virtual void setKeyState(SDLKey,bool)=0;virtual void setCursorId(Adorn*,const TextureId&);
 void renderGameCursor(Adorn*);
};
}


namespace boost {namespace detail {
class sp_counted_base {
 sp_counted_base(const sp_counted_base&);
 sp_counted_base&operator=(const sp_counted_base&);
 long use_count_,weak_count_;
public:
 sp_counted_base():use_count_(1),weak_count_(1){}
 virtual ~sp_counted_base(){}
 virtual void dispose()=0;
 virtual void destroy(){delete this;}
 virtual void*get_deleter(const std::type_info&)=0;
 void add_ref_copy(){_InterlockedIncrement(&use_count_);}
 void weak_release(){if(_InterlockedDecrement(&weak_count_)==0)destroy();}
 void release(){if(_InterlockedDecrement(&use_count_)==0){dispose();weak_release();}}
};
class shared_count {
 sp_counted_base*pi_;
public:
 shared_count():pi_(0){}
 shared_count(const shared_count&r):pi_(r.pi_){if(pi_)pi_->add_ref_copy();}
 ~shared_count(){if(pi_)pi_->release();}
};
}
template<class T>class shared_ptr {
 T*px;detail::shared_count pn;
public:
 shared_ptr():px(0),pn(){}
 shared_ptr(const shared_ptr&r):px(r.px),pn(r.pn){}
 T*get()const{return px;}
};
}
namespace RBX {
template<class C,class E>class __declspec(novtable) Listener {
protected:
 virtual void onEvent(const C*,E)=0;
 Listener&operator=(const Listener&);
 virtual ~Listener(){}
};
struct RaiseRange;
template<class C,class E>class __declspec(novtable) Notifier {
 mutable std::vector<Listener<C,E>*>listeners;
 mutable RaiseRange*raiseRange;
protected:
 virtual ~Notifier(){}
 virtual void onAddListener(Listener<C,E>*)const{}
 virtual void onRemoveListener(Listener<C,E>*)const{}
public:
 void addListener(Listener<C,E>*)const;
};
}

namespace RBX {
class RunTransition;class Heartbeat;
class RunService {
public:
 char prefix[0x130];
 Notifier<RunService,Heartbeat> heartbeat;
 char middle[0x20];
 Notifier<RunService,RunTransition> transition;
};
class DataModel {public:RunService* getRunService();};
}
extern boost::shared_ptr<RBX::DataModel> nativeSharedDataModel(RBX::DataModel*);
extern boost::shared_ptr<RBX::RunService> nativeSharedRunService(RBX::RunService*);
struct NativeCriticalSection {CRITICAL_SECTION state;NativeCriticalSection();~NativeCriticalSection(){DeleteCriticalSection(&state);}};
struct NativeFrameView:CFrameWnd {
 NativeFrameView* nativeGetTopLevelFrame()const;
 NativeFrameView* nativeGetParentFrame()const;
};
inline HWND nativeTopWindowHandle(NativeFrameView*w){NativeFrameView*p=w->nativeGetTopLevelFrame();if(!p)return NULL;return p->m_hWnd;}
class DxUserInput:public RBX::UserInputBase,public RBX::Listener<RBX::RunService,RBX::RunTransition>,public RBX::Listener<RBX::RunService,RBX::Heartbeat> {
 char gap30[4];
 NativeCriticalSection member;
 NativeFrameView* current;
 ACCEL* acceleratorData;
 volatile UINT acceleratorCount;
 BYTE flag58,flag59;
 char gap5a[2];
 DWORD value5c;
 volatile float value60,value64;
 BYTE keys[256];
 DWORD value168;
 NativeFrameView* window;
 HWND handle;
 ATL::CComPtr<IDirectInput8A> input;
 ATL::CComPtr<IDirectInputDevice8A> device,extraDevice;
 boost::shared_ptr<RBX::DataModel> reference;
 boost::shared_ptr<RBX::RunService> relatedReference;
 BYTE flag190,flag191,flag192,flag193;
protected:
 virtual G3D::Vector2 getCursorPosition();
 virtual void onEvent(const RBX::RunService*,RBX::RunTransition);
 virtual void onEvent(const RBX::RunService*,RBX::Heartbeat);
public:
 virtual ~DxUserInput();
 virtual void setWrapMode(WrapMode);
 virtual WrapMode getWrapMode()const;
 virtual void centerCursor();
 virtual bool keyDown(SDLKey)const;
 virtual void setKeyState(SDLKey,bool);
 DxUserInput(NativeFrameView*,RBX::DataModel*);
 void initializeFirst();void initializeSecond();
};

#include <memory>
namespace boost { class noncopyable {protected:noncopyable(){}~noncopyable(){}private:noncopyable(const noncopyable&);noncopyable&operator=(const noncopyable&);}; }
namespace RBX {
struct __declspec(novtable) IRunView {virtual void InvalidateRunView()=0;virtual void AdjustThrottle(double)=0;};
struct __declspec(novtable) IMetric {IMetric(){}virtual ~IMetric(){}virtual std::string getMetric(const std::string&)const=0;};
namespace Profiling {
struct NativeSample {double sampleTime;double kernelTime;int frames;};
class Profiler:private boost::noncopyable {public:virtual ~Profiler();const double bucketTimeSpan;int currentBucket;NativeSample buckets[2048];double lastSampleTime;const std::string name;Profiler(const char*);};
class CodeProfiler:public Profiler {public:CodeProfiler*parent;CodeProfiler(const char*);};
}
class RenderStatsItem;
}
namespace G3D {class RenderDevice {public:~RenderDevice();};class GWindow;}
struct OwnedVirtual0 {virtual ~OwnedVirtual0();};
struct OwnedVirtual1 {virtual ~OwnedVirtual1();};
struct NativeContext {char prefix[0x130];int mode;};
NativeContext* __cdecl getContext();extern int defaultMode;extern const double initialValue;extern const char renderName[];
class NativeRobloxWnd:public CWnd,public RBX::IRunView,public RBX::IMetric {
 int mode;int reserved;
 boost::shared_ptr<RBX::DataModel> dataModel;
 ATL::CComPtr<IUnknown> workspace;
 boost::shared_ptr<RBX::RunService> runService;
 boost::shared_ptr<RBX::RenderStatsItem> renderStats;
 bool enabled;
 std::auto_ptr<DxUserInput> input;
 bool option,flag1,flag2,flag3;
 double value;
 std::auto_ptr<RBX::Profiling::CodeProfiler> profiler;
 bool profilerFlag;
 void* opaqueA0;G3D::GWindow* window;bool flagA8;
 std::auto_ptr<G3D::RenderDevice> device;
 std::auto_ptr<OwnedVirtual0> ownerB0;
 std::auto_ptr<OwnedVirtual1> ownerB4;
 int counter;
public:
 NativeRobloxWnd(bool);
 virtual ~NativeRobloxWnd();
 virtual void InvalidateRunView();virtual void AdjustThrottle(double);
 virtual std::string getMetric(const std::string&)const;
};
NativeRobloxWnd::NativeRobloxWnd(bool arg):enabled(true),option((value=initialValue,arg)),flag1(false),flag2(false),flag3(true),profiler(new RBX::Profiling::CodeProfiler(renderName)),profilerFlag(false),opaqueA0(0),window(0),flagA8(false){
 counter=0;reserved=0;NativeContext*context=getContext();if(defaultMode==0)defaultMode=context->mode;mode=defaultMode;if(mode==1)mode=3;
}
typedef char native_profiler_extent[(sizeof(RBX::Profiling::CodeProfiler)==0xc048)?1:-1];
typedef char native_input_extent[(sizeof(DxUserInput)==404)?1:-1];
typedef char native_window_extent[(sizeof(NativeRobloxWnd)==0xc0)?1:-1];
