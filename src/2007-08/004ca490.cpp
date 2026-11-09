// from server: 56% by colin
struct CSHA1 {
    char pad[0x10];
    int field_10;
    int field_14;
    int field_18;

    int sub_4ca490(char* a1, int a2, int a3);
};

struct CString {
    char* data;
};

struct CStringRef {
    char* data;
};

extern "C" {
    int __stdcall sub_4a35d0(void* self, const char* str);
    int __stdcall sub_4a35b0(void* self, void* other);
    int __stdcall sub_4ca390(void* self, void* a, void* b);
}

extern char byte_892fcc;
extern int dword_8bf9c0;
extern int dword_8bf9bc;

int CSHA1::sub_4ca490(char* a1, int a2, int a3) {
    char buf[0x1c];
    int local4;
    int local8;
    int localC;
    int local10;
    int local14;
    int local18;
    int local1C;
    int local20;
    int local24;
    int local28;
    int local2C;

    if (sub_4a35d0(&local28, &byte_892fcc)) {
        return 0;
    }

    local4 = local24;
    local8 = local28;
    localC = local2C;

    sub_4a35b0(&local14, &local4);

    local20 = 0;
    sub_4ca390(&this->field_10, &local14, &dword_8bf9c0);
    dword_8bf9c0 = *(int*)&local14;

    if (this->field_18 == 0) {
        // eax = &dword_8bf9bc
    }

    int* p = (this->field_18 == 0) ? &dword_8bf9bc : (int*)this->field_18;
    int result = *p;
    if (result == 0) {
        return 0;
    }
    return *(int*)(result + 0xc);
}
