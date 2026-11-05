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
storage at +0x58. Initial candidate used map<UINT, const Name*>; the subsequent
bind-method compilation below refines that declaration to DWORD keys.

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

## Document field and binding recovery

The new candidate CRobloxDoc.h has no storage padding: owning XML snapshot at
0x74, vector<Verb*> at 0x78, owning StandardVerbs pointer at 0x90 and manually
released CWorkspace pointer at 0x94. Original run/stop 00455820/00455580 use
SerializerV2's XML root factory 00591a30 and loader 00593500; destructor
00451940 destroys the snapshot through 00413a70. StandardVerbs is explicitly
deleted before vector cleanup; the workspace is released in DeleteContents,
not through an automatic COM-pointer member destructor. The precise XML owner
template spelling remains unproven; std::auto_ptr reproduces the observed ABI.

```
python rebuild/2008-06/tests/record_native_document.py shared-layouts/document-compile.json
```

Pinned compilation verifies complete size 0x98 and all four member offsets.
COFF vtable relocations identify the 46 inherited virtual slots and all native
Doc overrides. Declaring those methods does not prove their implementations.
Constructor 00451ac0 matches 124 bytes; bindExisting 00451a10 matches 78 bytes;
bindOwned 00451a60 matches 91 bytes (relocation fields masked throughout).
The bodies now use shared fields rather than opaque offset accessors.

The binding comparison exposed a distinction absent from the constructor:
UINT map keys reused the input parameter address, producing 62/75-byte bodies.
DWORD keys require the original's unsigned key conversion. Separately reading
the name before map mutation reproduces the original evaluation order, including
the null-verb branch. These changes produce both complete exact bind bodies.
DWORD is the supported declaration choice; typedef spelling is not recoverable
from bytes alone. Active client still uses the passing shell; selected-function
count remains 2,997/14,344. No completed native class swap is claimed.

## Lifecycle dependency checkpoint

Shared StandardVerbs declarations now reuse the recovered native composition;
its destructor 00450450 matches 998 bytes. Shared v8xml/XmlElement.h reuses the
matched header unit whose value union includes double. That changes the donor
layout to the native 40-byte, eight-byte-aligned object; destructor 00413a70
then matches all 138 bytes. The donor destructor had the same byte length but
different member offsets, so a size-only check would have missed the mismatch.

Doc OnNewDocument 00452f60 matches 149 bytes, OnCloseDocument 0044f210 matches
five, GetRuntimeClass 0044f200 matches six and CreateObject 00452f00 matches 89.
Original EH metadata (FuncInfo 008d9074, handler type 008d9040) proves the new
document handler catches std::exception by reference (adjectives 8). The new
body preserves the original error message spelling and clears the modified
flag only after command/workspace initialization succeeds. The logging helper
00428850 and initialization 00451b60 remain explicit unresolved link edges.

Doc destructor is still OPEN: a forced-inline shared binder destructor emits
204 bytes versus the native 198, including an extra binder-vtable store at
candidate offset 0x95. Default inlining emitted an out-of-line call (182 bytes).
Ob1 and Oi/Ot profiles retain the extra store; O1 produces 131 bytes. Adding
novtable to the shared class merely to fix this destructor would also remove
the independently verified binder constructor's vtable write. Do not weaken
that constructor gate. Resolve the shared class's code-generation boundary
before swapping its lifecycle into the client.

The original embedded type library is now read without COM registration:

```
python rebuild/2008-06/tests/record_native_typelib.py shared-layouts/original-typelib.json
```

The reader requests the dual vtable interfaces, preserving HRESULT/retval
parameters that the IDispatch view transforms. It verifies IWorkspace's eight
methods and IContent::Upload, their actual GUIDs and native x86 slot offsets.
Host COM pointer-size normalization is explicit. RobloxLib.h provides these
shared declarations; the pinned compiler verifies four-byte interfaces and
16-byte VARIANT. This does not implement the COM object.

Original CComObject<CWorkspace> RTTI supplies the missing object's actual base
order: IDispatchImpl<IWorkspace>, CComObjectRootEx<CComSingleThreadModel>,
CComCoClass, ISupportErrorInfoImpl, IObjectSafetyRobloxImpl, IObjectWithSiteImpl,
and Selection/Workspace listeners. The construction body at 0046ab60 initializes
the data-model shared pointer at 0x24 and another shared pointer at 0x2c.
The second pointee and callback ownership remain to be identified before its
shared declaration and Doc::DeleteContents can be completed.

No active ABI swap occurred; runtime gates and selected-function baseline are
unchanged. Source provenance and rejected destructor profiles are recorded in
native-classes/source-manifest.json. A concurrent stale verifier overwrite was
preserved locally, then the stronger size/body/dependency checks were restored.

Next: recover binder command-routing definitions and document lifecycle bodies;
derive View/Frame constructor member boundaries and complete Humanoid state
fields. Compile size/offset probes with the pinned original compiler before
using shared declarations. Run P5 and scoped P6 gates after each active swap.
