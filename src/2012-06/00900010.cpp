// from server: 42% by Intel
struct NormalBreakConnector {
    char pad[56];
    float field_38;
    float field_3C;
    float field_40;
    float* func();
};

extern "C" int __cdecl sub_972290(int, int);

float* NormalBreakConnector::func() {
    static int initFlag = 0;
    static float storedVals[3];
    const float* initVal = (const float*)0xBF1524;
    int* flagPtr = (int*)0xE567A0;
    float* storedPtr = (float*)0xE56794;
    int* callbackPtr = (int*)0xE5809C;
    char* globalByte = (char*)0xE580B3;
    const char* strPtr = (const char*)0xBF1530;

    if (!*globalByte) {
        return &field_38;
    }

    if (!(*flagPtr & 1)) {
        storedVals[0] = *initVal;
        storedVals[1] = *initVal;
        storedVals[2] = *initVal;
        *flagPtr |= 1;
    }

    if (field_38 > storedPtr[0] || field_38 != field_38) {
        return &field_38;
    }
    if (field_3C > storedPtr[1] || field_3C != field_3C) {
        return &field_38;
    }
    if (field_40 > storedPtr[2] || field_40 != field_40) {
        return &field_38;
    }

    if (*callbackPtr) {
        int result = ((int (__cdecl*)(int, int, int))*callbackPtr)(0xAD, 0xBF15F8, 0xBF15C8);
        if (result) {
            return &field_38;
        }
    }

    sub_972290(*globalByte, (int)strPtr);
    return &field_38;
}
