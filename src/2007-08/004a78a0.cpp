// from server: 32% by tester
struct Replicator {
    void sub_4A6DC0(float, float, float);
    void sub_49FD90(int, int, int*);
    void sub_4A0230(int, int);
    void sub_4A78A0(int);
};

void Replicator::sub_4A78A0(int a2) {
    float* v = (float*)this;
    if (a2 != 0) {
        sub_4A0230(0, (int)this);
        float f8 = v[2];
        float f4 = v[1];
        float f0 = v[0];
        sub_4A6DC0(f0, f4, f8);
        return;
    }
    if (v[0] == *(float*)0x79d1d8) {
        return;
    }
    if (v[0] == *(float*)0x79d1cc) {
        return;
    }
    if (v[1] == *(float*)0x79d1dc) {
        return;
    }
    if (v[1] == *(float*)0x79d1d0) {
        return;
    }
    if (v[2] == *(float*)0x79d1d8) {
        return;
    }
    if (v[2] == *(float*)0x79d1cc) {
        return;
    }
    sub_4A0230(1, (int)this);
    int i0 = (int)((v[0] - *(double*)0x797990) * *(double*)0x79d638 * *(double*)0x79d630);
    int i1 = (int)((v[1] - *(double*)0x79d628) * *(double*)0x79d620 * *(double*)0x79d618);
    int i2 = (int)((v[2] - *(double*)0x797990) * *(double*)0x79d638 * *(double*)0x79d630);
    if ((unsigned short)i0 >= 0x8000) i0 = 0xffff;
    if ((unsigned short)i1 >= 0x4000) i1 = 0xffff;
    if ((unsigned short)i2 >= 0x8000) i2 = 0xffff;
    sub_49FD90(1, 0xf, &i0);
    sub_49FD90(1, 0xe, &i1);
    sub_49FD90(1, 0xf, &i2);
}
