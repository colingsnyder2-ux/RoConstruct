// from server: 100% by colin
extern "C" void __cdecl sub_557330(void*, void*);
extern "C" void __cdecl sub_5BFAA0();
extern "C" void __cdecl sub_5BFB10();
extern "C" void __cdecl sub_5BFB80();
extern "C" void __cdecl sub_5BFBF0();
extern "C" void __cdecl sub_5BFC60();
extern "C" void __cdecl sub_5BFCD0();
extern "C" void __cdecl sub_5BFD40();

struct RBX_VRocket_FactoryProduct {
    void Init();
};

void RBX_VRocket_FactoryProduct::Init()
{
    sub_557330((void*)0x97780c, (void*)0x5bffd0);
    sub_5BFAA0();
    sub_557330((void*)0x977818, (void*)0x5c0000);
    sub_5BFBF0();
    sub_557330((void*)0x97781c, (void*)0x5c0010);
    sub_5BFC60();
    sub_557330((void*)0x977820, (void*)0x5c0020);
    sub_5BFCD0();
    sub_557330((void*)0x977810, (void*)0x5bffe0);
    sub_5BFB10();
    sub_557330((void*)0x977814, (void*)0x5bfff0);
    sub_5BFB80();
    sub_557330((void*)0x977824, (void*)0x5c0030);
    sub_5BFD40();
}
