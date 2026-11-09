// from server: 100% by king_originala
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// Native UserInputBase constructor. Real ContentId and G3D pointer APIs.
// Native base ctor omits vptr writes; derived DxUserInput installs final vptrs.
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
// The SDK supplies these eight actual virtual APIs and owned field types.
// novtable reflects measured base-ctor emission, not an SDK-header mutation.
class __declspec(novtable) UserInputBase {
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
UserInputBase::UserInputBase():currentCursor(NULL){}
}
typedef char NativeInputSize[sizeof(RBX::UserInputBase)==40?1:-1];
typedef char NativeContentSize[sizeof(RBX::ContentId)==32?1:-1];
typedef char NativeInputPointerSize[sizeof(G3D::ReferenceCountedPointer<RBX::TextureProxyBase>)==4?1:-1];
typedef char NativeInputVectorSize[sizeof(G3D::Vector2)==8?1:-1];
