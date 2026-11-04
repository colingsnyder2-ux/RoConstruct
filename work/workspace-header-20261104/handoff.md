# Implementation handoff
Uncommitted; lease RBX::Workspace headers retained. No more testing authorized.
Donor root: tools/rbxgs/Client/App/include (tools may resolve through shared checkout junction).

## rebuild\2008-06\native-headers\v8datamodel\Workspace.h
Copied from tools\rbxgs\Client\App\include\v8datamodel\Workspace.h
Line 26: `extern const char* sWorkspace;` -> `extern const char sWorkspace[];`
Line 27: `class Workspace : public DescribedNonCreatable<Workspace, RootInstance, &sWorkspace>,` -> `class Workspace : public DescribedNonCreatable<Workspace, RootInstance, sWorkspace>,`

## rebuild\2008-06\native-headers\v8datamodel\Camera.h
Copied from tools\rbxgs\Client\App\include\v8datamodel\Camera.h
Line 16: `extern const char* sCamera;` -> `extern const char sCamera[];`
Line 17: `class Camera : public DescribedCreatable<Camera, Instance, &sCamera>` -> `class Camera : public DescribedCreatable<Camera, Instance, sCamera>`

## rebuild\2008-06\native-headers\v8datamodel\RootInstance.h
Copied from tools\rbxgs\Client\App\include\v8datamodel\RootInstance.h
Line 15: `extern const char* sRootInstance;` -> `extern const char sRootInstance[];`
Line 16: `class RootInstance : public Reflection::Described<RootInstance, &sRootInstance, ModelInstance>,` -> `class RootInstance : public Reflection::Described<RootInstance, sRootInstance, ModelInstance>,`

## rebuild\2008-06\native-headers\v8datamodel\Stats.h
Copied from tools\rbxgs\Client\App\include\v8datamodel\Stats.h
Line 10: `extern const char* sStatsItem;` -> `extern const char sStatsItem[];`
Line 11: `class Item : public DescribedNonCreatable<Item, Instance, &sStatsItem>` -> `class Item : public DescribedNonCreatable<Item, Instance, sStatsItem>`
Line 70: `extern const char *sStats;` -> `extern const char sStats[];`
Line 71: `class StatsService : public DescribedNonCreatable<StatsService, Instance, &sStats>,` -> `class StatsService : public DescribedNonCreatable<StatsService, Instance, sStats>,`

## rebuild\2008-06\native-headers\script\Script.h
Copied from tools\rbxgs\Client\App\include\script\Script.h
Line 10: `extern const char* sScript;` -> `extern const char sScript[];`
Line 11: `class Script : public DescribedCreatable<Script, Instance, &sScript>` -> `class Script : public DescribedCreatable<Script, Instance, sScript>`
Line 68: `extern const char* sLocalScript;` -> `extern const char sLocalScript[];`
Line 69: `class LocalScript : public DescribedCreatable<LocalScript, Script, &sLocalScript>` -> `class LocalScript : public DescribedCreatable<LocalScript, Script, sLocalScript>`

Created rebuild/2008-06/tests/NativeWorkspaceHeaderCompile.cpp (new probe; no donor).

Dependency lists: include-graph.json lists 157 potential consumers and baseline compile outcomes. affected-recorders.json lists 218 scripts referencing those source basenames; conservative textual candidates, not verified execution coverage. The graph follows textual includes without evaluating preprocessor conditions.

Checks launched before latest stop instruction: see results.json and trial-*.log. No commit.
