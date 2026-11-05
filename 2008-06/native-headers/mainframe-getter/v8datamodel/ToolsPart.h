#pragma once
// Inactive TU profile: original setter signature, inline value snapshot.
// Do not combine this definition with the shared ToolsPart.h in one TU.
#include "v8datamodel/MouseCommand.h"
#include "v8datamodel/BrickColor.h"
#include "v8datamodel/PartInstance.h"
namespace RBX {
class PartTool : public MouseCommand {
    boost::shared_ptr<PartInstance> partInstance;
protected:
    virtual void render3dAdorn(Adorn*);
    virtual void onMouseHover(const UIEvent&);
public:
    PartTool(Workspace*);
};
class FillToolColor : public Notifier<FillToolColor, BrickColor> {
    BrickColor color;
public:
    FillToolColor();
    BrickColor get() const { return color; }
    void set(const BrickColor& value)
    {
        BrickColor next = value;
        if (color != next) {
            color = next;
            raise(next);
        }
    }
};
extern char sFillTool[];
class FillTool : public Named<PartTool, sFillTool> {
public:
    static FillToolColor color;
protected:
    virtual MouseCommand* onMouseDown(const UIEvent&);
    virtual const std::string getCursorName() const;
public:
    FillTool(Workspace* w) : Named<PartTool, sFillTool>(w) {}
    virtual MouseCommand* isSticky() const;
};
}
