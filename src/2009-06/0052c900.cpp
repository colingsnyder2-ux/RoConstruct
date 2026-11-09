// from server: 100% by EspClaude
// from server: 92% by atomic.potato
// roc 2009-06 0052c900  unit: RBX::VCylinderMesh::?$FactoryProduct::Creator  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0052c900
//
// 0052c900  56                   push esi
// 0052c901  57                   push edi
// 0052c902  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0052c906  57                   push edi
// 0052c907  8bf1                 mov esi, ecx
// 0052c909  e862360000           call 0x52ff70
// 0052c90e  d94728               fld dword ptr [edi + 0x28]
// 0052c911  d95e48               fstp dword ptr [esi + 0x48]
// 0052c914  5f                   pop edi
// 0052c915  d944240c             fld dword ptr [esp + 0xc]
// 0052c919  8bc6                 mov eax, esi
// 0052c91b  d95e4c               fstp dword ptr [esi + 0x4c]
// 0052c91e  d9442410             fld dword ptr [esp + 0x10]
// 0052c922  d95e50               fstp dword ptr [esi + 0x50]
// 0052c925  d90594758b00         fld dword ptr [0x8b7594]
// 0052c92b  d95654               fst dword ptr [esi + 0x54]
// 0052c92e  d95e58               fstp dword ptr [esi + 0x58]
// 0052c931  5e                   pop esi
// 0052c932  c20c00               ret 0xc

struct VCylinderMesh {
    char pad0[0x48];
    float f48;
    float f4c;
    float f50;
    float f54;
    float f58;

    VCylinderMesh* sub_52c900(void* arg0, float a, float b);
};

extern float g_inf;
struct Other {
    void sub_52ff70(void*);
};

VCylinderMesh* VCylinderMesh::sub_52c900(void* arg0, float a, float b)
{
    ((Other*)this)->sub_52ff70(arg0);
    f48 = *(float*)((char*)arg0 + 0x28);
    f4c = a;
    f50 = b;
    f54 = -1.0f;
    f58 = -1.0f;
    return this;
}
