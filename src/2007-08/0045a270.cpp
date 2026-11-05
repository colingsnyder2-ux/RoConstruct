// from server: 15% by colin
// roc 2007-08 0045a270  unit: RBX::VCamera::?$FactoryProduct::Creator  size: 439 bytes

extern "C" void __stdcall _invalid_parameter_noinfo();

extern "C" void __cdecl sub_725520(const char*, const char*);
extern "C" void __cdecl sub_458270();
extern "C" void* __cdecl sub_4580f0();
extern "C" void* __cdecl sub_52cb30();
extern "C" void __cdecl sub_40e470();
extern "C" void __cdecl sub_402a60();
extern "C" void __cdecl sub_492360();
extern "C" void __cdecl sub_554de0();

struct Name;

struct CreatorList {
    void* begin;
    void* end;
    void* cap;
};

struct S {
    char pad[0x130];
    CreatorList creators;
    int field134;

    void* getCreator(int index);
    void* addCreator(int index);
    void* findCreator(int index);
    void* Creator();
};

void* S::getCreator(int index) {
    if (this->creators.begin == 0) {
        _invalid_parameter_noinfo();
    }
    return ((void**)this->creators.begin)[index * 2];
}

void* S::addCreator(int index) {
    int count;
    if (this->creators.begin == 0) {
        count = 0;
    } else {
        count = (int)(((char*)this->creators.end - (char*)this->creators.begin) >> 3);
    }
    if (index + 1 > count) {
        sub_40e470();
    }
    return 0;
}

void* S::findCreator(int index) {
    int count;
    if (this->creators.begin == 0) {
        count = 0;
    } else {
        count = (int)(((char*)this->creators.end - (char*)this->creators.begin) >> 3);
    }
    if (index + 1 > count) {
        sub_40e470();
    }
    if (this->creators.begin == 0) {
        _invalid_parameter_noinfo();
    }
    return ((void**)this->creators.begin)[index * 2];
}

void* S::Creator() {
    void* existing;

    sub_725520((const char*)0x8bbfd8, (const char*)0x4588d0);
    sub_458270();

    existing = this->getCreator(0);
    if (existing != 0) {
        return existing;
    }

    if ((*(unsigned char*)0x8bc070 & 1) == 0) {
        *(unsigned int*)0x8bc070 |= 1;
        sub_725520((const char*)0x8bbfcc, (const char*)0x458660);
        void* a = sub_4580f0();
        void* b = sub_52cb30();
        *(unsigned char*)0x8bc06c = (a == b);
    }

    if (*(unsigned char*)0x8bc06c == 0) {
        sub_725520((const char*)0x8bbfcc, (const char*)0x458660);
        sub_4580f0();
        sub_554de0();
        return 0;
    }

    return 0;
}
