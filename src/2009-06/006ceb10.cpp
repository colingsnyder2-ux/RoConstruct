// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
namespace RBX {
class Ball { public: void update(); };
struct Prim { char pad[0x2c]; Ball* ball; };
class RevoluteLink { char pad0[4]; Prim* prim; public: void update(); };
void RevoluteLink::update()
{
    if (prim)
        prim->ball->update();
}
}
