// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_dragcollectload_5f8a98e0b8fa7443.cpp

// Candidate translation unit (score above; library headers required).
extern "C" void _ReadWriteBarrier();
#pragma intrinsic(_ReadWriteBarrier)
#include <boost/weak_ptr.hpp>
#include <G3D/Vector3.h>
// from server: 82% by colin
// roc 2008-06 00665b00  unit: RBX::PartDragTool  size: 87 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00665b00
//
// 00665b00  51                   push ecx
// 00665b01  56                   push esi
// 00665b02  8bf1                 mov esi, ecx
// 00665b04  807e3400             cmp byte ptr [esi + 0x34], 0
// 00665b08  753a                 jne 0x665b44
// 00665b0a  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 00665b0d  e8ce82faff           call 0x60dde0
// 00665b12  84c0                 test al, al
// 00665b14  742e                 je 0x665b44
// 00665b16  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 00665b19  c6463401             mov byte ptr [esi + 0x34], 1
// 00665b1d  e8de82faff           call 0x60de00
// 00665b22  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 00665b25  8d4638               lea eax, [esi + 0x38]
// 00665b28  50                   push eax
// 00665b29  83ec08               sub esp, 8
// 00665b2c  8bd4                 mov edx, esp
// 00665b2e  89642410             mov dword ptr [esp + 0x10], esp
// 00665b32  52                   push edx
// 00665b33  e868ffffff           call 0x665aa0
// 00665b38  8b4618               mov eax, dword ptr [esi + 0x18]
// 00665b3b  8b4e1c               mov ecx, dword ptr [esi + 0x1c]
// 00665b3e  50                   push eax
// 00665b3f  e8ac790000           call 0x66d4f0
// 00665b44  8b16                 mov edx, dword ptr [esi]
// 00665b46  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00665b4a  8b5208               mov edx, dword ptr [edx + 8]
// 00665b4d  50                   push eax
// 00665b4e  8bce                 mov ecx, esi
// 00665b50  ffd2                 call edx
// 00665b52  5e                   pop esi
// 00665b53  59                   pop ecx
// 00665b54  c20400               ret 4

// from server: 75% by king_originala
// roc 2008-06 00665b00  unit: RBX::PartDragTool  size: 87 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00665b00
//
// 00665b00  51                   push ecx
// 00665b01  56                   push esi
// 00665b02  8bf1                 mov esi, ecx
// 00665b04  807e3400             cmp byte ptr [esi + 0x34], 0
// 00665b08  753a                 jne 0x665b44
// 00665b0a  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 00665b0d  e8ce82faff           call 0x60dde0
// 00665b12  84c0                 test al, al
// 00665b14  742e                 je 0x665b44
// 00665b16  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 00665b19  c6463401             mov byte ptr [esi + 0x34], 1
// 00665b1d  e8de82faff           call 0x60de00
// 00665b22  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 00665b25  8d4638               lea eax, [esi + 0x38]
// 00665b28  50                   push eax
// 00665b29  83ec08               sub esp, 8
// 00665b2c  8bd4                 mov edx, esp
// 00665b2e  89642410             mov dword ptr [esp + 0x10], esp
// 00665b32  52                   push edx
// 00665b33  e868ffffff           call 0x665aa0
// 00665b38  8b4618               mov eax, dword ptr [esi + 0x18]
// 00665b3b  8b4e1c               mov ecx, dword ptr [esi + 0x1c]
// 00665b3e  50                   push eax
// 00665b3f  e8ac790000           call 0x66d4f0
// 00665b44  8b16                 mov edx, dword ptr [esi]
// 00665b46  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00665b4a  8b5208               mov edx, dword ptr [edx + 8]
// 00665b4d  50                   push eax
// 00665b4e  8bce                 mov ecx, esi
// 00665b50  ffd2                 call edx
// 00665b52  5e                   pop esi
// 00665b53  59                   pop ecx
// 00665b54  c20400               ret 4

struct Part;
typedef boost::weak_ptr<Part> Pair;

struct Source
{
    bool ready();
    void activate();
    Pair collect() const;
};

struct Receiver
{
    void apply(void*, Pair, const G3D::Vector3&);
};

struct S
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2(void*);

    char padding04[20];
    void* value18;
    Receiver* receiver1c;
    Source* source20;
    char padding24[16];
    bool active34;
    char padding35[3];
    G3D::Vector3 value38;

    void f(void*);
};

void S::f(void* argument)
{
    if (!active34 && source20->ready())
    {
        active34 = true;
        source20->activate();
        Source* source=source20;
        _ReadWriteBarrier();
        receiver1c->apply(value18, source->collect(), value38);
    }
    slot2(argument);
}
