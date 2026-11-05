// from server: 50% by atomic.potato
// roc 2011-06 006f55e0  unit: RBX::VInstance::?$EventDesc  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 006f55e0
//
// 006f55e0  8b442404             mov eax, dword ptr [esp + 4]
// 006f55e4  85c0                 test eax, eax
// 006f55e6  7415                 je 0x6f55fd
// 006f55e8  8b542408             mov edx, dword ptr [esp + 8]
// 006f55ec  8b4924               mov ecx, dword ptr [ecx + 0x24]
// 006f55ef  83c0e4               add eax, -0x1c
// 006f55f2  52                   push edx
// 006f55f3  03c8                 add ecx, eax
// 006f55f5  e8d620eaff           call 0x5976d0
// 006f55fa  c20800               ret 8
// 006f55fd  8b542408             mov edx, dword ptr [esp + 8]
// 006f5601  8b4924               mov ecx, dword ptr [ecx + 0x24]
// 006f5604  33c0                 xor eax, eax
// 006f5606  52                   push edx
// 006f5607  03c8                 add ecx, eax
// 006f5609  e8c220eaff           call 0x5976d0
// 006f560e  c20800               ret 8





extern "C" int __stdcall _005976d0(int, int);

struct S {
    int f(int, int);
};

int S::f(int a, int b) {
    int eax = a;
    if (!eax) {
        goto label1;
    }
    int edx = b;
    int ecx = *(int*)(*(int*)eax + 0x24);
    eax += -0x1c;
    int temp = edx;
    ecx += eax;
    _005976d0(ecx, temp);
    return 8;
label1:
    edx = b;
    ecx = *(int*)(*(int*)eax + 0x24);
    eax = 0;
    temp = edx;
    ecx += eax;
    _005976d0(ecx, temp);
    return 8;
}
