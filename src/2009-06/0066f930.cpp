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
	void assign(Data data);
	Data data;
};
class Primitive
{
	char exePad2009[0x74];
	Guid guid;
	bool guidSetExternally;
public:
	void setGuid(const Guid& value);
};
void Primitive::setGuid(const Guid& value)
{
	guid.assign(value.data);
	guidSetExternally = true;
}
}
