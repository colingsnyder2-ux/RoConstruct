"use strict";
const assert = require("node:assert/strict"), fs = require("node:fs"), vm = require("node:vm");
const html = fs.readFileSync("docs/index.html", "utf8");
const context = {
  fmt: n => String(n), pct: (n, total) => (total ? 100 * n / total : 0).toFixed(2) + "%",
  esc: s => String(s).replaceAll("<", "&lt;"), hex: n => n.toString(16).padStart(8, "0"),
  integrationMetric: "gains", ENGINE: "Roblox", APP: "App", classify: data => data.funcs.map(() => ["Roblox", "Physics"]),
};
vm.createContext(context);
vm.runInContext(html.slice(html.indexOf("function integrationSummary("), html.indexOf("/* One click")), context);
const native = {client: "2008-06", updated: "2026-10-28 12:00 UTC", native: ["00000001"],
  groups: {integrated: {bytes: 25}, exact_waiting: {bytes: 75}, partial: {bytes: 0}, unmined: {bytes: 0}},
  jobs: [
    {when: "2026-10-27 01:00 UTC", distinct_gains: 3, gains: 5},
    {when: "2026-10-28 10:00 UTC", distinct_gains: 0, gains: 4},
  ]};
const days = context.integrationDays(native);
assert.deepEqual(Array.from(days, d => [d.day, d.gains, d.jobs]), [
  ["2026-10-26", 3, 1], ["2026-10-27", 0, 0], ["2026-10-28", 0, 1],
]);
assert.equal(context.integrationSummary(native, "other"), "");
assert.match(context.integrationSummary(native, native.client), /Integrated · 25.00%/);
assert.match(context.integrationSummary(native, native.client), /aria-valuenow="25.00"/);
assert.doesNotMatch(context.integrationSummary({...native, groups: {}}, native.client), /NaN|Infinity/);
assert.match(context.integrationDaily(native), /Integrated 25.00%/);
assert.doesNotMatch(context.integrationDaily(native), /stacked by model|gpt-|claude|data-integration-metric/);
assert.doesNotMatch(context.integrationDaily({...native, jobs: []}), /NaN|Infinity/);
assert.match(context.integrationDaily({...native, jobs: []}), /Daily integration coverage/);
assert.equal(context.integrationDays({...native, daily: [{day: "2026-10-27", gains: 9, jobs: 2}]})[0].gains, 9);
new vm.Script(html.match(/<script>([\s\S]*)<\/script>/)[1]);
assert.doesNotMatch(html, /Code coverage view|code-mode|data-work-view/);
assert.match(html, /id="live-integration"/);
console.log("Integration frontend tests passed.");
