// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Hook { Hook* next; };
struct Head { int key; char pad[0x2c]; };
struct Item : Head, Hook {};
struct Finder {
	bool f(const int& key, Hook*& it, int);
};
bool Finder::f(const int& key, Hook*& it, int)
{
	for (Hook* n = it->next; n != it; n = n->next) {
		Item* o = static_cast<Item*>(n);
		if (key == o->key) {
			it = n;
			return false;
		}
	}
	return true;
}
