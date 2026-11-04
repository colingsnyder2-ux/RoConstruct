// Layout probes for the inactive native gui/Widget.h, WidgetButtons.h, WidgetChat.h, WidgetMenuItem.h, HealthHud.h,
// EquationDisplay.h and ArrowPanel.h;
// tests/record_native_widget.py checks each function body is `mov eax, imm32; ret` with the value from the binary
// (allocation sizes passed to new, constructor field stores).
#include <stddef.h>
#include "gui/WidgetButtons.h"
#include "gui/WidgetChat.h"
#include "gui/WidgetMenuItem.h"
#include "gui/HealthHud.h"
#include "gui/EquationDisplay.h"
#include "gui/ArrowPanel.h"

struct NativeWidgetLayout
{
	static size_t widgetState() { return offsetof(RBX::Widget, widgetState); }                 // 0x144 (006422b0)
	static size_t widgetSize() { return sizeof(RBX::Widget); }                                 // 0x148 (VerbWidget::verb)
	static size_t verb() { return offsetof(RBX::VerbWidget, verb); }                           // 0x148 (00642370)
	static size_t verbWidgetSize() { return sizeof(RBX::VerbWidget); }                         // 0x14c (MenuItem field)
	static size_t keyCode() { return offsetof(RBX::KeyButton, keyCode); }                      // 0x148 (0064f110)
	static size_t keyIsDown() { return offsetof(RBX::KeyButton, keyIsDown); }                  // 0x14c (0064f110)
	static size_t keyButtonSize() { return sizeof(RBX::KeyButton); }                           // 0x150 (imageDraw)
	static size_t imageWidgetDraw() { return offsetof(RBX::ImageWidget, guiImageDraw); }       // 0x148 (0064f1c0)
	static size_t imageWidgetSize() { return sizeof(RBX::ImageWidget); }                       // 0x180 (00656f80)
	static size_t imageButtonDraw() { return offsetof(RBX::ImageButton, guiImageDraw); }       // 0x14c (0064f340)
	static size_t imageButtonSize() { return sizeof(RBX::ImageButton); }                       // 0x184 (00601f20)
	static size_t imageKeyButtonDraw() { return offsetof(RBX::ImageKeyButton, imageDraw); }    // 0x150 (0064f500)
	static size_t imageKeyButtonSize() { return sizeof(RBX::ImageKeyButton); }                 // 0x188 (0064f600 + 0x38)
	static size_t chatWidgetCode() { return offsetof(RBX::ChatWidget, code); }                 // 0x148 (0064e8c0)
	static size_t chatWidgetSize() { return sizeof(RBX::ChatWidget); }                         // 0x164 (00602149)
	static size_t unifiedImageDraw() { return offsetof(RBX::UnifiedImageWidget, guiImageDraw); } // 0x148 (00601c50)
	static size_t unifiedImageSize() { return sizeof(RBX::UnifiedImageWidget); }               // 0x180
	static size_t chatButtonSize() { return sizeof(RBX::ChatButton); }                         // 0x180 (006022a0)
	static size_t menuItemAccelerator() { return offsetof(RBX::MenuItem, accelerator); }       // 0x14c (0064ebf0)
	static size_t menuItemSize() { return sizeof(RBX::MenuItem); }                             // 0x168 (00601e50)
	static size_t healthHudVisit() { return offsetof(RBX::HealthHud, visit); }                 // 0x144 (00656490)
	static size_t healthHudSize() { return sizeof(RBX::HealthHud); }                           // 0x14c (006023ef)
	static size_t equation() { return offsetof(RBX::EquationDisplay, equation); }              // 0x188 (00656a50)
	static size_t equationDisplaySize() { return sizeof(RBX::EquationDisplay); }               // 0x1a4 (00602570)
	static size_t arrowPanelDataModel() { return offsetof(RBX::ArrowPanel, dataModel); }       // 0x15c (00656db6)
	static size_t arrowPanelController() { return offsetof(RBX::ArrowPanel, controller); }     // 0x160 (00656dda)
	static size_t arrowButtonDataModel() { return offsetof(RBX::ArrowButton, dataModel); }     // 0x188 (006570c1)
	static size_t arrowButtonController() { return offsetof(RBX::ArrowButton, controller); }   // 0x18c (0065711f)
	static size_t arrowButtonSize() { return sizeof(RBX::ArrowButton); }                       // 0x190 (006571b0)
};

size_t nativeWidgetState() { return NativeWidgetLayout::widgetState(); }
size_t nativeWidgetSize() { return NativeWidgetLayout::widgetSize(); }
size_t nativeVerbWidgetVerb() { return NativeWidgetLayout::verb(); }
size_t nativeVerbWidgetSize() { return NativeWidgetLayout::verbWidgetSize(); }
size_t nativeKeyButtonKeyCode() { return NativeWidgetLayout::keyCode(); }
size_t nativeKeyButtonKeyIsDown() { return NativeWidgetLayout::keyIsDown(); }
size_t nativeKeyButtonSize() { return NativeWidgetLayout::keyButtonSize(); }
size_t nativeImageWidgetDraw() { return NativeWidgetLayout::imageWidgetDraw(); }
size_t nativeImageWidgetSize() { return NativeWidgetLayout::imageWidgetSize(); }
size_t nativeImageButtonDraw() { return NativeWidgetLayout::imageButtonDraw(); }
size_t nativeImageButtonSize() { return NativeWidgetLayout::imageButtonSize(); }
size_t nativeImageKeyButtonDraw() { return NativeWidgetLayout::imageKeyButtonDraw(); }
size_t nativeImageKeyButtonSize() { return NativeWidgetLayout::imageKeyButtonSize(); }
size_t nativeChatWidgetCode() { return NativeWidgetLayout::chatWidgetCode(); }
size_t nativeChatWidgetSize() { return NativeWidgetLayout::chatWidgetSize(); }
size_t nativeUnifiedImageWidgetDraw() { return NativeWidgetLayout::unifiedImageDraw(); }
size_t nativeUnifiedImageWidgetSize() { return NativeWidgetLayout::unifiedImageSize(); }
size_t nativeChatButtonSize() { return NativeWidgetLayout::chatButtonSize(); }
size_t nativeMenuItemAccelerator() { return NativeWidgetLayout::menuItemAccelerator(); }
size_t nativeMenuItemSize() { return NativeWidgetLayout::menuItemSize(); }
size_t nativeHealthHudVisit() { return NativeWidgetLayout::healthHudVisit(); }
size_t nativeHealthHudSize() { return NativeWidgetLayout::healthHudSize(); }
size_t nativeEquationDisplayEquation() { return NativeWidgetLayout::equation(); }
size_t nativeEquationDisplaySize() { return NativeWidgetLayout::equationDisplaySize(); }
size_t nativeArrowPanelDataModel() { return NativeWidgetLayout::arrowPanelDataModel(); }
size_t nativeArrowPanelController() { return NativeWidgetLayout::arrowPanelController(); }
size_t nativeArrowButtonDataModel() { return NativeWidgetLayout::arrowButtonDataModel(); }
size_t nativeArrowButtonController() { return NativeWidgetLayout::arrowButtonController(); }
size_t nativeArrowButtonSize() { return NativeWidgetLayout::arrowButtonSize(); }
