// from server: 44% by atomic.potato
struct VInstance {
    char pad0[0x14];
    void* field14;
    char pad18[0x20];
    int field38;
    int field3c;
    void* field40;
    void* field44;
    void ctor(int a2, int a3, int a4, int a5, int a6, int a7);
};

extern "C" {
    int __cdecl sub_40a3b0(int, int);
    void __cdecl sub_702890(void*, int);
    void* __cdecl sub_642fc0();
    void* __cdecl sub_6432d0();
    int __cdecl sub_6322e0(int, void*, void*);
    void __cdecl sub_6aa7a0(void*, int);
    void* __cdecl sub_7f3860(int);
}

extern int dword_B8FF80;
extern int dword_B8FDA0;

void VInstance::ctor(int a2, int a3, int a4, int a5, int a6, int a7)
{
    int v8;
    int v9;
    void* v10;
    void* v11;
    int v12;

    v8 = sub_40a3b0(a2, a3);
    sub_702890(this, v8);
    this->field38 = a4;
    this->field3c = a5;
    dword_B8FF80++;
    v9 = 0;
    v10 = sub_642fc0();
    this->field40 = v10;
    v11 = sub_7f3860(8);
    if (v11) {
        *(int*)v11 = 0x9a3990;
        *(int*)((char*)v11 + 4) = a6;
    } else {
        v11 = 0;
    }
    this->field44 = v11;
    dword_B8FDA0++;
    v9 = 1;
    this->field14 = sub_6432d0();
    dword_B8FF80++;
    v12 = (int)sub_642fc0();
    v12 = sub_6322e0(a7, (void*)v12, &this->field40);
    sub_6aa7a0(&this->field14, v12);
}
