// from server: 100% by Espeon
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// from server: 80% by colin
// roc 2008-06 00644670  unit: RBX::HUMAN::Climbing  size: 320 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00644670
//
// 00644670  8b442404             mov eax, dword ptr [esp + 4]
// 00644674  83f810               cmp eax, 0x10
// 00644677  0f87e8000000         ja 0x644765
// 0064467d  ff24856c476400       jmp dword ptr [eax*4 + 0x64476c]
// 00644684  8b4108               mov eax, dword ptr [ecx + 8]
// 00644687  8a80e8010000         mov al, byte ptr [eax + 0x1e8]
// 0064468d  d0e8                 shr al, 1
// 0064468f  2401                 and al, 1
// 00644691  c20400               ret 4
// 00644694  8b4908               mov ecx, dword ptr [ecx + 8]
// 00644697  8a81e8010000         mov al, byte ptr [ecx + 0x1e8]
// 0064469d  2401                 and al, 1
// 0064469f  c20400               ret 4
// 006446a2  8b5108               mov edx, dword ptr [ecx + 8]
// 006446a5  8a82e8010000         mov al, byte ptr [edx + 0x1e8]
// 006446ab  c0e803               shr al, 3
// 006446ae  2401                 and al, 1
// 006446b0  c20400               ret 4
// 006446b3  8b4108               mov eax, dword ptr [ecx + 8]
// 006446b6  0fb680e8010000       movzx eax, byte ptr [eax + 0x1e8]
// 006446bd  c1e803               shr eax, 3
// 006446c0  f7d0                 not eax
// 006446c2  83e001               and eax, 1
// 006446c5  c20400               ret 4
// 006446c8  e863f3ffff           call 0x643a30
// 006446cd  c20400               ret 4
// 006446d0  e87bf3ffff           call 0x643a50
// 006446d5  c20400               ret 4
// 006446d8  8a4120               mov al, byte ptr [ecx + 0x20]
// 006446db  c20400               ret 4
// 006446de  33c0                 xor eax, eax
// 006446e0  384120               cmp byte ptr [ecx + 0x20], al
// 006446e3  0f94c0               sete al
// 006446e6  c20400               ret 4
// 006446e9  8b4908               mov ecx, dword ptr [ecx + 8]
// 006446ec  8a81e8010000         mov al, byte ptr [ecx + 0x1e8]
// 006446f2  c0e804               shr al, 4
// 006446f5  2401                 and al, 1
// 006446f7  c20400               ret 4
// 006446fa  8b5108               mov edx, dword ptr [ecx + 8]
// 006446fd  0fb682e8010000       movzx eax, byte ptr [edx + 0x1e8]
// 00644704  c1e804               shr eax, 4
// 00644707  f7d0                 not eax
// 00644709  83e001               and eax, 1
// 0064470c  c20400               ret 4
// 0064470f  33c0                 xor eax, eax
// 00644711  394124               cmp dword ptr [ecx + 0x24], eax
// 00644714  0f95c0               setne al
// 00644717  c20400               ret 4
// 0064471a  33c0                 xor eax, eax
// 0064471c  394124               cmp dword ptr [ecx + 0x24], eax
// 0064471f  0f94c0               sete al
// 00644722  c20400               ret 4
// 00644725  e8c6fdffff           call 0x6444f0
// 0064472a  c20400               ret 4
// 0064472d  e8befdffff           call 0x6444f0
// 00644732  33c9                 xor ecx, ecx
// 00644734  84c0                 test al, al
// 00644736  0f94c1               sete cl
// 00644739  8ac1                 mov al, cl
// 0064473b  c20400               ret 4
// 0064473e  d9ee                 fldz 
// 00644740  d8590c               fcomp dword ptr [ecx + 0xc]
// 00644743  dfe0                 fnstsw ax
// 00644745  f6c401               test ah, 1
// 00644748  7508                 jne 0x644752
// 0064474a  b801000000           mov eax, 1
// 0064474f  c20400               ret 4
// 00644752  33c0                 xor eax, eax
// 00644754  c20400               ret 4
// 00644757  8a4111               mov al, byte ptr [ecx + 0x11]
// 0064475a  c20400               ret 4
// 0064475d  e84ef7ffff           call 0x643eb0
// 00644762  c20400               ret 4
// 00644765  32c0                 xor al, al
// 00644767  c20400               ret 4
// 0064476a  8bff                 mov edi, edi
// 0064476c  844664               test byte ptr [esi + 0x64], al
// 0064476f  0094466400e946       add byte ptr [esi + eax*2 + 0x46e90064], dl
// 00644776  6400fa               add dl, bh
// 00644779  46                   inc esi
// 0064477a  6400a2466400b3       add byte ptr fs:[edx - 0x4cff9bba], ah
// 00644781  46                   inc esi
// 00644782  6400c8               add al, cl
// 00644785  46                   inc esi
// 00644786  6400d0               add al, dl
// 00644789  46                   inc esi
// 0064478a  6400d8               add al, bl
// 0064478d  46                   inc esi
// 0064478e  6400de               add dh, bl
// 00644791  46                   inc esi
// 00644792  64001a               add byte ptr fs:[edx], bl
// 00644795  47                   inc edi
// 00644796  64000f               add byte ptr fs:[edi], cl
// 00644799  47                   inc edi
// 0064479a  6400254764002d       add byte ptr fs:[0x2d006447], ah
// 006447a1  47                   inc edi
// 006447a2  64005747             add byte ptr fs:[edi + 0x47], dl
// 006447a6  64003e               add byte ptr fs:[esi], bh
// 006447a9  47                   inc edi
// 006447aa  64005d47             add byte ptr fs:[ebp + 0x47], bl

// from server: 79% by colin
// roc 2008-06 00644670  unit: RBX::HUMAN::Climbing  size: 320 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00644670
//
// 00644670  8b442404             mov eax, dword ptr [esp + 4]
// 00644674  83f810               cmp eax, 0x10
// 00644677  0f87e8000000         ja 0x644765
// 0064467d  ff24856c476400       jmp dword ptr [eax*4 + 0x64476c]
// 00644684  8b4108               mov eax, dword ptr [ecx + 8]
// 00644687  8a80e8010000         mov al, byte ptr [eax + 0x1e8]
// 0064468d  d0e8                 shr al, 1
// 0064468f  2401                 and al, 1
// 00644691  c20400               ret 4
// 00644694  8b4908               mov ecx, dword ptr [ecx + 8]
// 00644697  8a81e8010000         mov al, byte ptr [ecx + 0x1e8]
// 0064469d  2401                 and al, 1
// 0064469f  c20400               ret 4
// 006446a2  8b5108               mov edx, dword ptr [ecx + 8]
// 006446a5  8a82e8010000         mov al, byte ptr [edx + 0x1e8]
// 006446ab  c0e803               shr al, 3
// 006446ae  2401                 and al, 1
// 006446b0  c20400               ret 4
// 006446b3  8b4108               mov eax, dword ptr [ecx + 8]
// 006446b6  0fb680e8010000       movzx eax, byte ptr [eax + 0x1e8]
// 006446bd  c1e803               shr eax, 3
// 006446c0  f7d0                 not eax
// 006446c2  83e001               and eax, 1
// 006446c5  c20400               ret 4
// 006446c8  e863f3ffff           call 0x643a30
// 006446cd  c20400               ret 4
// 006446d0  e87bf3ffff           call 0x643a50
// 006446d5  c20400               ret 4
// 006446d8  8a4120               mov al, byte ptr [ecx + 0x20]
// 006446db  c20400               ret 4
// 006446de  33c0                 xor eax, eax
// 006446e0  384120               cmp byte ptr [ecx + 0x20], al
// 006446e3  0f94c0               sete al
// 006446e6  c20400               ret 4
// 006446e9  8b4908               mov ecx, dword ptr [ecx + 8]
// 006446ec  8a81e8010000         mov al, byte ptr [ecx + 0x1e8]
// 006446f2  c0e804               shr al, 4
// 006446f5  2401                 and al, 1
// 006446f7  c20400               ret 4
// 006446fa  8b5108               mov edx, dword ptr [ecx + 8]
// 006446fd  0fb682e8010000       movzx eax, byte ptr [edx + 0x1e8]
// 00644704  c1e804               shr eax, 4
// 00644707  f7d0                 not eax
// 00644709  83e001               and eax, 1
// 0064470c  c20400               ret 4
// 0064470f  33c0                 xor eax, eax
// 00644711  394124               cmp dword ptr [ecx + 0x24], eax
// 00644714  0f95c0               setne al
// 00644717  c20400               ret 4
// 0064471a  33c0                 xor eax, eax
// 0064471c  394124               cmp dword ptr [ecx + 0x24], eax
// 0064471f  0f94c0               sete al
// 00644722  c20400               ret 4
// 00644725  e8c6fdffff           call 0x6444f0
// 0064472a  c20400               ret 4
// 0064472d  e8befdffff           call 0x6444f0
// 00644732  33c9                 xor ecx, ecx
// 00644734  84c0                 test al, al
// 00644736  0f94c1               sete cl
// 00644739  8ac1                 mov al, cl
// 0064473b  c20400               ret 4
// 0064473e  d9ee                 fldz 
// 00644740  d8590c               fcomp dword ptr [ecx + 0xc]
// 00644743  dfe0                 fnstsw ax
// 00644745  f6c401               test ah, 1
// 00644748  7508                 jne 0x644752
// 0064474a  b801000000           mov eax, 1
// 0064474f  c20400               ret 4
// 00644752  33c0                 xor eax, eax
// 00644754  c20400               ret 4
// 00644757  8a4111               mov al, byte ptr [ecx + 0x11]
// 0064475a  c20400               ret 4
// 0064475d  e84ef7ffff           call 0x643eb0
// 00644762  c20400               ret 4
// 00644765  32c0                 xor al, al
// 00644767  c20400               ret 4
// 0064476a  8bff                 mov edi, edi
// 0064476c  844664               test byte ptr [esi + 0x64], al
// 0064476f  0094466400e946       add byte ptr [esi + eax*2 + 0x46e90064], dl
// 00644776  6400fa               add dl, bh
// 00644779  46                   inc esi
// 0064477a  6400a2466400b3       add byte ptr fs:[edx - 0x4cff9bba], ah
// 00644781  46                   inc esi
// 00644782  6400c8               add al, cl
// 00644785  46                   inc esi
// 00644786  6400d0               add al, dl
// 00644789  46                   inc esi
// 0064478a  6400d8               add al, bl
// 0064478d  46                   inc esi
// 0064478e  6400de               add dh, bl
// 00644791  46                   inc esi
// 00644792  64001a               add byte ptr fs:[edx], bl
// 00644795  47                   inc edi
// 00644796  64000f               add byte ptr fs:[edi], cl
// 00644799  47                   inc edi
// 0064479a  6400254764002d       add byte ptr fs:[0x2d006447], ah
// 006447a1  47                   inc edi
// 006447a2  64005747             add byte ptr fs:[edi + 0x47], dl
// 006447a6  64003e               add byte ptr fs:[esi], bh
// 006447a9  47                   inc edi
// 006447aa  64005d47             add byte ptr fs:[ebp + 0x47], bl

struct HumanoidState;

struct Climbing {
    char pad0[8];
    HumanoidState* humanoid;
    float field_c;
    char pad10;
    bool field_11;
    char pad3[0x20 - 0x11 - 1];
    bool field_20;
    char pad4[0x24 - 0x20 - 1];
    int field_24;
    bool method_6444f0();
    bool method_643a30();
    bool method_643a50();
    bool method_643eb0();
    bool dispatch(int index);
};

struct HumanoidState {
    char pad0[0x1e8];
    union { unsigned char flags; struct {bool bit0:1; bool bit1:1; bool bit2:1; bool bit3:1; bool bit4:1;} bits; };
};

bool Climbing::dispatch(int index) {
    switch (index) {
    case 0:
        if ((humanoid->flags >> 1) & 1)
            return true;
        return false;
    case 1:
        return humanoid->bits.bit0;
    case 2:
        return humanoid->bits.bit3;
    case 3:
        return (~(humanoid->flags >> 3)) & 1;
    case 4:
        return method_643a30();
    case 5:
        return method_643a50();
    case 6:
        return field_20;
    case 7:
        return field_20 == 0;
    case 8:
        return humanoid->bits.bit4;
    case 9:
        return (~(humanoid->flags >> 4)) & 1;
    case 10:
        return field_24 != 0;
    case 11:
        return field_24 == 0;
    case 12:
        return method_6444f0();
    case 13:
        return !method_6444f0();
    case 14:
        return field_c <= 0.0f;
    case 15:
        return field_11;
    case 16:
        return method_643eb0();
    default:
        return false;
    }
}
