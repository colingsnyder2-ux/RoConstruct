// from server: 57% by Intel
struct VectorBase {
    int* begin;
    int* end;
    int* capacity;
};

struct SomeObject {
    char pad[0x14];
    VectorBase vec1;
    char pad2[0xC];
    void* ptrAt20;
};

struct InnerObject {
    char pad[0x104];
    VectorBase vec2;
};

struct AnotherObject {
    char pad[0xF8];
    int* begin;
    int* end;
};

int __stdcall sub_5618e0(void* thisptr);
InnerObject* __stdcall sub_562300(VectorBase* thisptr, int arg);

bool __fastcall FollowCameraCommand_isChecked(SomeObject* thisptr)
{
    InnerObject* inner = sub_562300(&thisptr->vec1, 1);
    VectorBase* vec2 = &inner->vec2;
    int* begin = vec2->begin;
    int* end = vec2->end;

    if (!begin || begin == end)
        return false;

    void* ptr = thisptr->ptrAt20;
    if (ptr)
        sub_5618e0(ptr);

    AnotherObject* another = (AnotherObject*)ptr;
    int* anotherBegin = another->begin;
    int* anotherEnd = another->end;

    if (!anotherBegin)
        return false;

    int count = (anotherEnd - anotherBegin) >> 2;
    return count == 1;
}
