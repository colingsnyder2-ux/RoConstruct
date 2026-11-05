// from server: 0% by tester
extern "C" void __stdcall sub_6A2780();
extern "C" void* __cdecl sub_5709D0(void*, int);
extern "C" int __cdecl sub_573D60(void*, void*, void*, void*, void*, void*, void*, void*);

struct S {
    int field0;
    int field4;
    int field8;
    int fieldC;
    S* method(int* src);
};

S* S::method(int* src) {
    int count = (src[2] - src[1]) / 12;
    this->field4 = 0;
    this->field8 = 0;
    this->fieldC = 0;
    if (count != 0) {
        if ((unsigned int)count > 0x2AAAAAAA) {
            sub_6A2780();
        }
        void* mem = sub_5709D0(0, count * 12);
        this->fieldC = (int)((char*)mem + count * 12);
        this->field4 = (int)mem;
        this->field8 = (int)mem;
        int result = sub_573D60(mem, (void*)src[1], (void*)src[2], mem, this, 0, 0, 0);
        this->field8 = result;
    }
    return this;
}
