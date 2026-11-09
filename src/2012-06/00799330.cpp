// from server: 47% by Intel
struct VHumanoid {
    int field_30;
    int field_34;
    int field_38;
    int field_3C;
    int field_138;
    int BoundFuncDesc(int a1, int a2);
};

extern "C" int __cdecl sub_68A700(int a1, int a2, int a3);

int VHumanoid::BoundFuncDesc(int a1, int a2) {
    int v3 = sub_68A700(a1, 0, this->field_3C);
    int v4 = a2 ? a2 - 28 : 0;
    int v5 = this->field_34;
    int v6 = this->field_30;
    int v7 = this->field_38;
    int v8 = v4 ? *(int*)(v4 + 312) : 0;
    int v9 = *(int*)(v8 + v7);
    int v10 = v9 + v4;
    float v11 = *(float*)&v10;
    int v12 = v10 + v5 + 312;
    return ((int(__cdecl*)(int, int, float))v6)(v12, v5, v11);
}
