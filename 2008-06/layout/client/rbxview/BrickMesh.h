#pragma once
#include "ViewNew/RenderBaseMesh.h"
#include <boost/thread/once.hpp>

namespace RBX
{
	namespace ViewNew
	{
		class BrickMesh : public RenderBase::Mesh
		{
		public:
			static const float normalPerturbation;    // 00826e3c
			static const float bevel;                 // 00826e38 (0.0f; read only by the PBB Face / Side strips)

			struct Cache;
		private:
			static Cache* cache;                      // 00972754
			static boost::once_flag cacheFlag;        // 00972870
			static void initCache();                  // 004e5360
			static void releaseUnused();              // 004e5710
		public:
			static void flushCache();                 // 004e5670
		};
	}
}
