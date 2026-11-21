#pragma once
#include "v8datamodel/PVInstance.h"
#include "v8datamodel/ICameraOwner.h"
#include "util/IRenderable.h"
#include "util/ICameraSubject.h"
#include "util/ISelectable3d.h"
#include "util/Extents.h"

namespace RBX
{
	class IModelModifier;
	class Primitive;
	class PartInstance;

	extern char sModel[];
	class ModelInstance : public DescribedCreatable<ModelInstance, PVInstance, sModel>,
						  public IRenderable,
						  public virtual IPrimaryPart,
						  public virtual ICameraSubject,
						  public virtual ISelectable3d
	{
	private:
		mutable G3D::CoordinateFrame modelInPrimary;
		mutable PartInstance* primaryPart;
		boost::shared_ptr<PartInstance> candidatePrimaryPart;
		std::vector<IModelModifier*> modifiers;
		ComputeProp<float, ModelInstance> FlagHeight;
		ComputeProp<Extents, ModelInstance> LocalGridExtents;
		ComputeProp<Extents, ModelInstance> WorldGridExtents;

	public:
		static bool showModelCoord;

	private:
		void updatePrimaryPart(PartInstance* set) const;
		float computeFlagHeight() const;
		Extents computeLocalGridExtents() const;
		Extents computeWorldGridExtents() const;
		void dirtyAll() const;
		virtual bool shouldRender3dAdorn() const;
		virtual void render3dAdorn(Adorn* adorn);
		virtual void render3dSelect(Adorn* adorn, SelectState selectState);
	protected:
		// 00585050 / 00584fc0: ModelInstance's own entries in vtable slots 7 / 8 of 00830dc4 (also inherited unchanged by
		// the RootInstance / Workspace vtables 00831d68, 008337f0, 00833a70 and 00833db0); they override the PVInstance
		// declarations, so the slot order is unchanged.
		virtual void onChildAdded(Instance* child);
		virtual void onChildRemoving(Instance* child);
		virtual void onDescendentAdded(Instance* instance);
		virtual void onDescendentRemoving(const boost::shared_ptr<Instance>& instance);
		virtual bool askSetParent(const Instance* instance) const;
	private:
		virtual void onLastChildRemoved()
		{
		}
	public:
		ModelInstance();
		virtual ~ModelInstance();
	public:
		// 005d8690 = <Humanoid> (162 bytes; callers Humanoid::modelIsCharacter 005d9a20, getLocalHumanoidFromContext 005d9bb0,
		// render3dAdorn 005d9c30, 005db4c0, render2d 005db960), 005d4460 = <Skin> (BodyColors::apply 005d4b60): walks the
		// modifiers vector (+0x1ec, first/last +0x1f8/+0x1fc) with checked const_iterators and dynamic_casts each entry
		// from IModelModifier (RTTI 0x936908). Analog name (the registry has only placeholders for both instantiations).
		template<class T> T* findModifierOfType() const
		{
			std::vector<IModelModifier*>::const_iterator end = modifiers.end();
			for (std::vector<IModelModifier*>::const_iterator iter = modifiers.begin(); iter != end; ++iter)
			{
				if (T* result = dynamic_cast<T*>(*iter))
					return result;
			}
			return NULL;
		}
		PartInstance* getPrimaryPartInternal() const;
		void setPrimaryPart(PartInstance* set);
		const G3D::CoordinateFrame& getModelInPrimary() const
		{
			return modelInPrimary;
		}
		void setModelInPrimary(const G3D::CoordinateFrame& set)
		{
			modelInPrimary = set;
		}
		virtual void onExtentsChanged() const;
		virtual const Primitive* getBiggestPrimitive() const;
		virtual bool hitTest(const G3D::Ray& worldRay, G3D::Vector3& worldHitPoint);
		virtual Extents getExtentsWorld() const
		{
			return WorldGridExtents;
		}
		virtual Extents getExtentsLocal() const
		{
			return LocalGridExtents;
		}
		virtual const G3D::CoordinateFrame getLocation() const;
		virtual void onCameraNear(float distance);
		virtual void getCameraIgnorePrimitives(std::vector<const Primitive*>& primitives);
		virtual PartInstance* getPrimaryPart()
		{
			return getPrimaryPartInternal();
		}
		virtual const PartInstance* getPrimaryPartConst() const
		{
			return getPrimaryPartInternal();
		}
		void setFrontAndTop(const G3D::Vector3&);
		void destroyIfNoParts(const ModelInstance*);
		void makeJoints();
		void breakJoints();
		float computeTotalMass() const;
		float computeLargestMoment() const;
	protected:
		virtual void legacyTraverseState(const G3D::CoordinateFrame& parentState);
	};
}

