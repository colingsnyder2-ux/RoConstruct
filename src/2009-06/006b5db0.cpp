// from server: 100% by EspClaude
// from server: 100% by colin
// roc 2008-06 006159f0  unit: RBX::ArrowTool  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006159f0
//
// 006159f0  8bc1                 mov eax, ecx
// 006159f2  83c9ff               or ecx, 0xffffffff
// 006159f5  894808               mov dword ptr [eax + 8], ecx
// 006159f8  89480c               mov dword ptr [eax + 0xc], ecx
// 006159fb  33c9                 xor ecx, ecx
// 006159fd  894810               mov dword ptr [eax + 0x10], ecx
// 00615a00  884814               mov byte ptr [eax + 0x14], cl
// 00615a03  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00615a07  c700fc398400         mov dword ptr [eax], 0x8439fc
// 00615a0d  c74004e0398400       mov dword ptr [eax + 4], 0x8439e0
// 00615a14  894818               mov dword ptr [eax + 0x18], ecx
// 00615a17  c20400               ret 4

struct S_func_006159f0 {
    int f(int a1);
};

int S_func_006159f0::f(int a1)
{
    *(int*)((char*)this + 8) = -1;
    *(int*)((char*)this + 12) = -1;
    *(int*)((char*)this + 16) = 0;
    *(char*)((char*)this + 20) = 0;
    *(int*)((char*)this + 0) = 0x8439fc;
    *(int*)((char*)this + 4) = 0x8439e0;
    *(int*)((char*)this + 24) = a1;
    return (int)this;
}
