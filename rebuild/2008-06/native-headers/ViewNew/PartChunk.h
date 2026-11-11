#pragma once
// >>> native-status (generated) -- do not edit >>>
// PartChunk | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 80fe20d8 | roc native-status --write
// 2008-06 native RBX::ViewNew::PartChunk / Part / Decal / Texture (inactive). The donor tree has no ViewNew/
// directory, so this header shadows nothing (the donor shape is Client/RbxView/Part.h, namespace RBX::View).
//   PartChunk  RTTI vtable 00826ec4 -> RenderBase::Chunk -> G3D::ReferenceCountedObject (all mdisp 0). Abstract
//              (slots 5 and 10 are _purecall). ctor 004eaae0 (float polygonOffset, const shared_ptr<PartInstance>&,
//              view; ret 0xc): Chunk(polygonOffset) 004e8160, vptr, coordinateFrame +0x28 (CoordinateFrame ctor
//              004782d0), five scoped_connections of 0x14 bytes at +0x58 / +0x6c / +0x80 / +0x94 / +0xa8 (+4 / +8
//              zeroed, bytes +0xc / +0x10 cleared), partInstance shared_ptr +0xbc / +0xc0, material +0xc4 = NULL,
//              materialInvalid +0xc8 = true, mesh +0xcc = NULL, view +0xd0, specialShape +0xd4 = NULL.
//              The connections are, in order, event 00973e90 (slot 004ea5e0), event 00973c6c (slot 004e73b0),
//              event_ancestryChanged 00973c38 (slot 004e6520), the property-changed event 00973f48 (vcall of slot
//              11) and the special-shape property connection (assigned outside the ctor).
//              dtor 004e8250 destroys mesh, material, partInstance, the five connections (reverse), then ~Chunk.
//              Slots: 0 ??_G 004e8fc0, 1 cachesShadows (Chunk inline, folded 0060a2f0), 2 renderShadows (Chunk
//              inline, folded 004e83a0), 3 castsShadows / 4 cullable (folded `mov al, 1; ret` 00565950),
//              5 getMaterial pure, 6 getMesh 004e6b50, 7 cframe 004e5ff0, 8 / 9 Chunk 004e5b60 / 004e5b70,
//              10 updateMesh pure (getMesh calls [vtbl+0x28]), 11 onPropertyChanged 004e6a30 ([vtbl+0x2c]).
//              invalidateMesh 004e6740 (releases +0xcc) and invalidateMaterial 004e68b0 (releases +0xc4, sets +0xc8)
//              read PartInstance +0x1c8, so they are not built here (PartInstance layout belongs to its owner).
//   Part       RTTI vtable 00826f94 -> PartChunk, Chunk, RCO, Listener<PartInstance, CanAggregateChanged> (mdisp
//              0xd8, vtable 00826f88: 0 onEvent 004e6400, 1 ??_E thunk 004ea460). new 0xf0 (004db80b before the
//              ctor 004ebcc0). ctor stores both vptrs and clears the scoped_connection at +0xdc.
//              dtor 004ea3e0: if (partInstance) PartInstance+0x1a0 (Notifier<PartInstance, CanAggregateChanged>)
//              ->removeListener(this + 0xd8) (005e5a80), ~scoped_connection +0xdc, ~PartChunk. ??_G 004ea470.
//              Slots 5 getMaterial 004eb190, 10 updateMesh 004ef930, 11 onPropertyChanged 004e6b00.
//   Decal      RTTI vtable 00826ef8 -> PartChunk. new 0x108 (004db975 before the ctor 004eae10). ctor: decal
//              shared_ptr<RBX::Decal> +0xd8 / +0xdc, scoped_connections +0xe0 / +0xf4. dtor 004e8550 in reverse,
//              ??_G 004e8fe0. Slots 5 getMaterial 004ebe70, 10 updateMesh 004f0300.
//   Texture    RTTI vtable 00826f2c -> PartChunk. new 0x108 (004db92e before the ctor 004eafd0); same members as
//              Decal with shared_ptr<RBX::Texture> +0xd8. dtor 004e85f0, ??_G 004e9000. Slots 5 getMaterial
//              004ec070, 10 updateMesh 004f0540.
// Only forward declarations of PartInstance / CanAggregateChanged / MaterialBase here: the native
// v8datamodel/PartInstance.h reaches the donor RbxGraphics/TextureProxyBase.h (util/IRenderable.h -> Adorn.h), which
// cannot share a unit with RenderLib/Material2008.h (TextureProxyBase2008.h). Units include what their bodies need.
#include "RenderLib/AggregateChunk2008.h"
#include "util/Events.h"
#include <boost/shared_ptr.hpp>
#include <boost/signals/connection.hpp>

struct NativeViewNewPartLayout;

namespace RBX
{
	class Instance;
	class PartInstance;
	struct CanAggregateChanged;
	class ViewBase;     // the views (ViewRbxGfx / ViewG3D, RTTI base RBX::ViewBase) pass `this`; only stored here
	class SpecialShape;
	class Decal;
	class Texture;

	namespace Reflection
	{
		class PropertyDescriptor;
	}

	namespace ViewNew
	{
		class PartChunk : public RenderBase::Chunk
		{
			friend struct ::NativeViewNewPartLayout;
		private:
			G3D::CoordinateFrame coordinateFrame;                               // +0x28
			boost::signals::scoped_connection childAddedConnection;             // +0x58
			boost::signals::scoped_connection childRemovedConnection;           // +0x6c
			boost::signals::scoped_connection ancestorChangedConnection;        // +0x80
			boost::signals::scoped_connection propertyChangedConnection;        // +0x94
			boost::signals::scoped_connection shapePropertyChangedConnection;   // +0xa8
		protected:
			boost::shared_ptr<PartInstance> partInstance;                       // +0xbc
			G3D::ReferenceCountedPointer<RenderBase::MaterialBase> material;    // +0xc4
			bool materialInvalid;                                               // +0xc8
			G3D::ReferenceCountedPointer<RenderBase::Mesh> mesh;                // +0xcc
			ViewBase* view;                                                     // +0xd0
			SpecialShape* specialShape;                                         // +0xd4

		private:
			virtual void updateMesh() = 0;                                      // slot 10
		public:
			virtual ~PartChunk();                                               // 004e8250
			virtual bool castsShadows() const
			{
				return true;
			}
			virtual bool cullable() const
			{
				return true;
			}
		protected:
			PartChunk(float polygonOffset, const boost::shared_ptr<PartInstance>& partInstance, ViewBase* view); // 004eaae0
			void invalidateMesh();                                              // 004e6740
			void invalidateMaterial();                                          // 004e68b0
			virtual void onPropertyChanged(const Reflection::PropertyDescriptor* descriptor); // slot 11, 004e6a30
		public:
			virtual G3D::ReferenceCountedPointer<RenderBase::Mesh> getMesh();   // 004e6b50
			virtual const G3D::CoordinateFrame& cframe();                       // 004e5ff0
		private:
			// slots bound in the ctor (boost::bind RTTI .?AV?$bind_t@XV?$mf1@XVPartChunk@ViewNew@RBX@@V?$shared_ptr@
			// VInstance@RBX@@@boost@@... and mf0<void, PartChunk>)
			void onChildAdded(boost::shared_ptr<Instance> child);               // 004ea5e0
			void onChildRemoved(boost::shared_ptr<Instance> child);             // 004e73b0
			void onAncestorChanged(boost::shared_ptr<Instance> ancestor);       // 004e6520
			void onSpecialShapeChanged();
		};

		class Part : public PartChunk, public Listener<PartInstance, CanAggregateChanged>
		{
			friend struct ::NativeViewNewPartLayout;
		private:
			boost::signals::scoped_connection connection;                       // +0xdc (signal 009761d4, slot 004e73a0)

		public:
			Part(const boost::shared_ptr<PartInstance>& partInstance, ViewBase* view); // 004ebcc0
			virtual ~Part();                                                    // 004ea3e0
			virtual G3D::ReferenceCountedPointer<RenderBase::MaterialBase> getMaterial(); // 004eb190
		protected:
			virtual void onPropertyChanged(const Reflection::PropertyDescriptor* descriptor); // 004e6b00
			virtual void onEvent(const PartInstance* source, CanAggregateChanged event);   // 004e6400
		private:
			bool usesMegaTexture() const;                                       // 004e5f80 (reads PartInstance +0x1dc)
			void invalidate();                                                  // 004e73a0
			virtual void updateMesh();                                          // 004ef930
		};

		class Decal : public PartChunk
		{
			friend struct ::NativeViewNewPartLayout;
		private:
			boost::shared_ptr<RBX::Decal> decal;                                // +0xd8
			boost::signals::scoped_connection decalAncestorChangedConnection;   // +0xe0
			boost::signals::scoped_connection decalPropertyChangedConnection;   // +0xf4

		public:
			Decal(RBX::Decal* decal, PartInstance* partInstance, ViewBase* view); // 004eae10
			virtual ~Decal();                                                   // 004e8550
			virtual G3D::ReferenceCountedPointer<RenderBase::MaterialBase> getMaterial(); // 004ebe70
		protected:
			void onDecalPropertyChanged(const Reflection::PropertyDescriptor* descriptor);   // 004e6b90
			void onDecalAncestorChanged(boost::shared_ptr<Instance> ancestor);               // 004e83b0
		private:
			virtual void updateMesh();                                          // 004f0300
		};

		class Texture : public PartChunk
		{
			friend struct ::NativeViewNewPartLayout;
		private:
			boost::shared_ptr<RBX::Texture> decal;                              // +0xd8
			boost::signals::scoped_connection textureAncestorChangedConnection; // +0xe0
			boost::signals::scoped_connection texturePropertyChangedConnection; // +0xf4

		public:
			Texture(RBX::Texture* decal, PartInstance* partInstance, ViewBase* view); // 004eafd0
			virtual ~Texture();                                                 // 004e85f0
			virtual G3D::ReferenceCountedPointer<RenderBase::MaterialBase> getMaterial(); // 004ec070
		protected:
			void onTexturePropertyChanged(const Reflection::PropertyDescriptor* descriptor); // 004e6bc0
			void onTextureAncestorChanged(boost::shared_ptr<Instance> ancestor);
		private:
			virtual void updateMesh();                                          // 004f0540
		};
	}
}
