// from server: 77% by atomic.potato
struct PrismPoly {
    char pad0[0x18];
    void* field18;
};

extern "C" void __stdcall EnterCriticalSection(void*);
extern "C" void __stdcall LeaveCriticalSection(void*);
extern "C" void __stdcall std_exception_ctor(void*, const char**);

void* __fastcall sub_757ff0();
void __cdecl sub_4c2460();
void __cdecl sub_7954a0();
void __cdecl sub_7a89b2(void*, void*);

extern void* g_9ea374;
extern void* g_9ea370;
extern void* g_9ea924;
extern char g_bc48f8;
extern void* g_a00020;
extern void* g_a19218;
extern const char* g_b01ab4;

void* __fastcall PrismPoly_00758050(PrismPoly* self)
{
    void* esi;
    void* edi;
    char buf[8];

    esi = sub_757ff0();
    EnterCriticalSection(&g_9ea374);
    if (*(void**)((char*)esi + 0x18)) {
        *(void**)((char*)esi + 0x18) = **(void***)((char*)esi + 0x18);
    } else {
        sub_4c2460();
    }
    edi = esi;
    LeaveCriticalSection(&g_9ea370);
    if (edi != 0) {
        if (g_bc48f8) {
            sub_7954a0();
        }
        *(void**)(buf + 4) = &g_a19218;
        sub_7a89b2(buf, (void*)&g_b01ab4);
        *(void**)(buf + 4) = &g_a00020;
        std_exception_ctor(buf, &g_b01ab4);
    }
    return edi;
}
