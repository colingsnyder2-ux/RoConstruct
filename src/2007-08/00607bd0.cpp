// from server: 23% by colin
struct RBX_ClumpStage {
    char pad0[0x2c];
    void* field2c;
    char pad30[0xc];
    void* field3c;
    void* field40;
    void* field44;
    void* field48;
    char pad4c[0x10];
    void* field5c;
    void* field60;
    char pad64[0x20];
    void* field84;
    char pad88[0x8];
    void* field90;

    void func_00607bd0();
};

extern "C" void __stdcall func_004ef230();
extern "C" void* __stdcall func_005375c0();
extern "C" void* __stdcall func_00570200();
extern "C" void* __stdcall func_005b3a60();
extern "C" void* __stdcall func_005b4dc0();
extern "C" void* __stdcall func_005b4de0();
extern "C" void* __stdcall func_005e29b0();
extern "C" void* __stdcall func_00605670();
extern "C" void* __stdcall func_00605b30();
extern "C" void* __stdcall func_00605c10();
extern "C" void* __stdcall func_00605c80();
extern "C" void* __stdcall func_00605d00();
extern "C" void* __stdcall func_00606700();
extern "C" void* __stdcall func_00606c70();
extern "C" void* __stdcall func_0060b200();
extern "C" void* __stdcall func_0060b220();
extern "C" void* __stdcall func_0060be60();
extern "C" void* __stdcall func_0060bfe0();
extern "C" void* __stdcall func_0062fc62();
extern "C" void* __stdcall func_0062fef6();
extern "C" void* __stdcall func_0077e6d8();

void RBX_ClumpStage::func_00607bd0()
{
    while (this->field40 != 0) {
        void* v3c = this->field3c;
        void* v28 = (char*)this + 0x38;
        void* v2c = v3c;
        func_004ef230();
        void* edi = v28;
        if (edi == 0) {
            func_0077e6d8();
        }
        void* esi = v2c;
        if (esi == *(void**)((char*)edi + 4)) {
            func_0077e6d8();
        }
        void* v24 = *(void**)((char*)esi + 0xc);
        void* ebx = *(void**)v24;
        void* esi2 = *(void**)((char*)ebx + 0x20);
        if (esi2 != 0) {
            if (ebx == *(void**)((char*)esi2 + 0x24) && *(void**)((char*)esi2 + 0x20) == 0) {
                func_00605c10();
                func_0060b220();
                continue;
            }
            void* eax = *(void**)((char*)esi2 + 0x20);
            if (eax != 0) {
                func_00606c70();
            }
            if (*(void**)((char*)esi2 + 0x28) != 0) {
                void* v20 = esi2;
                func_00605b30();
            } else {
                void* v20 = esi2;
                func_00605b30();
            }
            func_00606700();
            func_0060be60();
            func_0062fc62();
            continue;
        }
        void* v20 = func_0062fef6();
        if (v20 != 0) {
            func_0060bfe0();
            void* esi3 = v20;
            func_0060b220();
            func_005e29b0();
            func_00605c10();
            func_00605d00();
            void* ebx2 = func_005b4dc0();
            if (ebx2 == 0) {
                continue;
            }
            while (1) {
                void* ecx = this->field48;
                void* eax = *(void**)((char*)ecx + 4);
                if (*(char*)((char*)eax + 0x11) == 0) {
                    if (ebx2 < *(void**)((char*)eax + 0xc)) {
                        eax = *(void**)eax;
                    } else {
                        eax = *(void**)((char*)eax + 8);
                    }
                }
                void* esi4 = ecx;
                void* eax2 = *(void**)((char*)ecx + 4);
                if (*(char*)((char*)eax2 + 0x11) == 0) {
                    if (*(void**)((char*)eax2 + 0xc) < ebx2) {
                        eax2 = *(void**)((char*)eax2 + 8);
                    } else {
                        esi4 = eax2;
                        eax2 = *(void**)eax2;
                    }
                }
                func_005375c0();
                func_005b3a60();
                if (*(void**)((char*)this + 0x1c) != 0) {
                    break;
                }
                void* ecx2 = this->field60;
                void* eax3 = *(void**)((char*)ecx2 + 4);
                if (*(char*)((char*)eax3 + 0x11) == 0) {
                    if (ebx2 < *(void**)((char*)eax3 + 0xc)) {
                        eax3 = *(void**)eax3;
                    } else {
                        eax3 = *(void**)((char*)eax3 + 8);
                    }
                }
                void* edi2 = ecx2;
                void* eax4 = *(void**)((char*)ecx2 + 4);
                if (*(char*)((char*)eax4 + 0x11) == 0) {
                    if (*(void**)((char*)eax4 + 0xc) < ebx2) {
                        eax4 = *(void**)((char*)eax4 + 8);
                    } else {
                        edi2 = eax4;
                        eax4 = *(void**)eax4;
                    }
                }
                func_005375c0();
                func_005b3a60();
                if (*(void**)((char*)this + 0x1c) != 0) {
                    break;
                }
                void* esi5 = (char*)this + 0x2c;
                void* ebp2 = *(void**)((char*)esi5 + 4);
                func_00570200();
                void* edi3 = eax;
                void* eax5 = *(void**)edi3;
                if (eax5 != 0 && eax5 != esi5) {
                    func_0077e6d8();
                }
                if (*(void**)((char*)edi3 + 4) != ebp2) {
                    func_00605c80();
                }
                break;
            }
            if (func_0060b200() != 0) {
                func_005e29b0();
            } else {
                func_00605670();
            }
            void* ebx3 = func_005b4de0();
            if (ebx3 == 0) {
                continue;
            }
            ebx2 = ebx3;
        }
    }
}
