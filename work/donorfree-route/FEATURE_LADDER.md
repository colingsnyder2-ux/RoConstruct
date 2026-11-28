# RobloxQT feature ladder (2008-06)

Goal: `run/RobloxQT.exe` behaves like `run/RobloxOrig.exe` at every step. Work top to bottom. A tier
counts only when every row in it passes on both exes with no crash, no heap error (0xC0000374) and
no new MessageBox. `featladder` automates the rows marked [auto]; the others are manual for now.

Status column: update when a build passes. Current build: 8/9 auto steps (insert_items missing 11).

Automated harnesses (each runs the original first and reports only what breaks in ours):
- Tier 0-1.1, 4.1: `featladder.py` (cycle.py runs it after every link)
- Tier 1.2: `insertsweep.py` (inserts every Insert Object class through the dialog)
- Tier 1/3/4: `scripttest.py` with `feature_test.lua` (`-script`, results read from the Explorer)
- Tier 5: `scripttest.py --lua solo_test.lua` (Novetus 2008M way: createLocalPlayer + LoadCharacter + run)
- Tier 2: `tooltest.py` crash smoke only; the 3D view reads the mouse through DirectInput, so drag/resize effect is checked by hand
- Tier 6.3: `novetus/script2008M.lua` CSServer / CSConnect (local server + client)

## Tier 0 - Boot (done)
| # | Test | Pass when |
|---|------|-----------|
| 0.1 [auto] | Launch | Main window within 10 s |
| 0.2 [auto] | File > New | Title "Roblox - [Place1]", baseplate renders |
| 0.3 [auto] | Idle | CPU < 15 % for 10 s |
| 0.4 [auto] | Explorer | Roots: Workspace, Players, Lighting, StarterPack ... |

## Tier 1 - Every instance (in progress)
| # | Test | Pass when |
|---|------|-----------|
| 1.1 [auto] | Insert > Object list | Same class list as orig |
| 1.2 | Insert each class once (Part, Seat, SpawnLocation, Explosion, Message, Hint, Sky, Script, LocalScript, all Values, Body*, Motor, Backpack, Hole...) | Appears in Explorer, no crash |
| 1.3 | Properties pane on each inserted object | Every property shows a value; editing Name/Color/Size/Anchored applies |
| 1.4 | Delete, Undo, Redo on each | Object gone/back, no crash |
| 1.5 | Copy/Paste, Group/Ungroup (Model) | Copies appear, model in Explorer |

## Tier 2 - Part editing tools
| # | Test | Pass when |
|---|------|-----------|
| 2.1 | Select part by click | Selection box drawn, Explorer highlights |
| 2.2 | Drag tool | Part follows mouse, snaps to grid/surface |
| 2.3 | Resize tool | Handles shown, dragging changes Size in 1-stud steps |
| 2.4 | Rotate / Tilt (Ctrl+R / Ctrl+T) | 90 deg turns |
| 2.5 | Move up/down, Anchor, Lock | Position/flags change in Properties |
| 2.6 | Surface tools (Weld, Glue, Studs, Hinge, Motor) | Surface property changes, joints form on contact |
| 2.7 | Paint / material | Color and material change render |

## Tier 3 - Scripting
| # | Test | Pass when |
|---|------|-----------|
| 3.1 | Command bar: `print("hi")` | "hi" in Output |
| 3.2 | Command bar: `Instance.new("Part", workspace)` | Part appears |
| 3.3 | Tools > Execute Script (feature_test.lua below) | All lines print PASS |
| 3.4 | Script object in Workspace runs on Run | Its prints appear |
| 3.5 | Script errors | Error text + line in Output, client survives |

## Tier 4 - Physics and events
| # | Test | Pass when |
|---|------|-----------|
| 4.1 [auto] | Run / Stop / Reset | Game time advances, reset restores place |
| 4.2 | Unanchored part falls | Lands on baseplate, comes to rest |
| 4.3 | Stack of parts / welded model | Stays joined, falls as one |
| 4.4 | Touched event | Fires once per contact (script below) |
| 4.5 | Explosion | Breaks joints, flings parts, no crash |
| 4.6 | BodyVelocity / BodyPosition / BodyGyro | Part moves as set |
| 4.7 | Hinge / Motor | Spins |

## Tier 5 - Play solo / character
| # | Test | Pass when |
|---|------|-----------|
| 5.1 | Play solo (Tools > Test > Play Solo) | Character spawns at SpawnLocation |
| 5.2 | WASD + space, mouse camera | Walks, jumps, camera orbits/zooms |
| 5.3 | Character dies on fall/Explosion | Respawns |
| 5.4 | StarterPack tool | In backpack, equip, activate |
| 5.5 | LocalScript in character | Runs |
| 5.6 | Message / Hint, Sound, Decal, Sky, Lighting.TimeOfDay | Show / play / render |

## Tier 6 - Files and network
| # | Test | Pass when |
|---|------|-----------|
| 6.1 | Save .rbxl, close, open | Same objects, properties, scripts |
| 6.2 | Open orig-saved place in ours and vice versa | Identical load |
| 6.3 | Local server + client (2 instances) | Client joins, sees parts, character replicates |
| 6.4 | Toolbox / web pages (IE views) | Open; IE hang on hidden desktop is intentional |

## Tier 7 - Complete
| # | Test | Pass when |
|---|------|-----------|
| 7.1 | 30 min play solo session with all above | No crash, memory stable |
| 7.2 | Page heap run (RobloxPH.exe) of tiers 1-5 | No heap error |
| 7.3 | fastcensus/stubhits on a full session | No stub hit in any tested path |

Client is complete when tiers 0-7 pass. Then remove the IFEO RobloxPH.exe key.

## feature_test.lua (Tier 3.3, 4.4)
Paste into the command bar or Tools > Execute Script after File > New, then press Run.
Every line prints PASS or FAIL; nothing should print an error.

```lua
local function check(name, ok) print((ok and "PASS " or "FAIL ") .. name) end

-- instances
local classes = {"Part","Seat","SpawnLocation","Message","Hint","Sky","Script","Model",
  "IntValue","NumberValue","StringValue","BoolValue","ObjectValue","Vector3Value","Color3Value",
  "BodyVelocity","BodyPosition","BodyGyro","Explosion","Sound","Decal","Texture","Backpack"}
for _, c in ipairs(classes) do
  local ok, o = pcall(function() return Instance.new(c) end)
  check("new " .. c, ok and o ~= nil and o.className == c)
  if ok and o then pcall(function() o:Remove() end) end
end

-- properties
local p = Instance.new("Part")
p.Name = "TestPart"; p.Size = Vector3.new(4, 1, 2); p.Position = Vector3.new(0, 20, 0)
p.Anchored = false; p.BrickColor = BrickColor.new("Bright red")
p.Parent = workspace
check("parent", workspace:FindFirstChild("TestPart") == p)
check("size", p.Size.x == 4 and p.Size.y == 1)
check("color", p.BrickColor.Name == "Bright red")

-- values
local v = Instance.new("StringValue"); v.Value = "abc"; check("StringValue", v.Value == "abc")
local n = Instance.new("NumberValue"); n.Value = 1.5; check("NumberValue", n.Value == 1.5)

-- clone / remove
local c = p:Clone(); c.Parent = workspace; c.Position = Vector3.new(10, 20, 0)
check("clone", c ~= p and c.Name == "TestPart")

-- touched + physics (needs Run)
local touched = false
p.Touched:connect(function(hit) touched = true end)
wait(3)
check("falls", p.Position.y < 15)
check("touched", touched)

-- explosion
local e = Instance.new("Explosion"); e.Position = c.Position; e.Parent = workspace
wait(1)
check("explosion survived", true)
print("feature_test done")
```
