// from server: 77% by atomic.potato
extern "C" int __stdcall sub_7F90E0(int, const char*, const char*, int, int, int, int);
extern "C" void __fastcall sub_603950(int);
extern "C" void __fastcall sub_6428A0(int);

extern unsigned char byte_CCC395;
extern char byte_A92D80[];
extern char byte_A92FA4[];

struct RBX_SelectAllCommand {
    char pad_0[0xc];
    int* field_c;
    void execute(int);
};

void RBX_SelectAllCommand::execute(int) {
    if (byte_CCC395) {
        sub_7F90E0(3, byte_A92FA4, byte_A92D80, 0x99, 0, 0, 0);
    }
    int* p = field_c;
    sub_603950((int)p);
    int* q = field_c;
    sub_6428A0(*(int*)((char*)q + 0xacc));
}
