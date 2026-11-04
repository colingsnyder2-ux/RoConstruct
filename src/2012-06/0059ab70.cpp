// from server: 65% by Intel
bool __cdecl sub_567BD0();

struct VAuthoringSettings_FactoryProduct {
    unsigned int field0;
    int field4;
    int field8;
    unsigned char* fieldC;
    bool SomeFunction(unsigned char* output);
};

bool VAuthoringSettings_FactoryProduct::SomeFunction(unsigned char* output) {
    int eax = field8;
    int ecx = (eax - 1) & 7;
    eax = eax - ecx + 7;
    field8 = eax;

    if (eax + 24 > field0) {
        return false;
    }

    bool flag = sub_567BD0();

    int index = field8 >> 3;
    unsigned char cl = fieldC[index];

    if (!flag) {
        output[0] = cl;
        output[1] = fieldC[index + 1];
        output[2] = fieldC[index + 2];
        output[3] = 0;
    } else {
        output[3] = cl;
        output[2] = fieldC[index + 1];
        output[1] = fieldC[index + 2];
        output[0] = 0;
    }

    field8 += 24;
    return true;
}
