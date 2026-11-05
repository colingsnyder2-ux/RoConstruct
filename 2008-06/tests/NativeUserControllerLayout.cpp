// Layout probe for the inactive native native-headers/v8datamodel/UserController.h;
// tests/record_native_user_controller.py checks each size function body is `mov eax, imm32; ret` with the value from
// the binary:
//   sizeof(ControllerService)            0x144  creator 0045c580 allocates 0x144 (constructor 005cb9e0)
//   sizeof(KeyboardPrimaryController)    0x10   constructor 005cb9e0 new(0x10)
//   sizeof(KeyboardSecondaryController)  0x10   constructor 005cb9e0 new(0x10)
//   sizeof(NullController)               0x0c   constructor 005cb9e0 new(0xc)
//   sizeof(PlayerController)             0x2c   getController 005cbd10 new(0x2c)
//   sizeof(AIChaseController/AIFleeController) 0x64  getController 005cbd10 new(0x64)
// Field offsets are compile-time asserts (NativeUserControllerLayout is a friend of each class).
#include <stddef.h>
#include "v8datamodel/UserController.h"

struct NativeUserControllerLayout
{
	typedef char HardwareDevice[offsetof(RBX::ControllerService, hardwareDevice) == 0x130 ? 1 : -1];
	typedef char PlayerControllerField[offsetof(RBX::ControllerService, playerController) == 0x134 ? 1 : -1];
	typedef char KeyboardPrimary[offsetof(RBX::ControllerService, keyboardPrimaryController) == 0x138 ? 1 : -1];
	typedef char KeyboardSecondary[offsetof(RBX::ControllerService, keyboardSecondaryController) == 0x13c ? 1 : -1];
	typedef char Null[offsetof(RBX::ControllerService, nullController) == 0x140 ? 1 : -1];
	typedef char Service[offsetof(RBX::HardwareController, controllerService) == 0x0c ? 1 : -1];
	typedef char RunServiceField[offsetof(RBX::SteppingController, runService) == 0x10 ? 1 : -1];
	typedef char Controlled[offsetof(RBX::SteppingController, controlledInstance) == 0x18 ? 1 : -1];
	typedef char PlayerService[offsetof(RBX::PlayerController, controllerService) == 0x20 ? 1 : -1];
	typedef char StepsRotating[offsetof(RBX::PlayerController, stepsRotating) == 0x28 ? 1 : -1];
	typedef char RetargetTime[offsetof(RBX::AIController, retargetTime) == 0x20 ? 1 : -1];
	typedef char Buffer[offsetof(RBX::AIController, buffer) == 0x24 ? 1 : -1];
	typedef char Target[offsetof(RBX::AIController, target) == 0x5c ? 1 : -1];
};

size_t nativeControllerServiceSize() { return sizeof(RBX::ControllerService); }
size_t nativeKeyboardPrimaryControllerSize() { return sizeof(RBX::KeyboardPrimaryController); }
size_t nativeKeyboardSecondaryControllerSize() { return sizeof(RBX::KeyboardSecondaryController); }
size_t nativeNullControllerSize() { return sizeof(RBX::NullController); }
size_t nativePlayerControllerSize() { return sizeof(RBX::PlayerController); }
size_t nativeAIChaseControllerSize() { return sizeof(RBX::AIChaseController); }
size_t nativeAIFleeControllerSize() { return sizeof(RBX::AIFleeController); }
