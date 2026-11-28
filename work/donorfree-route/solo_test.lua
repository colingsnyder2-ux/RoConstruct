-- FEATURE_LADDER Tier 5 (play solo) as a -script check, the Novetus 2008M way (novetus/script2008M.lua CS3DView):
-- local player, character, run. Summary 'R5 pass=N fail=a,b' lands in Workspace (scripttest.py --lua solo_test.lua).
local np, fails = 0, {}
local function rec(name, ok) if ok then np = np + 1 else table.insert(fails, name) end end
local function check(name, f) local ok, r = pcall(f) rec(name, ok and r ~= false) end
local function report(tag) local v = Instance.new("StringValue") v.Name = tag .. " pass=" .. np .. " fail=" .. table.concat(fails, ",") v.Parent = workspace end
local floor = Instance.new("Part") floor.Anchored = true floor.Size = Vector3.new(100, 1, 100) floor.Position = Vector3.new(0, 0, 0) floor.Parent = workspace
local plr
check("run", function() game:service("RunService"):run() return true end)
check("local player", function() plr = game.Players:createLocalPlayer(0) return plr ~= nil end)
check("load character", function() plr:LoadCharacter() return plr.Character ~= nil end)
wait(3)
check("humanoid", function() return plr.Character:findFirstChild("Humanoid") ~= nil end)
check("torso", function() return plr.Character:findFirstChild("Torso") ~= nil end)
check("alive", function() return plr.Character.Humanoid.Health > 0 end)
check("standing", function() local y = plr.Character.Torso.Position.y return y > 0 and y < 20 end)
check("walk", function() local t = plr.Character.Torso local p0 = t.Position plr.Character.Humanoid:MoveTo(p0 + Vector3.new(10, 0, 0), floor) wait(2) return (t.Position - p0).magnitude > 2 end)
check("jump", function() plr.Character.Humanoid.Jump = true wait(0.3) return true end)
check("die", function() plr.Character.Humanoid.Health = 0 wait(1) return plr.Character.Humanoid.Health == 0 end)
report("R5")
