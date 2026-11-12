// from server: 100% by EspClaude
// from server: 46% by colin
// roc 2007-08 004efd40  unit: RBX::Render::VChunk::?$WeakReferenceCountedPointer  size: 137 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004efd40
//
// 004efd40  6aff                 push -1
// 004efd42  6818d47400           push 0x74d418
// 004efd47  64a100000000         mov eax, dword ptr fs:[0]
// 004efd4d  50                   push eax
// 004efd4e  51                   push ecx
// 004efd4f  56                   push esi
// 004efd50  57                   push edi
// 004efd51  a188518b00           mov eax, dword ptr [0x8b5188]
// 004efd56  33c4                 xor eax, esp
// 004efd58  50                   push eax
// 004efd59  8d442410             lea eax, [esp + 0x10]
// 004efd5d  64a300000000         mov dword ptr fs:[0], eax
// 004efd63  8bf1                 mov esi, ecx
// 004efd65  8974240c             mov dword ptr [esp + 0xc], esi
// 004efd69  8b442420             mov eax, dword ptr [esp + 0x20]
// 004efd6d  c7063cf57900         mov dword ptr [esi], 0x79f53c
// 004efd73  c7460400000000       mov dword ptr [esi + 4], 0
// 004efd7a  8b38                 mov edi, dword ptr [eax]
// 004efd7c  c744241800000000     mov dword ptr [esp + 0x18], 0
// 004efd84  e807dbfdff           call 0x4cd890
// 004efd89  85ff                 test edi, edi
// 004efd8b  897e04               mov dword ptr [esi + 4], edi
// 004efd8e  7423                 je 0x4efdb3
// 004efd90  6a08                 push 8
// 004efd92  e85f011400           call 0x62fef6
// 004efd97  83c404               add esp, 4
// 004efd9a  85c0                 test eax, eax
// 004efd9c  740d                 je 0x4efdab
// 004efd9e  8b4e04               mov ecx, dword ptr [esi + 4]
// 004efda1  8b4908               mov ecx, dword ptr [ecx + 8]
// 004efda4  8930                 mov dword ptr [eax], esi
// 004efda6  894804               mov dword ptr [eax + 4], ecx
// 004efda9  eb02                 jmp 0x4efdad
// 004efdab  33c0                 xor eax, eax
// 004efdad  8b5604               mov edx, dword ptr [esi + 4]
// 004efdb0  894208               mov dword ptr [edx + 8], eax
// 004efdb3  8bc6                 mov eax, esi
// 004efdb5  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004efdb9  64890d00000000       mov dword ptr fs:[0], ecx
// 004efdc0  59                   pop ecx
// 004efdc1  5f                   pop edi
// 004efdc2  5e                   pop esi
// 004efdc3  83c410               add esp, 0x10
// 004efdc6  c20400               ret 4
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
template G3D::WeakReferenceCountedPointer<RBX::Render::VChunk>::WeakReferenceCountedPointer(const G3D::ReferenceCountedPointer<RBX::Render::VChunk>&);
