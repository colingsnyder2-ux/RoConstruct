// from server: 36% by colin
// roc 2007-08 00452959  unit: ReportAbuseVerb  size: 90 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00452959
//
// 00452959  33db                 xor ebx, ebx
// 0045295b  8d8d34ffffff         lea ecx, [ebp - 0xcc]
// 00452961  c645fc04             mov byte ptr [ebp - 4], 4
// 00452965  ff1584e67700         call dword ptr [0x77e684]
// 0045296b  8d8dc8010000         lea ecx, [ebp + 0x1c8]
// 00452971  c645fc01             mov byte ptr [ebp - 4], 1
// 00452975  e816920100           call 0x46bb90
// 0045297a  8d4d00               lea ecx, [ebp]
// 0045297d  885dfc               mov byte ptr [ebp - 4], bl
// 00452980  e857da1d00           call 0x6303dc
// 00452985  8d4dec               lea ecx, [ebp - 0x14]
// 00452988  ff15bcdd7700         call dword ptr [0x77ddbc]
// 0045298e  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00452991  64890d00000000       mov dword ptr fs:[0], ecx
// 00452998  59                   pop ecx
// 00452999  5f                   pop edi
// 0045299a  5e                   pop esi
// 0045299b  5b                   pop ebx
// 0045299c  8b8d04020000         mov ecx, dword ptr [ebp + 0x204]
// 004529a2  33cd                 xor ecx, ebp
// 004529a4  e875e01d00           call 0x630a1e
// 004529a9  81c508020000         add ebp, 0x208
// 004529af  8be5                 mov esp, ebp
// 004529b1  5d                   pop ebp
// 004529b2  c3                   ret 

struct ReportAbuseVerb {
    void f();
};

extern "C" void __stdcall sub_77E684();
extern "C" void __stdcall sub_77DDBC();
extern "C" void __cdecl sub_46BB90();
extern "C" void __cdecl sub_6303DC();
extern "C" void __cdecl sub_630A1E();

void ReportAbuseVerb::f()
{
    char buf1[0xcc];
    char buf2[0x1c8];
    char buf3[0x14];

    sub_77E684();
    sub_46BB90();
    sub_6303DC();
    sub_77DDBC();
    sub_630A1E();
}
