// Inactive native recovery of RBX::Accoutrement and RBX::Hat.
// Layout and evidence: native-headers/v8datamodel/Accoutrement.h. Verified by tests/record_native_appearance.py.
// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
#include "v8datamodel/Accoutrement.h"

namespace RBX
{
	const char sAccoutrement[] = "Accoutrement";
	const char sHat[] = "Hat";

	// Factory/reflection template members (the generic definitions are not in the shared headers yet;
	// same local definitions as native-classes/Clothing.cpp).
	template<class C, class D, const char* N>
	FactoryProduct<C, D, N>::FactoryProduct() : D() {}

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::className() { return Name::declare<N>(); }

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::getClassName() const { return className(); }

	template<class C, class D, const char* N>
	DescribedCreatable<C, D, N>::DescribedCreatable()
		: Reflection::Described<C, N, FactoryProduct<C, D, N> >() {}

	template<> Reflection::ClassDescriptor& Reflection::Described<Accoutrement, sAccoutrement,
		FactoryProduct<Accoutrement, Instance, sAccoutrement> >::classDescriptor() {
		static Reflection::ClassDescriptor descriptor(Instance::classDescriptor(), sAccoutrement);
		return descriptor;
	}
	template<> Reflection::ClassDescriptor& Reflection::Described<Hat, sHat,
		FactoryProduct<Hat, Accoutrement, sHat> >::classDescriptor() {
		static Reflection::ClassDescriptor descriptor(Accoutrement::classDescriptor(), sHat);
		return descriptor;
	}

	template class FactoryProduct<Accoutrement, Instance, sAccoutrement>;
	template class FactoryProduct<Hat, Accoutrement, sHat>;
	template DescribedCreatable<Accoutrement, Instance, sAccoutrement>::DescribedCreatable();
	template DescribedCreatable<Hat, Accoutrement, sHat>::DescribedCreatable();

	// Property descriptors (static initializers 007f4fb0..007f5190).
	static Reflection::PropDescriptor<Accoutrement, G3D::CoordinateFrame> prop_AttachmentPoint("AttachmentPoint", "Appearance", &Accoutrement::getAttachmentPoint, &Accoutrement::setAttachmentPoint, Reflection::PropertyDescriptor::STREAMING);
	static Reflection::PropDescriptor<Accoutrement, G3D::Vector3> prop_AttachmentPos("AttachmentPos", "Appearance", &Accoutrement::getAttachmentPos, &Accoutrement::setAttachmentPos, Reflection::PropertyDescriptor::UI);
	static Reflection::PropDescriptor<Accoutrement, G3D::Vector3> prop_AttachmentForward("AttachmentForward", "Appearance", &Accoutrement::getAttachmentForward, &Accoutrement::setAttachmentForward, Reflection::PropertyDescriptor::UI);
	static Reflection::PropDescriptor<Accoutrement, G3D::Vector3> prop_AttachmentUp("AttachmentUp", "Appearance", &Accoutrement::getAttachmentUp, &Accoutrement::setAttachmentUp, Reflection::PropertyDescriptor::UI);
	static Reflection::PropDescriptor<Accoutrement, G3D::Vector3> prop_AttachmentRight("AttachmentRight", "Appearance", &Accoutrement::getAttachmentRight, &Accoutrement::setAttachmentRight, Reflection::PropertyDescriptor::UI);
	static Reflection::PropDescriptor<Accoutrement, int> prop_BackendAccoutrementState("BackendAccoutrementState", "Appearance", &Accoutrement::getBackendAccoutrementState, &Accoutrement::setBackendAccoutrementState, Reflection::PropertyDescriptor::STREAMING);

	Accoutrement::Accoutrement()
		: backendAccoutrementState(NOTHING)
	{
		setName("Accoutrement");
	}

	Accoutrement::~Accoutrement()
	{
	}

	const G3D::CoordinateFrame& Accoutrement::getAttachmentPoint() const
	{
		return attachmentPoint;
	}

	// 005b0920. Only caller setDesiredState 005b2510 calls it out of line (as Tool::setDesiredState 005ff900 calls
	// the two-disconnect steps 005fd4c0 / 005fd4e0), while VS2008 /Ob2 inlines a plain body; the rbxgs donor marks
	// it __declspec(noinline) for the same reason. INFERRED: the attribute is not proven to be original source.
	__declspec(noinline) void Accoutrement::downFrom_InCharacter()
	{
		characterChildAdded.disconnect();
		characterChildRemoved.disconnect();
	}

	const G3D::Vector3 Accoutrement::getAttachmentPos() const
	{
		return attachmentPoint.translation;
	}

	const G3D::Vector3 Accoutrement::getAttachmentForward() const
	{
		return attachmentPoint.lookVector();
	}

	const G3D::Vector3 Accoutrement::getAttachmentUp() const
	{
		return attachmentPoint.upVector();
	}

	const G3D::Vector3 Accoutrement::getAttachmentRight() const
	{
		return attachmentPoint.rightVector();
	}

	void Accoutrement::onCameraNear(float distance)
	{
		for (size_t i = 0; i < numChildren(); i++)
		{
			if (ICameraSubject* subject = dynamic_cast<ICameraSubject*>(getChild(i)))
				subject->onCameraNear(distance);
		}
	}

	void Accoutrement::render3dSelect(Adorn* adorn, SelectState selectState)
	{
		for (size_t i = 0; i < numChildren(); i++)
		{
			if (IRenderable* renderable = dynamic_cast<IRenderable*>(getChild(i)))
				renderable->render3dSelect(adorn, selectState);
		}
	}

	void Accoutrement::setBackendAccoutrementState(int value)
	{
		if (value != backendAccoutrementState)
		{
			backendAccoutrementState = (AccoutrementState)value;
			raisePropertyChanged(prop_BackendAccoutrementState);
		}
	}

	// 005b2510: walk one state per pass toward desiredState (backendAccoutrementState +0x154), the inlined
	// setBackendAccoutrementState raising prop_BackendAccoutrementState (00976ccc) through 0040db00. serviceProvider is
	// only read by the donor's RBXASSERT(Network::Players::backendProcessing(...)), absent in this release build.
	void Accoutrement::setDesiredState(AccoutrementState desiredState, const ServiceProvider* serviceProvider)
	{
		do
		{
			if (backendAccoutrementState < desiredState)
			{
				switch (backendAccoutrementState)
				{
				case IN_CHARACTER:
					upTo_Equipped();
					break;
				case IN_WORKSPACE:
					upTo_InCharacter();
					break;
				case HAS_HANDLE:
					upTo_InWorkspace();
					break;
				case NOTHING:
					connectTouchEvent();
					break;
				default:
					break;
				}
				setBackendAccoutrementState(backendAccoutrementState + HAS_HANDLE);
			}
			else if (desiredState < backendAccoutrementState)
			{
				switch (backendAccoutrementState)
				{
				case EQUIPPED:
					downFrom_Equipped();
					break;
				case IN_CHARACTER:
					downFrom_InCharacter();
					break;
				case IN_WORKSPACE:
					downFrom_InWorkspace();
					break;
				case HAS_HANDLE:
					downFrom_HasHandle();
					break;
				default:
					break;
				}
				setBackendAccoutrementState(backendAccoutrementState - HAS_HANDLE);
			}
		} while (desiredState != backendAccoutrementState);
	}

	void Accoutrement::setAttachmentPos(const G3D::Vector3& v)
	{
		setAttachmentPoint(G3D::CoordinateFrame(attachmentPoint.rotation, v));
	}

	Hat::Hat()
	{
		setName("Hat");
	}
}

// Name registrations emitted by this unit (bytes and sX relocation identity proven against the 2008-06 client).
template void RBX::Name::callDoDeclare<RBX::sAccoutrement>();
template void RBX::Name::callDoDeclare<RBX::sHat>();
