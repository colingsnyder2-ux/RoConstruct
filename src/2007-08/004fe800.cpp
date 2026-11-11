// from server: 100% by EspClaude
// from server: 82% by EspClaude
// roc 2007-08 004fe800  unit: RBX::Render::AggregateChunk  size: 973 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004fe800
//
// 004fe800  6aff                 push -1
// 004fe802  689ae97400           push 0x74e99a
// 004fe807  64a100000000         mov eax, dword ptr fs:[0]
// 004fe80d  50                   push eax
// 004fe80e  81ec04010000         sub esp, 0x104
// 004fe814  53                   push ebx
// 004fe815  55                   push ebp
// 004fe816  56                   push esi
// 004fe817  57                   push edi
// 004fe818  a188518b00           mov eax, dword ptr [0x8b5188]
// 004fe81d  33c4                 xor eax, esp
// 004fe81f  50                   push eax
// 004fe820  8d842418010000       lea eax, [esp + 0x118]
// 004fe827  64a300000000         mov dword ptr fs:[0], eax
// 004fe82d  8be9                 mov ebp, ecx
// 004fe82f  8bbc243c010000       mov edi, dword ptr [esp + 0x13c]
// 004fe836  33c0                 xor eax, eax
// 004fe838  89442418             mov dword ptr [esp + 0x18], eax
// 004fe83c  89842420010000       mov dword ptr [esp + 0x120], eax
// 004fe843  8b07                 mov eax, dword ptr [edi]
// 004fe845  8b7044               mov esi, dword ptr [eax + 0x44]
// 004fe848  8b4050               mov eax, dword ptr [eax + 0x50]
// 004fe84b  83f808               cmp eax, 8
// 004fe84e  bb08000000           mov ebx, 8
// 004fe853  7d02                 jge 0x4fe857
// 004fe855  8bd8                 mov ebx, eax
// 004fe857  68310d0000           push 0xd31
// 004fe85c  e82f1cf8ff           call 0x480490
// 004fe861  83e803               sub eax, 3
// 004fe864  83c404               add esp, 4
// 004fe867  3bf0                 cmp esi, eax
// 004fe869  7d02                 jge 0x4fe86d
// 004fe86b  8bc6                 mov eax, esi
// 004fe86d  d9e8                 fld1 
// 004fe86f  33c9                 xor ecx, ecx
// 004fe871  85c0                 test eax, eax
// 004fe873  d95d0c               fstp dword ptr [ebp + 0xc]
// 004fe876  d9ee                 fldz 
// 004fe878  0f9ec1               setle cl
// 004fe87b  d95d10               fstp dword ptr [ebp + 0x10]
// 004fe87e  c6450300             mov byte ptr [ebp + 3], 0
// 004fe882  c6450101             mov byte ptr [ebp + 1], 1
// 004fe886  c6450000             mov byte ptr [ebp], 0
// 004fe88a  c6450200             mov byte ptr [ebp + 2], 0
// 004fe88e  c6450400             mov byte ptr [ebp + 4], 0
// 004fe892  c6450500             mov byte ptr [ebp + 5], 0
// 004fe896  83e901               sub ecx, 1
// 004fe899  23c8                 and ecx, eax
// 004fe89b  c6450600             mov byte ptr [ebp + 6], 0
// 004fe89f  f60508d18b0001       test byte ptr [0x8bd108], 1
// 004fe8a6  894c2414             mov dword ptr [esp + 0x14], ecx
// 004fe8aa  7515                 jne 0x4fe8c1
// 004fe8ac  8b1564e57700         mov edx, dword ptr [0x77e564]
// 004fe8b2  830d08d18b0001       or dword ptr [0x8bd108], 1
// 004fe8b9  dd02                 fld qword ptr [edx]
// 004fe8bb  dd1d00d18b00         fstp qword ptr [0x8bd100]
// 004fe8c1  dd0500d18b00         fld qword ptr [0x8bd100]
// 004fe8c7  8bb42428010000       mov esi, dword ptr [esp + 0x128]
// 004fe8ce  d9e0                 fchs 
// 004fe8d0  56                   push esi
// 004fe8d1  d95d08               fstp dword ptr [ebp + 8]
// 004fe8d4  e8c7a6ffff           call 0x4f8fa0
// 004fe8d9  83c404               add esp, 4
// 004fe8dc  8b07                 mov eax, dword ptr [edi]
// 004fe8de  8b0e                 mov ecx, dword ptr [esi]
// 004fe8e0  50                   push eax
// 004fe8e1  c784242401000000000000 mov dword ptr [esp + 0x124], 0
// 004fe8ec  c744241c01000000     mov dword ptr [esp + 0x1c], 1
// 004fe8f4  e877fbffff           call 0x4fe470
// 004fe8f9  68570d0000           push 0xd57
// 004fe8fe  e88d1bf8ff           call 0x480490
// 004fe903  d90568647900         fld dword ptr [0x796468]
// 004fe909  d9842430010000       fld dword ptr [esp + 0x130]
// 004fe910  83c404               add esp, 4
// 004fe913  d8d1                 fcom st(1)
// 004fe915  dfe0                 fnstsw ax
// 004fe917  ddd9                 fstp st(1)
// 004fe919  f6c401               test ah, 1
// 004fe91c  7504                 jne 0x4fe922
// 004fe91e  c6450301             mov byte ptr [ebp + 3], 1
// 004fe922  d9842430010000       fld dword ptr [esp + 0x130]
// 004fe929  dc35e8fe7800         fdiv qword ptr [0x78fee8]
// 004fe92f  d95c241c             fstp dword ptr [esp + 0x1c]
// 004fe933  d9e8                 fld1 
// 004fe935  d9c0                 fld st(0)
// 004fe937  d9ee                 fldz 
// 004fe939  dce9                 fsub st(1), st(0)
// 004fe93b  d944241c             fld dword ptr [esp + 0x1c]
// 004fe93f  d9c0                 fld st(0)
// 004fe941  decb                 fmulp st(3)
// 004fe943  d9ca                 fxch st(2)
// 004fe945  dec1                 faddp st(1)
// 004fe947  d95d0c               fstp dword ptr [ebp + 0xc]
// 004fe94a  d9ca                 fxch st(2)
// 004fe94c  dc1d78b37900         fcomp qword ptr [0x79b378]
// 004fe952  dfe0                 fnstsw ax
// 004fe954  f6c401               test ah, 1
// 004fe957  7504                 jne 0x4fe95d
// 004fe959  c6450501             mov byte ptr [ebp + 5], 1
// 004fe95d  80bc243401000000     cmp byte ptr [esp + 0x134], 0
// 004fe965  d9c9                 fxch st(1)
// 004fe967  dcc0                 fadd st(0), st(0)
// 004fe969  dee1                 fsubrp st(1)
// 004fe96b  d95d10               fstp dword ptr [ebp + 0x10]
// 004fe96e  7418                 je 0x4fe988
// 004fe970  85db                 test ebx, ebx
// 004fe972  7e14                 jle 0x4fe988
// 004fe974  837c241400           cmp dword ptr [esp + 0x14], 0
// 004fe979  c6450001             mov byte ptr [ebp], 1
// 004fe97d  bb01000000           mov ebx, 1
// 004fe982  7504                 jne 0x4fe988
// 004fe984  c6450100             mov byte ptr [ebp + 1], 0
// 004fe988  8b06                 mov eax, dword ptr [esi]
// 004fe98a  8b784c               mov edi, dword ptr [eax + 0x4c]
// 004fe98d  8b4050               mov eax, dword ptr [eax + 0x50]
// 004fe990  8d0c80               lea ecx, [eax + eax*4]
// 004fe993  c1e104               shl ecx, 4
// 004fe996  03cf                 add ecx, edi
// 004fe998  8bd1                 mov edx, ecx
// 004fe99a  2bd7                 sub edx, edi
// 004fe99c  b867666666           mov eax, 0x66666667
// 004fe9a1  f7ea                 imul edx
// 004fe9a3  c1fa05               sar edx, 5
// 004fe9a6  8bc2                 mov eax, edx
// 004fe9a8  c1e81f               shr eax, 0x1f
// 004fe9ab  6890d34f00           push 0x4fd390
// 004fe9b0  03c2                 add eax, edx
// 004fe9b2  50                   push eax
// 004fe9b3  51                   push ecx
// 004fe9b4  57                   push edi
// 004fe9b5  e8f6fcffff           call 0x4fe6b0
// 004fe9ba  8b06                 mov eax, dword ptr [esi]
// 004fe9bc  8b7850               mov edi, dword ptr [eax + 0x50]
// 004fe9bf  2bfb                 sub edi, ebx
// 004fe9c1  83c410               add esp, 0x10
// 004fe9c4  85ff                 test edi, edi
// 004fe9c6  7e3c                 jle 0x4fea04
// 004fe9c8  33db                 xor ebx, ebx
// 004fe9ca  85ff                 test edi, edi
// 004fe9cc  7e24                 jle 0x4fe9f2
// 004fe9ce  8bff                 mov edi, edi
// 004fe9d0  8b0e                 mov ecx, dword ptr [esi]
// 004fe9d2  8b4150               mov eax, dword ptr [ecx + 0x50]
// 004fe9d5  2bc7                 sub eax, edi
// 004fe9d7  03c3                 add eax, ebx
// 004fe9d9  8d1480               lea edx, [eax + eax*4]
// 004fe9dc  c1e204               shl edx, 4
// 004fe9df  03514c               add edx, dword ptr [ecx + 0x4c]
// 004fe9e2  83c140               add ecx, 0x40
// 004fe9e5  52                   push edx
// 004fe9e6  e8d59bffff           call 0x4f85c0
// 004fe9eb  83c301               add ebx, 1
// 004fe9ee  3bdf                 cmp ebx, edi
// 004fe9f0  7cde                 jl 0x4fe9d0
// 004fe9f2  8b0e                 mov ecx, dword ptr [esi]
// 004fe9f4  8b4150               mov eax, dword ptr [ecx + 0x50]
// 004fe9f7  6a01                 push 1
// 004fe9f9  2bc7                 sub eax, edi
// 004fe9fb  50                   push eax
// 004fe9fc  83c14c               add ecx, 0x4c
// 004fe9ff  e8cc93ffff           call 0x4f7dd0
// 004fea04  8b06                 mov eax, dword ptr [esi]
// 004fea06  8b7840               mov edi, dword ptr [eax + 0x40]
// 004fea09  8b4044               mov eax, dword ptr [eax + 0x44]
// 004fea0c  8d0c80               lea ecx, [eax + eax*4]
// 004fea0f  c1e104               shl ecx, 4
// 004fea12  03cf                 add ecx, edi
// 004fea14  8bd1                 mov edx, ecx
// 004fea16  2bd7                 sub edx, edi
// 004fea18  b867666666           mov eax, 0x66666667
// 004fea1d  f7ea                 imul edx
// 004fea1f  c1fa05               sar edx, 5
// 004fea22  8bc2                 mov eax, edx
// 004fea24  c1e81f               shr eax, 0x1f
// 004fea27  6890d34f00           push 0x4fd390
// 004fea2c  03c2                 add eax, edx
// 004fea2e  50                   push eax
// 004fea2f  51                   push ecx
// 004fea30  57                   push edi
// 004fea31  e87afcffff           call 0x4fe6b0
// 004fea36  8b0e                 mov ecx, dword ptr [esi]
// 004fea38  8b4144               mov eax, dword ptr [ecx + 0x44]
// 004fea3b  2b442424             sub eax, dword ptr [esp + 0x24]
// 004fea3f  83c410               add esp, 0x10
// 004fea42  85c0                 test eax, eax
// 004fea44  7e10                 jle 0x4fea56
// 004fea46  8b5144               mov edx, dword ptr [ecx + 0x44]
// 004fea49  6a01                 push 1
// 004fea4b  2bd0                 sub edx, eax
// 004fea4d  52                   push edx
// 004fea4e  83c140               add ecx, 0x40
// 004fea51  e87a93ffff           call 0x4f7dd0
// 004fea56  807d0000             cmp byte ptr [ebp], 0
// 004fea5a  0f94c1               sete cl
// 004fea5d  884d02               mov byte ptr [ebp + 2], cl
// 004fea60  8b0e                 mov ecx, dword ptr [esi]
// 004fea62  8b4944               mov ecx, dword ptr [ecx + 0x44]
// 004fea65  33c0                 xor eax, eax
// 004fea67  85c9                 test ecx, ecx
// 004fea69  7e12                 jle 0x4fea7d
// 004fea6b  33d2                 xor edx, edx
// 004fea6d  8d4900               lea ecx, [ecx]
// 004fea70  8b0e                 mov ecx, dword ptr [esi]
// 004fea72  83c001               add eax, 1
// 004fea75  83c250               add edx, 0x50
// 004fea78  3b4144               cmp eax, dword ptr [ecx + 0x44]
// 004fea7b  7cf3                 jl 0x4fea70
// 004fea7d  8b0e                 mov ecx, dword ptr [esi]
// 004fea7f  33c0                 xor eax, eax
// 004fea81  394150               cmp dword ptr [ecx + 0x50], eax
// 004fea84  7e0f                 jle 0x4fea95
// 004fea86  33d2                 xor edx, edx
// 004fea88  8b0e                 mov ecx, dword ptr [esi]
// 004fea8a  83c001               add eax, 1
// 004fea8d  83c250               add edx, 0x50
// 004fea90  3b4150               cmp eax, dword ptr [ecx + 0x50]
// 004fea93  7cf3                 jl 0x4fea88
// 004fea95  807d0400             cmp byte ptr [ebp + 4], 0
// 004fea99  0f84fc000000         je 0x4feb9b
// 004fea9f  6a01                 push 1
// 004feaa1  e8eafaffff           call 0x4fe590
// 004feaa6  8bc8                 mov ecx, eax
// 004feaa8  e8a31c2300           call 0x730750
// 004feaad  8d542414             lea edx, [esp + 0x14]
// 004feab1  56                   push esi
// 004feab2  52                   push edx
// 004feab3  e8d8faffff           call 0x4fe590
// 004feab8  8bc8                 mov ecx, eax
// 004feaba  e8512c2300           call 0x731710
// 004feabf  8b18                 mov ebx, dword ptr [eax]
// 004feac1  8b06                 mov eax, dword ptr [esi]
// 004feac3  3bd8                 cmp ebx, eax
// 004feac5  8b2de8d27700         mov ebp, dword ptr [0x77d2e8]
// 004feacb  c784242001000001000000 mov dword ptr [esp + 0x120], 1
// 004fead6  7457                 je 0x4feb2f
// 004fead8  85c0                 test eax, eax
// 004feada  7443                 je 0x4feb1f
// 004feadc  83c004               add eax, 4
// 004feadf  50                   push eax
// 004feae0  ffd5                 call ebp
// 004feae2  85c0                 test eax, eax
// 004feae4  7533                 jne 0x4feb19
// 004feae6  8b06                 mov eax, dword ptr [esi]
// 004feae8  8b7808               mov edi, dword ptr [eax + 8]
// 004feaeb  85ff                 test edi, edi
// 004feaed  741c                 je 0x4feb0b
// 004feaef  90                   nop 
// 004feaf0  8b0f                 mov ecx, dword ptr [edi]
// 004feaf2  8b01                 mov eax, dword ptr [ecx]
// 004feaf4  8b5004               mov edx, dword ptr [eax + 4]
// 004feaf7  ffd2                 call edx
// 004feaf9  8bc7                 mov eax, edi
// 004feafb  8b7f04               mov edi, dword ptr [edi + 4]
// 004feafe  50                   push eax
// 004feaff  e85e111300           call 0x62fc62
// 004feb04  83c404               add esp, 4
// 004feb07  85ff                 test edi, edi
// 004feb09  75e5                 jne 0x4feaf0
// 004feb0b  8b0e                 mov ecx, dword ptr [esi]
// 004feb0d  85c9                 test ecx, ecx
// 004feb0f  7408                 je 0x4feb19
// 004feb11  8b01                 mov eax, dword ptr [ecx]
// 004feb13  8b10                 mov edx, dword ptr [eax]
// 004feb15  6a01                 push 1
// 004feb17  ffd2                 call edx
// 004feb19  c70600000000         mov dword ptr [esi], 0
// 004feb1f  85db                 test ebx, ebx
// 004feb21  740c                 je 0x4feb2f
// 004feb23  891e                 mov dword ptr [esi], ebx
// 004feb25  83c304               add ebx, 4
// 004feb28  53                   push ebx
// 004feb29  ff15ecd27700         call dword ptr [0x77d2ec]
// 004feb2f  8b442414             mov eax, dword ptr [esp + 0x14]
// 004feb33  85c0                 test eax, eax
// 004feb35  c684242001000000     mov byte ptr [esp + 0x120], 0
// 004feb3d  7440                 je 0x4feb7f
// 004feb3f  83c004               add eax, 4
// 004feb42  50                   push eax
// 004feb43  ffd5                 call ebp
// 004feb45  85c0                 test eax, eax
// 004feb47  7536                 jne 0x4feb7f
// 004feb49  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004feb4d  8b7908               mov edi, dword ptr [ecx + 8]
// 004feb50  85ff                 test edi, edi
// 004feb52  741f                 je 0x4feb73
// 004feb54  8b0f                 mov ecx, dword ptr [edi]
// 004feb56  8b01                 mov eax, dword ptr [ecx]
// 004feb58  8b5004               mov edx, dword ptr [eax + 4]
// 004feb5b  ffd2                 call edx
// 004feb5d  8bc7                 mov eax, edi
// 004feb5f  8b7f04               mov edi, dword ptr [edi + 4]
// 004feb62  50                   push eax
// 004feb63  e8fa101300           call 0x62fc62
// 004feb68  83c404               add esp, 4
// 004feb6b  85ff                 test edi, edi
// 004feb6d  75e5                 jne 0x4feb54
// 004feb6f  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004feb73  85c9                 test ecx, ecx
// 004feb75  7408                 je 0x4feb7f
// 004feb77  8b01                 mov eax, dword ptr [ecx]
// 004feb79  8b10                 mov edx, dword ptr [eax]
// 004feb7b  6a01                 push 1
// 004feb7d  ffd2                 call edx
// 004feb7f  8b842440010000       mov eax, dword ptr [esp + 0x140]
// 004feb86  50                   push eax
// 004feb87  8d4c2424             lea ecx, [esp + 0x24]
// 004feb8b  51                   push ecx
// 004feb8c  e8fff9ffff           call 0x4fe590
// 004feb91  8bc8                 mov ecx, eax
// 004feb93  e8b81a2300           call 0x730650
// 004feb98  50                   push eax
// 004feb99  eb08                 jmp 0x4feba3
// 004feb9b  8b942440010000       mov edx, dword ptr [esp + 0x140]
// 004feba2  52                   push edx
// 004feba3  8b8c2448010000       mov ecx, dword ptr [esp + 0x148]
// 004febaa  e8b18affff           call 0x4f7660
// 004febaf  8bc6                 mov eax, esi
// 004febb1  8b8c2418010000       mov ecx, dword ptr [esp + 0x118]
// 004febb8  64890d00000000       mov dword ptr fs:[0], ecx
// 004febbf  59                   pop ecx
// 004febc0  5f                   pop edi
// 004febc1  5e                   pop esi
// 004febc2  5d                   pop ebp
// 004febc3  5b                   pop ebx
// 004febc4  81c410010000         add esp, 0x110
// 004febca  c22000               ret 0x20

// from server: 100% by king_originala
// roc-lang: cpp
// roc-cl: 50727
// Native G3D 6.09 interface view; unrelated methods omitted.
#include <algorithm>
#include <limits>
#include <intrin.h>
#include <stddef.h>
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
namespace G3D {
class AtomicInt32 {
 volatile long _value;
public:
 AtomicInt32(int x):_value(x){}
 void increment(){InterlockedIncrement(&_value);}
 unsigned int decrement(){return InterlockedDecrement(&_value)!=0;}
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
    _WeakPtr*                   weakPtr;
    _WeakPtrLinkedList*         next;
    inline _WeakPtrLinkedList() : weakPtr(0), next(0) {}
    inline _WeakPtrLinkedList(_WeakPtr* p, _WeakPtrLinkedList* n) : weakPtr(p), next(n) {}
};
class ReferenceCountedObject {
public:
    AtomicInt32                 ReferenceCountedObject_refCount;
    _WeakPtrLinkedList*         ReferenceCountedObject_weakPointer;
protected:
    ReferenceCountedObject() : 
        ReferenceCountedObject_refCount(0), 
        ReferenceCountedObject_weakPointer(0) {
        do {} while (0);
    }
public:
    void ReferenceCountedObject_zeroWeakPointers() {
        _WeakPtrLinkedList* node = ReferenceCountedObject_weakPointer;
        while (node != 0) {
            node->weakPtr->objectCollected();
            _WeakPtrLinkedList* tmp = node;
            node = node->next;
            delete tmp;
        }
    }
    virtual ~ReferenceCountedObject() {}
    ReferenceCountedObject(const ReferenceCountedObject& notUsed) : 
        ReferenceCountedObject_refCount(0),
        ReferenceCountedObject_weakPointer(0) {
        (void)notUsed;
        do {} while (0);
    }
    ReferenceCountedObject& operator=(const ReferenceCountedObject& other) {
        (void)other;
        return *this;
    }
};
template <class T>
class ReferenceCountedPointer {
private:
    T*           m_pointer;
public:
	typedef T element_type;
    inline T* pointer() const {
        return m_pointer;
    }
    inline T* getPointer() const {
        return m_pointer;
    }
private:
    void zeroPointer() {
        if (m_pointer != 0) {
            do {} while (0);
            do {} while (0);
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
                do {} while (0);
		        m_pointer = x;
                do {} while (0);
                m_pointer->ReferenceCountedObject_refCount.increment();
            }
        }
    }
public:      
    inline ReferenceCountedPointer() : m_pointer(0) {}
    template <class S>
    inline ReferenceCountedPointer(const ReferenceCountedPointer<S>& p) : 
        m_pointer(0) {
        setPointer(p.getPointer());
    }
    template <class S>
    ReferenceCountedPointer<S> downcast() {
        return ReferenceCountedPointer<S>(dynamic_cast<S*>(m_pointer));
    }
    inline ReferenceCountedPointer(const ReferenceCountedPointer<T>& p) : m_pointer(0) {
        setPointer(p.m_pointer);
    }
    inline ReferenceCountedPointer(T* p) : m_pointer(0) { 
        setPointer(p); 
    }
    inline ~ReferenceCountedPointer() {
        zeroPointer();
    }
    inline const ReferenceCountedPointer<T>& operator=(const ReferenceCountedPointer<T>& p) {
        setPointer(p.m_pointer);
        return *this;
    }   
    inline ReferenceCountedPointer<T>& operator=(T* p) {
        setPointer(p);
        return *this;
    }
    inline bool operator==(const ReferenceCountedPointer<T>& y) const { 
        return (m_pointer == y.m_pointer); 
    }
    inline bool operator!=(const ReferenceCountedPointer<T>& y) const { 
        return (m_pointer != y.m_pointer); 
    }
	bool operator < (const ReferenceCountedPointer<T>& y) const {
        return (m_pointer < y.m_pointer); 
	}
	bool operator > (const ReferenceCountedPointer<T>& y) const {
        return (m_pointer > y.m_pointer); 
	}
	bool operator <= (const ReferenceCountedPointer<T>& y) const {
        return (m_pointer <= y.m_pointer); 
	}
	bool operator >= (const ReferenceCountedPointer<T>& y) const {
        return (m_pointer >= y.m_pointer); 
	}
    inline T& operator*() const {
        do {} while (0);
        return (*m_pointer);
    }
    inline T* operator->() const {
        return m_pointer;
    }
    inline bool isNull() const {
        return (m_pointer == 0);
    }
    inline bool notNull() const {
        return (m_pointer != 0);
    }
    inline int isLastReference() const {
        return (m_pointer->ReferenceCountedObject_refCount.value() == 1);
    }
};

class Vector3 { public: float x,y,z; };
class Vector4 { public: float x,y,z,w; };
class Matrix3 { public:float elt[3][3]; };
class CoordinateFrame { public:Matrix3 rotation;Vector3 translation; };
class Color3 { public:float r,g,b;
 Color3& operator*=(float fScalar){r*=fScalar;g*=fScalar;b*=fScalar;return *this;}
};
class Texture;
typedef ReferenceCountedPointer<Texture> TextureRef;
class GLight  {
public:
    Vector4             position;
    Vector3             spotDirection;
    double              spotCutoff;
    double              attenuation[3];
    Color3              color;
    bool                enabled;
    bool                specular;
    bool                diffuse;
    GLight();
    static GLight directional(const Vector3& toLight, const Color3& color, bool specular = true, bool diffuse = true);
    static GLight point(const Vector3& pos, const Color3& color, double constAtt = 1, double linAtt = 0, double quadAtt = 0, bool specular = true, bool diffuse = true);
    static GLight spot(const Vector3& pos, const Vector3& pointDirection, double cutOffAngleDegrees, const Color3& color, double constAtt = 1, double linAtt = 0, double quadAtt = 0, bool specular = true, bool diffuse = true);
    bool operator==(const GLight& other) const;
    bool operator!=(const GLight& other) const;
};

template<class T> class Array {
 T* data;int num,numAllocated;
public:
 int size()const{return num;}
 T& operator[](int n){return data[n];}
 const T& operator[](int n)const{return data[n];}
 void sort(bool (__cdecl *lessThan)(const T&,const T&)){std::sort(data,data+num,lessThan);}
 void append(const T&);
 void resize(int,bool);
 ~Array();
 Array&operator=(const Array&);
};
class LightingParameters { public: LightingParameters& operator=(const LightingParameters&);
public:
    Color3                  emissiveScale;
    Color3                  skyAmbient;
    Color3                  diffuseAmbient;
    Color3                  lightColor;
    Color3                  ambient;
    Vector3                 lightDirection;
    enum {SUN, MOON}        source;
    bool                    physicallyCorrect;
    Vector3		            trueSunPosition;
    Vector3                 sunPosition;
    Vector3		            trueMoonPosition;
    Vector3                 moonPosition;
	double			        moonPhase;	
    CoordinateFrame	        starFrame;
	CoordinateFrame		    trueStarFrame;
    Vector3		            starVec;
    float                   geoLatitude;
    LightingParameters();
     LightingParameters(
	     const double     _time,
	     bool 	            _physicallyCorrect = true,
	     float              _latitude = 41.7333f);
    void setTime(const double _time);
	void setLatitude(float _latitude);
    GLight directionalLight() const;
};
class Lighting : public ReferenceCountedObject {
private:
    Lighting();
public:
    Color3              emissiveScale;
    Color3              ambientTop;
    Color3              ambientBottom;
    TextureRef          environmentMap;
    Color3              environmentMapColor;
    Array<GLight>       lightArray;
    Array<GLight>       shadowedLightArray;
    static ReferenceCountedPointer<Lighting> create();
Lighting&operator=(const Lighting&);
};

class ToneMap {public:
 void setEnabled(bool);
 ReferenceCountedPointer<Lighting> prepareLighting(const ReferenceCountedPointer<Lighting>&)const;
 LightingParameters prepareLightingParameters(const LightingParameters&)const;
};
int glGetInteger(unsigned int);
inline float lerp(float a, float b, float f) { return a + (b - a) * f; }
inline const double& inf(){static const double i=std::numeric_limits<double>::infinity();return i;}
}
typedef char glight_size[sizeof(G3D::GLight)==80?1:-1];
typedef char lighting_size[sizeof(G3D::Lighting)==88?1:-1];
typedef char lighting_array_offset[offsetof(G3D::Lighting,lightArray)==0x40?1:-1];
typedef char lighting_parameters_size[sizeof(G3D::LightingParameters)==248?1:-1];
bool brighter(const G3D::GLight& A, const G3D::GLight& B);

namespace RBX {
namespace Render {

class EffectSettings
{
private:
    bool _stencilShadows;
    bool _alphaBlendShadowLights;
    bool _useAllLightsInUnshadowedPass;
    bool _skyBox;
    bool _toneMap;
    bool _hemisphereLighting;
    bool _depthBlur;
    float _farCullZ;
    float _groundLOD;
    float _LODShift;

public:
    static G3D::ToneMap* getToneMap();

    G3D::ReferenceCountedPointer<G3D::Lighting> update(
        float shadingDetail,
        float meshDetail,
        bool shadows,
        float cameraDistanceFromCharacters,
        const G3D::ReferenceCountedPointer<G3D::Lighting>& desiredLighting,
        const G3D::LightingParameters& desiredSkyParameters,
        G3D::LightingParameters& outSkyParameters);
};

G3D::ReferenceCountedPointer<G3D::Lighting> EffectSettings::update(
    float shadingDetail,
    float meshDetail,
    bool shadows,
    float cameraDistanceFromCharacters,
    const G3D::ReferenceCountedPointer<G3D::Lighting>& desiredLighting,
    const G3D::LightingParameters& desiredSkyParameters,
    G3D::LightingParameters& outSkyParameters)
{
    int lightCount = desiredLighting->lightArray.size();
    int shadowLightCount = desiredLighting->shadowedLightArray.size();
    int numShadowLights = shadowLightCount >= 8 ? 8 : shadowLightCount;
    int maxLights = G3D::glGetInteger(0xd31) - 3;
    int numNonShadowLights = lightCount >= maxLights ? maxLights : lightCount;
    numNonShadowLights = numNonShadowLights > 0 ? numNonShadowLights : 0;

    _groundLOD = 1.0f;
    _LODShift = 0.0f;
    _skyBox = false;
    _alphaBlendShadowLights = true;
    _stencilShadows = false;
    _useAllLightsInUnshadowedPass = false;
    _toneMap = false;
    _hemisphereLighting = false;
    _depthBlur = false;
    _farCullZ = -G3D::inf();

    G3D::ReferenceCountedPointer<G3D::Lighting> lighting = G3D::Lighting::create();
    *lighting = *desiredLighting;

    G3D::glGetInteger(0xd57);

    if (shadingDetail >= 10) {
        _skyBox = true;
    }

    float detail = meshDetail / 100.0;
    _groundLOD = G3D::lerp(0.0f, 1.0f, detail);

    if (shadingDetail >= 30.0f) {
        _hemisphereLighting = true;
    }

    _LODShift = G3D::lerp(-1.0f, 1.0f, detail);

    if (shadows && numShadowLights > 0) {
        _stencilShadows = true;
        numShadowLights = 1;

        if (numNonShadowLights == 0) {
            _alphaBlendShadowLights = false;
        }
    }

    lighting->shadowedLightArray.sort(brighter);

    int excessShadowLights = lighting->shadowedLightArray.size() - numShadowLights;

    if (excessShadowLights > 0) {
        for (int i = 0; i < excessShadowLights; i++) {
            lighting->lightArray.append(
                lighting->shadowedLightArray[lighting->shadowedLightArray.size() - excessShadowLights + i]);
        }

        lighting->shadowedLightArray.resize(lighting->shadowedLightArray.size() - excessShadowLights, true);
    }

    lighting->lightArray.sort(brighter);

    int excessLights = lighting->lightArray.size() - numNonShadowLights;

    if (excessLights > 0) {
        lighting->lightArray.resize(lighting->lightArray.size() - excessLights, true);
    }

    _useAllLightsInUnshadowedPass = _stencilShadows == false;

    for (int i = 0; i < lighting->lightArray.size(); i++) {
        G3D::GLight& l = lighting->lightArray[i];
        l.color *= 1.0f;
    }
    for (int i = 0; i < lighting->shadowedLightArray.size(); i++) {
        G3D::GLight& l = lighting->shadowedLightArray[i];
        l.color *= 1.0f;
    }

    if (_toneMap) {
        getToneMap()->setEnabled(true);
        lighting = getToneMap()->prepareLighting(lighting);
        outSkyParameters = getToneMap()->prepareLightingParameters(desiredSkyParameters);
    }
    else {
        outSkyParameters = desiredSkyParameters;
    }

    return lighting;
}

}
}


