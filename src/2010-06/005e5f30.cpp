// from server: 35% by colin
struct DataState;
struct DataModel;

struct Verb {
    char pad[0x14];
    char vec[0x0c];
    DataModel* dataModel;
};

struct EditSelectionVerb : Verb {
    void doIt(DataState* dataState);
};

struct SnapSelectionVerb : EditSelectionVerb {
    void doIt(DataState* dataState);
};

extern "C" {
    void __stdcall _invalid_parameter_noinfo();
    void* __cdecl sub_5e0c40();
    void __cdecl sub_4154b0();
    void* __cdecl sub_5e4a50();
    void __cdecl sub_5d7350();
    void __cdecl sub_628bc0();
    void __cdecl sub_5ee8e0();
    void __cdecl sub_6aa7d0(void*, int, int, int, void*, int);
    void __cdecl sub_5e1f70();
}

void SnapSelectionVerb::doIt(DataState* dataState)
{
    sub_5e0c40();
    if (this->dataModel) {
        sub_4154b0();
    }

    void* p1 = sub_5e4a50();
    int* a = *(int**)((char*)p1 + 0x98);
    int v1 = a[4];
    if ((unsigned)a[3] > (unsigned)v1) {
        _invalid_parameter_noinfo();
    }
    int saved = a[0];

    void* p2 = sub_5e4a50();
    int* b = *(int**)((char*)p2 + 0x98);
    int v2 = b[3];
    if ((unsigned)v2 > (unsigned)b[4]) {
        _invalid_parameter_noinfo();
    }
    int v3 = b[0];

    sub_6aa7d0(&saved, v3, v2, v1, (void*)sub_5e1f70, saved);

    if (this->dataModel) {
        sub_5d7350();
    } else {
        sub_628bc0();
    }

    sub_5ee8e0();
}
