# P5 controller reconstruction

- Target `005cb530` is `PlayerController::onEvent`; the existing source
  recovered by address uses `UserInputBase`, local Player/Character,
  Workspace camera and Humanoid. It gives arrow keys priority over WASD;
  arrow-left/right pan the camera and forward/backward move along the camera
  heading. WASD moves on the camera ground plane, with opposite-key precedence
  and diagonal normalization. Space clears Sit and sets Jump.
- `005ce960` reads SDL navigation keys, `005ca400`/`005ca3c0`/`005ca3e0`
  supply the relevant axis precedence, and `005dc230` updates Humanoid
  Strafe. Camera `005ccb00` reads the current ICharacterSubject cursor-lock
  flag; this rebuild maps it to the existing donor `cursorLocked` member.
  The 2008 compiler layout report places that member at decimal 60 (0x3c),
  matching the target read.
- The matched 005cb530 source labels the final ignored poll as ctrlKeyDown;
  target `005ca390` tests SDL values 307/308 (RALT/LALT), so the adapter polls
  Alt. The return value is unused in the target.
- `0045f7b0` shows the original view assigning ControllerService's hardware
  input. The rebuilt `PlayerNativeInput` bridges the same interface to focused
  Win32 input; it is not the recovered original DxUserInput. Original startup,
  camera renderer synchronization, character spawn and input focus remain open.
- `Humanoid::buildJoints` is an existing donor implementation used explicitly
  by the fixture diagnostic. Running force/hover states remain documented
  behavioral glue; they are not claimed as recovered native movement physics.

Two 120-frame tests previously spun in `TimerService::onEvent` while a Player
idle callback repeatedly rescheduled itself. The 32-bit timer regression
confirmed D3D9 had changed x87 precision to 24 bits: at epoch-sized local time,
adding 0.01 seconds rounded to zero and a self-rescheduling timer fired four
times in one heartbeat. The original executable's renderer initialization at
`0067ab34..0067abfd` checks `Floating-point mode`, sets it to `Consistent`,
and logs that it is forcing the setting. The rebuild now sets the same option.
With the actual 2008 rgdx.dll, x87 precision is 53 bits and the test fires once;
repeated normal input/physics tests still need to demonstrate stability.
