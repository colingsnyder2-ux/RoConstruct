"use strict";
const assert = require("node:assert/strict"), fs = require("node:fs"), vm = require("node:vm");
const html = fs.readFileSync("docs/index.html", "utf8");
const c = {fmt:String, pct:(n,t)=>(100*n/t).toFixed(2)+"%", mb:n=>`${n} B`,
  hex:n=>n.toString(16).padStart(8,"0"), esc:String,
  classify:d=>d.funcs.map(()=>["Roblox","Core"]),
  sectionMode:()=>"", views:{}, UNLABELED:"Unknown"};
vm.createContext(c);
vm.runInContext(html.slice(html.indexOf("function dailyGraph("),html.indexOf("function miningGraph(")),c);
vm.runInContext(html.slice(html.indexOf("function integrationBar("),html.indexOf("/* One click")),c);
const data = {client:"2008-06", updated:"2026-11-05 12:00 UTC", native:["00000001"],
  inactive:{"00000001":["overlap",true],"00000002":["inactive",true],"00000003":["draft",false]},
  groups:{integrated:{functions:1,bytes:20},owned_waiting:{functions:2,bytes:50},
    exact_waiting:{functions:1,bytes:30},partial:{functions:0,bytes:0},unmined:{functions:0,bytes:0}},
  native_code:{inactive:{functions:1,bytes:40},draft:{functions:1,bytes:10}}};
assert.match(c.integrationBar(data,data.client), /Native code coverage.*60 B of 100 B.*60.00%/);
assert.match(c.integrationSummary(data,data.client), /Native coverage[\s\S]*aria-label="Native code coverage bytes"[\s\S]*aria-valuenow="60.00"/);
const daily = c.integrationDaily({...data,history:[{day:"2026-11-04",groups:data.groups,native_code:data.native_code}]});
assert.match(daily, /<th>Inactive native<\/th><th>Draft native<\/th>/);
assert.match(daily, /<td>2026-11-04<\/td><td>1<\/td><td>1<\/td><td>1<\/td><td>1<\/td><td>0<\/td>/);
assert.match(daily, /60.00%/);
c.integrationData = data;
vm.runInContext(fs.readFileSync("docs/library-coverage.js","utf8"),c);
const library = c.libraryTable({name:data.client,units:["Core"],funcs:[[1,20,100,0],[2,40,100,0],[3,10,50,0],[4,30,100,0]]},true);
assert.match(library, /<td>1 \/ 4<\/td><td>1<\/td><td>1<\/td>/);
assert.match(library, /60.00%/);
assert.doesNotMatch(html,/Every class and function in this client|id="tree-filter"|href="graph.html"/);
assert.doesNotMatch(fs.readFileSync("docs/graph.html","utf8"),/<script/);
assert.doesNotMatch(fs.readFileSync("README.md","utf8"),/RoConstruct-findings/);
console.log("Native site progress: union coverage, inactive/draft history, library breakdown and disabled graph passed.");
