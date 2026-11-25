// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" char g_00834c38[];   // INFERRED: unnamed global at 0x00834c38 in the original
extern "C" char g_00834c54[];   // INFERRED: unnamed global at 0x00834c54 in the original
extern "C" char g_00834c5c[];   // INFERRED: unnamed global at 0x00834c5c in the original
extern "C" char g_00834c74[];   // INFERRED: unnamed global at 0x00834c74 in the original
extern "C" char g_00834c7c[];   // INFERRED: unnamed global at 0x00834c7c in the original
extern "C" char g_00834c8c[];   // INFERRED: unnamed global at 0x00834c8c in the original
extern "C" char g_00834c9c[];   // INFERRED: unnamed global at 0x00834c9c in the original
extern "C" char g_00834cac[];   // INFERRED: unnamed global at 0x00834cac in the original
extern "C" char g_00834cbc[];   // INFERRED: unnamed global at 0x00834cbc in the original
extern "C" char g_00834ccc[];   // INFERRED: unnamed global at 0x00834ccc in the original
extern "C" char g_00834cdc[];   // INFERRED: unnamed global at 0x00834cdc in the original
extern "C" char g_00834ce4[];   // INFERRED: unnamed global at 0x00834ce4 in the original
extern "C" char g_00834cec[];   // INFERRED: unnamed global at 0x00834cec in the original
extern "C" char g_00834cfc[];   // INFERRED: unnamed global at 0x00834cfc in the original
extern "C" char g_00834eb4[];   // INFERRED: unnamed global at 0x00834eb4 in the original
extern "C" char g_00846144[];   // INFERRED: unnamed global at 0x00846144 in the original

// INFERRED: no class header was available for FactoryProduct<Hat,Accoutrement,&sHat>,
// so the layout is a file-local type and the function uses the fn_<address> convention.
struct Local_005b23f0 {
    unsigned char data[0x1d8];
};

// Accoutrement::Accoutrement(int) base constructor (__thiscall, 1 stack arg)
extern "C" void __fastcall fn_005b2230(Local_005b23f0* self, int unusedEdx, int arg);

extern "C" Local_005b23f0* __fastcall fn_005b23f0(Local_005b23f0* self, int unusedEdx, int initialize)
{
    unsigned char* data = self->data;
    volatile int state = 0;

    if (initialize) {
        *reinterpret_cast<unsigned long*>(data + 0x150) = ((int)&g_00834eb4);
        *reinterpret_cast<unsigned long*>(data + 0x1d4) = ((int)&g_00846144);
    }

    fn_005b2230(self, 0, 0);

    int* table = *reinterpret_cast<int**>(data + 0x150);

    *reinterpret_cast<unsigned long*>(data) = ((int)&g_00834cfc);
    *reinterpret_cast<unsigned long*>(data + 0x10) = ((int)&g_00834cec);
    *reinterpret_cast<unsigned long*>(data + 0x14) = ((int)&g_00834ce4);
    *reinterpret_cast<unsigned long*>(data + 0x20) = ((int)&g_00834cdc);
    *reinterpret_cast<unsigned long*>(data + 0x24) = ((int)&g_00834ccc);
    *reinterpret_cast<unsigned long*>(data + 0x44) = ((int)&g_00834cbc);
    *reinterpret_cast<unsigned long*>(data + 0x64) = ((int)&g_00834cac);
    *reinterpret_cast<unsigned long*>(data + 0x84) = ((int)&g_00834c9c);
    *reinterpret_cast<unsigned long*>(data + 0xa4) = ((int)&g_00834c8c);
    *reinterpret_cast<unsigned long*>(data + 0xc4) = ((int)&g_00834c7c);
    *reinterpret_cast<unsigned long*>(data + 0x130) = ((int)&g_00834c74);
    *reinterpret_cast<unsigned long*>(data + 0x140) = ((int)&g_00834c5c);

    *reinterpret_cast<unsigned long*>(data + 0x150 + table[1]) = ((int)&g_00834c54);
    table = *reinterpret_cast<int**>(data + 0x150);
    *reinterpret_cast<unsigned long*>(data + 0x150 + table[2]) = ((int)&g_00834c38);

    table = *reinterpret_cast<int**>(data + 0x150);
    int offset = table[1];
    *reinterpret_cast<int*>(data + 0x14c + offset) = offset - 0x78;

    table = *reinterpret_cast<int**>(data + 0x150);
    offset = table[2];
    *reinterpret_cast<int*>(data + 0x14c + offset) = offset - 0x80;

    return self;
}
