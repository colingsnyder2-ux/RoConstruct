// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD

struct SignalTarget
{
	virtual void slot0();
	virtual void slot1();
	virtual void slot2();
	virtual void slot3();
	virtual void slot4();
	virtual void slot5();
	virtual void slot6(int value);
};

struct VHumanoid
{
	char pad0[0x34];
	SignalTarget* signal;

	void fireSignal();
};

void VHumanoid::fireSignal()
{
	signal->slot6(2);
}
