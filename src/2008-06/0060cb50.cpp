// from server: 100% by tester
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
namespace RBX {
class ContactConnector;
class Contact { char pad[0x34]; ContactConnector* connector; public: void deleteConnector(ContactConnector*& c); void onPrimitiveRemoved(); };
void Contact::onPrimitiveRemoved() { if (connector) deleteConnector(connector); }
}
