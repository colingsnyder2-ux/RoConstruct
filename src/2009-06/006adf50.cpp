// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD /fp:fast
struct Other { char pad[0xcc]; float scale; void setValue(float v); };
struct Obj { char pad[0x40]; double t; void reset(Other* o, float f); };
void Obj::reset(Other* o, float f) { t = 0.0; o->setValue(o->scale * f); }
