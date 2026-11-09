// from server: 57% by colin
// roc 2007-08 00439390  unit: CPropertyGridItemBrickColor  size: 97 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00439390
//
// 00439390  8964240c             mov dword ptr [esp + 0xc], esp
// 00439394  7422                 je 0x4393b8
// 00439396  8d442420             lea eax, [esp + 0x20]
// 0043939a  50                   push eax
// 0043939b  ff1574dd7700         call dword ptr [0x77dd74]
// 004393a1  e8eaf6ffff           call 0x438a90
// 004393a6  8b16                 mov edx, dword ptr [esi]
// 004393a8  83c404               add esp, 4
// 004393ab  50                   push eax
// 004393ac  8b82e4000000         mov eax, dword ptr [edx + 0xe4]
// 004393b2  8bce                 mov ecx, esi
// 004393b4  ffd0                 call eax
// 004393b6  eb1c                 jmp 0x4393d4
// 004393b8  6854597800           push 0x785954
// 004393bd  c78600010000ffffffff mov dword ptr [esi + 0x100], 0xffffffff
// 004393c7  ff15b8dd7700         call dword ptr [0x77ddb8]
// 004393cd  8bce                 mov ecx, esi
// 004393cf  e85cf22500           call 0x698630
// 004393d4  8d4c241c             lea ecx, [esp + 0x1c]
// 004393d8  ff15bcdd7700         call dword ptr [0x77ddbc]
// 004393de  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004393e2  64890d00000000       mov dword ptr fs:[0], ecx
// 004393e9  59                   pop ecx
// 004393ea  5e                   pop esi
// 004393eb  83c410               add esp, 0x10
// 004393ee  c20400               ret 4

struct CPropertyGridItemBrickColor {
    void func_00439390(int);
};

extern "C" void __stdcall func_00438a90();
extern "C" void __stdcall func_00698630();
extern "C" void __stdcall func_0077dd74();
extern "C" void __stdcall func_0077ddb8();
extern "C" void __stdcall func_0077ddbc();

void CPropertyGridItemBrickColor::func_00439390(int arg)
{
    if (arg == 0) {
        func_0077dd74();
        func_00438a90();
        void (CPropertyGridItemBrickColor::*pmf)(int) = 0;
        (this->*(*(void (CPropertyGridItemBrickColor::**)(int))(*(int*)this + 0xe4)))(arg);
    } else {
        func_0077ddb8();
        *(int*)((char*)this + 0x100) = -1;
        func_00698630();
    }
    func_0077ddbc();
}
