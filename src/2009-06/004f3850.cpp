// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX { namespace Reflection {
struct Slot;
void disconnectSlot(Slot* s);
class SlotList
{
public:
	void visit(void (*fn)(Slot*));
};
class EventSource
{
	char pad[0x10];
	SlotList* slots;
public:
	void disconnectAll();
};
void EventSource::disconnectAll()
{
	if (slots)
		slots->visit(&disconnectSlot);
}
}}
