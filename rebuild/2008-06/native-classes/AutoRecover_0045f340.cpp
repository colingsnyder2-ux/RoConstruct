// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: raw-offset constructor; sub-object vtables written directly (types unknown)
extern "C" {
void* __fastcall fn_0045ebe0(void* self, int unusedEdx);
void* __fastcall fn_0045f120(void* self, int unusedEdx, const char* name, void* val);
void* __fastcall fn_0045f230(void* self, int unusedEdx, const char* name, void* val);
void* __fastcall fn_005c9c70(void* self, int unusedEdx, const char* name);
void* __fastcall fn_0045f340(void* self, int unusedEdx, char* arg);
}

#define F(o) (*(void**)((char*)self + (o)))
#define VT(o, a) (*(unsigned*)((char*)self + (o)) = (a))

void* __fastcall fn_0045f340(void* self, int unusedEdx, char* arg)
{
    fn_0045ebe0(self, 0);
    VT(0x00, 0x81a32c);
    VT(0x10, 0x81a31c);
    VT(0x14, 0x81a314);
    VT(0x20, 0x81a30c);
    VT(0x24, 0x81a2fc);
    VT(0x44, 0x81a2ec);
    VT(0x64, 0x81a2dc);
    VT(0x84, 0x81a2cc);
    VT(0xa4, 0x81a2bc);
    VT(0xc4, 0x81a2ac);
    F(0x170) = arg;

    fn_0045f120(self, 0, "2D CPU Render", arg);
    void* t = fn_0045f120(self, 0, "3D CPU Total", arg + 0x108);
    t = fn_0045f120(t, 0, "CPU Shadow", arg + 0x160);
    fn_0045f120(t, 0, "computeProxyArrays", arg + 0x1b8);
    fn_0045f120(t, 0, "Sort", arg + 0xb0);
    fn_0045f230(t, 0, "Proxy count", arg + 0x220);
    t = fn_0045f230(t, 0, "Total Triangles", arg + 0x228);
    fn_0045f230(t, 0, "Ambient + Unshadowed", arg + 0x234);
    fn_0045f230(t, 0, "Mark Shadows", arg + 0x22c);
    fn_0045f230(t, 0, "Shadowed Light", arg + 0x230);
    fn_0045f120(self, 0, "SwapBuffer", arg + 0x58);

    void* agg = fn_005c9c70(self, 0, "Aggregation");
    F(0x158) = agg;
    fn_0045f230(agg, 0, "Total Chunks", (void*)0x97288c);
    fn_0045f230(F(0x158), 0, "Aggregated Chunks", (void*)0x972890);
    fn_0045f230(F(0x158), 0, "AggregateChunks", (void*)0x972894);

    void* mem = fn_005c9c70(self, 0, "Memory");
    F(0x15c) = fn_005c9c70(mem, 0, "Tex");
    F(0x160) = fn_005c9c70(mem, 0, "VAR");
    F(0x164) = fn_005c9c70(mem, 0, "Video");

    void* sc = fn_005c9c70(self, 0, "State Changes");
    F(0x168) = fn_005c9c70(sc, 0, "Major");
    F(0x16c) = fn_005c9c70(sc, 0, "Minor");
    return self;
}
