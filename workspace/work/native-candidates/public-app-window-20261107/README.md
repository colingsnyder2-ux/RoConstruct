# Inactive application window candidate

Original path: `rebuild/2008-06/native-classes/ApplicationWindowClass.cpp`. Public work commit `bbe4a925d3c7faf3dcab4cbfc5321ebf08e32ab8`, blob `fa95b9eeaaa5b7674231cdf816f01c655d108508`, source SHA-256 `85aacb819b321a22bc11cb7f246a22132d42dc7035b4c3c02c889ecf89f38d0b`.

`nativeInitializeCom` at 004495a0 independently matches all 173 code bytes and referenced data using MSVC 2008 RTM. `bindings.json` verifies imports, literals and direct relocation targets against the original. Original final call is indirect through CFrameWnd vtable offset 0x144; dynamic provider identity and ABI remain unproved. Existing CRobloxApp references this provider. Keep inactive until virtual target, class ABI, affected closure/regression and owner selection/runtime gates are independently established. This file is not executable activation or server credit.

Update: pinned MFC 9.0.21022.8 PE evidence resolves vtable slot 0x144 to CFrameWnd::Create via the original runtime-class factory and constructor. The source is now integrated inactive; full application selection and runtime remain open. Existing CRobloxApp::InitInstance compiles but differs from the original (75%). See work/2008-06/shared-layouts/public-app-window-reconciliation.json.
