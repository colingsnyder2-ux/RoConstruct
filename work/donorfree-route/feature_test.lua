-- FEATURE_LADDER Tiers 1/3/4 as a -script check: summaries 'R1 pass=N fail=a,b' (before Run) and 'R2 ...' (after physics)
-- land in Workspace as StringValue names (scripttest.py reads them from the Explorer). Each check runs in pcall: an error is a FAIL, not an abort.
local np, fails = 0, {}
local function rec(name, ok) if ok then np = np + 1 else table.insert(fails, name) end end
local function report(tag) local v = Instance.new("StringValue") v.Name = tag .. " pass=" .. np .. " fail=" .. table.concat(fails, ",") v.Parent = workspace end
local function check(name, f) local ok, r = pcall(f) rec(name, ok and r ~= false) end

local classes = {"Part","Seat","SpawnLocation","Message","Hint","Sky","Script","LocalScript","Model","IntValue","NumberValue",
  "StringValue","BoolValue","ObjectValue","Vector3Value","Color3Value","BrickColorValue","CFrameValue","BodyVelocity",
  "BodyPosition","BodyGyro","BodyForce","BodyAngularVelocity","BodyThrust","Explosion","Sound","Decal","Texture","Backpack",
  "Tool","HopperBin","Humanoid","SpecialMesh","Sparkles","ForceField","ClickDetector","Team","Hole","Flag","FlagStand",
  "Shirt","Pants","ShirtGraphic","Skin","BodyColors","Accoutrement","RocketPropulsion"}
for _, c in ipairs(classes) do
  check("new " .. c, function() local o = Instance.new(c) local ok = o ~= nil and o.className == c o.Parent = workspace o:Remove() return ok end)
end

local p
check("part props", function()
  p = Instance.new("Part") p.Name = "TestPart" p.Size = Vector3.new(4, 1, 2) p.Position = Vector3.new(0, 30, 0)
  p.Anchored = false p.BrickColor = BrickColor.new("Bright red") p.Parent = workspace
  return workspace:FindFirstChild("TestPart") == p and p.Size.x == 4 and p.BrickColor == BrickColor.new("Bright red") end)
check("values", function()
  local s = Instance.new("StringValue") s.Value = "abc" local n = Instance.new("NumberValue") n.Value = 1.5
  return s.Value == "abc" and n.Value == 1.5 end)
check("clone", function() local c = p:Clone() c.Parent = workspace c.Position = Vector3.new(10, 30, 0) return c ~= p end)
check("children", function() local ok, c = pcall(function() return workspace:children() end) if not ok then c = workspace:getChildren() end return #c > 2 end)
local fired = false
pcall(function() local v = Instance.new("IntValue") v.Changed:connect(function() fired = true end) v.Value = 5 end)

local floor = Instance.new("Part") floor.Anchored = true floor.Size = Vector3.new(40, 1, 40) floor.Position = Vector3.new(0, 5, 0) floor.Parent = workspace
local touched = false
pcall(function() p.Touched:connect(function() touched = true end) end)
report("R1")
pcall(function() game:service("RunService"):run() end)
pcall(function() game:GetService("RunService"):Run() end)
for i = 1, 80 do wait(0.1) if touched then break end end   -- the harness also presses Run
check("connect", function() return fired end)
check("falls", function() return p.Position.y < 25 end)
check("touched", function() return touched end)
check("explosion", function() local e = Instance.new("Explosion") e.Position = p.Position e.Parent = workspace return true end)
wait(1)
check("after explosion", function() return workspace.Parent ~= nil end)
report("R2")
