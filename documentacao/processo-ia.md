# Diário de Desenvolvimento com Inteligência Artificial

**Projeto:** TicketQueue — Sistema de Fila Virtual para Ingressos  
**Disciplina:** Algoritmos e Estruturas de Dados  
**Instituição:** Senac  
**Data do registro:** 11/11/2026

---

## Etapa 1 — Desenvolvimento inicial em C

**Objetivo:** Desenvolver um sistema de fila virtual utilizando a estrutura de dados FIFO.

**Desenvolvimento:**

A primeira versão do TicketQueue foi construída em linguagem C, utilizando uma fila circular implementada com vetor.

A estrutura possuía:
- Capacidade máxima de 20 participantes.
- Índices `inicio` e `fim`.
- Variável `quantidade`.
- Operações de inserção e remoção.
- Controle de 10 ingressos disponíveis.

**Testes realizados:** Foram cadastrados Ana, Raissa e Bia. O sistema chamou Ana primeiro e, após a confirmação da compra, o estoque passou de 10 para 9 ingressos.

**Resultado:** A implementação inicial demonstrou o funcionamento da estrutura FIFO.

## Etapa 2 — Migração para uma aplicação Web

**Objetivo:** Criar uma interface mais visual e interativa.

Foi decidido migrar a aplicação para HTML, CSS e JavaScript, preservando a lógica da fila circular originalmente desenvolvida em C.

Durante as primeiras tentativas, ocorreram problemas no cadastro dos participantes. O formulário recarregava a página e os nomes não apareciam na fila.

Foram discutidas possíveis causas relacionadas ao carregamento do JavaScript e à utilização de módulos.

**Decisão:** Abandonar a versão Web anterior e criar uma nova pasta de trabalho, com códigos reescritos do zero.

## Etapa 3 — Reconstrução do TicketQueue

**Data:** 11/11/2026

**Prompt:** "vamos criar outra pasta de trabalho do zero, esquece essas"

**Desenvolvimento:**

Foi criada uma nova estrutura de projeto denominada `TicketQueue-Projeto-Final`.

A nova implementação utiliza:
- `index.html` — estrutura da interface.
- `style.css` — apresentação visual.
- `script.js` — lógica da fila circular e controle de ingressos.
- `documentacao/` — registro do processo de desenvolvimento.

O JavaScript foi organizado sem módulos externos, permitindo executar a aplicação diretamente no navegador.

**Resultado:** Código completo fornecido pela IA para aplicação no VS Code.

## Etapa 4 — Implementação da fila circular em JavaScript

**Data:** 11/11/2026

**Prompt:** "ok, agr me mande todos os codigos"

**Desenvolvimento:**

A lógica de C foi adaptada para JavaScript, preservando as operações:

- `inicializar_fila()`
- `fila_vazia()`
- `fila_cheia()`
- `enfileirar()`
- `desenfileirar()`
- `mostrar_fila()`

O sistema também permite chamar o próximo participante e confirmar a compra, atualizando o estoque.

**Resultado:** Implementação fornecida, com estrutura FIFO e capacidade de 20 participantes.

## Etapa 5 — Personalização para o show do Travis Scott

**Data:** 11/11/2026

**Prompt:** "chat, está perfeito mas eu quero q seja de um show especifico, quero q seja do show do travis scott, faça todas as alteraçoes necessarias"

**Objetivo:** Personalizar o TicketQueue para simular a venda de ingressos de um show do Travis Scott.

**Alterações propostas:**
- Substituição do Festival Conexão pelo show fictício do Travis Scott.
- Atualização dos textos e informações do evento.
- Nova identidade visual.
- Personalização do ingresso ilustrativo.
- Preservação da lógica FIFO.

**Arquivos alterados:** `index.html` e `style.css`.

**Arquivo preservado:** `script.js`.

**Resultado:** Personalização implementada no código fornecido pela IA.

## Etapa 6 — Correção da aparência visual

**Data:** 11/11/2026

**Problema identificado:** Após a personalização, a página apresentou problemas de formatação, incluindo textos com cores inadequadas, elementos desalinhados e ingresso ocupando uma largura excessiva.

**Diagnóstico da IA:** O CSS anterior havia sido fornecido como complemento, e não como arquivo completo.

**Solução proposta:** Substituir o `style.css` por um código completo, contendo regras de estrutura, tipografia, cores, componentes e responsividade.

**Resultado:** Novo CSS fornecido, aguardando confirmação dos testes visuais.

---

## Etapa 7 — Testes finais

**Status:** Pendente de registro.

Os testes deverão verificar:
- Entrada de participantes.
- Ordem de atendimento FIFO.
- Confirmação de compra.
- Atualização do estoque.
- Fila cheia.
- Fila vazia.
- Esgotamento dos ingressos.
- Comportamento visual em diferentes tamanhos de tela.

Os resultados serão preenchidos após a execução dos testes.

---

## Considerações finais

A inteligência artificial foi utilizada como ferramenta de apoio à programação, à organização dos arquivos, à identificação de problemas e à documentação do desenvolvimento.

A estrutura de dados central do projeto é uma fila circular FIFO, inicialmente implementada em C e posteriormente adaptada para JavaScript.

O TicketQueue é uma simulação acadêmica, sem comercialização real de ingressos ou vínculo oficial com o artista.

---

## Etapa 8 — Versionamento e publicação no GitHub

**Data:** 11/11/2026

**Objetivo:** Utilizar o Git e o GitHub para armazenar o código-fonte, preservar o histórico de alterações e disponibilizar o projeto para avaliação.

**Ferramentas utilizadas:**
- Visual Studio Code
- Terminal PowerShell
- Git
- GitHub

**Procedimento realizado:**

1. Inicialização do repositório local com `git init`.
2. Definição da branch principal com `git branch -M main`.
3. Adição dos arquivos com `git add .`.
4. Criação do commit inicial com `git commit -m "Versao inicial TicketQueue - Travis Scott"`.
5. Conexão ao repositório remoto com `git remote add origin`.
6. Publicação dos arquivos com `git push -u origin main`.

**Repositório:** https://github.com/ann4rodrigues/ticket-queue

**Commit inicial:** `d357fc7`

**Arquivos publicados:**
- `index.html`
- `style.css`
- `script.js`
- `documentacao/processo-ia.md`
- `documentacao/historico-prompt.md`

**Resultado:** O terminal confirmou a publicação na branch `main` e a configuração do acompanhamento da branch remota `origin/main`.

**Conclusão:** O projeto foi armazenado com sucesso no GitHub, permitindo registrar futuras atualizações e acompanhar seu desenvolvimento.

---

## Etapa 9 — Testes funcionais e validação do sistema

**Data:** 11/11/2026

**Objetivo:** Verificar o funcionamento da fila circular FIFO, o controle de estoque e as regras de atendimento do TicketQueue.

### Teste 1 — Cadastro de participantes

**Procedimento:**
Foram cadastrados três participantes, na seguinte ordem:

1. Ana
2. Raissa
3. Bia

**Resultado:** Os participantes foram adicionados corretamente à fila, respeitando a ordem de entrada.

**Status:** Aprovado.

### Teste 2 — Atendimento FIFO

**Procedimento:**
Após o cadastro dos três participantes, foi acionada a opção de chamar o próximo participante.

**Resultado:** Ana foi chamada primeiro, enquanto Raissa e Bia permaneceram aguardando.

**Status:** Aprovado.

### Teste 3 — Confirmação da compra

**Procedimento:**
Foi confirmada a compra do ingresso pela primeira participante atendida.

**Resultado:**
- Estoque inicial: 10 ingressos.
- Estoque após a compra: 9 ingressos.
- Ingressos vendidos: 1.
- Participantes aguardando: 2.

**Status:** Aprovado.

### Teste 4 — Capacidade máxima e reutilização de posições da fila circular

**Procedimento:**

Foram cadastrados 20 participantes, atingindo a capacidade máxima da fila. Em seguida, foi realizada uma tentativa de cadastrar um 21º participante.

Posteriormente, alguns participantes foram chamados para atendimento, liberando posições na estrutura. Novas tentativas de cadastro foram realizadas.

**Resultados observados:**

- O sistema impediu a entrada do 21º participante enquanto a fila estava cheia.
- Após a retirada de participantes da fila, novas entradas foram permitidas.
- As posições liberadas puderam ser reutilizadas.
- A capacidade máxima de 20 participantes foi respeitada.

**Conclusão:**

O teste demonstrou o funcionamento correto da fila circular, que permite reutilizar posições liberadas durante as operações de remoção e inserção.

**Status:** Aprovado.

### Teste 5 — Esgotamento dos ingressos

**Procedimento:**
Foi realizado um cenário de vendas até o esgotamento do estoque inicial de 10 ingressos.

**Resultado observado:**
- O sistema informou que não havia mais ingressos disponíveis.
- A quantidade de ingressos disponíveis chegou a zero.

**Status:** Aviso de esgotamento confirmado. Demais verificações pendentes.

### Considerações sobre a capacidade da fila

O TicketQueue utiliza dois limites independentes:

- **Capacidade da fila:** 20 participantes.
- **Estoque inicial:** 10 ingressos.

Essa diferença permite demonstrar que a capacidade de armazenamento da estrutura de dados não corresponde necessariamente à quantidade de produtos disponíveis.

A estrutura FIFO garante que o atendimento ocorra por ordem de chegada. Já o controle de estoque determina quando as vendas devem ser encerradas.

### Conclusão parcial

Os testes iniciais confirmaram o funcionamento do cadastro, da ordem FIFO e da atualização do estoque após uma compra.

O sistema também apresentou uma mensagem informando o esgotamento dos ingressos.

A validação completa depende da confirmação do comportamento da fila cheia e do bloqueio de novas compras após o esgotamento do estoque.