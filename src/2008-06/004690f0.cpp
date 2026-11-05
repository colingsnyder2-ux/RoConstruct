// from server: 100% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: mfc-9.0-shared roc_king_originala_dxinput_ctor_e0e5fafa00b66f00.cpp

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
DxUserInput::DxUserInput(NativeFrameView*w,RBX::DataModel*o):acceleratorData(0),acceleratorCount(0),flag58(0),flag59(0),value5c(0),value60(0),value64(0),value168(0),window(w),handle(nativeTopWindowHandle(w)),reference(nativeSharedDataModel(o)),relatedReference(nativeSharedRunService(o?o->getRunService():0)),flag190(0),flag191(0),flag192(0),flag193(0){
 boost::shared_ptr<RBX::RunService>*r=&relatedReference;
 current=window->nativeGetParentFrame();
 if(current){do{
  unsigned count=CopyAcceleratorTableA(current->GetDefaultAccelerator(),0,0);
  acceleratorCount=count;
  if(count){ACCEL*allocated=new ACCEL[count];acceleratorData=allocated;CopyAcceleratorTableA(current->GetDefaultAccelerator(),allocated,acceleratorCount);break;}
  current=current->nativeGetParentFrame();
 }while(current);}
 memset(keys,0,256);
 HRESULT hr=DirectInput8Create(GetModuleHandleA(NULL),DIRECTINPUT_VERSION,IID_IDirectInput8A,reinterpret_cast<void**>(&input),NULL);
 if(FAILED(hr))AtlThrow(hr);
 initializeFirst();initializeSecond();
 if(r->get())r->get()->heartbeat.addListener(static_cast<RBX::Listener<RBX::RunService,RBX::Heartbeat>*>(this));
 _ReadWriteBarrier();
 if(r->get())r->get()->transition.addListener(static_cast<RBX::Listener<RBX::RunService,RBX::RunTransition>*>(this));
}



