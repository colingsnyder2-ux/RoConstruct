// 2008-06 native Notifier instance that the DataModel translation unit (v8datamodel/DataModel.cpp) emits first in
// link order inside the application range 00574000..00578000, inactive. Verified by
// tests/record_native_app_unit574.py against the committed util/Events.h and v8datamodel/Workspace.h (read-only):
//   * Notifier<Workspace, DrawChanged>::raise(DrawChanged) const 00576940 (evidence name; the RaiseRange loop over
//     the listeners, calling raise(event, listener) 00576450 for each).
//   * Notifier<Workspace, DrawChanged>::raise(DrawChanged, Listener*) const 00576450 is the same compiled body; the
//     original extent table splits it at the catch funclets 0057648e / 005764a1 (exact only when joined: BOUNDS).
#include "v8datamodel/Workspace.h"

template void RBX::Notifier<RBX::Workspace, RBX::DrawChanged>::raise(RBX::DrawChanged) const;
