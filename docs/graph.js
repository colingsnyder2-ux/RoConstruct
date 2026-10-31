/* Static, partitioned evidence explorer. No backend and no executable data. */
'use strict';
const GraphUI = {
  limit: 150,
  matches(row, query) { return row.join(' ').toLowerCase().includes(query.toLowerCase().replace(/^0x/, '')); },
  visible(node, mining, integration) {
    const states = node.states || {};
    return (!mining || states[mining]) && (!integration || (integration === 'NOT_LINKED' ? !states.LINKED : states[integration]));
  },
  partition(id) { return /^[0-9a-f]{8}$/i.test(id) ? id.slice(0, 5) : 'external'; }
};
if (typeof module !== 'undefined') module.exports = GraphUI;
if (typeof document !== 'undefined') {
  const $ = id => document.getElementById(id);
  let index, client, selected, cy, generation = 0;
  let cache = new Map(), pending = new Map(), displayed = new Map(), pathIds = new Set();
  const status = text => { $('message').textContent = text; };
  const text = (tag, value) => { const el = document.createElement(tag); el.textContent = value; return el; };
  async function json(path) {
    const res = await fetch(path);
    if (!res.ok) throw new Error(`Cannot load ${path}: HTTP ${res.status}`);
    if(path.endsWith('.gz')) return JSON.parse(await new Response(res.body.pipeThrough(new DecompressionStream('gzip'))).text());
    return res.json();
  }
  async function node(id) {
    if (cache.has(id)) return cache.get(id);
    const key = GraphUI.partition(id);
    if (!pending.has(key)) {
      const localCache = cache;
      pending.set(key, json(`graph-data/${client}/${key}.json.gz`).then(rows => {
        for (const [a, n] of Object.entries(rows.nodes)) localCache.set(a, {...n,addr:a,outgoing:[],incoming:[]});
        for (const [source,target,kind,ev,confidence] of rows.edges) {
          const edge={source,target,kind,evidence:index.evidence[ev],confidence};
          if(rows.nodes[source])localCache.get(source).outgoing.push(edge);
          if(rows.nodes[target])localCache.get(target).incoming.push(edge);
        }
      }));
    }
    await pending.get(key);
    return cache.get(id);
  }
  function color(n) {
    const s = n.states || {};
    return s.BLOCKED ? '#ff6666' : s.RUNTIME_VERIFIED ? '#b39cff' : s.LINKED ? '#38c8ff' : s.MINED ? '#3fb950' : s.PARTIAL ? '#d8a63a' : '#65758b';
  }
  function draw() {
    const nodes = [...displayed.values()].filter(n => GraphUI.visible(n, $('mining').value, $('integration').value));
    const ids = new Set(nodes.map(n => n.addr)), edges = new Map();
    for (const n of nodes) for (const e of n.outgoing || []) {
      if (ids.has(e.target)) edges.set(`${e.source}:${e.target}:${e.kind}`, e);
    }
    cy.elements().remove();
    cy.add(nodes.map(n => ({data: {id:n.addr, label:`${n.name.length > 48 ? n.name.slice(0,45)+'…' : n.name}\n${n.addr}`, color:color(n)}, classes:[
      $('unresolved').checked && (n.unknown_virtual?.length || n.external) ? 'unresolved' : '',
      $('critical').checked && (n.incoming || []).some(e => e.kind === 'dependency') ? 'critical' : '',
      pathIds.has(n.addr) ? 'path' : ''
    ].join(' ')})));
    cy.add([...edges].map(([id,e]) => ({data:{id,source:e.source,target:e.target,kind:e.kind}, classes:e.kind})));
    cy.layout({name:'cose', padding:35, randomize:true, animate:false, numIter:500, nodeRepulsion:12000, idealEdgeLength:110, gravity:0.15, nodeDimensionsIncludeLabels:true}).run();
    if (selected && cy.getElementById(selected).length) cy.getElementById(selected).select();
    if(nodes.length){if(cy.zoom()<0.8)cy.zoom(0.8);cy.center(cy.getElementById(selected && ids.has(selected) ? selected : nodes[0].addr));}
    status(`${nodes.length} nodes · ${edges.size} edges · ${displayed.size >= GraphUI.limit ? '150-node limit reached; narrow focus' : 'drag nodes · scroll to zoom'}`);
  }
  async function expand(seeds, direction='outgoing', reset=false, kinds=['call','external','virtual']) {
    const current = generation;
    const nodeLimit = reset ? 50 : GraphUI.limit;
    if (reset || displayed.size >= GraphUI.limit) { displayed.clear(); pathIds.clear(); }
    const seen = new Set(seeds), queue = seeds.map(id => [id,0]);
    while (queue.length && displayed.size < nodeLimit) {
      const [id,d] = queue.shift(), n = await node(id);
      if (current !== generation) return;
      if (!n) continue;
      displayed.set(id,n);
      if (d >= Number($('depth').value)) continue;
      for (const e of n[direction] || []) {
        if(!kinds.includes(e.kind))continue;
        const target = direction === 'incoming' ? e.source : e.target;
        if (!seen.has(target)) { seen.add(target); queue.push([target,d+1]); }
      }
    }
    draw();
  }
  function action(label, callback) {
    const b = text('button',label); b.onclick = () => Promise.resolve(callback()).catch(fail); return b;
  }
  async function select(id) {
    const current = generation;
    selected = id;
    const n = await node(id);
    if(current !== generation)return;
    const panel = $('details'); panel.replaceChildren();
    if (!n) { panel.textContent = 'Unknown function'; return; }
    panel.append(text('h3',n.name));
    const list = document.createElement('dl');
    const states = Object.entries(n.states || {}).filter(([,v])=>v).map(([k])=>k).join(', ') || 'unknown';
    const rows = {Client:client, Address:n.addr, Kind:n.kind || n.node_type || 'unknown', Bytes:n.size ?? 'unknown', Integration:['COMPILED','LINKED','RUNTIME_VERIFIED','BLOCKED'].filter(k=>n.states?.[k]).join(', ') || 'unknown / no recorded integration', Unlocks:index.recommendations.find(r=>r.addr===id)?.unlocks ?? 'unknown / no recorded dependency', Mining:n.score == null ? 'unknown' : `${n.score}% (cached hint)`, States:states,
      Class:n.owning_class || 'unknown', Callers:n.unresolved_inventory ? 'unknown' : (n.incoming || []).filter(e=>e.kind==='call').length,
      Callees:n.unresolved_inventory ? 'unknown' : (n.outgoing || []).filter(e=>e.kind==='call').length,
      'Blocked by':(n.outgoing || []).filter(e=>e.kind==='dependency').map(e=>e.target).join(', ') || (n.blockers || []).join(', ') || 'unknown / no recorded blocker',
      'Virtual slots':n.unknown_virtual?.length ? `${n.unknown_virtual.length} unresolved; targets unknown` : 'none recorded',
      Native:n.native_source?.path || n.native_paths?.join(', ') || 'unknown', Library:n.library_source || 'unknown', 'Name evidence':n.name_confidence || 'unknown'};
    for (const [k,v] of Object.entries(rows)) list.append(text('dt',k),text('dd',String(v)));
    panel.append(list);
    const actions = document.createElement('div'); actions.className='actions';
    for (const [label,path] of [['View source',n.source]]) if(path) {
      const a = text('a',label); a.href=`https://github.com/colingsnyder2-ux/${path.startsWith('src/') ? 'RoConstruct-findings' : 'RoConstruct'}/blob/main/${path.split('/').map(encodeURIComponent).join('/')}`; a.target='_blank'; a.rel='noopener'; actions.append(a);
    }
    if(n.native_source?.path){const a=text('a','Verified native source');a.href=`https://github.com/colingsnyder2-ux/RoConstruct-findings/blob/main/${n.native_source.path.split('/').map(encodeURIComponent).join('/')}#L${n.native_source.line || 1}`;a.target='_blank';a.rel='noopener';actions.append(a);}
    actions.append(action('Show callers',()=>expand([id],'incoming')),action('Show callees',()=>expand([id])),action('Show dependencies',()=>expand([id],'outgoing',false,['dependency','ownership'])),action('Show class',()=>expand([id],'outgoing',false,['class'])),action('Milestone path',()=>milestonePath(id)));
    panel.append(actions);
    const evidence = document.createElement('details'); evidence.append(text('summary','Evidence & ownership'),text('pre',JSON.stringify({evidence:n.evidence,ownership:n.ownership,edges:n.outgoing},null,2))); panel.append(evidence);
    cy.elements().unselect(); cy.getElementById(id).select();
  }
  async function milestonePath(target) {
    const current = generation, queue = (index.milestones.p2 || []).map(id=>[id]), seen = new Set(queue.flat());
    // Bounded BFS from milestone roots toward selected dependency/callee.
    let examined = 0;
    while(queue.length && examined++ < 1500) {
      const path=queue.shift(), id=path[path.length-1];
      const n=await node(id); if(current!==generation)return;
      if(id===target){displayed.clear(); for(const a of path)displayed.set(a,await node(a));pathIds=new Set(path);draw();status('P2 path: '+path.join(' → '));return;}
      if(path.length>6)continue;
      for(const e of n?.outgoing || [])if(['call','dependency','virtual'].includes(e.kind)&&!seen.has(e.target)){seen.add(e.target);queue.push([...path,e.target]);}
    }
    status('No path found within 6 edges / 1500 examined nodes. Unknown dispatch may hide connections.');
  }
  function search() {
    if(!index)return;
    const query=$('search').value.trim(), results=$('results');results.replaceChildren();if(!query)return;
    const hits=index.search.filter(row=>GraphUI.matches(row,query)).slice(0,30);
    for(const row of hits)results.append(action(`${row[0]} · ${row[1]}`,async()=>{results.replaceChildren();await expand([row[0]],'outgoing',true);await select(row[0]);}));
    if(!hits.length)results.append(text('span','No indexed match.'));
  }
  function fail(error) { status(error.message); }
  async function load() {
    const current = ++generation; index=null; $('search').disabled=true; $('p2').disabled=true; client=$('client').value;cache=new Map();pending=new Map();displayed=new Map();selected=null;
    const loaded=await json(`graph-data/${client}/index.json.gz`);
    if(current!==generation)return;
    index=loaded; $('search').disabled=false; $('p2').disabled=!loaded.milestones.p2?.length; search();
    $('queue').replaceChildren();$('details').textContent='Select a function.';
    for(const rec of index.recommendations){const row=document.createElement('div');row.className='recommendation';row.append(action(`${rec.addr} · ${rec.name}`,async()=>{await expand([rec.addr],'outgoing',true);await select(rec.addr);}),text('small',`${rec.score} · ${rec.action} · unlocks ${rec.unlocks} · module scope ${rec.module_affected_functions || 0} fns`));row.title=JSON.stringify(rec.reasons);$('queue').append(row);}
    const seeds=index.milestones.p2 || index.recommendations.slice(0,1).map(r=>r.addr);
    await expand(seeds,'outgoing',true);if(seeds[0])await select(seeds[0]);
  }
  async function init() {
    if(typeof cytoscape==='undefined')throw new Error('Graph library unavailable. Check vendor/cytoscape.min.js.');
    cy=cytoscape({container:$('canvas'),elements:[],style:[
      {selector:'node',style:{'background-color':'data(color)',label:'data(label)',color:'#dce8fa','font-size':12,'text-wrap':'wrap','text-valign':'bottom','text-margin-y':7,width:25,height:25,'text-background-color':'#0a0e15','text-background-opacity':0.8}},
      {selector:'edge',style:{width:1.3,'line-color':'#45648e','target-arrow-color':'#45648e','target-arrow-shape':'triangle','curve-style':'bezier'}},
      {selector:'.dependency',style:{'line-style':'dashed','line-color':'#ff6666','target-arrow-color':'#ff6666'}},
      {selector:'.external',style:{'line-style':'dotted'}},
      {selector:'.unresolved',style:{'border-width':4,'border-color':'#d8a63a'}},
      {selector:'.critical',style:{'border-width':5,'border-color':'#ff6666'}},
      {selector:'.path',style:{'border-width':5,'border-color':'#fff'}},
      {selector:':selected',style:{'border-width':4,'border-color':'#fff','font-size':16,'font-weight':'bold','text-background-opacity':1}}
    ]});
    cy.on('tap','node',event=>select(event.target.id()).catch(fail));
    const clients=await json('graph-data/clients.json');for(const c of clients)$('client').append(new Option(c,c));
    $('client').onchange=()=>load().catch(fail);$('search').oninput=search;
    for(const id of ['mining','integration','unresolved','critical'])$(id).onchange=draw;
    $('fit').onclick=()=>cy.fit(undefined,35);$('p2').onclick=()=>expand(index.milestones.p2 || [],'outgoing',true).catch(fail);
    await load();
  }
  init().catch(fail);
}
