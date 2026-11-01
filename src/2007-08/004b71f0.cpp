// from server: 50% by colin
extern "C" int __cdecl sprintf(char*, const char*, ...);

struct S_func_004b71f0 {
    void* vfptr;
    char* field_4;
    char field_8;
    char pad_9[1];
    char field_a[0x100];
    char field_10a[0x100];
    void f(char* a1, int a2, int a3, int a4);
};

extern "C" int __cdecl sub_4b6d40(int);
extern "C" int __cdecl sub_4b7f70(int, int, int, int, int, int);

void S_func_004b71f0::f(char* a1, int a2, int a3, int a4)
{
    char buf[0x100];
    char tmp[8];
    int v1;
    short v2;
    int* p;

    p = (int*)((char*)field_4 + 0);
    v1 = *(int*)(*(int*)field_4 + 0xa0);
    ((void (__thiscall*)(void*, int, int, char*))v1)(field_4, *(int*)0x892abc, *(int*)0x892ac0, tmp);
    v1 = *(int*)tmp;
    v2 = *(short*)(tmp + 4);

    if (field_8 == 0) {
        sprintf(buf, "%sRcv,Raw,  NIL,  NIL,%5i,%5i,%i,%u:%i,%u:%i%s",
            field_a,
            sub_4b7f70(v1, v2, a2, a3, a4, (int)field_10a),
            a2, a3, a4, 0, 0, 0, 0, 0, 0);
    } else {
        int r = sub_4b6d40(a1[0]);
        if (r == 0) {
            r = ((int (__thiscall*)(void*, int))*(int*)(*(int*)this + 0x48))(this, a1[0]);
        }
        sprintf(buf, "%sRcv,Raw,NIL,NIL,%s,%i,%i,%u:%i,%u:%i%s",
            field_a,
            r,
            sub_4b7f70(v1, v2, a2, a3, a4, (int)field_10a),
            a2, a3, a4, 0, 0, 0, 0, 0, 0);
    }

    ((void (__thiscall*)(void*, char*))*(int*)(*(int*)this + 0x44))(this, tmp);
}
