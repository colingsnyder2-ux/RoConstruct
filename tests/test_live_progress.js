"use strict";
const assert = require("node:assert/strict"), fs = require("node:fs"), vm = require("node:vm");
const html = fs.readFileSync("docs/index.html", "utf8");
let requested = [], updates = 0;
const snapshot = {updated: "2026-10-20 23:00:00 UTC", clients: [
  {name: "C", functions: 3, matched: 1, partial: 1},
  {name: "other", functions: 4, matched: 2, partial: 0}], scores: {"00001000": 0}};
const publishedData = {units: ["A"], funcs: [[0x1000, 10, 0, 0, true], [0x1010, 10, 100, 0, true], [0x1020, 10, 50, 0, true]]};
const context = {URL, AbortSignal: {timeout() {}}, location: {hash: "#C"},
  progress: {server: "https://mining.example.com", clients: [{name: "C", started: true, matched: 3}, {name: "other"}]},
  hex: n => n.toString(16).padStart(8, "0"), cache: new Map(), liveScores: new Map(), liveFunctions: new Map(), liveView: {name: "C", update() { updates++; }}, overview() {},
  fetch: async url => { requested.push(String(url)); return {ok: true, json: async () => String(url) === "progress.json" ? snapshot : publishedData}; }};
vm.createContext(context);
vm.runInContext(html.slice(html.indexOf("async function refreshLiveProgress("), html.indexOf("function miningDays(")), context);
const data = {units: ["A"], funcs: [[0x1000, 10, 100, 0, true], [0x1010, 10, 100, 0, true]]};
const apply = vm.runInNewContext(html.slice(html.indexOf("  const applyScores ="), html.indexOf("  applyScores();")) + "\napplyScores;", {
  data, units: data.units, name: "C", latest: {functions: 2}, hex: n => n.toString(16).padStart(8, "0"),
  liveScores: new Map([["C", {"00001000": 50, "00001020": 0}]]),
  liveFunctions: new Map([["C", [["00001000", 12, 50, "A", 1], ["00001020", 8, 0, "B", 0]]]])});
assert.equal(apply(), true);
assert.deepEqual(Array.from(data.funcs, f => f[0]), [0x1000, 0x1020]); // Retired entry removed.
assert.deepEqual(Array.from(data.funcs, f => f[2]), [50, 0]);
assert.equal(data.funcs[0][1], 12); // Changed extent comes from the server.
assert.equal(data.units[data.funcs[1][3]], "B");
assert.equal(apply(), false); // Stable inventory keeps the current view/pagination.
(async () => {
  await context.refreshLiveProgress();
  assert.deepEqual(requested, ["progress.json", "data/C.json"]); // Never contact the private server.
  await context.refreshLiveProgress();
  assert.equal(updates, 1); // Unchanged snapshot keeps current UI.
  assert.equal(context.progress.clients[0].matched, 1); // A corrected score can go down.
  assert.equal(context.progress.clients[1].matched, 2);
  assert.equal(context.liveScores.get("C")["00001000"], 0);
  assert.equal(updates, 1);
  context.fetch = async () => { throw Error("offline"); };
  await context.refreshLiveProgress();
  assert.equal(context.progress.clients[0].matched, 1); // Keep last good snapshot.
  assert.equal(updates, 1);
  console.log("Live progress refresh tests passed.");
})().catch(error => { console.error(error); process.exitCode = 1; });
