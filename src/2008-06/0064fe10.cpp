// from server: 100% by coldek
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_claudeL_b45f35ad0bb3c249.cpp

// Candidate translation unit (score above; library headers required).
#pragma float_control(precise,off,push)
#include <deque>
struct ChatLine {char prefix[0x44];float dieTime;};
struct Heartbeat{const float time,step;};
struct ChatOutput {char prefix[0x174];std::deque<ChatLine*> fifo;float time;void removeOldest();bool expired(){if(fifo.empty())return false;ChatLine*o=*fifo.begin();if(o->dieTime<time)return true;return false;}};
struct Tick {char prefix[0x4c];float time;void onEvent(const void*,Heartbeat);};
void Tick::onEvent(const void*,Heartbeat event){time=event.step+time;ChatOutput*self=reinterpret_cast<ChatOutput*>(reinterpret_cast<char*>(this)-0x148);for(;;){if(!self->expired())break;self->removeOldest();}}
// v0
