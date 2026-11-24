// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no class header was supplied, so the function is declared on a raw `self` pointer
// with the member offsets taken from the disassembly. Callees use the fn_<addr> convention.

struct Heartbeat {
    float time; // INFERRED: first pushed-last value = accumulated time
    float step; // INFERRED: second value = the incoming step argument
};

// Notifier<RunService, Heartbeat>::raise (this = self + 0x150)
extern "C" void __fastcall fn_005549e0(void* notifier, int unusedEdx, Heartbeat hb);
// SignalDescriptor::findSignalInstance (this = descriptor at 0x973bb8, arg = signal source at self + 0x14)
extern "C" void* __fastcall fn_0056b620(void* descriptor, int unusedEdx, const void* source);
// signal2<void, float, float>::operator() (this = signalInstance + 0x10)
// INFERRED: the first stack argument is a pointer to the caller's step argument (edx also holds it).
extern "C" void __fastcall fn_00556eb0(void* signal, int unusedEdx, const float* p, float a, float b);

extern "C" void __fastcall fn_005571b0(char* self, int unusedEdx, float step)
{
    double& total = *(double*)(self + 0x1b8);
    total += step;

    Heartbeat hb;
    hb.time = (float)total;
    hb.step = step;
    fn_005549e0(self + 0x150, 0, hb);

    void* inst = fn_0056b620((void*)0x973bb8, 0, self + 0x14);
    if (inst)
        fn_00556eb0((char*)inst + 0x10, 0, &step, step, step);
}
