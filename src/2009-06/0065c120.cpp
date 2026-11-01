// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
class Name;
class Guid
{
public:
	struct Data { const Name* scope; int index; };
	Data data;
};
class Primitive
{
public:
	void setGuid(const Guid& value);
};
class PartInstance
{
public:
	virtual void onGuidChanged();
	char pad[8];
	Guid guid;
	char pad2[0x118 - 0xc - sizeof(Guid)];
	Primitive* primitive;
};
void PartInstance::onGuidChanged()
{
	primitive->setGuid(guid);
}
}
