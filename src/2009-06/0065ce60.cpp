// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace G3D { class CoordinateFrame; }
namespace RBX { namespace Reflection {
class Type {
public:
	Type(const char* name, int x);
	virtual ~Type();
	template<class T> static const Type& singleton();
};
template<class T> class TType : public Type {
public:
	TType(const char* name) : Type(name, 0) {}
	virtual ~TType() {}
};
template<> const Type& Type::singleton<G3D::CoordinateFrame>()
{
	static TType<G3D::CoordinateFrame> type("CoordinateFrame");
	return type;
}
}}
