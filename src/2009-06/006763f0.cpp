// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace G3D {
class Vector2 { public: float x, y; };
class Vector3 { public: float x, y, z; Vector2 xz() const; };
class Matrix3 { public: float elt[3][3]; };
class CoordinateFrame { public: Matrix3 rotation; Vector3 translation; };
}
namespace RBX {
class Base8 { public: int a, b; };
class TreeNode { public: int x; };
class Primitive : public Base8, public TreeNode {
public:
	const G3D::CoordinateFrame& getCoordinateFrame() const;
};
class Root { public: char pad[0x1c]; TreeNode* root; };
class Assembly {
public:
	char pad[0x24];
	Root* tree;
	Primitive* getAssemblyPrimitive() const { return static_cast<Primitive*>(tree->root); }
	G3D::Vector2 getPositionXZ() const;
};
G3D::Vector2 Assembly::getPositionXZ() const
{
	return getAssemblyPrimitive()->getCoordinateFrame().translation.xz();
}
}
