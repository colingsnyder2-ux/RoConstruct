// from server: 100% by tester
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct Item { void release(); };
struct Array { void resize(int, int); };
struct CXTPCommandBarList { char pad[0x24]; Array array; int count(); Item* at(int); void clear(); };
void CXTPCommandBarList::clear() { for (int i = 0; i < count(); ++i) at(i)->release(); array.resize(0, -1); }
