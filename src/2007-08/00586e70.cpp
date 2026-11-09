// from server: 59% by colin
// roc 2007-08 00586e70  unit: RBX::FillTool  size: 402 bytes
// library rbxgs/v8datamodel/ToolsPart.cpp (function ?FillTool@FillTool@RBX@@QAE@PAVWorkspace@2@@Z)

struct Workspace;
struct Instance;

struct PartTool {
    char pad0[0x18];
    Instance* workspace;
};

struct FillTool : PartTool {
    FillTool(Workspace* workspace);
};

extern "C" void* __stdcall sub_5E3DC0(void* parent, int zero, const char* name);
extern "C" void* __stdcall sub_62FEF6(unsigned int size);
extern "C" void __stdcall sub_564880(void* self, void* arg);
extern "C" void __stdcall sub_5784B0(void* self, int arg);
extern "C" void* __stdcall sub_561B10(int a, int b);
extern "C" void __stdcall sub_58C810(void* self);
extern "C" void __stdcall sub_410BB0(void* self);
extern "C" void __stdcall sub_77E69C(void* dst, void* src);

extern int dword_8A2838;
extern int dword_8C225C;
extern int dword_8C2A44;
extern char byte_8C6EE4;

FillTool::FillTool(Workspace* workspace)
{
    void* p = sub_5E3DC0(workspace, 0, &byte_8C6EE4);
    if (p == 0)
        return;

    void* obj1 = sub_62FEF6(0x2c);
    void* ebx;
    if (obj1 != 0) {
        *(int*)((char*)obj1 + 4) = 0x786db0;
        *(int*)((char*)obj1 + 0x28) = 0x786d0c;
        int ecx = *(int*)((char*)obj1 + 4);
        *(int*)obj1 = 0x786d9c;
        int edx = *(int*)(ecx + 4);
        *(int*)((char*)obj1 + edx + 4) = 0x786d94;
        int g = dword_8C225C;
        *(int*)((char*)obj1 + 8) = 0;
        *(int*)((char*)obj1 + 0xc) = 0;
        *(int*)((char*)obj1 + 0x10) = 0;
        *(int*)((char*)obj1 + 0x14) = g;
        *(int*)((char*)obj1 + 0x18) = 0;
        *(int*)((char*)obj1 + 0x20) = 0;
        *(int*)((char*)obj1 + 0x24) = 0;
        int ecx2 = *(int*)((char*)obj1 + 4);
        *(int*)obj1 = 0x786dac;
        int edx2 = *(int*)(ecx2 + 4);
        *(int*)((char*)obj1 + edx2 + 4) = 0x786da4;
        ebx = obj1;
    } else {
        ebx = 0;
    }

    char buf[8];
    *(int*)buf = 0x8C2A44;
    *(int*)(buf + 4) = (int)p + 4;
    sub_564880(ebx, buf);
    sub_5784B0((void*)dword_8A2838, *(int*)(buf + 4));

    int edx3 = *(int*)((char*)this + 0x18);
    void* r = sub_561B10(edx3, 10);
    sub_58C810(r);

    void* obj2 = sub_62FEF6(0x2c);
    void* esi;
    if (obj2 != 0) {
        *(int*)((char*)obj2 + 4) = 0x786db0;
        *(int*)((char*)obj2 + 0x28) = 0x786d0c;
        int ecx3 = *(int*)((char*)obj2 + 4);
        *(int*)obj2 = 0x786d9c;
        int edx4 = *(int*)(ecx3 + 4);
        *(int*)((char*)obj2 + edx4 + 4) = 0x786d94;
        int g2 = dword_8C225C;
        *(int*)((char*)obj2 + 8) = 0;
        *(int*)((char*)obj2 + 0xc) = 0;
        *(int*)((char*)obj2 + 0x10) = 0;
        *(int*)((char*)obj2 + 0x18) = 0;
        *(int*)((char*)obj2 + 0x14) = g2;
        *(int*)((char*)obj2 + 0x20) = 0;
        *(int*)((char*)obj2 + 0x24) = 0;
        int ecx4 = *(int*)((char*)obj2 + 4);
        *(int*)obj2 = 0x786dc4;
        int edx5 = *(int*)(ecx4 + 4);
        *(int*)((char*)obj2 + edx5 + 4) = 0x786dbc;
        esi = obj2;
    } else {
        esi = 0;
    }

    char buf2[8];
    *(int*)buf2 = 0x8C2A44;
    *(int*)(buf2 + 4) = (int)p + 4;
    sub_564880(esi, buf2);

    int ecx5 = *(int*)((char*)this + 0x18);
    int edx6 = *(int*)this;
    int ebp = *(int*)(ecx5 + 0x310);
    int eax2 = *(int*)edx6;
    int (*fn)(void*) = (int (*)(void*))eax2;
    int r2 = fn(this);

    char tmp[0x1c];
    sub_77E69C(tmp, (void*)(r2 + 4));
    sub_410BB0((void*)ebp);

    int ecx6 = *(int*)((char*)this + 0x18);
    int ecx7 = *(int*)(ecx6 + 0x310);
    int edx7 = *(int*)ecx7;
    int eax3 = *(int*)(edx7 + 4);
    int (*fn2)(int) = (int (*)(int))eax3;
    fn2(1);
}
