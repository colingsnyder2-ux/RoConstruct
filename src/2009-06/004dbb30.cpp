// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
class SpinLock {
public:
	long value;
	class scoped_lock {
		long* p;
	public:
		scoped_lock(SpinLock& l);
		~scoped_lock();
	};
};
struct Key { int a, b; };
struct Value { char pad[0x10]; int item; };
class Map {
public:
	Value& operator[](const Key& k);
};
class Owner {
public:
	char pad[0x1d0];
	SpinLock lock;
	Map map;
};
class Accessor {
public:
	char pad[0xc];
	Owner* owner;
	int* get(Key k);
};
int* Accessor::get(Key k)
{
	SpinLock& lk = owner->lock;
	SpinLock::scoped_lock l(lk);
	Owner* o = owner;
	return &o->map[k].item;
}
}
