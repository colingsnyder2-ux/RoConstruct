#include "v8datamodel/Explosion.h"
#include "v8datamodel/PartInstance.h"
#include "v8world/Primitive.h"
#include "v8world/World.h"
#include "v8world/ContactManager.h"
#include "v8datamodel/Workspace.h"
#include "RbxGraphics/Adorn.h"

namespace RBX
{
	namespace Reflection
	{
		template<class S>
		SignalDescImpl<2, S>::GenericSlotAdapter::GenericSlotAdapter(GenericSlotWrapper* wrapper)
			: wrapper(wrapper)
		{
		}

		template<class S>
		void SignalDescImpl<2, S>::GenericSlotAdapter::operator()(
			typename boost::function_traits<S>::arg1_type a, typename boost::function_traits<S>::arg2_type b)
		{
			std::vector<boost::any> args(2);
			args[0] = a;
			args[1] = b;
			wrapper->execute(args);
		}

		template<class S>
		boost::signals::connection SignalDescImpl<2, S>::connectGeneric(
			SignalInstance* instance, GenericSlotWrapper* wrapper, boost::signals::connect_position pos) const
		{
			return static_cast<typename TSignalDesc<S>::TSignalInstance*>(instance)->connect(GenericSlotAdapter(wrapper), pos);
		}
	}

	static Reflection::PropDescriptor<Explosion, float> propBlastRadius("BlastRadius", "Data", &Explosion::getBlastRadius, &Explosion::setBlastRadius, Reflection::PropertyDescriptor::STANDARD);
	Reflection::BoundProp<float, 1> Explosion::propBlastPressure("BlastPressure", "Data", &Explosion::blastPressure, Reflection::PropertyDescriptor::STANDARD);
	Reflection::BoundProp<G3D::Vector3, 1> Explosion::propPosition("Position", "Data", &Explosion::position, Reflection::PropertyDescriptor::STANDARD);
	Reflection::SignalDesc<Explosion, void(boost::shared_ptr<Instance>, float)> signal_Hit("Hit", "part", "distance");

	void Explosion::setBlastRadius(float _blastRadius)
	{
		float newRadius = G3D::clamp(_blastRadius, 0.0f, 100.0f);
		if (blastRadius != newRadius)
		{
			blastRadius = newRadius;
			raisePropertyChanged(propBlastRadius);
		}
	}

	void Explosion::onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider)
	{
		Notifier<RunService, Stepped>::disconnect(ServiceProvider::find<RunService>(oldProvider), this);
		Notifier<RunService, Stepped>::connect(ServiceProvider::find<RunService>(newProvider), this);
	}

	void Explosion::signalBlast(const G3D::Array<Primitive*>& primitives)
	{
		if (!signal_Hit.empty(this))
		{
			for (int i = 0; i < primitives.size(); i++)
			{
				Primitive* current = primitives[i];

				if (blastRadius * 2.0f > current->getRadius())
				{
					if (Instance* part = PartInstance::fromPrimitive(current))
					{
						float distance = (current->getCoordinateFrame().translation - position).magnitude();
						signal_Hit.fire(this, shared_from(part), distance);
					}
				}
			}
		}
	}

	void Explosion::onEvent(const RunService*, Stepped event)
	{
		age += event.step;
		if (age > 0.1f)
		{
			if (blastRadius > 0.0f)
			{
				G3D::Array<Primitive*> primitives;
				World* world = Workspace::getWorldIfInWorkspace(this);
				float radius = blastRadius;
				Extents extents = Extents::fromCenterCorner(position, G3D::Vector3(radius, radius, radius));
				world->getContactManager().getPrimitivesTouchingExtents(extents, NULL, primitives);
				signalBlast(primitives);
				doBlast(primitives);
			}
			setParent(NULL);
		}
	}

	void Explosion::render3dAdorn(Adorn* adorn)
	{
		adorn->setObjectToWorldMatrix(G3D::CoordinateFrame(position));
		float radius = blastRadius;
		adorn->explosion(G3D::Sphere(G3D::Vector3::zero(), radius), G3D::Color4(G3D::Color3::red()), G3D::Color4::clear());
	}
}

namespace RBX {
char sExplosion[] = "Explosion";
template<class C,class D,const char* N> FactoryProduct<C,D,N>::FactoryProduct():D() {}
template<class C,class D,const char* N> const Name& FactoryProduct<C,D,N>::className() { return Name::declare<N>(); }
template<class C,class D,const char* N> const Name& FactoryProduct<C,D,N>::getClassName() const { return className(); }
template<class C,class D,const char* N> DescribedCreatable<C,D,N>::DescribedCreatable():Reflection::Described<C,N,FactoryProduct<C,D,N> >() {}
Explosion::Explosion():blastRadius(4.0f),blastPressure(500000.0f),age(0.0f) { setName("Explosion"); }
}

template void RBX::Name::callDoDeclare<RBX::sExplosion>();
