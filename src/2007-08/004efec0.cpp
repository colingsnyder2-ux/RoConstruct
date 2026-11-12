// from server: 94% by EspClaude
// from server: 49% by tester
// roc 2007-08 004efec0  unit: RBX::Render::VChunk::?$WeakReferenceCountedPointer  size: 120 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004efec0
//
// 004efec0  6aff                 push -1
// 004efec2  6851d47400           push 0x74d451
// 004efec7  64a100000000         mov eax, dword ptr fs:[0]
// 004efecd  50                   push eax
// 004efece  83ec0c               sub esp, 0xc
// 004efed1  53                   push ebx
// 004efed2  55                   push ebp
// 004efed3  56                   push esi
// 004efed4  57                   push edi
// 004efed5  a188518b00           mov eax, dword ptr [0x8b5188]
// 004efeda  33c4                 xor eax, esp
// 004efedc  50                   push eax
// 004efedd  8d442420             lea eax, [esp + 0x20]
// 004efee1  64a300000000         mov dword ptr fs:[0], eax
// 004efee7  8b5c2438             mov ebx, dword ptr [esp + 0x38]
// 004efeeb  8b2decd27700         mov ebp, dword ptr [0x77d2ec]
// 004efef1  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 004efef5  8b742430             mov esi, dword ptr [esp + 0x30]
// 004efef9  8da42400000000       lea esp, [esp]
// 004eff00  85ff                 test edi, edi
// 004eff02  7620                 jbe 0x4eff24
// 004eff04  85f6                 test esi, esi
// 004eff06  7414                 je 0x4eff1c
// 004eff08  c70600000000         mov dword ptr [esi], 0
// 004eff0e  8b03                 mov eax, dword ptr [ebx]
// 004eff10  85c0                 test eax, eax
// 004eff12  7408                 je 0x4eff1c
// 004eff14  8906                 mov dword ptr [esi], eax
// 004eff16  83c004               add eax, 4
// 004eff19  50                   push eax
// 004eff1a  ffd5                 call ebp
// 004eff1c  83ef01               sub edi, 1
// 004eff1f  83c604               add esi, 4
// 004eff22  ebdc                 jmp 0x4eff00
// 004eff24  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 004eff28  64890d00000000       mov dword ptr fs:[0], ecx
// 004eff2f  59                   pop ecx
// 004eff30  5f                   pop edi
// 004eff31  5e                   pop esi
// 004eff32  5d                   pop ebp
// 004eff33  5b                   pop ebx
// 004eff34  83c418               add esp, 0x18
// 004eff37  c3                   ret 

#include <vector>
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

namespace G3D {
typedef unsigned int uint32;

class AtomicInt32 {
    volatile long _value;
public:
    inline AtomicInt32() {}
    inline AtomicInt32(const int x) { _value = x; }
    inline void increment() { InterlockedIncrement(&_value); }
    inline uint32 decrement() { return InterlockedDecrement(&_value) != 0; }
};

class _WeakPtr {
public:
    inline virtual ~_WeakPtr() {}
protected:
    friend class ReferenceCountedObject;
    virtual void objectCollected() = 0;
};

class _WeakPtrLinkedList {
public:
    _WeakPtr* weakPtr;
    _WeakPtrLinkedList* next;
    inline _WeakPtrLinkedList() : weakPtr(0), next(0) {}
    inline _WeakPtrLinkedList(_WeakPtr* p, _WeakPtrLinkedList* n) : weakPtr(p), next(n) {}
};

class ReferenceCountedObject {
public:
    AtomicInt32 ReferenceCountedObject_refCount;
    _WeakPtrLinkedList* ReferenceCountedObject_weakPointer;
protected:
    ReferenceCountedObject() : ReferenceCountedObject_refCount(0), ReferenceCountedObject_weakPointer(0) {}
public:
    void ReferenceCountedObject_zeroWeakPointers();
    virtual ~ReferenceCountedObject() {}
};

template <class T>
class ReferenceCountedPointer {
private:
    T* m_pointer;
public:
    inline T* getPointer() const { return m_pointer; }
private:
    void zeroPointer() {
        if (m_pointer != 0) {
            if (m_pointer->ReferenceCountedObject_refCount.decrement() == 0) {
                m_pointer->ReferenceCountedObject_zeroWeakPointers();
                delete m_pointer;
            }
            m_pointer = 0;
        }
    }
    void setPointer(T* x) {
        if (x != m_pointer) {
            zeroPointer();
            if (x != 0) {
                m_pointer = x;
                m_pointer->ReferenceCountedObject_refCount.increment();
            }
        }
    }
public:
    inline ReferenceCountedPointer() : m_pointer(0) {}
    inline ReferenceCountedPointer(const ReferenceCountedPointer<T>& p) : m_pointer(0) { setPointer(p.m_pointer); }
    inline ReferenceCountedPointer(T* p) : m_pointer(0) { setPointer(p); }
    inline ~ReferenceCountedPointer() { zeroPointer(); }
    inline bool notNull() const { return m_pointer != 0; }
};

template <class T>
class WeakReferenceCountedPointer : public _WeakPtr {
private:
    T* pointer;
public:
    ReferenceCountedPointer<T> createStrongPtr() const { return ReferenceCountedPointer<T>(pointer); }
private:
    void setPointer(T* p) {
        zeroPointer();
        pointer = p;
        if (pointer != 0) {
            _WeakPtrLinkedList* head = new _WeakPtrLinkedList(this, pointer->ReferenceCountedObject_weakPointer);
            pointer->ReferenceCountedObject_weakPointer = head;
        } else {
        }
    }
    void zeroPointer();
public:
    WeakReferenceCountedPointer() : pointer(0) {}
    WeakReferenceCountedPointer(const ReferenceCountedPointer<T>& strongPtr) : pointer(0) {
        setPointer(strongPtr.getPointer());
    }
    ~WeakReferenceCountedPointer() { zeroPointer(); }
protected:
    virtual void objectCollected() { pointer = 0; }
};
}

namespace RBX { namespace Render {
class VChunk : public G3D::ReferenceCountedObject {};
}}
typedef G3D::ReferenceCountedPointer<RBX::Render::VChunk> VChunkRef;
void fillChunks(VChunkRef* p, size_t n, const VChunkRef& v, std::allocator<VChunkRef>& al)
{
    stdext::unchecked_uninitialized_fill_n(p, n, v, al);
}
