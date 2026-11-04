// 2008-06 native RBX::Message / RBX::Hint (inactive); evidence in native-headers/v8datamodel/Message.h.
// Verified by tests/record_native_effects.py.
#include "v8datamodel/Message.h"
#include "util/Rect.h"
#ifdef NATIVE_MESSAGE_PENDING
#include "Network/Player.h" // a native Network::Player header (declaration-only overlay in the recorder)
#endif

namespace RBX
{
	const char sMessage[] = "Message"; // 009542a0 (classDescriptor 004a3cd0)
	const char sHint[] = "Hint";       // 009542a8 (classDescriptor 004a3dd0)

	// Template members the shared headers only declare (same definitions as Team.cpp / DecalBases.cpp).
	template<class C, class D, const char* N>
	FactoryProduct<C, D, N>::FactoryProduct() : D() {}

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::className() { return Name::declare<N>(); }

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::getClassName() const { return className(); }

	template<class C, class D, const char* N>
	DescribedCreatable<C, D, N>::DescribedCreatable()
		: Reflection::Described<C, N, FactoryProduct<C, D, N> >() {}

	template<class C, class D, const char* N>
	template<class A>
	DescribedCreatable<C, D, N>::DescribedCreatable(A arg0)
		: Reflection::Described<C, N, FactoryProduct<C, D, N> >(arg0) {}

	// Hint's factory/reflection members: the original emits them as COMDATs in the Network::Server unit
	// (004a3af0, 004a3cb0, 004a3dd0, 004a4a60), which creates Hints; instantiated here to verify them.
	template class FactoryProduct<Hint, Message, sHint>;
	template DescribedCreatable<Hint, Message, sHint>::DescribedCreatable();

	// Dynamic initializer 007f6970.
	static Reflection::PropDescriptor<Message, std::string> desc_Text("Text", "Appearance", &Message::getText, &Message::setText, Reflection::PropertyDescriptor::STANDARD);

	Message::Message()
		: Base("Message")
	{
	}

	void Message::setText(const std::string& value)
	{
		if (text != value)
		{
			text = value;
			raisePropertyChanged(desc_Text);
		}
	}

#ifdef NATIVE_MESSAGE_PENDING
	void Message::render2d(Adorn* adorn)
	{
		if (text.size() > 0)
		{
			if (!dynamic_cast<Network::Player*>(getParent()))
			{
				renderFullScreen(adorn);
			}
			else
			{
				renderPersonalMsg(adorn);
			}
		}
	}
#endif

	void Message::renderFullScreen(Adorn* adorn)
	{
		G3D::Rect2D rect = adorn->getViewport();
		Rect translucentArea = rect;
		G3D::Vector2 textPos = translucentArea.center();

		adorn->rect2d(translucentArea.toRect2D(), G3D::Color4(0.5f, 0.5f, 0.5f, 0.5f));
		adorn->drawFont2D(text, textPos, 14.0, G3D::Color3::white(), G3D::Color3::black(), Adorn::XALIGN_CENTER, Adorn::YALIGN_CENTER, Adorn::PROPORTIONAL_SPACING);
	}

	void Message::renderPersonalMsg(Adorn* adorn)
	{
		G3D::Rect2D rect = adorn->getViewport();
		Rect area(rect);
		area.low.x = rect.x0() + 30.0f;
		area.low.y = rect.y0() + 30.0f;
		area.high.x = rect.x1() * 0.25f + 30.0f;
		area.high.y = rect.y1() * 0.25f + 30.0f;
		G3D::Vector2 textPos = area.center();

		adorn->rect2d(area.toRect2D(), G3D::Color4(0.5f, 0.5f, 0.5f, 0.5f));
		adorn->drawFont2D(text, textPos, 14.0, G3D::Color3::white(), G3D::Color3::black(), Adorn::XALIGN_CENTER, Adorn::YALIGN_CENTER, Adorn::PROPORTIONAL_SPACING);
	}

	void Hint::render2d(Adorn* adorn)
	{
		G3D::Rect2D rect = adorn->getViewport();
		Rect area(rect);
		area.low.x = rect.x0();
		area.low.y = rect.y1() - 20.0f;
		area.high.x = rect.x1();
		area.high.y = rect.y1();
		G3D::Vector2 textPos = area.center();

		adorn->rect2d(area.toRect2D(), G3D::Color3::black());
		adorn->drawFont2D(text, textPos, 14.0, G3D::Color3::white(), G3D::Color4::clear(), Adorn::XALIGN_CENTER, Adorn::YALIGN_CENTER, Adorn::PROPORTIONAL_SPACING);
	}
}
