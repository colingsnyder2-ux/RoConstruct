// native-flags: /O2 /EHsc /MD /GS- /IC:\Users\colin\RoConstruct\tools\rbxgs\Client\Network\raknet30\Source /I{headers}/../native-classes
// 004ce270: forwarding thunk generated from its proven jump target (thunk_lane.py, no model)
#include "HuffmanEncodingTree.cpp"
// INFERRED: 004ce270 is a 5-byte jump to DataStructures::CircularLinkedList<struct HuffmanEncodingTreeNode *>::Clear; the forwarder name and owner are placeholders.
struct Thunk_004ce270 : DataStructures::CircularLinkedList<struct HuffmanEncodingTreeNode *> { void sub_004ce270(); };
void Thunk_004ce270::sub_004ce270() { DataStructures::CircularLinkedList<struct HuffmanEncodingTreeNode *>::Clear(); }
