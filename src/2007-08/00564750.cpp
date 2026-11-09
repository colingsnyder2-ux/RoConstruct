// from server: 58% by Intel
struct VectorBase {
    int* begin;
    int* end;
    int* capacity;
};

struct UnknownType {
    char pad[0x104];
    VectorBase vec;
};

struct SomeObject {
    char pad[0x14];
    UnknownType* (__thiscall *func)(SomeObject*, int);
};

struct AnotherObject {
    char pad[0x20];
    int (__thiscall *method)(AnotherObject*);
    char pad2[0xD8];
    VectorBase vec2;
};

int __cdecl sub_5618e0(AnotherObject*);

bool FollowCameraCommand_check(SomeObject* thisptr) {
    UnknownType* ptr = thisptr->func(thisptr, 1);
    VectorBase* v = &ptr->vec;
    int* begin = v->begin;
    int* end = v->end;
    if (!begin || (end - begin) / 8 == 0)
        return false;

    AnotherObject* obj = *(AnotherObject**)((char*)thisptr + 0x20);
    int eax;
    if (obj)
        eax = sub_5618e0(obj);
    else
        eax = 0;

    VectorBase* v2 = (VectorBase*)((char*)eax + 0xF8);
    int* begin2 = v2->begin;
    int* end2 = v2->end;
    if (!begin2)
        return false;

    int count = (end2 - begin2) / 4;
    return count == 1;
}
