// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Slot {
	char data[0x28];
	Slot(const Slot&);
	~Slot();
};
class Connection {
	void* registry;
	int pad;
	int item;
	void connect(Slot slot);
public:
	Connection(Slot slot, int unused);
};
Connection::Connection(Slot slot, int) : registry(0) { connect(slot); }
