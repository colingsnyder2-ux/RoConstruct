// from server: 45% by atomic.potato
// roc 2010-06 004f3280  unit: RBX::Network::VReplicator::?$EventDesc  size: 49 bytes
//
// 004f3280  8b442404             mov eax, dword ptr [esp + 4]
// 004f3284  85c0                 test eax, eax
// 004f3286  7415                 je 0x4f329d
// 004f3288  8b542408             mov edx, dword ptr [esp + 8]
// 004f328c  8b4938               mov ecx, dword ptr [ecx + 0x38]
// 004f328f  83c0e4               add eax, -0x1c
// 004f3292  52                   push edx
// 004f3293  03c8                 add ecx, eax
// 004f3295  e886f3ffff           call 0x4f2620
// 004f329a  c20800               ret 8
// 004f329d  8b542408             mov edx, dword ptr [esp + 8]
// 004f32a1  8b4938               mov ecx, dword ptr [ecx + 0x38]
// 004f32a4  33c0                 xor eax, eax
// 004f32a6  52                   push edx
// 004f32a7  03c8                 add ecx, eax
// 004f32a9  e872f3ffff           call 0x4f2620
// 004f32ae  c20800               ret 8

extern "C" int __stdcall _0x4f2620(int, int);

struct S {
    int f(int, int);
};

int S::f(int a, int b) {
    if (!a) {
        goto L1;
    }
    int edx = b;
    int ecx = *(int*)(*((int*)this) + 0x38);
    a -= 0x1c;
    int edx2 = edx;
    ecx += a;
    _0x4f2620(edx2, ecx);
    return 8;
L1:
    int edx3 = b;
    int ecx2 = *(int*)(*((int*)this) + 0x38);
    a = 0;
    int edx4 = edx3;
    ecx2 += a;
    _0x4f2620(edx4, ecx2);
    return 8;
}
