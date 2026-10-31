// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <ostream>
#include <string>
struct Name { std::string name; };
class XmlElement { char pad[0x10]; const Name* tag; public: const Name& getTag() const { return *tag; } };
class TextXmlWriter {
	char pad[0x24];
	std::ostream& stream;
protected:
	void writeCloseTag(const XmlElement* element, int depth);
};
void TextXmlWriter::writeCloseTag(const XmlElement* element, int depth)
{
	for (int i = 0; i < depth; ++i) {
		stream << '\t';
	}
	stream << "</" << element->getTag().name << '>';
}
