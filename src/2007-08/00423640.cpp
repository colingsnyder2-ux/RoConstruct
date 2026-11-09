// from server: 21% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct CSelectionTreeCtrl;

struct RefCounted {
    void* vptr;
    long refcount;
};

struct TreeNode {
    TreeNode* parent;
    TreeNode* left;
    TreeNode* right;
    char color;
    char pad[3];
};

struct Tree {
    TreeNode* header;
    int count;
};

struct Inner {
    char pad[0x14];
    void* ptr;
};

struct CSelectionTreeCtrl {
    void* vptr0;
    void* vptr1;
    void* vptr2;
    void* field_0c;
    void* field_10;
    Tree tree14;
    Tree tree20;
    char field_2c;
    char field_2d;
    char pad_2e[2];
    void* field_30;
    void* field_34;
    Tree tree38;
    int field_44;
    void* field_48;
    void* field_4c;

    CSelectionTreeCtrl(void* a, void* b, void* c, void* d);
};

struct ArgHolder {
    void* vptr;
    long refcount;
};

extern "C" void* __cdecl sub_4206D0(void*);
extern "C" void __cdecl sub_5835B0();
extern "C" void __cdecl sub_5A93B0();
extern "C" void __cdecl sub_725750();
extern "C" void __cdecl sub_725770();
extern "C" void __cdecl sub_40D550();
extern "C" void __cdecl sub_5595A0();
extern "C" void __cdecl sub_423240();
extern "C" void __cdecl sub_4339D0();

CSelectionTreeCtrl::CSelectionTreeCtrl(void* a, void* b, void* c, void* d)
{
    void* ebx = a;
    void* edx = b;
    void* ebp = c;
    void* arg4 = d;

    this->vptr0 = (void*)0x788578;
    this->vptr1 = (void*)0x78856c;
    this->vptr2 = (void*)0x788560;
    this->field_0c = ebx;
    this->field_10 = arg4;
    if (arg4 != 0) {
        _InterlockedExchangeAdd((volatile long*)((char*)arg4 + 4), 1);
    }

    sub_5835B0();
    this->tree14.header = 0;
    this->tree14.count = 0;

    sub_5A93B0();
    this->tree20.header = 0;
    this->tree20.count = 0;

    this->field_2c = (char)(this->field_2c & 0xfc);
    this->field_2d = 0;
    this->field_30 = ebp;
    this->field_34 = edx;

    sub_5835B0();
    this->tree38.header = 0;
    this->tree38.count = 0;

    this->field_44 = 0;
    this->field_48 = sub_4206D0(ebx);
    this->field_4c = *(void**)((char*)ebx + 0xc);

    sub_725750();
    sub_4339D0();
    sub_725770();
    sub_40D550();
    sub_423240();
    sub_5595A0();
}
