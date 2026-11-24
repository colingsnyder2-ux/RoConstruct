// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: callees are declared as real __thiscall member functions so the compiler
// emits plain thiscall sequences (no dummy edx). The member names stand in for the
// real symbols (drainTasks, Notifier::raise, findSignalInstance, signal1::operator()).
struct Heartbeat {
    const float time;
    const float step;
    Heartbeat(float t, float s) : time(t), step(s) {}
};

struct Signal {
    void raise(Heartbeat); // 0x554960
};

struct Listener {
    void emit(const float*, float); // 0x4937f0
};

struct Result {
    char pad[0x10];
    Listener listener;
};

struct Registry {
    Result* find(const void*); // 0x56b620
};

struct Primary { char pad[0x14]; };
struct Instance { char pad[0x11c]; };

struct RunService : Primary, Instance {
    char pad[0x88];
    double time;
    void tick(); // 0x5559a0 drainTasks
};

// INFERRED: the object at 0x973b40 is the SignalDescriptor global used for findSignalInstance.
extern "C" Registry g_00973b40;

extern "C" void __fastcall fn_00557150(RunService* self, int unusedEdx, float step)
{
    self->tick();
    reinterpret_cast<Signal*>(reinterpret_cast<char*>(self) + 0x130)->raise(Heartbeat((float)self->time, step));
    Result* r = g_00973b40.find(static_cast<Instance*>(self));
    if (r)
        r->listener.emit(&step, step);
}
