// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
namespace RBX {
struct A0 { virtual ~A0(); int pad[4]; };
struct A1 { virtual void a1(); };
struct A2 { virtual void a2(); void* descriptor; };
struct A3 { virtual void a3(); char pad[0x68]; };
struct A4 { virtual void a4(); char pad[0x10]; };
void* textureDescriptor();
struct TextureId {
	std::string id;
	void* desc;
	TextureId() : desc(textureDescriptor()) {}
};
class FaceInstance : public A0, public A1, public A2, public A3, public A4 {
public:
	FaceInstance();
	void setName(const std::string& name);
};
class Decal : public FaceInstance {
public:
	Decal();
	virtual ~Decal();
	TextureId texture;
	float specular;
	float shiny;
};
Decal::Decal() : specular(0), shiny(20)
{
	setName("Decal");
}
}
