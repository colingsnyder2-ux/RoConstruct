// from server: 100% by EspClaude
// from server: 52% by colin
// roc 2007-08 004f9020  unit: G3D::Lighting  size: 514 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004f9020
//
// 004f9020  6aff                 push -1
// 004f9022  687de17400           push 0x74e17d
// 004f9027  64a100000000         mov eax, dword ptr fs:[0]
// 004f902d  50                   push eax
// 004f902e  51                   push ecx
// 004f902f  53                   push ebx
// 004f9030  56                   push esi
// 004f9031  57                   push edi
// 004f9032  a188518b00           mov eax, dword ptr [0x8b5188]
// 004f9037  33c4                 xor eax, esp
// 004f9039  50                   push eax
// 004f903a  8d442414             lea eax, [esp + 0x14]
// 004f903e  64a300000000         mov dword ptr fs:[0], eax
// 004f9044  8bf1                 mov esi, ecx
// 004f9046  89742410             mov dword ptr [esp + 0x10], esi
// 004f904a  8b86ec020000         mov eax, dword ptr [esi + 0x2ec]
// 004f9050  8b3de8d27700         mov edi, dword ptr [0x77d2e8]
// 004f9056  33db                 xor ebx, ebx
// 004f9058  3bc3                 cmp eax, ebx
// 004f905a  c744241c0b000000     mov dword ptr [esp + 0x1c], 0xb
// 004f9062  742d                 je 0x4f9091
// 004f9064  83c004               add eax, 4
// 004f9067  50                   push eax
// 004f9068  ffd7                 call edi
// 004f906a  85c0                 test eax, eax
// 004f906c  751d                 jne 0x4f908b
// 004f906e  8b8eec020000         mov ecx, dword ptr [esi + 0x2ec]
// 004f9074  e857edf5ff           call 0x457dd0
// 004f9079  8b8eec020000         mov ecx, dword ptr [esi + 0x2ec]
// 004f907f  3bcb                 cmp ecx, ebx
// 004f9081  7408                 je 0x4f908b
// 004f9083  8b01                 mov eax, dword ptr [ecx]
// 004f9085  8b10                 mov edx, dword ptr [eax]
// 004f9087  6a01                 push 1
// 004f9089  ffd2                 call edx
// 004f908b  899eec020000         mov dword ptr [esi + 0x2ec], ebx
// 004f9091  8b86a4000000         mov eax, dword ptr [esi + 0xa4]
// 004f9097  50                   push eax
// 004f9098  c64424200a           mov byte ptr [esp + 0x20], 0xa
// 004f909d  e86e670000           call 0x4ff810
// 004f90a2  83c404               add esp, 4
// 004f90a5  8d8e98000000         lea ecx, [esi + 0x98]
// 004f90ab  899ea4000000         mov dword ptr [esi + 0xa4], ebx
// 004f90b1  899ea8000000         mov dword ptr [esi + 0xa8], ebx
// 004f90b7  899eac000000         mov dword ptr [esi + 0xac], ebx
// 004f90bd  c644241c09           mov byte ptr [esp + 0x1c], 9
// 004f90c2  e869bcffff           call 0x4f4d30
// 004f90c7  8b8684000000         mov eax, dword ptr [esi + 0x84]
// 004f90cd  3bc3                 cmp eax, ebx
// 004f90cf  c644241c08           mov byte ptr [esp + 0x1c], 8
// 004f90d4  742d                 je 0x4f9103
// 004f90d6  83c004               add eax, 4
// 004f90d9  50                   push eax
// 004f90da  ffd7                 call edi
// 004f90dc  85c0                 test eax, eax
// 004f90de  751d                 jne 0x4f90fd
// 004f90e0  8b8e84000000         mov ecx, dword ptr [esi + 0x84]
// 004f90e6  e8e5ecf5ff           call 0x457dd0
// 004f90eb  8b8e84000000         mov ecx, dword ptr [esi + 0x84]
// 004f90f1  3bcb                 cmp ecx, ebx
// 004f90f3  7408                 je 0x4f90fd
// 004f90f5  8b11                 mov edx, dword ptr [ecx]
// 004f90f7  8b02                 mov eax, dword ptr [edx]
// 004f90f9  6a01                 push 1
// 004f90fb  ffd0                 call eax
// 004f90fd  899e84000000         mov dword ptr [esi + 0x84], ebx
// 004f9103  8b8680000000         mov eax, dword ptr [esi + 0x80]
// 004f9109  3bc3                 cmp eax, ebx
// 004f910b  c644241c07           mov byte ptr [esp + 0x1c], 7
// 004f9110  742d                 je 0x4f913f
// 004f9112  83c004               add eax, 4
// 004f9115  50                   push eax
// 004f9116  ffd7                 call edi
// 004f9118  85c0                 test eax, eax
// 004f911a  751d                 jne 0x4f9139
// 004f911c  8b8e80000000         mov ecx, dword ptr [esi + 0x80]
// 004f9122  e8a9ecf5ff           call 0x457dd0
// 004f9127  8b8e80000000         mov ecx, dword ptr [esi + 0x80]
// 004f912d  3bcb                 cmp ecx, ebx
// 004f912f  7408                 je 0x4f9139
// 004f9131  8b11                 mov edx, dword ptr [ecx]
// 004f9133  8b02                 mov eax, dword ptr [edx]
// 004f9135  6a01                 push 1
// 004f9137  ffd0                 call eax
// 004f9139  899e80000000         mov dword ptr [esi + 0x80], ebx
// 004f913f  8b4668               mov eax, dword ptr [esi + 0x68]
// 004f9142  3bc3                 cmp eax, ebx
// 004f9144  c644241c06           mov byte ptr [esp + 0x1c], 6
// 004f9149  7424                 je 0x4f916f
// 004f914b  83c004               add eax, 4
// 004f914e  50                   push eax
// 004f914f  ffd7                 call edi
// 004f9151  85c0                 test eax, eax
// 004f9153  7517                 jne 0x4f916c
// 004f9155  8b4e68               mov ecx, dword ptr [esi + 0x68]
// 004f9158  e873ecf5ff           call 0x457dd0
// 004f915d  8b4e68               mov ecx, dword ptr [esi + 0x68]
// 004f9160  3bcb                 cmp ecx, ebx
// 004f9162  7408                 je 0x4f916c
// 004f9164  8b11                 mov edx, dword ptr [ecx]
// 004f9166  8b02                 mov eax, dword ptr [edx]
// 004f9168  6a01                 push 1
// 004f916a  ffd0                 call eax
// 004f916c  895e68               mov dword ptr [esi + 0x68], ebx
// 004f916f  8b4648               mov eax, dword ptr [esi + 0x48]
// 004f9172  3bc3                 cmp eax, ebx
// 004f9174  c644241c05           mov byte ptr [esp + 0x1c], 5
// 004f9179  7424                 je 0x4f919f
// 004f917b  83c004               add eax, 4
// 004f917e  50                   push eax
// 004f917f  ffd7                 call edi
// 004f9181  85c0                 test eax, eax
// 004f9183  7517                 jne 0x4f919c
// 004f9185  8b4e48               mov ecx, dword ptr [esi + 0x48]
// 004f9188  e843ecf5ff           call 0x457dd0
// 004f918d  8b4e48               mov ecx, dword ptr [esi + 0x48]
// 004f9190  3bcb                 cmp ecx, ebx
// 004f9192  7408                 je 0x4f919c
// 004f9194  8b11                 mov edx, dword ptr [ecx]
// 004f9196  8b02                 mov eax, dword ptr [edx]
// 004f9198  6a01                 push 1
// 004f919a  ffd0                 call eax
// 004f919c  895e48               mov dword ptr [esi + 0x48], ebx
// 004f919f  8d4e3c               lea ecx, [esi + 0x3c]
// 004f91a2  c644241c04           mov byte ptr [esp + 0x1c], 4
// 004f91a7  e884bbffff           call 0x4f4d30
// 004f91ac  8d4e30               lea ecx, [esi + 0x30]
// 004f91af  c644241c03           mov byte ptr [esp + 0x1c], 3
// 004f91b4  e887f9ffff           call 0x4f8b40
// 004f91b9  8b4e24               mov ecx, dword ptr [esi + 0x24]
// 004f91bc  51                   push ecx
// 004f91bd  c644242002           mov byte ptr [esp + 0x20], 2
// 004f91c2  e849660000           call 0x4ff810
// 004f91c7  895e24               mov dword ptr [esi + 0x24], ebx
// 004f91ca  895e28               mov dword ptr [esi + 0x28], ebx
// 004f91cd  895e2c               mov dword ptr [esi + 0x2c], ebx
// 004f91d0  8b5618               mov edx, dword ptr [esi + 0x18]
// 004f91d3  52                   push edx
// 004f91d4  c644242401           mov byte ptr [esp + 0x24], 1
// 004f91d9  e832660000           call 0x4ff810
// 004f91de  895e18               mov dword ptr [esi + 0x18], ebx
// 004f91e1  895e1c               mov dword ptr [esi + 0x1c], ebx
// 004f91e4  895e20               mov dword ptr [esi + 0x20], ebx
// 004f91e7  8b460c               mov eax, dword ptr [esi + 0xc]
// 004f91ea  50                   push eax
// 004f91eb  885c2428             mov byte ptr [esp + 0x28], bl
// 004f91ef  e81c660000           call 0x4ff810
// 004f91f4  83c40c               add esp, 0xc
// 004f91f7  8bce                 mov ecx, esi
// 004f91f9  895e0c               mov dword ptr [esi + 0xc], ebx
// 004f91fc  895e10               mov dword ptr [esi + 0x10], ebx
// 004f91ff  895e14               mov dword ptr [esi + 0x14], ebx
// 004f9202  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 004f920a  e831f9ffff           call 0x4f8b40
// 004f920f  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004f9213  64890d00000000       mov dword ptr fs:[0], ecx
// 004f921a  59                   pop ecx
// 004f921b  5f                   pop edi
// 004f921c  5e                   pop esi
// 004f921d  5b                   pop ebx
// 004f921e  83c410               add esp, 0x10
// 004f9221  c3                   ret 

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile *);

namespace G3D {

class ReferenceCountedObject {
public:
    long ReferenceCountedObject_refCount;
    void ReferenceCountedObject_zeroWeakPointers();
    virtual ~ReferenceCountedObject();
};

template <class T>
class ReferenceCountedPointer {
public:
    T *m_pointer;
    void zeroPointer() {
        if (m_pointer != 0) {
            if (InterlockedDecrement(&m_pointer->ReferenceCountedObject_refCount) == 0) {
                m_pointer->ReferenceCountedObject_zeroWeakPointers();
                delete m_pointer;
            }
            m_pointer = 0;
        }
    }
    ~ReferenceCountedPointer() { zeroPointer(); }
};

void freeBlock(void *p);

template <class T>
class Buffer {
public:
    T *first;
    T *last;
    T *end;
    ~Buffer() { freeBlock(first); first = 0; last = 0; end = 0; }
};

class A12 { public: int a, b, c; ~A12(); };
class B12 { public: int a, b, c; ~B12(); };

class Lighting {
public:
    A12 m0;
    Buffer<int> mc;
    Buffer<int> m18;
    Buffer<int> m24;
    A12 m30;
    B12 m3c;
    ReferenceCountedPointer<ReferenceCountedObject> m48;
    int pad4c[7];
    ReferenceCountedPointer<ReferenceCountedObject> m68;
    int pad6c[5];
    ReferenceCountedPointer<ReferenceCountedObject> m80;
    ReferenceCountedPointer<ReferenceCountedObject> m84;
    int pad88[4];
    B12 m98;
    Buffer<int> ma4;
    int padb0[143];
    ReferenceCountedPointer<ReferenceCountedObject> m2ec;
    ~Lighting();
};

Lighting::~Lighting()
{
}

}
