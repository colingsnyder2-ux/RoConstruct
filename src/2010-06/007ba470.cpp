// from server: 100% by tester
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct Array { char pad[8]; int size; void append(int, int); };
struct CXTPCommandBarList { char pad[0x24]; Array array; int f(int); };
int CXTPCommandBarList::f(int value) { Array* receiver = &array; int index = receiver->size; receiver->append(index, value); return value; }
