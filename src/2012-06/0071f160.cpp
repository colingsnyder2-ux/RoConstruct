// from server: 100% by Xemicl
// from server: 100% by Intel
// roc 2012-06 008caab0  unit: RBX::VCornerWedgeInstance::?$FactoryProduct  size: 162 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008caab0
//
// 008caab0  837c240400           cmp dword ptr [esp + 4], 0
// 008caab5  56                   push esi
// 008caab6  8bf1                 mov esi, ecx
// 008caab8  7414                 je 0x8caace
// 008caaba  c78684000000408dbb00 mov dword ptr [esi + 0x84], 0xbb8d40
// 008caac4  c786b800000018f2bb00 mov dword ptr [esi + 0xb8], 0xbbf218
// 008caace  6a00                 push 0
// 008caad0  e8cba8eeff           call 0x7b53a0
// 008caad5  8b8684000000         mov eax, dword ptr [esi + 0x84]
// 008caadb  c7062473be00         mov dword ptr [esi], 0xbe7324
// 008caae1  c746041873be00       mov dword ptr [esi + 4], 0xbe7318
// 008caae8  c746180c73be00       mov dword ptr [esi + 0x18], 0xbe730c
// 008caaef  c7461c0073be00       mov dword ptr [esi + 0x1c], 0xbe7300
// 008caaf6  c78680000000f872be00 mov dword ptr [esi + 0x80], 0xbe72f8
// 008cab00  c78690000000e072be00 mov dword ptr [esi + 0x90], 0xbe72e0
// 008cab0a  c7869c000000b472be00 mov dword ptr [esi + 0x9c], 0xbe72b4
// 008cab14  c786b40000008872be00 mov dword ptr [esi + 0xb4], 0xbe7288
// 008cab1e  c786c80000008072be00 mov dword ptr [esi + 0xc8], 0xbe7280
// 008cab28  8b4804               mov ecx, dword ptr [eax + 4]
// 008cab2b  c78431840000007872be00 mov dword ptr [ecx + esi + 0x84], 0xbe7278
// 008cab36  8b9684000000         mov edx, dword ptr [esi + 0x84]
// 008cab3c  8b4204               mov eax, dword ptr [edx + 4]
// 008cab3f  8d88b0fdffff         lea ecx, [eax - 0x250]
// 008cab45  898c3080000000       mov dword ptr [eax + esi + 0x80], ecx
// 008cab4c  8bc6                 mov eax, esi
// 008cab4e  5e                   pop esi
// 008cab4f  c20400               ret 4

struct VCornerWedgeInstance
{
    int Initialize(int a1);
};

extern "C" int __stdcall sub_7B53A0(int);

int VCornerWedgeInstance::Initialize(int a1)
{
    if (a1)
    {
        *(int *)((char *)this + 0x84) = 0xBB8D40;
        *(int *)((char *)this + 0xac) = 0xBBF218;
    }
    sub_7B53A0(0);
    int v2 = *(int *)((char *)this + 0x84);
    *(int *)this = 0xBE7324;
    *(int *)((char *)this + 4) = 0xBE7318;
    *(int *)((char *)this + 0x18) = 0xBE730C;
    *(int *)((char *)this + 0x1C) = 0xBE7300;
    *(int *)((char *)this + 0x80) = 0xBE72F8;
    *(int *)((char *)this + 0x90) = 0xBE72E0;
    *(int *)((char *)this + 0xa8) = 0xBE72B4;
    *(int *)((char *)this + 0xbc) = 0xBE7288;
    *(int *)((char *)this + 0x150) = 0xBE7280;
    int v3 = *(int *)(v2 + 4);
    *(int *)((char *)this + v3 + 0x84) = 0xBE7278;
    int v4 = *(int *)((char *)this + 0x84);
    int v5 = *(int *)(v4 + 4);
    *(int *)((char *)this + v5 + 0x80) = v5 - 0xf4;
    return (int)this;
}
