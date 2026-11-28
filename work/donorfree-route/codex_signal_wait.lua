-- Exercise Lua event wait and its argument conversion through the normal signal path.
-- Mirrors feature_test.lua so the command-line client stays alive and reports are readable.
local np, fails = 0, {}
local function rec(name, ok) if ok then np = np + 1 else table.insert(fails, name) end end
local function report(tag) local v = Instance.new("StringValue") v.Name = tag .. " pass=" .. np .. " fail=" .. table.concat(fails, ",") v.Parent = workspace end
local function check(name, f) local ok, r = pcall(f) rec(name, ok and r ~= false) end

local floor = Instance.new("Part")
floor.Anchored = true
floor.Size = Vector3.new(40, 1, 40)
floor.Position = Vector3.new(0, 5, 0)
floor.Parent = workspace

local value = Instance.new("IntValue")
value.Name = "WaitValue"
value.Parent = workspace

local setter = Instance.new("Script")
setter.Name = "WaitSetter"
setter.Source = "wait(1) local v = workspace:FindFirstChild('WaitValue') if v then v.Value = 37 end"
setter.Parent = workspace

report("R1")

pcall(function() game:service("RunService"):run() end)
pcall(function() game:GetService("RunService"):Run() end)

local ok, received = pcall(function() return value.Changed:wait() end)
check("signal_wait_argument", function() return ok and received == 37 end)
report("R2")
