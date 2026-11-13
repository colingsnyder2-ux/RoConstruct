// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/boost-function-pod-vtable /I{headers}/engine-world /I{headers}/part-embedded
// 2008-06 native rows of the RBX::Explosion unit (v8datamodel/Explosion.cpp, original 00629ba0..0062b8ef), inactive.
// Built against the committed v8datamodel/Explosion.h read-only. sExplosion, the constructor and the FactoryProduct /
// DescribedCreatable template members are defined by the committed native-classes/Explosion.cpp (another contributor;
// compiled read-only by the recorder, nothing here repeats them). Verified by tests/record_native_app_unit628.py.
//   Dynamic initializers (in this order): 007f7dc0 propBlastRadius 0097bfd4 (PropDescriptor<Explosion, float>
//   "BlastRadius" 00845ee4, "Data" 00822490, getter getBlastRadius 00629ba0, setter setBlastRadius 0062b5c0,
//   Functionality 5 = STANDARD), 007f7e00 propBlastPressure 0097c00c (BoundProp<float,1> "BlastPressure" 00845ef0,
//   member +0x158), 007f7e30 propPosition 0097bff0 (BoundProp<Vector3,1> "Position" 0083311c, member +0x148),
//   007f7e60 signal_Hit 0097c028 (SignalDesc<Explosion, void(shared_ptr<Instance>, float)> "Hit" 00845f00, "part"
//   0081c960, "distance" 00845f04).
//   /fp:fast: setBlastRadius compares against the float 100.0f at 008163a4 (G3D::clamp(float) inlined without the
//   double promotion). boost-function-pod-vtable: function2(GenericSlotAdapter)::assign_to 0062b130 stores the constant
//   stored_vtable 00845de4 without a guard or EH frame.
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
		// SignalDescImpl<2, S> members the shared reflection/signal.h declares without a body (same definitions as
		// native-classes/ChangeHistoryStart.cpp / AppUnit554RunServiceTemplates.cpp).
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

	// onEvent 0062b700 (Listener<RunService, Stepped> slot 0, vtable 00845e18): near miss, not counted. The original
	// compares age with 0.1f at 0081e704, then drops the dead ~Array stores (see the receipt).
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
