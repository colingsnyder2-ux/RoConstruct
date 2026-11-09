// from server: 100% by colin
// roc 2007-08 00596660  unit: RBX::LaserTool  size: 81 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00596660

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
    RTL_CRITICAL_SECTION cs;   // 0x8c4e14
    int field_2c;              // 0x8c4e2c
    int field_30;              // 0x8c4e30
    int field_34;              // 0x8c4e34
    int field_38;              // 0x8c4e38
    int field_3c;              // 0x8c4e3c
    int initFlag;              // 0x8c4e40
};

extern LaserToolStatic g_laserToolStatic;

extern "C" void __cdecl sub_00630d23(void*);

LaserToolStatic* getLaserToolStatic()
{
    if (!(g_laserToolStatic.initFlag & 1)) {
        g_laserToolStatic.initFlag |= 1;
        InitializeCriticalSection(&g_laserToolStatic.cs);
        g_laserToolStatic.field_2c = 0;
        g_laserToolStatic.field_30 = 0;
        g_laserToolStatic.field_34 = 0;
        g_laserToolStatic.field_38 = 0x20;
        g_laserToolStatic.field_3c = 0x20;
        sub_00630d23((void*)0x77aed0);
    }
    return &g_laserToolStatic;
}
