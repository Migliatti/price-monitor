# Issue tracker: GitHub

Issues e especificações vivem no GitHub Issues de Migliatti/price-monitor.
Use o CLI `gh` dentro deste clone.

## Operações

- Criar: `gh issue create --title "..." --body-file <arquivo>`
- Ler: `gh issue view <numero> --comments`
- Listar: `gh issue list --state open --json number,title,body,labels`
- Comentar: `gh issue comment <numero> --body-file <arquivo>`
- Adicionar label: `gh issue edit <numero> --add-label "..."`
- Remover label: `gh issue edit <numero> --remove-label "..."`
- Fechar: `gh issue close <numero> --comment "..."`

Use arquivos temporários para corpos com múltiplas linhas.
O repositório é inferido pelo remote; fora do clone, use
`--repo Migliatti/price-monitor`.

## Pull requests as a triage surface

**PRs as a request surface: no.**

## Instruções das skills

- "Publish to the issue tracker": criar uma GitHub issue.
- "Fetch the relevant ticket": ler a issue e seus comentários.
- Um número pode identificar issue ou PR: verificar o tipo quando necessário.

## Wayfinding

- O mapa é uma issue com label `wayfinder:map`, contendo notas,
  decisões tomadas e dúvidas em aberto.
- Tickets filhos usam labels `wayfinder:research`, `wayfinder:prototype`,
  `wayfinder:grilling` ou `wayfinder:task`.
- Vincular filhos como sub-issues via `gh api`. Quando indisponível,
  usar uma lista de tarefas no mapa e `Part of #<mapa>` no filho.
- Registrar bloqueios com dependências nativas via `gh api`,
  usando o ID numérico da issue bloqueadora. Quando indisponível,
  usar `Blocked by: #<numero>` no corpo.
- A fronteira contém filhos abertos, sem bloqueadores abertos e
  sem responsável; escolher o primeiro na ordem do mapa.
- Assumir um ticket: `gh issue edit <numero> --add-assignee @me`.
- Resolver: comentar a resposta, fechar o ticket e registrar no mapa
  um resumo da decisão com link.
