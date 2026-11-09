// from server: 100% by tajop
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs roc_unit_87654e5dcbbc6883.cpp

// Candidate translation unit (score above; library headers required).
// 2012-06 ScriptMouseCommand: layout from the target MouseCommand ctor (0x8677e0):
// IRenderable at +4 with fields to 0x1c, capturedMouse 0x1c, workspace 0x20,
// four zeroed dwords 0x24..0x30, so ScriptMouseCommand::mouse is at 0x34.
#include "util/Name.h"
#include "util/UIEvent.h"
#include "util/TextureId.h"
#include <boost/shared_ptr.hpp>

namespace RBX
{
	class Workspace;
	class MouseCommand;

	class Mouse
	{
	public:
		TextureId getIcon() const;
		void setCommand(MouseCommand* value);
	};

	boost::shared_ptr<Mouse> createMouse();

	class IRenderable
	{
		int index2d;
		int index3d;
		int index3;
		void* bucket;
		float f;
	public:
		virtual void render2d();
	};

	class MouseCommand : public INamed, public IRenderable
	{
		bool capturedMouse;
	protected:
		Workspace* workspace;
		int reserved[4];
		MouseCommand(Workspace* workspace);
	public:
		virtual ~MouseCommand();
		virtual TextureId getCursorId() const;
	};

	class ScriptMouseCommand : public MouseCommand
	{
		boost::shared_ptr<Mouse> mouse;
	public:
		ScriptMouseCommand(Workspace* workspace);
		virtual ~ScriptMouseCommand();
		virtual TextureId getCursorId() const;
		virtual const Name& getName() const;
	};
}

namespace FLog { extern unsigned char MouseCommandLifetime; }
void FastLogP(int level, const char* fmt, const void* arg);

namespace RBX
{
	ScriptMouseCommand::ScriptMouseCommand(Workspace* workspace)
		: MouseCommand(workspace)
	{
		if (FLog::MouseCommandLifetime)
			FastLogP(FLog::MouseCommandLifetime, "ScriptMouseCommand created: %p", this);
		mouse = createMouse();
		mouse->setCommand(this);
	}

	TextureId ScriptMouseCommand::getCursorId() const
	{
		return mouse->getIcon();
	}
}
