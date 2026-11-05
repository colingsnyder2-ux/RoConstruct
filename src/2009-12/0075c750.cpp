// from server: 100% by nuck16
// roc 2009-12 0075c750  unit: RBX::VSelectionPointLasso::?$FactoryProduct  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0075c750
//
// 0075c750  c70194699e00         mov dword ptr [ecx], 0x9e6994
// 0075c756  c7410488699e00       mov dword ptr [ecx + 4], 0x9e6988
// 0075c75d  c741187c699e00       mov dword ptr [ecx + 0x18], 0x9e697c
// 0075c764  c7411c74699e00       mov dword ptr [ecx + 0x1c], 0x9e6974
// 0075c76b  c7819400000064699e00 mov dword ptr [ecx + 0x94], 0x9e6964
// 0075c775  c781980000004c699e00 mov dword ptr [ecx + 0x98], 0x9e694c
// 0075c77f  e9fcfdffff           jmp 0x75c580

extern "C" void func_75c580();

struct S
{
    void f();
};

void S::f()
{
    *(int *)((char *)this + 0x0) = 0x9e6994;
    *(int *)((char *)this + 0x4) = 0x9e6988;
    *(int *)((char *)this + 0x18) = 0x9e697c;
    *(int *)((char *)this + 0x1c) = 0x9e6974;
    *(int *)((char *)this + 0x94) = 0x9e6964;
    *(int *)((char *)this + 0x98) = 0x9e694c;
    func_75c580();
}
