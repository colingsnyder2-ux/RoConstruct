// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" char g_0084616c[];   // INFERRED: unnamed global at 0x0084616c in the original
extern "C" char g_0084617c[];   // INFERRED: unnamed global at 0x0084617c in the original
extern "C" char g_0084618c[];   // INFERRED: unnamed global at 0x0084618c in the original
extern "C" char g_0084619c[];   // INFERRED: unnamed global at 0x0084619c in the original
extern "C" char g_008461ac[];   // INFERRED: unnamed global at 0x008461ac in the original
extern "C" char g_008461bc[];   // INFERRED: unnamed global at 0x008461bc in the original
extern "C" char g_008461cc[];   // INFERRED: unnamed global at 0x008461cc in the original
extern "C" char g_008461d4[];   // INFERRED: unnamed global at 0x008461d4 in the original
extern "C" char g_008461dc[];   // INFERRED: unnamed global at 0x008461dc in the original
extern "C" char g_008461ec[];   // INFERRED: unnamed global at 0x008461ec in the original
#include <string>
#include <new>

extern "C" void __fastcall fn_0062c820(void* self, int unusedEdx);
extern "C" void __fastcall fn_0061a200(void* self, int unusedEdx);
extern "C" void __fastcall fn_0055af90(void* self, int unusedEdx, const std::string& value);
// INFERRED: destructors of the base and list members, only run on the EH unwind path.
extern "C" void __fastcall fn_0062c800(void* self, int unusedEdx);
extern "C" void __fastcall fn_0061a1f0(void* self, int unusedEdx);

struct Local_0062ccd0_Base {
    unsigned char data[0x12f];
    __forceinline Local_0062ccd0_Base() { fn_0062c820(this, 0); }
    __forceinline ~Local_0062ccd0_Base() { fn_0062c800(this, 0); }
    __forceinline void setName(const std::string& s) { fn_0055af90(this, 0, s); }
};

struct Local_0062ccd0_Tool {
    unsigned char data[4];
    __forceinline Local_0062ccd0_Tool() { fn_0061a200(this, 0); }
    __forceinline ~Local_0062ccd0_Tool() { fn_0061a1f0(this, 0); }
};

struct Local_0062ccd0_Setup {
    __forceinline Local_0062ccd0_Setup(void* p) {
        unsigned char* b = static_cast<unsigned char*>(p);
        *reinterpret_cast<unsigned long*>(b) = (unsigned long)&g_008461ec;
        *reinterpret_cast<unsigned long*>(b + 0x10) = (unsigned long)&g_008461dc;
        *reinterpret_cast<unsigned long*>(b + 0x14) = (unsigned long)&g_008461d4;
        *reinterpret_cast<unsigned long*>(b + 0x20) = (unsigned long)&g_008461cc;
        *reinterpret_cast<unsigned long*>(b + 0x24) = (unsigned long)&g_008461bc;
        *reinterpret_cast<unsigned long*>(b + 0x44) = (unsigned long)&g_008461ac;
        *reinterpret_cast<unsigned long*>(b + 0x64) = (unsigned long)&g_0084619c;
        *reinterpret_cast<unsigned long*>(b + 0x84) = (unsigned long)&g_0084618c;
        *reinterpret_cast<unsigned long*>(b + 0xa4) = (unsigned long)&g_0084617c;
        *reinterpret_cast<unsigned long*>(b + 0xc4) = (unsigned long)&g_0084616c;
    }
};

// INFERRED: the service object at 0x973e8c; vtable slot 3 registers the stand.
struct Local_0062ccd0_Service {
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual void slot2() = 0;
    virtual void registerStand(void* p, const bool* flag) = 0;
};

extern Local_0062ccd0_Service* g_00973e8c;

struct Local_0062ccd0_Stand : Local_0062ccd0_Base {
    Local_0062ccd0_Setup setup;
    Local_0062ccd0_Tool tool;
    __forceinline Local_0062ccd0_Stand() : Local_0062ccd0_Base(), setup(this), tool() {
        {
            std::string name("FlagStandService");
            setName(name);
        }
        bool enabled = false;
        g_00973e8c->registerStand(reinterpret_cast<unsigned char*>(this) + 0x14, &enabled);
    }
};

extern "C" Local_0062ccd0_Stand* __fastcall fn_0062ccd0(Local_0062ccd0_Stand* self, int unusedEdx)
{
    return new (self) Local_0062ccd0_Stand();
}
