# price-monitor

Projeto da faculdade: **Monitoramento do preço da cesta básica usando pseudocódigo**, da disciplina Algoritmos e Pensamento Computacional — Experiência Prática I.

O algoritmo recebe o nome, o preço anterior e o preço atual de três produtos, calcula a variação percentual e classifica cada resultado como `AUMENTO`, `QUEDA` ou `ESTÁVEL`.

## Material da atividade

- [Pseudocódigo completo](docs/atividade/pseudocodigo.txt): versão consolidada dos blocos de entrada, cálculo, decisão e saída, com tratamento de preços inválidos.
- [Fluxograma e exemplos](docs/atividade/fluxograma-classificacao.png): representação da lógica com exemplos sintéticos de alta de 10%, queda de 10% e estabilidade. Anexo preparado para as atividades de classificação e exibição dos resultados.

A fórmula é `((preço atual - preço anterior) / preço anterior) × 100`. O preço anterior deve ser maior que zero e o preço atual não pode ser negativo. Quando esses requisitos não são atendidos, o percentual não é calculado nem exibido como zero.

O material usa pseudocódigo didático; não foi executado em um interpretador específico. Os exemplos numéricos do fluxograma foram calculados e conferidos separadamente. Uma alta de preço, por si só, não comprova abuso.

## Fonte

[Enunciado no DreamShaper](https://cds-expp-algoritmo-pensamento-comp-exp1-oferta2-262.dreamshaper.com/modules/inicio-da-experiencia-pratica-7s5a/apresentacao-do-desafio-ygem).

Reflexão pessoal e autoavaliação devem refletir a experiência do aluno.
