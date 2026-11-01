// from server: 100% by EspClaude
// from server: 74% by colin
// roc 2008-06 0064d3d0  unit: RBX::SimJobStage  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0064d3d0
//
// 0064d3d0  53                   push ebx
// 0064d3d1  8b5924               mov ebx, dword ptr [ecx + 0x24]
// 0064d3d4  56                   push esi
// 0064d3d5  8bc3                 mov eax, ebx
// 0064d3d7  57                   push edi
// 0064d3d8  8b38                 mov edi, dword ptr [eax]
// 0064d3da  8d9b00000000         lea ebx, [ebx]
// 0064d3e0  3bfb                 cmp edi, ebx
// 0064d3e2  7424                 je 0x64d408
// 0064d3e4  8b7708               mov esi, dword ptr [edi + 8]
// 0064d3e7  8b16                 mov edx, dword ptr [esi]
// 0064d3e9  8b4208               mov eax, dword ptr [edx + 8]
// 0064d3ec  8bce                 mov ecx, esi
// 0064d3ee  ffd0                 call eax
// 0064d3f0  85c0                 test eax, eax
// 0064d3f2  7410                 je 0x64d404
// 0064d3f4  8b16                 mov edx, dword ptr [esi]
// 0064d3f6  8b4208               mov eax, dword ptr [edx + 8]
// 0064d3f9  8bce                 mov ecx, esi
// 0064d3fb  ffd0                 call eax
// 0064d3fd  8bc8                 mov ecx, eax
// 0064d3ff  e86c8df9ff           call 0x5e6170
// 0064d404  8b3f                 mov edi, dword ptr [edi]
// 0064d406  ebd8                 jmp 0x64d3e0
// 0064d408  5f                   pop edi
// 0064d409  5e                   pop esi
// 0064d40a  5b                   pop ebx
// 0064d40b  c3                   ret 

#include <list>

struct Link {
    virtual void slot0();
    virtual void slot1();
    virtual Link* get();
    void update();
};

struct SimJobStage {
    char padding[0x10];
    std::list<Link*> links;
    void f();
};

void SimJobStage::f()
{
    typedef std::list<Link*>::iterator It;
    It last = links.end();
    It first = links.begin();
    It::_Checked_iterator_base_type cf(_CHECKED_BASE(first));
    It::_Checked_iterator_base_type cl(_CHECKED_BASE(last));
    for (; cf != cl; ++cf) {
        Link* link = *cf;
        if (link->get())
            link->get()->update();
    }
}
