// from server: 0% by atomic.potato
struct IdSerializer {
    char pad0[4];
    void* begin;
    void* end;
    void* cap;
    IdSerializer* construct(void* src);
};

extern "C" void* __cdecl sub_00479080(unsigned int, void*);
extern "C" void __cdecl sub_006a2780();
extern "C" int __cdecl sub_0056de00(void*, void*, void*, void*, void*, void*, void*, void*);

IdSerializer* IdSerializer::construct(void* src)
{
    int count = (*(int*)((char*)src + 8) - *(int*)((char*)src + 4)) / 12;
    begin = 0;
    end = 0;
    cap = 0;
    if (count != 0) {
        if ((unsigned int)count > 0x15555555)
            sub_006a2780();
        void* p = sub_00479080(count * 12, 0);
        cap = (char*)p + count * 12;
        begin = p;
        end = p;
        int r = sub_0056de00(this, p, *(void**)((char*)src + 4), *(void**)((char*)src + 8), p, 0, 0, 0);
        end = (void*)r;
    }
    return this;
}
