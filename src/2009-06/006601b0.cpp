// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Slot;
struct Signal { void visitSlots(void (*f)(Slot*)); };
void disconnectSlot(Slot*);
struct Owner { char pad[0x178]; Signal* sig; void disconnectAll(); };
void Owner::disconnectAll() { if (sig) sig->visitSlots(&disconnectSlot); }
