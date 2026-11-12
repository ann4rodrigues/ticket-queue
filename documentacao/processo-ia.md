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