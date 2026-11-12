// from server: 100% by EspClaude
// from server: 47% by colin
// roc 2007-08 004ef790  unit: RBX::Render::VMaterial::?$WeakReferenceCountedPointer  size: 175 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004ef790
//
// 004ef790  6aff                 push -1
// 004ef792  6878d37400           push 0x74d378
// 004ef797  64a100000000         mov eax, dword ptr fs:[0]
// 004ef79d  50                   push eax
// 004ef79e  51                   push ecx
// 004ef79f  56                   push esi
// 004ef7a0  57                   push edi
// 004ef7a1  a188518b00           mov eax, dword ptr [0x8b5188]
// 004ef7a6  33c4                 xor eax, esp
// 004ef7a8  50                   push eax
// 004ef7a9  8d442410             lea eax, [esp + 0x10]
// 004ef7ad  64a300000000         mov dword ptr fs:[0], eax
// 004ef7b3  8bf1                 mov esi, ecx
// 004ef7b5  8974240c             mov dword ptr [esp + 0xc], esi
// 004ef7b9  8b460c               mov eax, dword ptr [esi + 0xc]
// 004ef7bc  85c0                 test eax, eax
// 004ef7be  8b3de8d27700         mov edi, dword ptr [0x77d2e8]
// 004ef7c4  c744241800000000     mov dword ptr [esp + 0x18], 0
// 004ef7cc  7428                 je 0x4ef7f6
// 004ef7ce  83c004               add eax, 4
// 004ef7d1  50                   push eax
// 004ef7d2  ffd7                 call edi
// 004ef7d4  85c0                 test eax, eax
// 004ef7d6  7517                 jne 0x4ef7ef
// 004ef7d8  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 004ef7db  e8f085f6ff           call 0x457dd0
// 004ef7e0  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 004ef7e3  85c9                 test ecx, ecx
// 004ef7e5  7408                 je 0x4ef7ef
// 004ef7e7  8b01                 mov eax, dword ptr [ecx]
// 004ef7e9  8b10                 mov edx, dword ptr [eax]
// 004ef7eb  6a01                 push 1
// 004ef7ed  ffd2                 call edx
// 004ef7ef  c7460c00000000       mov dword ptr [esi + 0xc], 0
// 004ef7f6  8b4608               mov eax, dword ptr [esi + 8]
// 004ef7f9  85c0                 test eax, eax
// 004ef7fb  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 004ef803  7428                 je 0x4ef82d
// 004ef805  83c004               add eax, 4
// 004ef808  50                   push eax
// 004ef809  ffd7                 call edi
// 004ef80b  85c0                 test eax, eax
// 004ef80d  7517                 jne 0x4ef826
// 004ef80f  8b4e08               mov ecx, dword ptr [esi + 8]
// 004ef812  e8b985f6ff           call 0x457dd0
// 004ef817  8b4e08               mov ecx, dword ptr [esi + 8]
// 004ef81a  85c9                 test ecx, ecx
// 004ef81c  7408                 je 0x4ef826
// 004ef81e  8b01                 mov eax, dword ptr [ecx]
// 004ef820  8b10                 mov edx, dword ptr [eax]
// 004ef822  6a01                 push 1
// 004ef824  ffd2                 call edx
// 004ef826  c7460800000000       mov dword ptr [esi + 8], 0
// 004ef82d  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004ef831  64890d00000000       mov dword ptr fs:[0], ecx
// 004ef838  59                   pop ecx
// 004ef839  5f                   pop edi
// 004ef83a  5e                   pop esi
// 004ef83b  83c410               add esp, 0x10
// 004ef83e  c3                   ret 
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
class VMaterialItem : public G3D::ReferenceCountedObject {};
struct VMaterialHolder {
    int a0;
    int a4;
    G3D::ReferenceCountedPointer<VMaterialItem> m8;
    G3D::ReferenceCountedPointer<VMaterialItem> mC;
    ~VMaterialHolder();
};
VMaterialHolder::~VMaterialHolder()
{
}
}}
