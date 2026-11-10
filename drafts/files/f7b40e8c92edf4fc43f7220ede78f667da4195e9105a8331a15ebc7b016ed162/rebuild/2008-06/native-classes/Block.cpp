// 2008-06 native RBX::Block (inactive); evidence in native-headers/v8world/Block2008.h.
// Verified by tests/record_native_world_shapes.py. Unit 00647700..00649120: Block methods, the file-local
// RBX::myLess / RBX::BlockTemplate (0x60 bytes: BlockTemplate::getVertices 00648f30 news 0x60) and the
// std::map<Vector3, BlockTemplate*, myLess> members it instantiates.
// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
#include "v8world/Block2008.h"
#include "util/Math.h"
#include <G3D/AABox.h>
#include <G3D/CollisionDetection.h>
#include <functional>
#include <map>

namespace RBX
{
	static G3D::Vector3 vector3Abs(const G3D::Vector3& value)
	{
		return G3D::Vector3(fabsf(value.x), fabsf(value.y), fabsf(value.z));
	}

	struct myLess : public std::binary_function<G3D::Vector3, G3D::Vector3, bool>
	{
		// 00647760
		bool operator()(const G3D::Vector3& a, const G3D::Vector3& b) const
		{
			if (a.x < b.x)
				return true;
			if (a.x > b.x)
				return false;
			if (a.y < b.y)
				return true;
			if (a.y > b.y)
				return false;
			if (a.z < b.z)
				return true;
			return false;
		}
	};

	class BlockTemplate
	{
	public:
		static const G3D::Vector3* getVertices(const G3D::Vector3& corner);   // 00648f30

	private:
		BlockTemplate(const G3D::Vector3& _corner);                           // 00647e70

		class BlockTemplates : public std::map<G3D::Vector3, BlockTemplate*, myLess>
		{
		public:
			~BlockTemplates();                                                 // 006490b0
		};

		static BlockTemplates blockTemplates;                                  // 0097d5ec

		G3D::Vector3 vertices[8];                                              // +0x0 .. +0x60
	};

	BlockTemplate::BlockTemplates BlockTemplate::blockTemplates;

	// 006477b0: thin-shell moment per axis (main axis x, then the two others cyclically).
	G3D::Matrix3 Block::getMomentHollow(float mass) const
	{
		G3D::Vector3 size = gridSize;

		float area = 2 * (size.x * size.y + size.y * size.z + size.z * size.x);
		G3D::Vector3 I;
		for (int i = 0; i < 3; i++)
		{
			int j = (i + 1) % 3;
			int k = (i + 2) % 3;
			float x = size[i];
			float y = size[j];
			float z = size[k];

			float Ix = (mass / (2.0f * area)) * ((y * y * y * z / 3.0f)
												+ (y * z * z * z / 3.0f)
												+ (x * y * z * z)
												+ (x * y * y * y / 3.0f)
												+ (x * y * y * z)
												+ (x * z * z * z / 3.0f));
			I[i] = Ix;
		}
		return Math::fromDiagonal(I);
	}

	// 006478f0
	float Block::getGridVolume() const
	{
		return gridSize.z * gridSize.y * gridSize.x;
	}

	// 00647900
	const G3D::Vector3* Block::getEdgePoint(const G3D::Vector3int16& clip, NormalId& normalID) const
	{
		if (clip.x == 0)
		{
			normalID = NORM_X;
			return &vertices[4 + 2 * (clip.y <= 0) + (clip.z <= 0)];
		}
		if (clip.y == 0)
		{
			normalID = NORM_Y;
			return &vertices[2 + 4 * (clip.x <= 0) + (clip.z <= 0)];
		}
		normalID = NORM_Z;
		return &vertices[2 * (2 * (clip.x <= 0) + (clip.y <= 0)) + 1];
	}

	// 00647990
	const G3D::Vector3* Block::getPlanePoint(const G3D::Vector3int16& clip, NormalId& normalID) const
	{
		if (clip.x != 0)
		{
			normalID = clip.x > 0 ? NORM_X : NORM_X_NEG;
			return &vertices[4 * (clip.x <= 0)];
		}
		if (clip.y != 0)
		{
			normalID = clip.y > 0 ? NORM_Y : NORM_Y_NEG;
			return &vertices[2 * (clip.y <= 0)];
		}
		normalID = clip.z > 0 ? NORM_Z : NORM_Z_NEG;
		return &vertices[clip.z <= 0];
	}

	// 00647a20
	GeoPairType Block::getBallBlockInfo(int onBorder, G3D::Vector3int16 clip, const G3D::Vector3*& offset, NormalId& normalID)
	{
		if (onBorder == 1)
		{
			offset = getPlanePoint(clip, normalID);
			return BALL_PLANE_PAIR;
		}
		if (onBorder == 2)
		{
			offset = getEdgePoint(clip, normalID);
			return BALL_EDGE_PAIR;
		}
		offset = getCornerPoint(clip);
		return BALL_POINT_PAIR;
	}

	// 00647ab0
	GeoPairType Block::getBallInsideInfo(const G3D::Vector3& ray, const G3D::Vector3*& offset, NormalId& normalID)
	{
		float smallest = 1e30f;
		const G3D::Vector3& corner = *vertices;

		for (int i = 0; i < 3; i++)
		{
			float d = corner[i] - ray[i];
			if (smallest > d)
			{
				smallest = d;
				normalID = (NormalId)i;
			}
			d = ray[i] - corner[i];
			if (smallest > d)
			{
				smallest = d;
				normalID = (NormalId)(i + 3);
			}
		}

		offset = normalID > 2 ? &vertices[7] : vertices;
		return BALL_PLANE_PAIR;
	}

	// 00647b90
	void Block::projectToFace(G3D::Vector3& ray, G3D::Vector3int16& clip, int& onBorder)
	{
		onBorder = 0;
		const G3D::Vector3& corner = *vertices;

		if (ray.x > corner.x)
		{
			ray.x = corner.x;
			onBorder++;
			clip.x = 1;
		}
		if (ray.x < -corner.x)
		{
			ray.x = -corner.x;
			onBorder++;
			clip.x = -1;
		}
		if (ray.y > corner.y)
		{
			ray.y = corner.y;
			onBorder++;
			clip.y = 1;
		}
		if (ray.y < -corner.y)
		{
			ray.y = -corner.y;
			onBorder++;
			clip.y = -1;
		}
		if (ray.z > corner.z)
		{
			ray.z = corner.z;
			onBorder++;
			clip.z = 1;
		}
		if (ray.z < -corner.z)
		{
			ray.z = -corner.z;
			onBorder++;
			clip.z = -1;
		}
	}

	// 00647c70
	G3D::Vector2 Block::getProjectedVertex(const G3D::Vector3& vertex, NormalId normalID)
	{
		G3D::Vector2 answer(0, 0);
		switch (normalID)
		{
		case NORM_X:
			answer.x = vertex.y;
			answer.y = vertex.z;
			break;
		case NORM_Y:
			answer.x = vertex.z;
			answer.y = vertex.x;
			break;
		case NORM_Z:
			answer.x = vertex.x;
			answer.y = vertex.y;
			break;
		case NORM_X_NEG:
			answer.x = vertex.z;
			answer.y = vertex.y;
			break;
		case NORM_Y_NEG:
			answer.x = vertex.x;
			answer.y = vertex.z;
			break;
		case NORM_Z_NEG:
			answer.x = vertex.y;
			answer.y = vertex.x;
			break;
		}
		return answer;
	}

	// 00647d10
	int Block::getClosestEdge(const G3D::Matrix3& rotation, NormalId normalID, G3D::Vector3& crossAxis)
	{
		// crossAxis * rotation (vector to object space). Codegen analog: the original sums the column terms z, y,
		// x in this order under /fp:fast (00647d1b..00647d69); the donor G3D operator* (x, y, z) reorders them.
		G3D::Vector3 axisInBody;
		for (int r = 0; r < 3; ++r)
		{
			float sum = crossAxis[2] * rotation[2][r];
			sum += crossAxis[1] * rotation[1][r];
			sum += crossAxis[0] * rotation[0][r];
			axisInBody[r] = sum;
		}
		G3D::Vector2 projected = getProjectedVertex(axisInBody, normalID);

		if (projected.y > 0)
		{
			if (projected.x > 0)
				return normalID * 4;
			return normalID * 4 + 1;
		}
		if (projected.x > 0)
			return normalID * 4 + 3;
		return normalID * 4 + 2;
	}

	// 00647e70
	BlockTemplate::BlockTemplate(const G3D::Vector3& _corner)
	{
		float x = -fabsf(_corner.x);
		float y = -fabsf(_corner.y);
		float z = -fabsf(_corner.z);

		for (int i = 0; i < 2; i++)
		{
			x = x * -1.0f;
			for (int j = 0; j < 2; j++)
			{
				y = y * -1.0f;
				for (int k = 0; k < 2; k++)
				{
					z = z * -1.0f;
					vertices[4 * i + 2 * j + k] = G3D::Vector3(x, y, z);
				}
			}
		}
	}

	// 00647f40
	bool Block::hitTest(const G3D::Ray& rayInMe, G3D::Vector3& localHitPoint, bool& inside)
	{
		G3D::Vector3 halfSize = gridSize * 0.5f;
		inside = false;

		bool hit = G3D::CollisionDetection::collisionLocationForMovingPointFixedAABox(
			rayInMe.origin,
			rayInMe.direction,
			G3D::AABox(-halfSize, halfSize),
			localHitPoint,
			inside);

		if (!inside)
			return hit;

		inside = false;
		G3D::Ray outsideRay = G3D::Ray::fromOriginAndDirection(rayInMe.origin - rayInMe.direction * 1000.0f, rayInMe.direction);
		G3D::CollisionDetection::collisionLocationForMovingPointFixedAABox(
			outsideRay.origin,
			outsideRay.direction,
			G3D::AABox(-halfSize, halfSize),
			localHitPoint,
			inside);
		return true;
	}

	// 00648270
	G3D::Vector3 Block::getCenterToCorner(const G3D::Matrix3& rotation) const
	{
		if (cornerRadius < 3.0f)   // 00648270: constant 3.0f at 0081e380
			return G3D::Vector3(cornerRadius, cornerRadius, cornerRadius);

		G3D::Vector3 maxValue = vector3Abs(rotation * vertices[0]);
		for (int i = 1; i < 4; i++)
			maxValue = maxValue.max(vector3Abs(rotation * vertices[i]));
		return maxValue;
	}

	// 00648f30
	const G3D::Vector3* BlockTemplate::getVertices(const G3D::Vector3& corner)
	{
		BlockTemplates::iterator iter = blockTemplates.find(corner);
		if (iter != blockTemplates.end())
			return iter->second->vertices;

		BlockTemplate* answer = new BlockTemplate(corner);
		blockTemplates[corner] = answer;
		return answer->vertices;
	}

	// 00648fd0
	void Block::onSetSize()
	{
		vertices = BlockTemplate::getVertices(gridSize * -0.5f);
		cornerRadius = vertices[0].magnitude();
	}

	// 006490b0
	BlockTemplate::BlockTemplates::~BlockTemplates()
	{
		iterator iter = begin();
		while (iter != end())
		{
			delete iter->second;
			iter++;
		}
	}
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class std::_Container_base_aux_alloc_real<std::allocator<std::pair<G3D::Vector3 const ,RBX::BlockTemplate *> > >;
template class std::_Tree<std::_Tmap_traits<G3D::Vector3,RBX::BlockTemplate *,RBX::myLess,std::allocator<std::pair<G3D::Vector3 const ,RBX::BlockTemplate *> >,0> >;
template class std::allocator<std::_Tree_nod<std::_Tmap_traits<G3D::Vector3,RBX::BlockTemplate *,RBX::myLess,std::allocator<std::pair<G3D::Vector3 const ,RBX::BlockTemplate *> >,0> >::_Node *>;
template class std::allocator<std::pair<G3D::Vector3 const ,RBX::BlockTemplate *> >;
