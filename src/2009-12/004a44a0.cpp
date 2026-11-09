// from server: 30% by atomic.potato
struct UTVertexPositionNormalStudsTex_SpecializedMeshGen {
    char pad0[8];
    void* begin;
    void* end;
    void* cap;
    int f(int, int, int, int);
};

extern "C" void __cdecl sub_442160();
extern "C" void* __cdecl sub_49B650(int, int);
extern "C" void __cdecl sub_4A0790(void*, void*, void*, void*, void*, void*);
extern "C" void __cdecl sub_4A2B70(void*, void*, void*, void*);
extern "C" void __cdecl sub_7F385A(void*);

int UTVertexPositionNormalStudsTex_SpecializedMeshGen::f(int a1, int a2, int a3, int a4) {
    int count;
    void* p;
    int n;
    int i;
    int total;
    int oldCount;
    void* oldBegin;
    void* newBegin;
    int newCount;
    int newTotal;

    if (this->begin == 0) {
        count = 0;
    } else {
        count = ((char*)this->end - (char*)this->begin) / 28;
    }

    n = a2;
    if (n == 0) {
        return 0;
    }

    oldCount = ((char*)this->end - (char*)this->begin) / 28;
    if ((unsigned)(0x4444444 - oldCount) < (unsigned)n) {
        sub_442160();
    }

    total = count + n;
    if ((unsigned)count >= (unsigned)total) {
        goto done;
    }

    newCount = count >> 1;
    if ((unsigned)(0x4444444 - newCount) < (unsigned)count) {
        count = 0;
    } else {
        count = count + newCount;
    }
    if ((unsigned)count < (unsigned)total) {
        count = total;
    }

    p = sub_49B650(count, 0);

    oldBegin = this->begin;
    i = ((char*)this->end - (char*)this->begin) / 28;
    newBegin = (char*)p + i * 28;

    sub_4A2B70(this, newBegin, (void*)n, *(void**)((char*)this + 0x14));

    sub_4A0790(this->begin, (void*)*(int*)((char*)this + 0x10), (char*)this + 8, newBegin, (void*)n, 0);

    newTotal = i + n;
    sub_4A0790((void*)*(int*)((char*)this + 0x10), newBegin, (char*)this + 8, (char*)p + newTotal * 28, (void*)n, 0);

    oldCount = ((char*)this->end - (char*)this->begin) / 28;
    if (this->begin != 0) {
        sub_7F385A(this->begin);
    }

    this->cap = (char*)p + count * 28;
    this->end = (char*)p + (oldCount + n) * 28;
    this->begin = p;

done:
    return 0;
}
