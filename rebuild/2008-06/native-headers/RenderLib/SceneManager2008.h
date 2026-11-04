#pragma once
// 2008-06 native RBX::RenderBase::SceneManager / SimpleSceneManager (inactive). Named *2008.h so it never shadows
// a donor RenderLib header (the donor SceneManager lives in RenderLib/RenderScene.h, namespace RBX::Render).
//   SceneManager       RTTI vtable 00826b44 (no bases); 7 slots: 0..5 _purecall (invalidateModel, addModel,
//                      removeModel, clear, setSleeping, prerender), 6 ??_G 004d7350 (virtual dtor declared last).
//                      ctor 004d6f60 (vptr, renderScene +0x4), dtor 004d6f50. size 0x8 (SimpleSceneManager: new 8 in
//                      ViewRbxGfx::ViewRbxGfx 004d9a8a, which stores +0x4 and the vtable 00826b64 only).
//   SimpleSceneManager RTTI vtable 00826b64 -> SceneManager (mdisp 0); slots 0 invalidateModel 004d7320,
//                      1 addModel 004d7db0, 2 removeModel 004d8380 (jmp 004d8320), 3 clear 004d8310,
//                      4 setSleeping / 5 prerender 00458e90 (ret 8), 6 ??_G 004d7350 (folded with SceneManager's).
//   AggregatingSceneManager RTTI vtable 0082ced0 -> SceneManager (mdisp 0); /Od RenderBase library code. new 0x68
//                      (ViewG3D ctor 004dbcf4); ctor 0053f0d0: SceneManager(renderScene) 004d6f60, vtable, map +0x8
//                      (00540800), set +0x28 / +0x48 (00540a80); dtor 0053f160 in reverse. Slots: 0 invalidateModel
//                      00540240, 1 addModel 0053f1e0 (calls addToScene 004d7db0), 2 removeModel 0053f580, 3 clear
//                      0053f6a0, 4 setSleeping 0053fa50, 5 prerender 0053fc00, 6 ??_G 00540300.
//     BucketKey        ctor 0053f200: castsShadows +0x0 (chunk slot 3), cullable +0x1 (slot 4), polygonOffset +0x4
//                      (chunk +0x18), material +0x8 (slot 5 getMaterial).
//     Bucket           RTTI 0082cef0 -> ReferenceCountedObject (0), boost::noncopyable (mdisp 0xc); new 0x24 (0053f3b9);
//                      ctor 00540390 (RCO 00472990, noncopyable +0xc, vtable, std::vector queue +0xc 00540560);
//                      dtor 00540440 (vector dtor 005405d0, ~noncopyable, ~ReferenceCountedObject 007accf0);
//                      one slot: ??_G 00540410.
//   RenderSceneBase    only used through a pointer here; its layout (vtable 00827424, chunk array +0x8, size 0x268)
//                      is not declared because the 4-byte member at +0x4 is not derived yet (see RenderScene2008.h).
#include "RenderLib/AggregateChunk2008.h"
#include <boost/noncopyable.hpp>
#include <map>
#include <set>

struct NativeRenderSceneLayout;

namespace RBX
{
	namespace RenderBase
	{
		class RenderSceneBase;

		class SceneManager
		{
			friend struct ::NativeRenderSceneLayout;
		protected:
			RenderSceneBase* renderScene;                             // +0x4

		public:
			virtual void invalidateModel(const G3D::ReferenceCountedPointer<Chunk>& chunk, bool isSleeping) = 0;
			virtual void addModel(const G3D::ReferenceCountedPointer<Chunk>& chunk) = 0;
			virtual void removeModel(const G3D::ReferenceCountedPointer<Chunk>& chunk) = 0;
			virtual void clear() = 0;
			virtual void setSleeping(const G3D::ReferenceCountedPointer<Chunk>& chunk, bool sleeping) = 0;
			virtual void prerender(double time) = 0;
			virtual ~SceneManager();                                  // 004d6f50

		protected:
			SceneManager(RenderSceneBase* renderScene);               // 004d6f60
			void clearScene();                                        // inlined into SimpleSceneManager::clear 004d8310
			void addToScene(const G3D::ReferenceCountedPointer<Chunk>& chunk);      // 004d7db0
			void removeFromScene(const G3D::ReferenceCountedPointer<Chunk>& chunk); // 004d8320
		};

		class SimpleSceneManager : public SceneManager
		{
		public:
			// Out of line: no copy survives in the original (every caller, e.g. ViewRbxGfx::ViewRbxGfx 004d9a8a,
			// has it inlined); defining it here emits the vtable 00826b64 and ??_G for the slot check.
			SimpleSceneManager(RenderSceneBase* renderScene);

			virtual void invalidateModel(const G3D::ReferenceCountedPointer<Chunk>& chunk, bool isSleeping); // 004d7320
			virtual void addModel(const G3D::ReferenceCountedPointer<Chunk>& chunk);       // 004d7db0
			virtual void removeModel(const G3D::ReferenceCountedPointer<Chunk>& chunk);    // 004d8380
			virtual void clear();                                                           // 004d8310
			virtual void setSleeping(const G3D::ReferenceCountedPointer<Chunk>& chunk, bool sleeping); // 00458e90
			virtual void prerender(double time);                                            // 00458e90
		};

		class AggregatingSceneManager : public SceneManager
		{
			friend struct ::NativeRenderSceneLayout;
		public:
			class Bucket : public G3D::ReferenceCountedObject, public boost::noncopyable
			{
				friend struct ::NativeRenderSceneLayout;
			private:
				std::vector<G3D::ReferenceCountedPointer<Chunk> > queue;     // +0xc
			public:
				Bucket();                                                     // 00540390
				// implicit (virtual through ReferenceCountedObject) destructor 00540440: it does not store the
				// Bucket vtable, unlike a user-declared one
				bool dequeueSleepingChunk(const G3D::ReferenceCountedPointer<Chunk>& chunk);
				void addToQueue(const G3D::ReferenceCountedPointer<Chunk>& chunk);
				void optimize(AggregatingSceneManager& manager, double time);
			};

			struct BucketKey
			{
				bool castsShadows;                                            // +0x0
				bool cullable;                                                // +0x1
				float polygonOffset;                                          // +0x4
				G3D::ReferenceCountedPointer<MaterialBase> material;              // +0x8

				BucketKey(const G3D::ReferenceCountedPointer<Chunk>& that);   // 0053f200
				bool operator<(const BucketKey& other) const;
			};

		private:
			std::map<BucketKey, G3D::ReferenceCountedPointer<Bucket> > buckets;            // +0x08
			std::set<G3D::WeakReferenceCountedPointer<Chunk> > invalidSleepingModels;      // +0x28
			std::set<G3D::WeakReferenceCountedPointer<Chunk> > invalidMovingModels;        // +0x48

		public:
			AggregatingSceneManager(RenderSceneBase* renderScene);            // 0053f0d0
			virtual ~AggregatingSceneManager();                               // 0053f160

			virtual void invalidateModel(const G3D::ReferenceCountedPointer<Chunk>& chunk, bool isSleeping); // 00540240
			virtual void addModel(const G3D::ReferenceCountedPointer<Chunk>& chunk);       // 0053f1e0
			virtual void removeModel(const G3D::ReferenceCountedPointer<Chunk>& chunk);    // 0053f580
			virtual void clear();                                                           // 0053f6a0
			virtual void setSleeping(const G3D::ReferenceCountedPointer<Chunk>& chunk, bool sleeping); // 0053fa50
			virtual void prerender(double time);                                            // 0053fc00
		};
	}
}
