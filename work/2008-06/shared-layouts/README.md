# Shared layout recovery

Owner: Codex. UI implementation ownership remains Claude's. No active ABI change
has been made in this checkpoint; no new class has been swapped into the client.

Reproduce original evidence:

```
python rebuild/2008-06/tests/record_native_layouts.py shared-layouts/original-evidence.json
```

The receipt pins the original executable, observer and runtime metadata. It
parses x86 complete-object locators, hierarchy descriptors and base-class PMDs,
and independently checks the three MFC runtime size records in the original PE.
The mined source declarations remain codegen analogs, not header authority.

| Class | Proven inheritance / offset | Complete size |
|---|---|---|
| CRobloxDoc | VerbBinder<CRobloxDoc, CDocument> at 0 | 0x98 |
| CRobloxView | VerbBinder<CRobloxView, CView> at 0; RBX::VerbContainer at 0x78; Listener<ServiceProvider, ServiceAdded> at 0xa0; Listener<ServiceProvider, ServiceRemoving> at 0xa4; Listener<Network::Players, SuperSafeChanged> at 0xa8 | 0x1f0 |
| CMainFrame | CXTPMDIFrameWnd at 0; Listener<FillToolColor, BrickColor> at 0xf0 | 0x4b4 |
| HUMAN::HumanoidState | INamed at 0; HitTestFilter at 4 | Not supplied by MFC metadata |
| HUMAN::MovingNoPhysicsBase | Named<HumanoidState, sMovingNoPhysicsBase> at 0; SimJob at 0xa0; noncopyable at 0xa4 | Not supplied by MFC metadata |
| HUMAN::RunningNoPhysics | Named<MovingNoPhysicsBase, sRunningNoPhysics> at 0 | Not supplied by MFC metadata |

Doc construction: 00451ac0 calls intermediate constructor 00451590. The latter
calls CDocument construction, sets vtable 00817c24, and constructs a tree member
at +0x54 through 00446110. Doc then sets vtable 00817ce4, zeros +0x74, builds a
vector-like member at +0x78, and zeros +0x90/+0x94. Constructor shapes establish
storage and lifetime boundaries, not pointee types.

Resolved binder storage: src/2008-06/00451590.cpp uses map<int,int>, while the
mined destructor analog uses set<void*>. Those declarations were insufficient.
Original 00451a60 appends a verb pointer to the document vector at +0x78 and
stores its name (+4) into the map at +0x54. Original command routing 00451690
looks up the command ID, resolves the name through VerbContainer, and invokes
Verb::doIt or updates CCmdUI. The map search uses unsigned key comparison.
The view's recovered OnInitialUpdate independently uses the same UINT/Name*
storage at +0x58. The shared candidate now declares map<UINT, const Name*>.

Compiler-only checkpoint 0254dea8e6:

```
python rebuild/2008-06/tests/record_native_binder.py shared-layouts/binder-compile.json
```

Pinned MSVC 21022 verifies CDocument=0x54, CView=0x58, Doc binder=0x74, View
binder=0x78. The actual template-named Doc binder constructor matches original
00451590's 86 bytes with relocation fields masked. Header and observer hashes
are pinned in binder-compile.json. This does not establish the complete vtable
or active integration. OnCmdMsg remains a declaration; explicit instantiation
emits expected missing-definition warnings. No constructor match is added to
the running-executable count until selected by the linked client.

Next: recover binder command-routing definitions and document owner pointees;
derive View/Frame constructor member boundaries and complete Humanoid state
fields. Compile size/offset probes with the pinned original compiler before
using shared declarations. Run P5 and scoped P6 gates after each active swap.
