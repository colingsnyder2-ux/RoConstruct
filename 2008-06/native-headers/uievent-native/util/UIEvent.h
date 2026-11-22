#pragma once
// Include-path profile (/I{headers}/uievent-native): the 2008-06 native RBX::UIEvent for units that also include
// headers written against the donor path "util/UIEvent.h" (v8datamodel/Workspace.h, the donor gui/GuiEvent.h).
// Without it those headers reach tools/rbxgs util/UIEvent.h, which redefines the class of util/UIEvent2008.h
// (C2011), so a unit could not hold both DxUserInput (native layout, 0x14-byte events built in 004684a0 / 004685b0)
// and Workspace::onWrapMouse 005a0220. One definition only: this file forwards to the native header.
#include "util/UIEvent2008.h"
