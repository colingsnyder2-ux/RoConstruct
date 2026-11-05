// from server: 100% by Espeon
struct Heartbeat {const float time;const float step;Heartbeat(float t,float s):time(t),step(s){}};
struct Signal {void raise(Heartbeat);};
struct Listener {void emit(const float*,float);};
struct Result {char pad[0x10];Listener listener;};
struct Registry {Result* find(const void*);};
struct Primary {char pad[0x14];};
struct Instance {char pad[0x11c];};
struct RunService:Primary,Instance {char pad[0x88];double time;void tick();void f(float);};
void RunService::f(float step) {
 tick();
 reinterpret_cast<Signal*>((char*)this+0x130)->raise(Heartbeat((float)time,step));
 Result* r=reinterpret_cast<Registry*>(0x973b40)->find(static_cast<Instance*>(this));
 if(r)r->listener.emit(&step,step);
}
