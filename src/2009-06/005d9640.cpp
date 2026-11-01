// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <istream>
namespace RBX {
class MD5Hasher {
public:
	virtual ~MD5Hasher() {}
	virtual void addData(const char* data, int len) = 0;
	void addData(std::istream& stream);
};
void MD5Hasher::addData(std::istream& stream)
{
	char buffer[1024];
	stream.clear();
	stream.seekg(0, std::ios::beg);
	do
	{
		stream.read(buffer, 1024);
		addData(buffer, stream.gcount());
	} while (stream.gcount() > 0);
}
}
