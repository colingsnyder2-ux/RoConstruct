// from server: 100% by EspClaude
// roc 2009-06 006622e0  unit: RBX::VPartInstance::?$EventDesc  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006622e0
//
// 006622e0  6aff                 push -1
// 006622e2  68b4c28600           push 0x86c2b4
// 006622e7  64a100000000         mov eax, dword ptr fs:[0]
// 006622ed  50                   push eax
// 006622ee  64892500000000       mov dword ptr fs:[0], esp
// 006622f5  83ec08               sub esp, 8
// 006622f8  56                   push esi
// 006622f9  8bf1                 mov esi, ecx
// 006622fb  57                   push edi
// 006622fc  8d7e04               lea edi, [esi + 4]
// 006622ff  8bcf                 mov ecx, edi
// 00662301  897c240c             mov dword ptr [esp + 0xc], edi
// 00662305  ff15c0e48900         call dword ptr [0x89e4c0]
// 0066230b  c744241800000000     mov dword ptr [esp + 0x18], 0
// 00662313  e848b6f6ff           call 0x5cd960
// 00662318  89471c               mov dword ptr [edi + 0x1c], eax
// 0066231b  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0066231f  c7462400000000       mov dword ptr [esi + 0x24], 0
// 00662326  5f                   pop edi
// 00662327  8bc6                 mov eax, esi
// 00662329  5e                   pop esi
// 0066232a  64890d00000000       mov dword ptr fs:[0], ecx
// 00662331  83c414               add esp, 0x14
// 00662334  c3                   ret 
// copied from an identical function in another client (function ??0UserInputBase@RBX@@QAE@XZ)

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