// from server: 100% by colin
// roc 2007-08 005966c0  unit: RBX::LaserTool  size: 86 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005966c0

extern "C" {
    typedef struct _RTL_CRITICAL_SECTION {
        void* DebugInfo;
        long LockCount;
        long RecursionCount;
        void* OwningThread;
        void* LockSemaphore;
        unsigned long SpinCount;
    } RTL_CRITICAL_SECTION, *PRTL_CRITICAL_SECTION;

    __declspec(dllimport) void __stdcall InitializeCriticalSection(PRTL_CRITICAL_SECTION lpCriticalSection);
}

struct LaserToolStatic {
    char pad0[0x18];
    RTL_CRITICAL_SECTION cs;
    int field_38;
    int field_3c;
    int field_40;
    int field_44;
    int field_48;
    int field_4c;
};

extern int g_initialized;
extern LaserToolStatic g_laserToolStatic;

void __cdecl sub_630d23(void* p);

LaserToolStatic* GetLaserToolStatic();

LaserToolStatic* GetLaserToolStatic() {
    if (!(g_initialized & 1)) {
        g_initialized |= 1;
        InitializeCriticalSection(&g_laserToolStatic.cs);
        g_laserToolStatic.field_38 = 0;
        g_laserToolStatic.field_3c = 0;
        g_laserToolStatic.field_40 = 0;
        g_laserToolStatic.field_44 = 0x10;
        g_laserToolStatic.field_48 = 0x20;
        sub_630d23((void*)0x77aeb0);
    }
    return &g_laserToolStatic;
}
