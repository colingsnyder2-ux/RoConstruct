// from server: 100% by EspClaude
// roc-flags: /O2 /GS- /EHsc /MD
// from server: 47% by colin
// roc 2007-08 0055ebb0  unit: RBX::EngineStatsCommand  size: 128 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0055ebb0
//
// 0055ebb0  64a100000000         mov eax, dword ptr fs:[0]
// 0055ebb6  6aff                 push -1
// 0055ebb8  6808087500           push 0x750808
// 0055ebbd  50                   push eax
// 0055ebbe  64892500000000       mov dword ptr fs:[0], esp
// 0055ebc5  56                   push esi
// 0055ebc6  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 0055ebca  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0055ebce  56                   push esi
// 0055ebcf  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0055ebd7  e8545c0000           call 0x564830
// 0055ebdc  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0055ebe0  56                   push esi
// 0055ebe1  e87a5c0000           call 0x564860
// 0055ebe6  8b742420             mov esi, dword ptr [esp + 0x20]
// 0055ebea  85f6                 test esi, esi
// 0055ebec  c744240cffffffff     mov dword ptr [esp + 0xc], 0xffffffff
// 0055ebf4  742a                 je 0x55ec20
// 0055ebf6  8d4604               lea eax, [esi + 4]
// 0055ebf9  83c9ff               or ecx, 0xffffffff
// 0055ebfc  f00fc108             lock xadd dword ptr [eax], ecx
// 0055ec00  751e                 jne 0x55ec20
// 0055ec02  8b16                 mov edx, dword ptr [esi]
// 0055ec04  8b4204               mov eax, dword ptr [edx + 4]
// 0055ec07  8bce                 mov ecx, esi
// 0055ec09  ffd0                 call eax
// 0055ec0b  8d4e08               lea ecx, [esi + 8]
// 0055ec0e  83caff               or edx, 0xffffffff
// 0055ec11  f00fc111             lock xadd dword ptr [ecx], edx
// 0055ec15  7509                 jne 0x55ec20
// 0055ec17  8b06                 mov eax, dword ptr [esi]
// 0055ec19  8b5008               mov edx, dword ptr [eax + 8]
// 0055ec1c  8bce                 mov ecx, esi
// 0055ec1e  ffd2                 call edx
// 0055ec20  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0055ec24  64890d00000000       mov dword ptr fs:[0], ecx
// 0055ec2b  5e                   pop esi
// 0055ec2c  83c40c               add esp, 0xc
// 0055ec2f  c3                   ret 

#include <intrin.h>

class sp_counted_base {
public:
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy();
    void release()
    {
        if (_InterlockedDecrement(&use_count_) == 0)
        {
            dispose();
            weak_release();
        }
    }
    void weak_release()
    {
        if (_InterlockedDecrement(&weak_count_) == 0)
            destroy();
    }
    long use_count_;
    long weak_count_;
};

class shared_count {
public:
    sp_counted_base* pi_;
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};

template<class T> class shared_ptr {
public:
    T* px;
    shared_count pn;
    T* get() const { return px; }
};

class IDataState;
class DataModel {
public:
    void setDataState(IDataState* s);
};
class Workspace {
public:
    void setDataState(IDataState* s);
};

void __cdecl doEngineStats(DataModel* a, Workspace* b, shared_ptr<IDataState> state)
{
    a->setDataState(state.get());
    b->setDataState(state.get());
}
