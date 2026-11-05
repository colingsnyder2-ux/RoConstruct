// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005c62f0  unit: RBX::VArrowTool::?$TToolVerb  size: 75 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005c62f0
//
// 005c62f0  8b442404             mov eax, dword ptr [esp + 4]
// 005c62f4  56                   push esi
// 005c62f5  50                   push eax
// 005c62f6  8bf1                 mov esi, ecx
// 005c62f8  e8f3f60400           call 0x6159f0
// 005c62fd  d9ee                 fldz 
// 005c62ff  33c0                 xor eax, eax
// 005c6301  88461c               mov byte ptr [esi + 0x1c], al
// 005c6304  c70624918300         mov dword ptr [esi], 0x839124
// 005c630a  c7460408918300       mov dword ptr [esi + 4], 0x839108
// 005c6311  894620               mov dword ptr [esi + 0x20], eax
// 005c6314  894624               mov dword ptr [esi + 0x24], eax
// 005c6317  884628               mov byte ptr [esi + 0x28], al
// 005c631a  d95630               fst dword ptr [esi + 0x30]
// 005c631d  d95634               fst dword ptr [esi + 0x34]
// 005c6320  33c9                 xor ecx, ecx
// 005c6322  d95e38               fstp dword ptr [esi + 0x38]
// 005c6325  66894e3c             mov word ptr [esi + 0x3c], cx
// 005c6329  33d2                 xor edx, edx
// 005c632b  6689563e             mov word ptr [esi + 0x3e], dx
// 005c632f  894640               mov dword ptr [esi + 0x40], eax
// 005c6332  894644               mov dword ptr [esi + 0x44], eax
// 005c6335  8bc6                 mov eax, esi
// 005c6337  5e                   pop esi
// 005c6338  c20400               ret 4

struct Base {
    int f(int a1);
};

struct S {
    S* f(int a1);
};

S* S::f(int a1)
{
    ((Base*)this)->f(a1);
    *(volatile char*)((char*)this + 0x1c) = 0;
    *(volatile int*)((char*)this + 0x00) = 0x839124;
    *(volatile int*)((char*)this + 0x04) = 0x839108;
    *(volatile int*)((char*)this + 0x20) = 0;
    *(volatile int*)((char*)this + 0x24) = 0;
    *(volatile char*)((char*)this + 0x28) = 0;
    *(volatile float*)((char*)this + 0x30) = 0.0f;
    *(volatile float*)((char*)this + 0x34) = 0.0f;
    *(volatile float*)((char*)this + 0x38) = 0.0f;
    *(volatile short*)((char*)this + 0x3c) = 0;
    *(volatile short*)((char*)this + 0x3e) = 0;
    *(volatile int*)((char*)this + 0x40) = 0;
    *(volatile int*)((char*)this + 0x44) = 0;
    return this;
}
