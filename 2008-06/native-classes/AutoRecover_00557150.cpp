// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: callees declared as C helpers; RunService layout offsets taken from the disassembly.

extern "C" void __fastcall fn_005559a0(void* self, int unusedEdx);
extern "C" void __fastcall fn_00554960(void* notifier, int unusedEdx, float time, float step);
extern "C" void* __fastcall fn_0056b620(void* descriptor, int unusedEdx, const void* source);
extern "C" void __fastcall fn_004937f0(void* signal, int unusedEdx, float arg, const float* argRef);

extern "C" void __fastcall fn_00557150(char* self, int unusedEdx, float step)
{
    fn_005559a0(self, 0);                       // drainTasks
    float time = (float)*(double*)(self + 0x1b8);
    fn_00554960(self + 0x130, 0, time, step);   // Notifier<RunService, Heartbeat>::raise

    void* sig = fn_0056b620((void*)0x973b40, 0, self + 0x14);   // findSignalInstance
    if (sig)
        fn_004937f0((char*)sig + 0x10, 0, step, &step);
}
