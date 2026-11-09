// from server: 60% by atomic.potato
struct RBX_Instance {
    char pad[0x4c];
    RBX_Instance* field_4c;
};

extern "C" int __stdcall sub_7f4aaa(RBX_Instance*, int, int, int, int);
extern "C" int __stdcall sub_512420(RBX_Instance*, int);
extern "C" int __stdcall sub_46d0c0(RBX_Instance*);

struct RBX_Accoutrement {
    char pad[0x4c];
    RBX_Instance* field_4c;
    void sub_6ab2e0(int);
};

void RBX_Accoutrement::sub_6ab2e0(int a) {
    RBX_Accoutrement* esi = this;
    if (esi == 0) return;
    RBX_Instance* eax = esi->field_4c;
    if (eax != 0) {
        RBX_Instance* ecx = eax->field_4c;
        if (ecx != 0) {
            sub_46d0c0(ecx);
        }
    } else {
        eax = (RBX_Instance*)esi;
    }
    if (eax == 0) return;
    int r = sub_7f4aaa(eax, 0, 0xaffe40, 0xb03de8, 0);
    if (r == 0) return;
    if (sub_512420((RBX_Instance*)esi, 1) == 0) return;
    ((void(__thiscall*)(RBX_Accoutrement*))0x6ab120)(esi);
}
