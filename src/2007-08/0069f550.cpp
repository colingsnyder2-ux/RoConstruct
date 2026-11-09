// from server: 100% by colin
// roc 2007-08 0069f550  unit: CXTColorSelectorCtrl  size: 74 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0069f550
//
// 0069f550  56                   push esi
// 0069f551  57                   push edi
// 0069f552  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0069f556  83ff1a               cmp edi, 0x1a
// 0069f559  8bf1                 mov esi, ecx
// 0069f55b  7405                 je 0x69f562
// 0069f55d  83ff15               cmp edi, 0x15
// 0069f560  751c                 jne 0x69f57e
// 0069f562  e8291a0700           call 0x710f90
// 0069f567  8b10                 mov edx, dword ptr [eax]
// 0069f569  8bc8                 mov ecx, eax
// 0069f56b  8b4204               mov eax, dword ptr [edx + 4]
// 0069f56e  ffd0                 call eax
// 0069f570  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 0069f573  6a00                 push 0
// 0069f575  6a00                 push 0
// 0069f577  51                   push ecx
// 0069f578  ff15dcec7700         call dword ptr [0x77ecdc]
// 0069f57e  8b542418             mov edx, dword ptr [esp + 0x18]
// 0069f582  8b442414             mov eax, dword ptr [esp + 0x14]
// 0069f586  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0069f58a  52                   push edx
// 0069f58b  50                   push eax
// 0069f58c  51                   push ecx
// 0069f58d  57                   push edi
// 0069f58e  8bce                 mov ecx, esi
// 0069f590  e84708f9ff           call 0x62fddc
// 0069f595  5f                   pop edi
// 0069f596  5e                   pop esi
// 0069f597  c21000               ret 0x10

extern "C" int (__stdcall *InvalidateRect)(void*, const void*, int);
extern "C" int __stdcall sub_62FDDC();

struct CXTColorSelectorCtrl {
    char pad[0x20];
    void* hwnd;
    int OnMessage(int, unsigned int, unsigned int, unsigned int);
};

struct CXTColorSelectorCtrlHelper {
    virtual void vfunc0();
    virtual void vfunc1();
};

extern "C" CXTColorSelectorCtrlHelper* __cdecl sub_710f90();

int CXTColorSelectorCtrl::OnMessage(int msg, unsigned int wParam, unsigned int lParam, unsigned int unk) {
    if (msg == 0x1a || msg == 0x15) {
        CXTColorSelectorCtrlHelper* p = sub_710f90();
        p->vfunc1();
        InvalidateRect(this->hwnd, 0, 0);
    }
    return ((int (__thiscall*)(CXTColorSelectorCtrl*, int, unsigned int, unsigned int, unsigned int))sub_62FDDC)(this, msg, wParam, lParam, unk);
}
