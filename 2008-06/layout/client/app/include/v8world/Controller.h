// =============================================================================
// Controller.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/v8world/Controller.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#pragma once

#include "G3D/ReferenceCount.h"
#include "G3D/Color3.h"

namespace RBX
{
    class Controller : public G3D::ReferenceCountedObject
    {
    public:
        enum ControllerType
        {
            NO_CONTROLLER = 0,
            PRIMARY_CONTROLLER = 1,
            SECONDARY_CONTROLLER = 2,
            PAD_ONE_CONTROLLER = 3,
            PAD_TWO_CONTROLLER = 4,
            AI_CHASE_CONTROLLER = 5,
            AI_FLEE_CONTROLLER = 6,
            PLAYER_CONTROLLER = 7,
            NUM_CONTROLLER_TYPES = 8
        };

        enum InputType
        {
            NO_INPUT = 0,
            LEFT_TRACK_INPUT = 1,
            RIGHT_TRACK_INPUT = 2,
            RIGHT_LEFT_INPUT = 3,
            BACK_FORWARD_INPUT = 4,
            STRAFE_INPUT = 5,
            UP_DOWN_INPUT = 6,
            BUTTON_1_INPUT = 7,
            BUTTON_2_INPUT = 8,
            BUTTON_3_INPUT = 9,
            BUTTON_4_INPUT = 10,
            BUTTON_3_4_INPUT = 11,
            CONSTANT_INPUT = 12,
            SIN_INPUT = 13,
            NUM_INPUT_TYPES = 14
        };

        virtual ~Controller();
        virtual float getValue(InputType inputType) const = 0;
        virtual ControllerType getControllerType() const = 0;
        virtual bool hasIntelligence() const = 0;
        virtual bool isUserController() const = 0;
        bool isNullController();
        static bool isControllableInput(InputType inputType);
        static G3D::Color3 controllerTypeToColor(ControllerType controllerType);
    };
}
