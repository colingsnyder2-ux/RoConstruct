// from server: 50% by tester
struct LuaStatsItem {
    char pad[0x70];
    void* field70;
    void update();
};

extern "C" void __stdcall sub_936640(void* a, void* b);
extern "C" void __stdcall sub_9325b0(void* a, int b);
extern "C" int __stdcall sub_854530(void* a, void* b, int c);
extern "C" void __stdcall sub_854080(void* a);
extern "C" void __stdcall sub_853e30(void* a);

void LuaStatsItem::update()
{
    void* p = field70;
    sub_936640(p, *(void**)((char*)p + 0x20));
    sub_9325b0(p, 1);
    do
    {
        *(int*)((char*)p + 0x74) = 0;
        void* v = *(void**)((char*)p + 0x28);
        *(void**)((char*)p + 0x14) = v;
        void* w = *(void**)v;
        *(void**)((char*)p + 8) = w;
        *(void**)((char*)p + 0xc) = w;
        *(unsigned short*)((char*)p + 0x36) = 0;
        *(unsigned short*)((char*)p + 0x34) = 0;
    } while (sub_854530(p, (void*)0x853f60, 0) != 0);
    sub_854080((char*)p - 0x20);
    sub_853e30(p);
}
