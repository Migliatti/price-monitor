# Domain docs

## Layout

Este repositório usa single-context:

- `CONTEXT.md` na raiz: termos e conceitos do domínio.
- `docs/adr/`: decisões arquiteturais.

## Antes de explorar o código

Ler `CONTEXT.md` e os ADRs relevantes à área de trabalho.

Se esses arquivos não existirem, prosseguir silenciosamente.
Não sugerir sua criação antecipada: a skill domain-modeling os cria
quando termos ou decisões forem efetivamente definidos.

## Vocabulário

Usar os termos definidos em `CONTEXT.md` em issues, propostas,
hipóteses e testes. Evitar sinônimos que o glossário rejeite.

Se faltar um conceito, reconsiderar o termo ou registrar a lacuna
para domain-modeling.

## Conflitos com decisões

Se uma proposta contrariar um ADR, indicar explicitamente qual
decisão está sendo reaberta e explicar o motivo.
