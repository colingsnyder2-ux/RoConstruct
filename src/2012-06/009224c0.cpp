// from server: 49% by Intel
struct CleanStage {
    char pad_0[0xA0];
    void* field_A0;
    char pad_A4[8];
    void* field_AC;
    char pad_B0[20];
    void* field_C4;
    char pad_C8[12];
    void* field_D0;
    char pad_D4[12];
    void* field_DC;
    char pad_E0[56];
    void* field_B8;

    void* __stdcall GetMember(int index);

    void* Get_A0();

    void* Get_AC();

    void* Get_C4();

    void* Get_D0();

    void* Get_DC();

    void* Get_B8();
};

extern "C" int __cdecl sub_972290(const char*, int);

void* __stdcall CleanStage::GetMember(int index) {
    int idx = index - 1;
    if (idx > 5) {
        if (*(char*)0xE580B3 != 0) {
            int (__cdecl* callback)(const char*, const char*, int) = *(int (__cdecl**)(const char*, const char*, int))0xE5809C;
            if (callback) {
                if (callback("C:\\TeamCity\\buildAgent\\work\\8348b47e373515f7\\Client\\App\\V8World\\SleepStage.cpp", "C:\\TeamCity\\buildAgent\\work\\8348b47e373515f7\\Client\\App\\include\\gui/gui.h", 797)) {
                    return &this->field_B8;
                }
            }
            sub_972290("C:\\TeamCity\\buildAgent\\work\\8348b47e373515f7\\Client\\App\\V8World\\SleepStage.cpp", *(unsigned char*)0xE580B3);
        }
        return &this->field_B8;
    }

    static void* (CleanStage::* const jumpTable[6])() = {
        &CleanStage::Get_A0,
        &CleanStage::Get_AC,
        &CleanStage::Get_C4,
        &CleanStage::Get_D0,
        &CleanStage::Get_DC,
        &CleanStage::Get_B8
    };
    return (this->*jumpTable[idx])();
}

void* CleanStage::Get_A0() { return &this->field_A0; }
void* CleanStage::Get_AC() { return &this->field_AC; }
void* CleanStage::Get_C4() { return &this->field_C4; }
void* CleanStage::Get_D0() { return &this->field_D0; }
void* CleanStage::Get_DC() { return &this->field_DC; }
void* CleanStage::Get_B8() { return &this->field_B8; }
