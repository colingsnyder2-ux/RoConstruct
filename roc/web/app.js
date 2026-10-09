"use strict";
const $ = (selector) => document.querySelector(selector);
const esc = (value) => String(value ?? "").replace(/[&<>"']/g, char => ({"&":"&amp;","<":"&lt;",">":"&gt;",'"':"&quot;","'":"&#39;"}[char]));
const token = location.hash.slice(1) || sessionStorage.getItem("roc-session");
if (token) sessionStorage.setItem("roc-session", token);
history.replaceState(null, "", location.pathname);
let meta, jobs = [], page = "overview", selectedCommand = "mass", editing = null;
let cursor = 0, logs = [], follow = true, online = false, toastTimer, localModels = [];
const active = job => ["running", "paused", "stopping"].includes(job.status);
const liveKeys = new Set(["workers","model","rounds","max_size","max_tokens","strategy","order","thinking","reasoning_effort","use_revng","min_score","max_score","diverse_candidates","guided_mutations","near_repair","max_cloud_requests","max_cloud_tokens","max_cloud_cost"]);
const nullable = new Set(["min_score","max_score","max_cloud_requests","max_cloud_tokens","max_cloud_cost","reasoning_effort","unit_name","family_id"]);
const numeric = new Set(["workers","rounds","max_size","max_tokens","min_score","max_score","diverse_candidates","cloud_concurrency","max_cloud_requests","max_cloud_tokens","max_cloud_cost"]);
const automatic = {rounds:"auto",max_size:512,max_tokens:"auto",order:"auto",strategy:"direct",thinking:"auto",reasoning_effort:"auto",use_revng:false,cloud_concurrency:"auto"};

async function api(path, data) {
  const response = await fetch("/api/" + path, {method:data === undefined ? "GET" : "POST", headers:{"X-ROC-Token":token || "", "Content-Type":"application/json"}, ...(data === undefined ? {} : {body:JSON.stringify(data)})});
  const result = await response.json();
  if (!response.ok) throw new Error(result.error || "Request failed");
  return result;
}
function toast(message) { $("#toast").textContent = message; $("#toast").classList.add("visible"); clearTimeout(toastTimer); toastTimer = setTimeout(() => $("#toast").classList.remove("visible"), 6000); }
async function act(fn) { try { await fn(); } catch(error) { toast(error.message); } }
function badge(status) { return `<span class="badge ${esc(status)}">${esc(status)}</span>`; }
function icon(name) { return `<svg class="icon" aria-hidden="true"><use href="#i-${name}"/></svg>`; }
function heading(label, title, description, buttons="") { return `<div class="page-heading"><div><h1>${title}</h1><p>${description}</p></div><div class="button-row">${buttons}</div></div>`; }
function duration(job) { if (!job.started) return "—"; const seconds = Math.max(0, Math.floor((job.ended || Date.now()/1000)-job.started)); return seconds < 60 ? `${seconds}s` : seconds < 3600 ? `${Math.floor(seconds/60)}m ${seconds%60}s` : `${Math.floor(seconds/3600)}h ${Math.floor(seconds%3600/60)}m`; }
function button(label, attrs="", secondary=false) { const symbol=/start|run|resume/i.test(label) ? "play" : /pause/i.test(label) ? "pause" : /stop|cancel/i.test(label) ? "stop" : /apply|tune|controls/i.test(label) ? "sliders" : /fetch/i.test(label) ? "download" : /save/i.test(label) ? "check" : ""; return `<button class="button ${secondary ? "secondary" : ""}" ${attrs}>${symbol ? icon(symbol) : ""}${label}</button>`; }
function empty(title, description) { return `<div class="empty"><div class="empty-symbol">◇</div><h3>${title}</h3><p>${description}</p></div>`; }
function endRun(job) {
  return `<button class="button end-run" data-action="${job.kind==="worker" ? "stop" : "kill"}" data-id="${job.id}" title="${job.kind==="worker" ? "Stop new leases; finish active functions" : "Stop this command"}" ${job.status==="stopping" ? "disabled" : ""}>${icon("stop")}${job.status==="stopping" ? "Ending…" : "End run"}</button>`;
}
function runTable(rows, emptyTitle="No saved runs") {
  if (!rows.length) return `<div class="panel">${empty(emptyTitle, "Start a worker or choose a command.")}</div>`;
  return `<div class="panel"><table class="run-list"><thead><tr><th>RUN</th><th>STATUS</th><th class="optional">DURATION</th><th>RESULT</th><th></th></tr></thead><tbody>${rows.map(job => `<tr><td class="run-name" data-log="${job.id}">${esc(job.title)}<small>${job.id}</small></td><td>${badge(job.status)}</td><td class="optional">${duration(job)}</td><td>${job.kind === "worker" ? `${job.matched} exact / ${job.attempted} tried` : esc(job.stage || (job.exit_code === undefined ? "—" : "exit " + job.exit_code))}</td><td><div class="run-actions">${job.status === "queued" ? `<button class="text-button" data-action="cancel" data-id="${job.id}">Cancel</button>` : active(job) ? (job.kind==="worker" ? `<button class="text-button" data-action="edit" data-id="${job.id}">Controls</button>` : "")+endRun(job) : `<button class="text-button" data-rerun="${job.id}">Rerun</button>`}</div></td></tr>`).join("")}</tbody></table></div>`;
}
function overview() {
  const total = key => jobs.reduce((sum, job) => sum + (job[key] || 0), 0);
  const running = jobs.filter(active), workers = running.filter(job => job.kind === "worker");
  return heading("", "Overview", "Worker results, queued commands, and current activity.", button("Start worker", 'data-new-worker') + button("Run mass", 'data-open-command="mass"', true)) +
    `<div class="workflow"><span class="workflow-step">${icon("file")}Lease</span><span class="workflow-arrow">→</span><span class="workflow-step">${icon("code")}Draft C++</span><span class="workflow-arrow">→</span><span class="workflow-step">${icon("cpu")}Compile</span><span class="workflow-arrow">→</span><span class="workflow-step">${icon("branch")}Compare bytes</span><span class="workflow-arrow">→</span><span class="workflow-step">${icon("check")}Submit match</span></div>` +
    `<div class="stat-grid"><div class="stat"><div class="stat-icon">${icon("code")}</div><div class="stat-label">Exact matches</div><div class="stat-value">${total("matched")}</div><div class="stat-note">Recorded worker runs</div></div><div class="stat"><div class="stat-icon">${icon("file")}</div><div class="stat-label">Functions attempted</div><div class="stat-value">${total("attempted")}</div><div class="stat-note">${total("improved")} improved · ${total("failed")} failed</div></div><div class="stat"><div class="stat-icon">${icon("cpu")}</div><div class="stat-label">Worker loops</div><div class="stat-value">${workers.reduce((sum,job)=>sum+Object.keys(job.slots).length,0)}</div><div class="stat-note">${workers.reduce((sum,job)=>sum+(Number(job.config.workers)||Object.keys(job.slots).length),0)} requested · ${running.length} active runs</div></div><div class="stat"><div class="stat-icon">${icon("chart")}</div><div class="stat-label">Cloud requests</div><div class="stat-value">${jobs.reduce((sum,job)=>sum+(job.usage.requests||0),0)}</div><div class="stat-note">Usage appears after each function</div></div></div>` +
    `<div class="section-heading"><h2>Current activity</h2><button class="text-button" data-page="history">View run history →</button></div>` + runTable([...jobs].reverse().filter(job => active(job) || job.status === "queued").slice(0,10), "No active runs") +
    `<p class="help-note">Runs execute one at a time to protect shared source and work files. Parallel worker loops run within a worker session.</p>`;
}
function field(label, key, value, options={}) {
  const disabled = editing && !liveKeys.has(key) ? "disabled" : "";
  let input;
  if (options.choices) input = `<select name="${key}" ${disabled}>${options.choices.map(choice => { const [v,l] = Array.isArray(choice) ? choice : [choice,choice]; return `<option value="${esc(v)}" ${String(value ?? "") === String(v) ? "selected" : ""}>${esc(l)}</option>`; }).join("")}</select>`;
  else input = `<input name="${key}" value="${esc(value)}" type="${options.type || "text"}" ${options.min !== undefined ? `min="${options.min}"` : ""} ${options.max !== undefined ? `max="${options.max}"` : ""} ${options.type === "number" ? 'step="'+(key === "max_cloud_cost" ? "0.01" : "1")+'"' : ""} ${options.list ? `list="${options.list}"` : ""} ${options.placeholder ? `placeholder="${esc(options.placeholder)}"` : ""} ${disabled}>`;
  if (options.stepper) input = `<div class="stepper"><button type="button" data-step="-1" data-field="${key}" ${disabled} aria-label="Decrease ${label}">−</button>${input}<button type="button" data-step="1" data-field="${key}" ${disabled} aria-label="Increase ${label}">＋</button></div>`;
  return `<label class="field ${options.full ? "full" : ""}"><span>${label}</span>${input}</label>`;
}
function check(label, key, value) { return `<label class="inline-check"><input type="checkbox" name="${key}" ${value ? "checked" : ""} ${editing && !liveKeys.has(key) ? "disabled" : ""}>${label}</label>`; }
function workerForm(config) {
  const models = [...new Set([...localModels, ...meta.providers.flatMap(provider => provider.models.map(model => provider.name+":"+model)), config.model].filter(Boolean))];
  const preset = config.rounds==="auto" && config.max_tokens==="auto" ? "automatic" : config.rounds===2 && config.max_size===96 ? "fast" : config.rounds===6 && config.max_size===512 ? "deep" : config.rounds===4 && config.max_size===256 ? "balanced" : "";
  return `<form id="worker-form" class="panel panel-pad"><div class="section-heading"><h2>${editing ? "Tune active session" : "Configure a worker"}</h2>${editing ? `<button type="button" class="text-button" data-new-worker>New session →</button>` : ""}</div><div class="preset-row">${["automatic","fast","balanced","deep"].map(mode=>`<button type="button" data-preset="${mode}" class="${preset===mode ? "active" : ""}">${mode[0].toUpperCase()+mode.slice(1)}</button>`).join("")}</div><div class="field-grid">` +
    field("Client", "client", config.client, {choices:[["","All available clients"],...meta.clients.map(client=>[client.name,client.name])]}) +
    field("Username", "user", config.user) + field("Server", "server", config.server, {full:true,placeholder:"host:8765 or https://server"}) +
    field("Model", "model", config.model, {full:true,list:"models",placeholder:"provider:model or installed Ollama model"}) + `<datalist id="models">${models.map(model=>`<option value="${esc(model)}"></option>`).join("")}</datalist>` +
    field("Worker loops", "workers", config.workers, {placeholder:"auto or 1–256"}) +
    `</div><p class="help-note">Set worker count above, or use auto to choose per model. Automatic preserves your worker count, chooses rounds and output per function, prioritizes best evidence, and limits targets to 512 bytes. Advanced values override its defaults.</p><details class="form-section"><summary>Advanced controls</summary><div class="field-grid">` +
    field("Rounds per function", "rounds", config.rounds, {placeholder:"auto or 1–100"}) +
    field("Output tokens", "max_tokens", config.max_tokens, {placeholder:"auto or 128–8192"}) + field("Maximum function bytes", "max_size", config.max_size, {type:"number",min:1}) +
    field("Function order", "order", config.order, {choices:["random","auto","best","matched","unmatched","easiest"]}) + field("Strategy", "strategy", config.strategy, {choices:["auto","direct","structured","reference"]}) +
    field("Thinking", "thinking", config.thinking, {choices:["auto","enabled","disabled"]}) + field("Reasoning effort", "reasoning_effort", config.reasoning_effort, {choices:[["","Provider default"],"auto","low","medium","high","max"]}) +
    field("Minimum score", "min_score", config.min_score, {type:"number",min:0,max:100,placeholder:"Any"}) + field("Maximum score", "max_score", config.max_score, {type:"number",min:0,max:100,placeholder:"Any"}) +
    field("Diverse candidates", "diverse_candidates", config.diverse_candidates, {type:"number",min:1,max:16}) + field("Cloud concurrency", "cloud_concurrency", config.cloud_concurrency, {placeholder:"auto or 1–256"}) +
    field("Lease mode", "lease_mode", config.lease_mode, {choices:["function","family","unit"]}) + field("Unit name", "unit_name", config.unit_name) + field("Family fingerprint", "family_id", config.family_id, {full:true}) +
    field("Target addresses (comma separated)", "addresses", (config.targets || []).map(row=>row.addr).join(", "), {full:true,placeholder:"00401000, 00401200"}) +
    `<div class="field full button-row">${check("Rev.ng hints", "use_revng", config.use_revng)}${check("Guided mutations", "guided_mutations", config.guided_mutations)}${check("Near-match repair", "near_repair", config.near_repair)}${check("Source-only (no AI)", "source_only", config.source_only)}</div></div><h3 class="form-section">Cloud budgets</h3><div class="field-grid">` +
    field("Request cap", "max_cloud_requests", config.max_cloud_requests, {type:"number",min:1,placeholder:"Unlimited"}) + field("Token cap", "max_cloud_tokens", config.max_cloud_tokens, {type:"number",min:1,placeholder:"Unlimited"}) + field("Estimated spend cap ($)", "max_cloud_cost", config.max_cloud_cost, {type:"number",min:0.01,placeholder:"Requires configured pricing",full:true}) +
    `</div><p class="help-note">Budget edits preserve usage already spent. In-flight requests continue. Unknown prices cannot establish actual spend.</p></details><div class="consent">${check("Allow cloud prompts for this session", "cloud_allowed", config.cloud_allowed)}<p>Bounded assembly, symbols and source hints leave this PC. Provider keys and executable files stay local.</p></div><div class="form-footer"><span class="tiny muted">${editing ? "Edits apply before each loop's next function." : "Compilation and byte comparison stay local."}</span>${button(editing ? "Apply changes" : "Start worker", 'type="submit"')}</div><div class="button-row form-section"><button type="button" class="text-button" id="save-preset">Save preset</button><select id="saved-presets" aria-label="Load a saved preset"><option value="">Load saved preset…</option>${Object.keys(meta.preferences.presets).map(name=>`<option>${esc(name)}</option>`).join("")}</select><button type="button" class="text-button" id="refresh-models">Refresh models</button></div></form>`;
}
let controlsOpen=false, workerRun="", chatFollow=true, chatSignature="", chatCompact=false, workerLoop="";
function workers(config) {
  const current=jobs.find(job=>job.id===editing);
  if(!current || !active(current))editing=null;
  return `<div id="worker-chat" class="worker-chat" tabindex="0" role="log" aria-label="Live worker activity"><div id="worker-chat-rows"></div></div><button id="jump-live" class="jump-live" hidden>↓ Jump back to live</button><footer class="worker-footer"><div id="worker-tabs" class="worker-tabs" role="tablist" aria-label="Worker sessions"></div><div class="worker-footer-controls"><div id="worker-status" class="worker-live-bar"></div><div class="chat-toolbar"><select id="worker-run" aria-label="Worker session"><option value="">All sessions</option>${jobs.filter(j=>j.kind==="worker").map(j=>`<option value="${j.id}" ${workerRun===j.id ? "selected" : ""}>${esc(j.config.client)} · ${j.id.slice(0,6)}</option>`).join("")}</select><select id="worker-loop" aria-label="Worker loop"><option value="">All loops</option>${Array.from({length:Math.max(1,...jobs.filter(j=>j.kind==="worker").map(j=>Math.max(Object.keys(j.slots).length,Number(j.config.workers)||1)))},(_,i)=>`<option value="${i}" ${workerLoop===String(i) ? "selected" : ""}>Worker ${i+1}</option>`).join("")}</select><button class="text-button" id="chat-compact">${chatCompact ? "Regular" : "Compact"}</button><button class="text-button" id="chat-follow">${chatFollow ? "Live ↓" : "Latest ↓"}</button><button class="text-button" data-configure>Configure</button><button class="text-button" data-new-session>+ New</button></div></div></footer><aside class="worker-drawer ${controlsOpen ? "open" : ""}" aria-label="Worker configuration"><div class="drawer-heading"><h2>${editing ? "Session controls" : "New session"}</h2><button class="text-button" data-close-controls>Close ×</button></div>${workerForm(config || (editing ? current.config : meta.initial))}</aside>`;
}
function highlightCode(code) {
  return String(code).split(/(\/\/[^\n]*|"(?:\\.|[^"\\])*"|\b(?:void|int|float|double|char|bool|class|struct|return|if|else|for|while|const|static|unsigned|signed|auto|nullptr|true|false|sizeof)\b|\b\d+\b)/g).map(part=>{const cls=part.startsWith("//") ? "comment" : part.startsWith('"') ? "string" : /^\d+$/.test(part) ? "number" : /^(void|int|float|double|char|bool|class|struct|return|if|else|for|while|const|static|unsigned|signed|auto|nullptr|true|false|sizeof)$/.test(part) ? "keyword" : "";return cls ? `<span class="syntax-${cls}">${esc(part)}</span>` : esc(part);}).join("");
}
function codeBlock(code,label="C++") { return `<div class="chat-code"><div>${esc(label)}<button class="text-button" data-copy-code>Copy</button></div><pre><code>${label==="C++" ? highlightCode(code) : esc(code)}</code></pre></div>`; }
function terminalMessage(row, functions, compact=false) {
  const stamp=new Date(row.time*1000).toLocaleTimeString("en-GB"), worker=row.slot===undefined ? "roc" : "w"+(row.slot+1);
  const fn=functions.get(row.job+":"+row.slot);
  let marker="·", text=logText(row), extra="", kind=row.event;
  if(row.event==="job_started") {marker="›";text=`${row.client} ${row.addr} ${row.size ?? "?"} B ${row.unit || ""} · best ${row.previous}%`;}
  else if(row.event==="job_finished") {kind+=" "+(row.score===100||row.score>row.previous ? "improved" : "no-gain");marker=row.score===100 ? "✓" : row.score>row.previous ? "↑" : "·";text=`${row.client} ${row.addr}${row.supercompact ? "" : " "+(row.unit || fn?.unit || "")} · ${row.previous}% → ${row.score}%${row.score===100 ? " EXACT" : row.score<=row.previous ? " no gain" : " improved"}${row.seconds===undefined ? "" : " · "+row.seconds+"s"}`;}
  else if(row.event==="benchmark") {marker="≡";text=`${row.workers}w · ${row.completed} done · ${row.per_minute} fn/min · ${row.matched} exact · ${row.improved} improved · ${row.errors} errors`;}
  else if(row.event==="compile") {
    marker="$";const runs=row.compile_runs || [row],failed=runs.filter(r=>r.exit_code!==0).length;
    text=`compile${runs.length>1 ? " ×"+runs.length : ""} · ${failed ? failed+" failed" : "ok"}`;
    extra=runs.map((r,i)=>(runs.length>1 ? `<div class="compile-attempt">Attempt ${i+1} · exit ${r.exit_code}</div>` : "")+codeBlock(r.argv.map(a=>/\s/.test(a) ? JSON.stringify(a) : a).join(" "),"Command")+(r.output ? codeBlock(r.output,"Output") : "")).join("");
  }
  else if(["draft","candidate"].includes(row.event)) {marker=row.event==="draft" ? "◇" : "↑";text=row.event==="draft" ? `draft · round ${row.round}` : `verified candidate · ${row.score}%`;extra=codeBlock(row.code);}
  else if(/generated source[^\n]*:\n/.test(text)) {extra=codeBlock(text.slice(text.indexOf("\n")+1));text=text.slice(0,text.indexOf("\n")).replace(/generated source \(final (\d+)%\):/,"source · $1%");}
  else if(row.event==="error"||/error:|failed/i.test(text)) {marker="!";kind="error";}
  const content=`<span class="terminal-marker">${marker}</span><span class="terminal-text">${esc(text.trim())}</span>`;
  return `<article class="terminal-row ${esc(kind)}" data-key="${esc(row.job+":"+row.seq)}"><time>${stamp}</time><span class="terminal-worker">${worker}</span>${extra ? `<details ${!compact && ["draft","candidate"].includes(row.event) ? "open" : ""}><summary>${content}</summary>${extra}</details>` : `<div>${content}</div>`}</article>`;
}
function setChatFollow(enabled) {
  chatFollow=enabled;
  const button=$("#chat-follow"),jump=$("#jump-live");
  if(button)button.textContent=enabled ? "Live ↓" : "Latest ↓";
  if(jump)jump.hidden=enabled;
}
function scrollToLatest(node, smooth=false) {
  requestAnimationFrame(()=>{
    if(!node.isConnected || (node.id==="worker-chat"&&!chatFollow) || (node.id==="log-scroll"&&!follow))return;
    node.dataset.liveScrolling="1";
    node.scrollTo({top:node.scrollHeight,behavior:smooth && !matchMedia("(prefers-reduced-motion: reduce)").matches ? "smooth" : "instant"});
    setTimeout(()=>delete node.dataset.liveScrolling,500);
  });
}
function updateFeed(node, items, following, smooth) {
  const viewport=node.id==="worker-chat-rows"||node.id==="log-rows" ? node.parentElement : node;
  const top=viewport.scrollTop,edge=viewport.getBoundingClientRect().top,anchor=[...node.children].find(child=>child.getBoundingClientRect().bottom>edge),offset=anchor ? anchor.getBoundingClientRect().top-edge : 0;
  const existing=new Map([...node.children].map(child=>[child.dataset.key,child]));
  let next=node.firstElementChild;
  for(const [key,html] of items) {
    let child=existing.get(key);
    if(!child) {const template=document.createElement("template");template.innerHTML=html;child=template.content.firstElementChild;child.dataset.key=key;node.append(child);}
    else if(child.dataset.html!==html) {const opened=[...child.querySelectorAll("details")].map(d=>d.open);const template=document.createElement("template");template.innerHTML=html;const replacement=template.content.firstElementChild;replacement.dataset.key=key;replacement.querySelectorAll("details").forEach((d,i)=>d.open=opened[i]||false);if(child===next)next=replacement;child.replaceWith(replacement);child=replacement;}
    if(child!==next)node.insertBefore(child,next);
    next=child.nextElementSibling;child.dataset.html=html;existing.delete(key);
  }
  for(const child of existing.values())child.remove();
  if(following)scrollToLatest(viewport,smooth);
  else {
    const retained=anchor && [...node.children].find(child=>child.dataset.key===anchor.dataset.key);
    if(retained)viewport.scrollTop+=retained.getBoundingClientRect().top-viewport.getBoundingClientRect().top-offset;
    else viewport.scrollTop=top;
  }
}
function renderWorkerChat() {
  const node=$("#worker-chat");if(!node)return;
  const workerJobs=jobs.filter(j=>j.kind==="worker");
  const tabs=$("#worker-tabs"),tabSignature=workerJobs.map(j=>j.id+j.status).join()+workerRun;
  if(tabs.dataset.signature!==tabSignature) {tabs.innerHTML=`<button role="tab" aria-selected="${!workerRun}" class="worker-tab ${!workerRun ? "selected" : ""}" data-worker-tab="all">All workers</button>`+workerJobs.slice(-12).map(j=>`<div class="worker-tab-group"><button role="tab" aria-selected="${workerRun===j.id}" class="worker-tab ${workerRun===j.id ? "selected" : ""}" data-worker-tab="${j.id}"><span class="dot ${esc(j.status)}"></span>${esc(j.config.client)} <span>${j.id.slice(0,5)}</span><small>${esc(j.status)}</small></button>${!active(j)&&j.status!=="queued" ? `<button class="worker-tab-close" data-remove-run="${j.id}" aria-label="Remove finished run ${j.id}" title="Remove from run history">×</button>` : ""}</div>`).join("");tabs.dataset.signature=tabSignature;}
  const status=$("#worker-status"),statusHTML=workerCards();if(status.innerHTML!==statusHTML)status.innerHTML=statusHTML;
  const loopCount=workerJobs.filter(j=>active(j)&&(!workerRun||j.id===workerRun)).reduce((sum,j)=>sum+Object.keys(j.slots).length,0);
  const supercompact=loopCount>3, compact=chatCompact || supercompact;
  node.classList.toggle("compact",compact);node.classList.toggle("supercompact",supercompact);
  $("#chat-compact").textContent=supercompact ? "Supercompact · auto" : chatCompact ? "Regular" : "Compact";
  const foldSource=compact;
  const ids=new Set(workerJobs.map(job=>job.id));
  const rows=logs.filter(r=>ids.has(r.job)&&(!workerRun||r.job===workerRun)&&(workerLoop===""||String(r.slot)===workerLoop||r.event==="benchmark")&&(compact ? r.startup || ["job_finished","benchmark","error","rejected"].includes(r.event) : !["control","applied","usage"].includes(r.event))).slice(-180);
  const signature=compact+":"+supercompact+":"+rows.map(r=>r.job+":"+r.seq).join();
  setChatFollow(chatFollow);
  const viewFilter=workerRun+":"+workerLoop+":"+compact+":"+supercompact;
  if(!chatFollow && node.dataset.viewFilter===viewFilter && $("#worker-chat-rows").children.length)return;
  if(chatSignature===signature && $("#worker-chat-rows").children.length)return;
  const functions=new Map(),items=[];
  const grouped=[];
  for(const row of rows) {
    const last=grouped[grouped.length-1];
    if(row.event==="compile" && last?.event==="compile" && row.slot===last.slot && row.job===last.job)last.compile_runs.push(row);
    else grouped.push(row.event==="compile" ? {...row,compile_runs:[row]} : row);
  }
  for(const row of grouped) {
    if(row.event==="job_started")functions.set(row.job+":"+row.slot,row);
    if(row.event==="log" && !row.startup && /auto-think:|^\[.*best so far|Privacy:|Cloud model:|^thinking disabled for remaining rounds|^no improvement/.test(row.message.trim()))continue;
    items.push([row.job+":"+row.seq+":"+foldSource,terminalMessage(supercompact ? {...row,supercompact:true} : row,functions,foldSource)]);
  }
  if(!items.length)items.push(["empty",empty(loopCount ? "Working…" : "Ready for work", compact ? "One line per completed function. Benchmarks every 30 seconds while functions finish." : "Configure a session. Function activity and verified source appear here.")]);
  updateFeed($("#worker-chat-rows"),items,chatFollow,!!chatSignature);
  chatSignature=signature;node.dataset.viewFilter=viewFilter;
}
function workerCards() {
  const selected=jobs.find(j=>j.id===workerRun), current=selected || jobs.find(j=>j.kind==="worker"&&active(j));
  if(!current)return '<span class="muted">Idle</span>';
  return `<div class="live-session"><span class="session-summary">${badge(current.status)} <b>${Object.keys(current.slots).length}</b> loops · <b>${current.matched}</b> exact · ${current.attempted} tried</span>${active(current) ? `<button class="text-button" data-action="${current.status==="paused" ? "resume" : "pause"}" data-id="${current.id}" ${current.status==="stopping" ? "disabled" : ""}>${current.status==="paused" ? "Resume" : "Pause"}</button>${endRun(current)}<button class="text-button" data-action="kill" data-id="${current.id}" aria-label="Stop immediately">×</button>` : ""}</div>`;
}
function commands() {
  const command = meta.commands.find(command=>command.name===selectedCommand), names = meta.clients.map(client=>client.name);
  return heading("", "Commands", "Run ROC tools. Jobs queue to prevent conflicting file writes.") + `<div class="card-grid">${meta.commands.map(command=>`<button class="command-card ${command.name===selectedCommand ? "active" : ""}" data-command="${command.name}"><span class="command-icon">${icon(command.name === "client-fetch" || command.name === "pull" ? "download" : command.name === "mass" || command.name === "auto" || command.name === "check" ? "code" : command.name === "doctor" || command.name === "flags" ? "settings" : command.name.includes("stats") ? "chart" : "terminal")}</span><div class="cmd">roc ${command.name}</div><h3>${command.title}</h3><p>${command.description}</p></button>`).join("")}</div><form id="command-form" class="panel panel-pad command-settings"><h2>${command.title}</h2><div class="field-grid form-section">` +
    (command.target !== "none" ? field("Client", "client", meta.initial.client || (command.target==="one" ? names[0] : "all"), {choices:[...(command.target==="one" ? [] : [["all","All clients"]]),...names.map(name=>[name,name])]}) : "") +
    (["repair","check"].includes(command.name) ? field("Function address (optional)", "addr", "", {placeholder:"00401000"}) : "") +
    (command.name==="libs" ? field("Recipes", "recipes", "all", {placeholder:"all or comma-separated recipe names"}) : "") +
    (command.name==="repair" ? field("Source limit", "limit", 20, {type:"number",min:1})+field("Minimum score", "min_score", 80, {type:"number",min:0,max:100})+check("Try permutations", "permute", false) : "") +
    (command.name==="install" ? check("Accept compiler downloads", "accept_downloads", false) : "") + `</div><div id="command-preview" class="command-preview">roc ${command.name}</div><div class="form-footer"><span class="tiny muted">${command.name==="mass" ? "Static libs → STL → recipes → analyze → auto" : "Output appears in the console below."}</span>${button("Run command",'type="submit"')}</div></form>`;
}
function clientPage() {
  return heading("", "Clients", "Registered builds, local binaries, and analysis status.", button("Run doctor", 'data-open-command="doctor"', true)) + `<div class="panel">${meta.clients.map(client=>`<div class="client-row"><div><h3>Roblox ${esc(client.name)}</h3><p>${esc(client.compiler)}</p><div class="client-details"><span class="badge ${client.downloaded ? "completed" : "queued"}">${client.downloaded ? "Binary present" : "Download needed"}</span><span class="badge ${client.analyzed ? "completed" : "queued"}">${client.analyzed ? "Analyzed" : "Analysis needed"}</span></div></div><div class="button-row">${button(client.downloaded ? "Analyze" : "Fetch",`data-client-task="${client.downloaded ? "analyze" : "client-fetch"}" data-client="${esc(client.name)}"`,true)}${button("Work on client",`data-client-worker="${esc(client.name)}"`,true)}</div></div>`).join("")}</div><p class="help-note">“Binary present” means file exists. Use Doctor for full readiness checks. Install tools from Commands if a compiler is missing.</p>`;
}
function settings() {
  return heading("", "Settings", "Interface, theme, provider credentials, and dashboard lifecycle.") + `<div class="settings-stack"><form id="preferences-form" class="panel panel-pad"><h2>When a roconstruct:// link opens</h2><p class="help-note">Choose how website work links launch. “Ask every time” offers terminal or webpage before setup.</p><div class="field-grid">${field("URI interface", "uri_mode", meta.uri_mode, {choices:[["ask","Ask every time"],["terminal","Terminal"],["web","Webpage"]]})}${field("Appearance", "theme", meta.preferences.theme, {choices:["dark","light"]})}</div><div class="form-footer">${button("Save preferences", 'type="submit"')}</div></form><form id="provider-form" class="panel panel-pad"><h2>Provider credentials</h2><p class="help-note">Stored in ROC's user-local secrets file. Keys never enter run history or frontend storage.</p><div class="field-grid">${field("Provider", "provider", "", {choices:meta.providers.map(provider=>[provider.name,provider.name+(provider.ready ? " · ready" : " · key missing")])})}${field("API key", "key", "", {type:"password"})}</div><div class="form-footer">${button("Save key", 'type="submit"')}</div></form><div class="panel panel-pad"><h2>Session & lifecycle</h2><p class="help-note">Browser tabs may close freely. Dashboard process owns jobs. Exit stops active process trees and cancels queued work. Provider requests already sent may still bill.</p><button class="button secondary" id="exit-dashboard">Exit ROC dashboard</button></div></div>`;
}
function render(config) {
  if (!meta) return;
  document.querySelectorAll(".sidebar [data-page]").forEach(button=>button.classList.toggle("active",button.dataset.page===page));
  $("#page-name").textContent = {overview:"Overview",workers:"Workers",commands:"Commands",clients:"Clients",history:"Run history",functions:"Functions",settings:"Settings"}[page];
  $("#main").innerHTML = page==="overview" ? overview() : page==="workers" ? workers(config) : page==="commands" ? commands() : page==="clients" ? clientPage() : page==="history" ? heading("", "Run history", "Saved configurations, outcomes, and logs. Rerun interrupted sessions explicitly.")+runTable([...jobs].reverse()) : page==="functions" ? functionsPage() : settings();
  document.body.classList.toggle("workers-page",page==="workers");
  if (page==="workers") { $("#worker-status").innerHTML=workerCards();renderWorkerChat(); }
  if (page==="commands") act(previewCommand);
  if (page==="functions") act(loadFunctions);
}
function navigate(next, config) { page=next; if(next!=="workers") editing=null; render(config); $("#main").scrollTop=0; }
function readWorker() {
  const form=$("#worker-form"), config={...(editing ? jobs.find(job=>job.id===editing).config : meta.initial)};
  for(const input of form.querySelectorAll("[name]")) {
    const key=input.name;
    if(input.disabled || key==="addresses") continue;
    config[key]=input.type==="checkbox" ? input.checked : ["workers","rounds","max_tokens","cloud_concurrency"].includes(key) && input.value==="auto" ? "auto" : numeric.has(key) ? (input.value==="" && nullable.has(key) ? null : Number(input.value)) : (input.value==="" && nullable.has(key) ? null : input.value);
  }
  if(!editing) { const addresses=form.elements.addresses.value.split(/[,\s]+/).filter(Boolean).map(value=>value.toLowerCase().replace(/^0x/,"")); config.targets=addresses.length ? addresses.map(addr=>({client:config.client,addr})) : null; }
  return config;
}
function readCommand() { const form=$("#command-form"), data={command:selectedCommand}; for(const input of form.querySelectorAll("[name]")) data[input.name]=input.type==="checkbox" ? input.checked : input.type==="number" ? Number(input.value) : input.value; return data; }
async function previewCommand() { const data=readCommand(); if(data.command==="install"&&!data.accept_downloads) { $("#command-preview").textContent="roc install --yes"+(data.client&&data.client!=="all" ? " --client "+data.client : "")+"  (download consent required)"; return; } const result=await api("preview",data); if($("#command-preview")) $("#command-preview").textContent="roc "+result.args.join(" "); }
function logText(row) {
  if(row.message!==undefined) return row.message;
  if(row.event==="job_started") return `${row.client}:${row.addr} · ${row.unit || "function"} · ${row.size ?? "?"} B · baseline ${row.previous ?? 0}% → started`;
  if(row.event==="job_finished") return `${row.client}:${row.addr} → ${row.score}%${row.score===100 ? " EXACT MATCH" : ""} (previous ${row.previous}%)`;
  if(row.event==="applied") return `Configuration v${row.revision} applied before next lease`;
  if(row.event==="control") return `${row.stopping ? "Stopping after active functions" : row.paused ? "Paused; active functions continue" : "Configuration acknowledged"} · v${row.revision}`;
  if(row.event==="usage") return `${row.requests} cloud requests · ${row.tokens} reserved/settled tokens`;
  if(row.event==="slot_stopped") return "Worker loop retired";
  return row.event;
}
function filteredLogs() {
  const job=$("#log-job").value, level=$("#log-level").value, query=$("#log-search").value.toLowerCase();
  return logs.filter(row=>(!job || row.job===job)&&(!query || logText(row).toLowerCase().includes(query))&&(!level || (level==="error" ? ["error","rejected"].includes(row.event)||/error:|failed|traceback/i.test(logText(row)) : level==="match" ? row.event==="job_finished"&&row.score===100 : level==="control" ? ["control","applied","rejected"].includes(row.event) : row.event===level)));
}
function renderLogs() {
  const selected=$("#log-job").value, current=selected ? jobs.find(job=>job.id===selected&&active(job)) : jobs.find(active);
  const control=$("#console-end-run"),controlHTML=current ? endRun(current) : "";
  if(control.innerHTML!==controlHTML)control.innerHTML=controlHTML;
  const rows=filteredLogs().slice(-120),scroll=$("#log-scroll"),signature=rows.map(r=>r.job+":"+r.seq).join();
  if(scroll.dataset.signature!==signature) {const functions=new Map();updateFeed($("#log-rows"),rows.map(row=>{if(row.event==="job_started")functions.set(row.job+":"+row.slot,row);return [row.job+":"+row.seq,terminalMessage(row,functions,true)];}),false,false);if(follow)scrollToLatest(scroll);scroll.dataset.signature=signature;}
  $("#console-count").textContent=filteredLogs().length+" events";
}
async function poll() {
  let more=false;
  try {
    const state=await api("state?after="+cursor+"&wait=1");
    if(!online) { online=true; $("#connection").classList.remove("offline"); $("#connection").innerHTML='<span class="dot"></span>Local · connected'; }
    const previous = new Map(jobs.map(job=>[job.id,job.status]));
    jobs=state.jobs;
    if(jobs.some(job=>job.status==="completed"&&previous.get(job.id)!=="completed"&&["client-fetch","analyze","install"].includes(job.args?.[0]))) {
      meta=await api("meta");
      if(page==="clients")render();
    }
    if(state.events.length) { if(cursor && state.events[0].seq>cursor+1) $("#console-hint").textContent="Older events omitted from live view. Export run logs for retained output."; logs.push(...state.events); logs=logs.slice(-3000); }
    cursor=state.sequence;more=state.more;
    const selected=$("#log-job").value, signature=jobs.map(job=>job.id).join();
    if($("#log-job").dataset.signature!==signature) { $("#log-job").innerHTML='<option value="">All runs</option>'+jobs.map(job=>`<option value="${job.id}">${esc(job.title)} · ${job.id.slice(0,5)}</option>`).join("");$("#log-job").value=selected;$("#log-job").dataset.signature=signature; }
    $("#worker-count").textContent=jobs.filter(job=>job.kind==="worker"&&active(job)).length;
    if(page==="overview"||page==="history") render();
    else if(page==="workers") { if(editing&&!jobs.some(job=>job.id===editing&&active(job))) { editing=null;render(); }  }
    renderWorkerChat();
    renderLogs();
  } catch(error) { online=false;$("#connection").classList.add("offline");$("#connection").innerHTML='<span class="dot"></span>Disconnected';$("#console-hint").textContent=error.message+". Reconnecting…"; }
  setTimeout(poll,online ? 0 : 2000);
}
document.addEventListener("click", event=>act(async()=>{
  if(event.target.closest(".brand")) { event.preventDefault();navigate("overview");return; }
  const target=event.target.closest("button,[data-log]");if(!target)return;
  if(target.dataset.removeRun) {
    const id=target.dataset.removeRun;
    await api("control",{id,action:"remove"});
    jobs=jobs.filter(job=>job.id!==id);logs=logs.filter(row=>row.job!==id);
    if(workerRun===id)workerRun="";
    $("#worker-run").querySelector(`option[value="${id}"]`)?.remove();
    $("#worker-run").value=workerRun;
    chatSignature="";renderWorkerChat();renderLogs();return;
  }
  if(target.dataset.workerTab) {await selectWorker(target.dataset.workerTab==="all" ? "" : target.dataset.workerTab);return;}
  if(target.id==="chat-compact") {chatCompact=!chatCompact;target.textContent=chatCompact ? "Regular" : "Compact";renderWorkerChat();}
  if(target.dataset.page) navigate(target.dataset.page);
  if(target.dataset.function) { functionDetail=await api("functions?id="+target.dataset.function); detailTab="source";renderFunctionDetail(); }
  if(target.dataset.detailTab) { detailTab=target.dataset.detailTab;renderFunctionDetail(); }
  if(target.hasAttribute("data-new-worker") || target.hasAttribute("data-new-session")) { editing=null;controlsOpen=true;navigate("workers"); }
  if(target.hasAttribute("data-configure")) {editing=jobs.find(j=>j.kind==="worker"&&active(j)&&(!workerRun||j.id===workerRun))?.id || null;controlsOpen=true;render();}
  if(target.hasAttribute("data-close-controls")) {controlsOpen=false;$(".worker-drawer").classList.remove("open");}
  if(target.hasAttribute("data-copy-code")) {await navigator.clipboard.writeText(target.closest(".chat-code").querySelector("code").textContent);toast("Code copied");}
  if(target.id==="chat-follow"||target.id==="jump-live") {setChatFollow(true);chatSignature="";renderWorkerChat();scrollToLatest($("#worker-chat"),true);}
  if(target.dataset.openCommand) { selectedCommand=target.dataset.openCommand;navigate("commands"); }
  if(target.dataset.command) { selectedCommand=target.dataset.command;render(); }
  if(target.dataset.clientTask) { const result=await api("start",{kind:"command",command:target.dataset.clientTask,client:target.dataset.client});$("#console-hint").textContent="Queued "+result.id;toast("Task queued"); }
  if(target.dataset.clientWorker) { editing=null;navigate("workers",{...meta.initial,client:target.dataset.clientWorker}); }
  if(target.dataset.log) { $("#log-job").value=target.dataset.log;renderLogs(); }
  if(target.dataset.step) { const input=$("#worker-form").elements[target.dataset.field];input.value=Math.max(Number(input.min||1),Math.min(Number(input.max||1000000),Number(input.value)+Number(target.dataset.step))); }
  if(target.dataset.preset) { const config=readWorker(),presets={automatic,fast:{rounds:2,max_size:96,max_tokens:1024,use_revng:false},balanced:{rounds:4,max_size:256,max_tokens:2048},deep:{rounds:6,max_size:512,max_tokens:4096}};render({...config,...presets[target.dataset.preset]});document.querySelectorAll("[data-preset]").forEach(button=>button.classList.toggle("active",button.dataset.preset===target.dataset.preset)); }
  if(target.dataset.action) {
    const action=target.dataset.action,id=target.dataset.id;
    if(action==="edit") { controlsOpen=true;editing=id;navigate("workers");return; }
    if(action==="kill") { $("#confirm-dialog").dataset.id=id;$("#confirm-dialog").showModal();return; }
    await api("control",{id,action});toast(action==="stop" ? "Stopping after active functions" : "Control sent");
  }
  if(target.dataset.rerun) {
    const job=jobs.find(job=>job.id===target.dataset.rerun);
    if(job.kind==="worker") { editing=null;navigate("workers",job.config); }
    else {
      selectedCommand=job.args[0];navigate("commands");
      const fields=$("#command-form").elements, flag=name=>{const index=job.args.indexOf(name);return index>=0 ? job.args[index+1] : undefined;};
      if(fields.client) fields.client.value=flag("--client")||job.args[1]||"all";
      if(fields.addr) fields.addr.value=selectedCommand==="check" ? job.args[2]||"" : flag("--addr")||"";
      for(const key of ["limit","min_score"]) if(fields[key]&&flag("--"+key.replace("_","-")))fields[key].value=flag("--"+key.replace("_","-"));
      if(fields.permute)fields.permute.checked=job.args.includes("--permute");
      if(fields.recipes)fields.recipes.value=job.args.slice(1,job.args.indexOf("--client")).join(", ");
      await previewCommand();
    }
  }
  if(target.id==="confirm-cancel") $("#confirm-dialog").close();
  if(target.id==="confirm-stop") { await api("control",{id:$("#confirm-dialog").dataset.id,action:"kill"});$("#confirm-dialog").close(); }
  if(target.id==="refresh-models") { const config=readWorker();toast("Checking installed models…");localModels=(await api("models")).models;meta=await api("meta");render(config);toast("Models refreshed"); }
  if(target.id==="save-preset") { const name=prompt("Preset name");if(name) { const config=readWorker();await api("preferences",{preset:name,config});meta=await api("meta");render(config);toast("Preset saved"); } }
  if(target.id==="theme-button") { const theme=document.documentElement.dataset.theme==="light" ? "dark" : "light";document.documentElement.dataset.theme=theme;await api("preferences",{theme});meta.preferences.theme=theme; }
  if(target.id==="exit-dashboard"&&confirm("Exit ROC and stop all running and queued jobs? Cloud requests already sent may still bill.")) { await api("shutdown",{});toast("Dashboard stopped. You can close this tab."); }
}));
document.addEventListener("submit",event=>{
  event.preventDefault();act(async()=>{
    if(event.target.id==="worker-form") { const config=readWorker();if(editing) await api("control",{id:editing,action:"update",config:Object.fromEntries(Object.entries(config).filter(([key])=>liveKeys.has(key)))});else { const result=await api("start",{kind:"worker",config});toast("Worker queued");$("#console-hint").textContent="Worker session "+result.id; } }
    if(event.target.id==="worker-form") {controlsOpen=false;$(".worker-drawer")?.classList.remove("open");}
    if(event.target.id==="command-form") { const result=await api("start",{kind:"command",...readCommand()});toast("Command queued");$("#console-hint").textContent="Command run "+result.id; }
    if(event.target.id==="preferences-form") { const data=Object.fromEntries(new FormData(event.target));await api("preferences",data);meta=await api("meta");document.documentElement.dataset.theme=data.theme;toast("Preferences saved"); }
    if(event.target.id==="provider-form") { await api("provider",Object.fromEntries(new FormData(event.target)));event.target.elements.key.value="";meta=await api("meta");render();toast("Key saved locally"); }
  });
});
document.addEventListener("change",event=>act(async()=>{
  if(event.target.id==="worker-loop") {workerLoop=event.target.value;chatSignature="";renderWorkerChat();}
  if(event.target.id==="worker-run") await selectWorker(event.target.value);
  if(event.target.id==="saved-presets"&&event.target.value) render(meta.preferences.presets[event.target.value]);
  if(event.target.closest("#command-form")) await previewCommand();
}));
for(const id of ["log-job","log-level","log-search","log-wrap"]) $("#"+id).addEventListener("input",()=>{renderLogs();});
$("#follow-console").addEventListener("click",()=>{follow=!follow;$("#follow-console").textContent=follow ? "↓ Following" : "↓ Follow";$("#follow-console").classList.toggle("selected",follow);renderLogs();});

$("#clear-console").addEventListener("click",()=>{logs=[];renderLogs();});
$("#collapse-console").addEventListener("click",()=>{$(".console").classList.toggle("collapsed");renderLogs();});
$("#export-console").addEventListener("click",()=>act(async()=>{
  const id=$("#log-job").value;let text;
  if(id) { const response=await fetch("/api/log?id="+id,{headers:{"X-ROC-Token":token}});if(!response.ok)throw Error("Could not export log");text=await response.text(); } else text=filteredLogs().map(row=>JSON.stringify(row)).join("\n");
  const url=URL.createObjectURL(new Blob([text],{type:"text/plain"}));const link=document.createElement("a");link.href=url;link.download="roc-"+(id||"console")+".jsonl";link.click();setTimeout(()=>URL.revokeObjectURL(url),1000);
}));
new ResizeObserver(()=>renderLogs()).observe($("#log-scroll"));
act(async()=>{meta=await api("meta");document.documentElement.dataset.theme=meta.preferences.theme;render();poll();});

let functionRows=[], functionDetail=null, detailTab="source";
function functionsPage() {
  return heading("", "Functions", "Function attempts, source changes, compiler commands, and round results.", button("Refresh", 'id="refresh-functions"', true)) + `<div class="function-tools"><input id="function-search" placeholder="Search function, address, client…" aria-label="Search functions"><select id="function-status" aria-label="Filter status"><option value="">All results</option>${["working","matched","improved","unchanged","failed"].map(v=>`<option>${v}</option>`).join("")}</select><select id="function-sort" aria-label="Sort functions"><option value="recent">Latest first</option><option value="score">Highest score</option><option value="gain">Largest gain</option><option value="unit">Function name</option><option value="addr">Address</option></select></div><div class="panel" id="function-list"></div><div id="function-detail"></div><p class="help-note">Latest 300 attempts. History starts with this worker version. Source shows best locally verified candidate; final status reports worker outcome. Compiler paths describe temporary files used during execution.</p>`;
}
async function loadFunctions() { functionRows=await api("functions"); if(page!=="functions")return;renderFunctionList();renderFunctionDetail(); }
function renderFunctionList() {
  const query=$("#function-search").value.toLowerCase(), status=$("#function-status").value, sort=$("#function-sort").value;
  const rows=functionRows.filter(r=>(!status||r.status===status)&&`${r.unit} ${r.client} ${r.addr}`.toLowerCase().includes(query)).sort((a,b)=>sort==="score" ? b.score-a.score : sort==="gain" ? (b.score-b.base_score)-(a.score-a.base_score) : ["unit","addr"].includes(sort) ? String(a[sort]).localeCompare(String(b[sort])) : b.started-a.started);
  $("#function-list").innerHTML=rows.length ? `<div class="function-table"><table class="run-list"><thead><tr><th>FUNCTION</th><th>RESULT</th><th>SCORE</th><th>MODEL</th><th>TIME</th></tr></thead><tbody>${rows.map(r=>`<tr><td><button class="text-button function-name" data-function="${r.id}">${esc(r.unit || r.addr)}</button><small>${esc(r.client)} · ${esc(r.addr)}</small></td><td>${badge(r.status)}</td><td>${r.base_score}% → <b>${r.score}%</b></td><td>${esc(r.model)}</td><td>${r.ended ? Math.round(r.ended-r.started)+"s" : "Active"}</td></tr>`).join("")}</tbody></table></div>` : empty("No function attempts", "Start a worker to record function activity.");
}
function renderFunctionDetail() {
  if(!functionDetail || !$("#function-detail"))return;
  const r=functionDetail;
  let body;
  if(detailTab==="source")body=`<p class="help-note">${r.before ? "Original leased source" : "No source supplied with lease"} → best verified candidate</p><div class="source-pair"><div><h3>Before · ${r.base_score}%</h3><pre>${esc(r.before || "// No source supplied")}</pre></div><div><h3>Best candidate · ${r.best_score ?? r.score}%</h3><pre>${esc(r.after || "// No verified source")}</pre></div></div>`;
  else if(detailTab==="timeline")body=`<ol class="function-timeline">${r.timeline.map(e=>`<li><time>${e.seconds}s</time><span>${esc(e.message)}</span></li>`).join("")}</ol>`;
  else if(detailTab==="commands")body=r.commands.length ? r.commands.map(c=>`<div class="command-record"><div>${badge(c.exit_code===0 ? "completed" : "failed")} <span class="muted">${esc(c.cwd)}</span></div><pre>${esc(c.argv.map(v=>/\s/.test(v) ? JSON.stringify(v) : v).join(" "))}</pre>${c.output ? `<details><summary>Compiler output</summary><pre>${esc(c.output)}</pre></details>` : ""}</div>`).join("") : empty("No compiler commands", "Cached results and skipped compilation do not execute commands.");
  else body=(r.rounds||[]).map((round,i)=>`<details class="round-record"><summary>Attempt ${i+1} · ${esc(round.score ?? round.kind ?? "Details")}</summary><pre>${esc(JSON.stringify(round,null,2))}</pre></details>`).join("") || empty("No generation rounds", "Deterministic paths may finish without generation.");
  $("#function-detail").innerHTML=`<section class="panel panel-pad function-detail"><div class="section-heading"><div><h2>${esc(r.unit || r.addr)}</h2><p class="muted">${esc(r.client)} · ${esc(r.addr)} · ${esc(r.model)}</p></div>${badge(r.status)}</div><div class="detail-tabs">${["source","timeline","commands","attempts"].map(t=>`<button class="text-button ${t===detailTab ? "selected" : ""}" data-detail-tab="${t}">${t[0].toUpperCase()+t.slice(1)}</button>`).join("")}</div>${r.failure ? `<p class="failure-note">${esc(r.failure)}</p>` : ""}${body}</section>`;
}
document.addEventListener("input", event=>{if(event.target.id.startsWith("function-"))renderFunctionList();});
document.addEventListener("click",event=>{if(event.target.closest("#refresh-functions"))act(loadFunctions);});

setInterval(()=>{if(page==="functions")act(loadFunctions);},5000);

function pauseFollow(event) {
  const node=event.target.closest("#worker-chat,#log-scroll");if(!node)return;
  if(event.type==="wheel" && event.deltaY>=0)return;
  if(event.type==="keydown" && !["ArrowUp","PageUp","Home"].includes(event.key))return;
  if(event.type==="pointerdown" && event.target!==node)return;
  delete node.dataset.liveScrolling;
  if(node.id==="worker-chat")setChatFollow(false);
  else {follow=false;$("#follow-console").textContent="↓ Follow";$("#follow-console").classList.remove("selected");}
}
for(const type of ["wheel","touchstart","keydown","pointerdown"])document.addEventListener(type,pauseFollow,{passive:true});
document.addEventListener("scroll",event=>{
  const node=event.target;if(node.id!=="worker-chat"&&node.id!=="log-scroll")return;
  const previous=Number(node.dataset.scrollTop ?? node.scrollTop),bottom=node.scrollHeight-node.clientHeight-node.scrollTop;
  if(node.id==="worker-chat") {
    if(!node.dataset.liveScrolling && node.scrollTop<previous-2 && bottom>40)setChatFollow(false);
    else if(bottom<12)setChatFollow(true);
  }
  node.dataset.scrollTop=node.scrollTop;
},true);
const feedResize=new ResizeObserver(()=>{const node=$("#worker-chat");if(node&&chatFollow)scrollToLatest(node,true);});
const observeFeed=new MutationObserver(()=>{const rows=$("#worker-chat-rows");if(rows&&rows!==observeFeed.rows){feedResize.disconnect();feedResize.observe(rows);feedResize.observe(rows.parentElement);observeFeed.rows=rows;}});
observeFeed.observe($("#main"),{childList:true});

async function selectWorker(id) {
  workerRun=id;chatSignature="";$("#worker-run").value=id;renderWorkerChat();
  if(!id)return;
  try {await loadSessionLog(id);}
  catch(error) {toast(error.message+". Showing retained output.");}
  if(page==="workers" && workerRun===id) {chatSignature="";renderWorkerChat();}
}
async function loadSessionLog(id) {
  let response;
  try {response=await fetch("/api/log?id="+encodeURIComponent(id),{headers:{"X-ROC-Token":token},signal:AbortSignal.timeout(10000)});}
  catch(error) {throw new Error(error.name==="TimeoutError" ? "Session history request timed out" : "Dashboard disconnected — reopen ROC GUI");}
  if(!response.ok)throw new Error(response.status===403 ? "Dashboard session expired — reopen ROC GUI" : "Session history unavailable");
  const rows=(await response.text()).split("\n").filter(Boolean).map(line=>JSON.parse(line));
  const keys=new Set(logs.map(r=>r.job+":"+r.seq));
  logs.push(...rows.filter(r=>!keys.has(r.job+":"+r.seq)));
  logs.sort((a,b)=>a.time-b.time);logs=logs.slice(-3000);
}
