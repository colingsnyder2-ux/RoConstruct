// 2008-06 native RBX::ViewNew BrickMesh unit (inactive, pass 2): the BrickMesh static cache (Cache ctor 004e5300,
// initCache 004e5360, flushCache 004e5670, releaseUnused 004e5710) and the shadow box helper 004e3570 with its
// unit-local appendQuad 004de1d0. Declarations: ViewNew/BrickMesh.h and ViewNewBrickBuild2008/BrickMeshCache2008.h.
// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// >>> native-status (generated) -- do not edit >>>
// ViewNewBrickMeshBuild2008 | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 8d6d222f | roc native-status --write
#include "ViewNewBrickBuild2008/BrickMeshCache2008.h"

static int orderedCompare(const G3D::Vector3& a, const G3D::Vector3& b)   // 004dc360
{
	if (a.x < b.x)
		return -1;
	if (a.x > b.x)
		return 1;

	if (a.y < b.y)
		return -1;
	if (a.y > b.y)
		return 1;

	if (a.z < b.z)
		return -1;
	if (a.z > b.z)
		return 1;

	return 0;
}

inline bool Lookup::operator<(const Lookup& other) const
{
	int c = orderedCompare(size, other.size);
	if (c < 0)
		return true;
	if (c > 0)
		return false;
	if (surfaceTypes.data < other.surfaceTypes.data)
		return true;
	if (surfaceTypes.data > other.surfaceTypes.data)
		return false;
	if (color < other.color)       // an if statement: `return color < other.color` materializes the bool (setl)
		return true;
	return false;
}

static void appendQuad(std::vector<unsigned short>& indices, int a, int b, int c, int d)   // 004de1d0
{
	indices.push_back(a);
	indices.push_back(b);
	indices.push_back(c);
	indices.push_back(a);
	indices.push_back(c);
	indices.push_back(d);
}

namespace RBX
{
	namespace ViewNew
	{
		void buildShadowBox(const G3D::Vector3& halfSize, std::vector<G3D::Vector3>& vertices, std::vector<unsigned short>& indices)
		{
			vertices.reserve(8);
			indices.reserve(36);
			vertices.push_back(G3D::Vector3(-halfSize.x, -halfSize.y, -halfSize.z));
			vertices.push_back(G3D::Vector3(-halfSize.x, -halfSize.y, halfSize.z));
			vertices.push_back(G3D::Vector3(-halfSize.x, halfSize.y, -halfSize.z));
			vertices.push_back(G3D::Vector3(-halfSize.x, halfSize.y, halfSize.z));
			vertices.push_back(G3D::Vector3(halfSize.x, -halfSize.y, -halfSize.z));
			vertices.push_back(G3D::Vector3(halfSize.x, -halfSize.y, halfSize.z));
			vertices.push_back(G3D::Vector3(halfSize.x, halfSize.y, -halfSize.z));
			vertices.push_back(G3D::Vector3(halfSize.x, halfSize.y, halfSize.z));
			appendQuad(indices, 7, 5, 4, 6);
			appendQuad(indices, 2, 0, 1, 3);
			appendQuad(indices, 7, 6, 2, 3);
			appendQuad(indices, 1, 0, 4, 5);
			appendQuad(indices, 3, 1, 5, 7);
			appendQuad(indices, 6, 4, 0, 2);
		}

		BrickMesh::Cache* BrickMesh::cache;
		boost::once_flag BrickMesh::cacheFlag = BOOST_ONCE_INIT;

		void BrickMesh::initCache()
		{
			cache = new Cache();
		}

		void BrickMesh::flushCache()
		{
			boost::call_once(&initCache, cacheFlag);
			Cache& c = *cache;
			boost::recursive_mutex::scoped_lock lock(c.mutex);
			c.meshes.clear();
		}

		void BrickMesh::releaseUnused()
		{
			boost::call_once(&initCache, cacheFlag);
			Cache& c = *cache;
			boost::recursive_mutex::scoped_lock lock(c.mutex);
			for (std::map<Lookup, Variations>::iterator i = c.meshes.begin(); i != c.meshes.end(); ++i)
			{
				for (int k = 0; k < 4; ++k)
				{
					if (i->second.meshes[k].notNull() && i->second.meshes[k].isLastReference())
						i->second.meshes[k] = NULL;
				}
			}
		}
	}
}

template Variations& std::map<Lookup, Variations>::operator[](const Lookup&);

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class G3D::ReferenceCountedPointer<RBX::RenderBase::Mesh>;
template class std::_Container_base_aux_alloc_real<std::allocator<std::pair<Lookup const ,Variations> > >;
template class std::_Tmap_traits<Lookup,Variations,std::less<Lookup>,std::allocator<std::pair<Lookup const ,Variations> >,0>;
template class std::_Tree<std::_Tmap_traits<Lookup,Variations,std::less<Lookup>,std::allocator<std::pair<Lookup const ,Variations> >,0> >;
template class std::_Vector_const_iterator<G3D::Vector3,std::allocator<G3D::Vector3> >;
template class std::_Vector_const_iterator<unsigned short,std::allocator<unsigned short> >;
template class std::_Vector_iterator<G3D::Vector3,std::allocator<G3D::Vector3> >;
template class std::_Vector_iterator<unsigned short,std::allocator<unsigned short> >;
template class std::allocator<std::_Tree_nod<std::_Tmap_traits<Lookup,Variations,std::less<Lookup>,std::allocator<std::pair<Lookup const ,Variations> >,0> >::_Node *>;
template class std::allocator<std::pair<Lookup const ,Variations> >;
template class std::vector<G3D::Vector3,std::allocator<G3D::Vector3> >;
template class std::vector<unsigned short,std::allocator<unsigned short> >;
