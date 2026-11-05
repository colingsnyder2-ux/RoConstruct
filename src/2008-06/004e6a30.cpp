// from server: 100% by Espeon
// from server: 88% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// from server: 82% by colin
// roc 2008-06 004e6a30  unit: RBX::ViewNew::PartChunk  size: 208 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004e6a30
//
// 004e6a30  56                   push esi
// 004e6a31  57                   push edi
// 004e6a32  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 004e6a36  8bf1                 mov esi, ecx
// 004e6a38  81ff48619700         cmp edi, 0x976148
// 004e6a3e  7511                 jne 0x4e6a51
// 004e6a40  e8fbfcffff           call 0x4e6740
// 004e6a45  8bce                 mov ecx, esi
// 004e6a47  e864feffff           call 0x4e68b0
// 004e6a4c  5f                   pop edi
// 004e6a4d  5e                   pop esi
// 004e6a4e  c20400               ret 4
// 004e6a51  81ff28619700         cmp edi, 0x976128
// 004e6a57  74ee                 je 0x4e6a47
// 004e6a59  81ffa8609700         cmp edi, 0x9760a8
// 004e6a5f  740f                 je 0x4e6a70
// 004e6a61  57                   push edi
// 004e6a62  e8895f1000           call 0x5ec9f0
// 004e6a67  83c404               add esp, 4
// 004e6a6a  84c0                 test al, al
// 004e6a6c  740c                 je 0x4e6a7a
// 004e6a6e  8bce                 mov ecx, esi
// 004e6a70  e8cbfcffff           call 0x4e6740
// 004e6a75  5f                   pop edi
// 004e6a76  5e                   pop esi
// 004e6a77  c20400               ret 4
// 004e6a7a  81ff6c629700         cmp edi, 0x97626c
// 004e6a80  7579                 jne 0x4e6afb
// 004e6a82  8b8ebc000000         mov ecx, dword ptr [esi + 0xbc]
// 004e6a88  8b06                 mov eax, dword ptr [esi]
// 004e6a8a  d98124020000         fld dword ptr [ecx + 0x224]
// 004e6a90  8b5020               mov edx, dword ptr [eax + 0x20]
// 004e6a93  51                   push ecx
// 004e6a94  8bce                 mov ecx, esi
// 004e6a96  d91c24               fstp dword ptr [esp]
// 004e6a99  ffd2                 call edx
// 004e6a9b  8b86bc000000         mov eax, dword ptr [esi + 0xbc]
// 004e6aa1  8b16                 mov edx, dword ptr [esi]
// 004e6aa3  83b8c801000000       cmp dword ptr [eax + 0x1c8], 0
// 004e6aaa  8b4224               mov eax, dword ptr [edx + 0x24]
// 004e6aad  8bce                 mov ecx, esi
// 004e6aaf  7425                 je 0x4e6ad6
// 004e6ab1  ffd0                 call eax
// 004e6ab3  d905ac9b8100         fld dword ptr [0x819bac]
// 004e6ab9  d8d1                 fcom st(1)
// 004e6abb  dfe0                 fnstsw ax
// 004e6abd  ddd9                 fstp st(1)
// 004e6abf  f6c441               test ah, 0x41
// 004e6ac2  7535                 jne 0x4e6af9
// 004e6ac4  8b16                 mov edx, dword ptr [esi]
// 004e6ac6  8b4220               mov eax, dword ptr [edx + 0x20]
// 004e6ac9  51                   push ecx
// 004e6aca  8bce                 mov ecx, esi
// 004e6acc  d91c24               fstp dword ptr [esp]
// 004e6acf  ffd0                 call eax
// 004e6ad1  5f                   pop edi
// 004e6ad2  5e                   pop esi
// 004e6ad3  c20400               ret 4
// 004e6ad6  ffd0                 call eax
// 004e6ad8  d81d94748200         fcomp dword ptr [0x827494]
// 004e6ade  dfe0                 fnstsw ax
// 004e6ae0  f6c405               test ah, 5
// 004e6ae3  7a16                 jp 0x4e6afb
// 004e6ae5  8b16                 mov edx, dword ptr [esi]
// 004e6ae7  d9ee                 fldz 
// 004e6ae9  8b4220               mov eax, dword ptr [edx + 0x20]
// 004e6aec  51                   push ecx
// 004e6aed  8bce                 mov ecx, esi
// 004e6aef  d91c24               fstp dword ptr [esp]
// 004e6af2  ffd0                 call eax
// 004e6af4  5f                   pop edi
// 004e6af5  5e                   pop esi
// 004e6af6  c20400               ret 4
// 004e6af9  ddd8                 fstp st(0)
// 004e6afb  5f                   pop edi
// 004e6afc  5e                   pop esi
// 004e6afd  c20400               ret 4

struct Part{char p0[0x1c8];int flag;char p1[0x224-0x1cc];float transparency;};
struct PartChunk{virtual void slot0();virtual void slot1();virtual void slot2();virtual void slot3();virtual void slot4();virtual void slot5();virtual void slot6();virtual void slot7();virtual void set(float);virtual float get();char padding[0xb8];Part* field_bc;void method_4e6740();void method_4e68b0();void method_4e6a30(void*);};
extern char propertyA,propertyB,propertyC,propertyD;
extern "C" bool __cdecl is_type(void* type);

extern float g_819bac;
extern float g_827494;

void PartChunk::method_4e6a30(void* arg)
{
    if (arg == &propertyA) {
        method_4e6740();
        method_4e68b0();
        return;
    }
    if (arg == &propertyB) {
        method_4e68b0();
        return;
    }
    if (arg == &propertyC) {
        method_4e6740();
        return;
    }
    if (is_type(arg)) {
        method_4e6740();
        return;
    }
    if (arg == &propertyD) {
        set(field_bc->transparency);
        if(field_bc->flag){if(get()<0.5f)set(0.5f);}
        else {if(get()<1.0f)set(0.0f);}
    }
}
