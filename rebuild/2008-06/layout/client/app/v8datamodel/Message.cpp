// =============================================================================
// Message.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/v8datamodel/Message.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#include "v8datamodel/Message.h"
#include "util/Object.h"

namespace RBX
{
	template<typename Class, typename DerivedClass, const char* ClassName>
	boost::shared_ptr<Object> FactoryProduct<Class, DerivedClass, ClassName>::Creator::create() const
	{
		return Creatable<Instance>::create<Class>();
	}
}

template boost::shared_ptr<RBX::Message> RBX::Creatable<RBX::Instance>::create<RBX::Message>();
template boost::shared_ptr<RBX::Hint> RBX::Creatable<RBX::Instance>::create<RBX::Hint>();
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::Message, RBX::Instance, RBX::sMessage>::Creator::create() const;

#include "util/Rect.h"
#include "Network/Player.h" // native Network::Player (render2d dynamic_casts the parent to it)

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

	// DescribedCreatable(Arg0Type) is defined inline in reflection/reflection.h.

	template class FactoryProduct<Hint, Message, sHint>;
	template DescribedCreatable<Hint, Message, sHint>::DescribedCreatable();

	static Reflection::PropDescriptor<Message, std::string> desc_Text(
		"Text",
		"Appearance",
		&Message::getText,
		&Message::setText,
		Reflection::PropertyDescriptor::STANDARD);

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

	void Message::renderFullScreen(Adorn* adorn)
	{
		G3D::Rect2D rect = adorn->getViewport();
		Rect translucentArea = rect;
		G3D::Vector2 textPos = translucentArea.center();

		adorn->rect2d(translucentArea.toRect2D(), G3D::Color4(0.5f, 0.5f, 0.5f, 0.5f));
		adorn->drawFont2D(
			text,
			textPos,
			14.0,
			G3D::Color3::white(),
			G3D::Color3::black(),
			Adorn::XALIGN_CENTER,
			Adorn::YALIGN_CENTER,
			Adorn::PROPORTIONAL_SPACING);
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
		adorn->drawFont2D(
			text,
			textPos,
			14.0,
			G3D::Color3::white(),
			G3D::Color3::black(),
			Adorn::XALIGN_CENTER,
			Adorn::YALIGN_CENTER,
			Adorn::PROPORTIONAL_SPACING);
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
		adorn->drawFont2D(
			text,
			textPos,
			14.0,
			G3D::Color3::white(),
			G3D::Color4::clear(),
			Adorn::XALIGN_CENTER,
			Adorn::YALIGN_CENTER,
			Adorn::PROPORTIONAL_SPACING);
	}
}

template void RBX::Name::callDoDeclare<RBX::sMessage>();

#include "Network/Players.h"
