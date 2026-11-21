#pragma once
#include "reflection/reflection.h"
#include "util/Object.h"
#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>

struct NativeReplicatorLayout;

namespace RBX
{
	namespace Network
	{
		extern const char sMarker[];

		class Marker : public DescribedNonCreatable<Marker, Reflection::DescribedBase, sMarker>, private boost::noncopyable
		{
			friend struct ::NativeReplicatorLayout; // tests/NativeReplicatorLayout.cpp offset asserts
		private:
			bool returned;                                                            // +0xc

		private:
			Marker()                                                                  // 004b9140
				: returned(false)
			{
			}

		public:
			static boost::shared_ptr<Marker> newMarker()                              // 004b9190
			{
				return boost::shared_ptr<Marker>(new Marker);
			}
		};
	}
}
