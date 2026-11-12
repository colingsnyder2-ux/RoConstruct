// from server: 100% by EspClaude
// roc-flags: /O2 /GS- /EHsc /MD
// from server: 45% by colin
// roc 2007-08 0055f830  unit: RBX::VPVInstance::?$FilteredSelection  size: 227 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0055f830
//
// 0055f830  6aff                 push -1
// 0055f832  68bdac7500           push 0x75acbd
// 0055f837  64a100000000         mov eax, dword ptr fs:[0]
// 0055f83d  50                   push eax
// 0055f83e  64892500000000       mov dword ptr fs:[0], esp
// 0055f845  83ec20               sub esp, 0x20
// 0055f848  56                   push esi
// 0055f849  8bf1                 mov esi, ecx
// 0055f84b  89742404             mov dword ptr [esp + 4], esi
// 0055f84f  e8cc55eeff           call 0x444e20
// 0055f854  c786e800000084917a00 mov dword ptr [esi + 0xe8], 0x7a9184
// 0055f85e  33c0                 xor eax, eax
// 0055f860  c70664937a00         mov dword ptr [esi], 0x7a9364
// 0055f866  c746045c937a00       mov dword ptr [esi + 4], 0x7a935c
// 0055f86d  c7461054937a00       mov dword ptr [esi + 0x10], 0x7a9354
// 0055f874  c7461444937a00       mov dword ptr [esi + 0x14], 0x7a9344
// 0055f87b  c7462c34937a00       mov dword ptr [esi + 0x2c], 0x7a9334
// 0055f882  c7464424937a00       mov dword ptr [esi + 0x44], 0x7a9324
// 0055f889  c7465c14937a00       mov dword ptr [esi + 0x5c], 0x7a9314
// 0055f890  c7467404937a00       mov dword ptr [esi + 0x74], 0x7a9304
// 0055f897  c7868c000000f4927a00 mov dword ptr [esi + 0x8c], 0x7a92f4
// 0055f8a1  c786e8000000ec927a00 mov dword ptr [esi + 0xe8], 0x7a92ec
// 0055f8ab  8986ec000000         mov dword ptr [esi + 0xec], eax
// 0055f8b1  8944242c             mov dword ptr [esp + 0x2c], eax
// 0055f8b5  8986f0000000         mov dword ptr [esi + 0xf0], eax
// 0055f8bb  8986f8000000         mov dword ptr [esi + 0xf8], eax
// 0055f8c1  8986fc000000         mov dword ptr [esi + 0xfc], eax
// 0055f8c7  898600010000         mov dword ptr [esi + 0x100], eax
// 0055f8cd  6810927a00           push 0x7a9210
// 0055f8d2  8d4c240c             lea ecx, [esp + 0xc]
// 0055f8d6  c644243002           mov byte ptr [esp + 0x30], 2
// 0055f8db  ff1598e67700         call dword ptr [0x77e698]
// 0055f8e1  8d442408             lea eax, [esp + 8]
// 0055f8e5  50                   push eax
// 0055f8e6  8bce                 mov ecx, esi
// 0055f8e8  c644243003           mov byte ptr [esp + 0x30], 3
// 0055f8ed  e8fe22feff           call 0x541bf0
// 0055f8f2  8d4c2408             lea ecx, [esp + 8]
// 0055f8f6  c644242c02           mov byte ptr [esp + 0x2c], 2
// 0055f8fb  ff15ace67700         call dword ptr [0x77e6ac]
// 0055f901  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0055f905  8bc6                 mov eax, esi
// 0055f907  5e                   pop esi
// 0055f908  64890d00000000       mov dword ptr fs:[0], ecx
// 0055f90f  83c42c               add esp, 0x2c
// 0055f912  c3                   ret 

#include <string>
#include <vector>

namespace RBX {

// Polymorphic subobjects of the 2007-08 Instance base; offsets 0,4,0x10,0x14,0x2c,
// 0x44,0x5c,0x74,0x8c and 0xe8 come from the vtable stores in the target.
struct S00 { virtual ~S00(); };
struct S04 { virtual void f04(); int a[2]; };
struct S10 { virtual void f10(); };
struct S14 { virtual void f14(); int a[5]; };
struct S2c { virtual void f2c(); int a[5]; };
struct S44 { virtual void f44(); int a[5]; };
struct S5c { virtual void f5c(); int a[5]; };
struct S74 { virtual void f74(); int a[5]; };
struct S8c { virtual void f8c(); int a[22]; };

class Instance : public S00, public S04, public S10, public S14, public S2c,
                 public S44, public S5c, public S74, public S8c {
public:
    Instance();
    virtual ~Instance();
    void setName(const std::string& name);
};

class ISelection {
public:
    virtual void onSelectionChanged() = 0;
};

struct SharedCount {
    void* pi;
    SharedCount() : pi(0) {}
    ~SharedCount();
};

struct SharedRef {
    void* px;
    SharedCount pn;
    SharedRef() : px(0), pn() {}
};

class PVInstance;

template<class T> class FilteredSelection : public Instance, public ISelection {
public:
    SharedRef owner;
    std::vector<T*> items;
    virtual void onSelectionChanged();
    FilteredSelection();
};

template<class T> FilteredSelection<T>::FilteredSelection()
{
    setName("FilteredSelection");
}

template class FilteredSelection<PVInstance>;

}
