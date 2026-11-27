// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
namespace G3D {
class Vector3 { public: float x, y, z; };
class Vector3int16 { public: short x, y, z; };
}
namespace RBX {
using G3D::Vector3;
using G3D::Vector3int16;
enum NormalId { NORM_X, NORM_Y, NORM_Z, NORM_X_NEG, NORM_Y_NEG, NORM_Z_NEG };
enum GeoPairType { BALL_POINT_PAIR = 0, BALL_EDGE_PAIR = 1, BALL_PLANE_PAIR = 2 };
class Block {
    char pad[0x28];
    const Vector3* vertices;
    const Vector3* getCornerPoint(const Vector3int16& clip) const
    {
        return &vertices[((clip.x <= 0) * 2 + (clip.y <= 0)) * 2 + (clip.z <= 0)];
    }
    const Vector3* getEdgePoint(const Vector3int16& clip, NormalId& normalID) const;
    const Vector3* getPlanePoint(const Vector3int16& clip, NormalId& normalID) const;
public:
    GeoPairType getBallBlockInfo(int onBorder, Vector3int16 clip, const Vector3*& offset, NormalId& normalID);
};
GeoPairType Block::getBallBlockInfo(int onBorder, Vector3int16 clip, const Vector3*& offset, NormalId& normalID)
{
	if (onBorder == 1) {
		offset = getPlanePoint(clip, normalID);
		return BALL_PLANE_PAIR;
	}
	if (onBorder == 2) {
		offset = getEdgePoint(clip, normalID);
		return BALL_EDGE_PAIR;
	}
	offset = getCornerPoint(clip);
	return BALL_POINT_PAIR;
}
}
