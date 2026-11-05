// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
namespace RBX {
class DataModel;
class UIEvent;
class MouseCommand;
class Dragger { public: void stop(); };
class ChangeHistoryService { public: static void requestWaypoint(const char* name, DataModel* dm); };
class DragTool {
public:
	virtual const std::string& getName() const;
	virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
	virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
	virtual void releaseCapture();
	virtual MouseCommand* onMouseUp(const UIEvent& event);
	char pad[0x14];
	DataModel* dataModel;
	Dragger* dragger;
	char pad2[8];
	bool captured;
};
MouseCommand* DragTool::onMouseUp(const UIEvent& event)
{
	if (captured) {
		dragger->stop();
		captured = false;
		ChangeHistoryService::requestWaypoint(getName().c_str(), dataModel);
	}
	releaseCapture();
	return 0;
}
}
