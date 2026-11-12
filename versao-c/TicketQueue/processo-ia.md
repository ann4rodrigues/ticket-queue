
# Registro de desenvolvimento com IA — TicketQueue

## Informações do projeto

**Disciplina:** Algoritmos — SENAC  
**Projeto:** TicketQueue — Fila Virtual para Venda de Ingressos Online  
**Linguagem:** C  
**Estrutura de dados:** Fila encadeada (FIFO)  
**Ambiente:** Visual Studio Code, MSYS2 UCRT64 e GCC

---

## Etapa 1 — Planejamento do projeto

**Data:** 10/11/2026

**Objetivo:** Definir o problema e a estrutura de dados.

**Prompt utilizado:** Solicitação de planejamento do EP conforme o documento do professor, utilizando o tema de fila virtual para venda de ingressos.

**Resposta recebida:** Proposta de um sistema que organiza clientes por ordem de chegada, utilizando uma fila FIFO.

**Decisões:** Escolha de uma implementação em linguagem C, com menu interativo no terminal e fila encadeada.

**Resultado:** Definição das funcionalidades, operações da fila, casos extremos e etapas de desenvolvimento.

---

## Etapa 2 — Implementação inicial

**Data:** 10/11/2026

**Objetivo:** Desenvolver a primeira versão do TicketQueue.

**Prompt utilizado:** Solicitação de implementação da primeira etapa, com explicação do código e registro no processo-ia.md.

**Resposta recebida:** Proposta de implementação das funções de inserção, remoção, exibição e verificação da fila.

**Arquivos do projeto:** main.c, fila.c, fila.h e arquivos auxiliares.

**Resultado:** Primeira versão do código disponibilizada para a equipe.

**Observação:** O funcionamento dessa versão ainda deverá ser confirmado pela equipe no ambiente local.

---

## Etapa 3 — Configuração do ambiente

**Data:** 10–11/11/2026

**Objetivo:** Configurar o ambiente de programação em C e instalar a biblioteca Allegro 5.

**Solicitações realizadas:**
- Identificação do terminal correto do MSYS2.
- Orientações para atualização do MSYS2.
- Instalação e verificação do GCC.
- Instalação do Allegro 5.
- Configuração do terminal UCRT64 no VS Code.
- Correção do reconhecimento da biblioteca pelo IntelliSense.

**Problema encontrado:** O VS Code não reconhecia inicialmente o cabeçalho allegro5/allegro.h.

**Correção:** Configuração do caminho do compilador e dos diretórios de inclusão no VS Code.

**Teste realizado:** Compilação e execução de um programa que cria uma janela gráfica de 800 x 600 pixels durante cinco segundos.

**Resultado:** A janela abriu corretamente e fechou após o tempo programado. O Allegro foi reconhecido na versão 5.2.11.

**Observação:** O Allegro foi configurado e testado, mas sua utilização no TicketQueue ainda não foi definida.

---

## Etapa 4 — Organização dos arquivos

**Data:** 11/11/2026

**Objetivo:** Organizar os arquivos do projeto.

**Problemas encontrados:**
- Arquivos inicialmente acessados dentro de um ZIP.
- Dificuldade para abrir a pasta do projeto no VS Code.
- Arquivos duplicados ou auxiliares fora da pasta principal.
- Diário de desenvolvimento ainda em branco.

**Orientações recebidas:**
- Extrair o ZIP.
- Abrir a pasta no VS Code.
- Identificar os arquivos principais.
- Preservar os registros de IA e os backups.

**Resultado:** Pasta do projeto localizada e arquivo processo-ia.md aberto para atualização.

---

## Histórico integral das interações

Este documento resume as iterações do projeto.

O histórico completo dos prompts, respostas, alternativas, decisões e correções deverá ser preservado e anexado à entrega.

**Evidências a acrescentar:**
- Exportação ou cópia integral das conversas com IA.
- Capturas de tela dos testes.
- Resultados de compilação.
- Histórico de commits, caso seja utilizado Git.
- Registros das próximas etapas de desenvolvimento.


---

## Etapa 5 — Compilação e testes funcionais

**Data:** 11/11/2026

**Objetivo:** Verificar o funcionamento da interface gráfica, da fila FIFO e do controle de ingressos.

**Solicitação à IA:** Orientar a compilação e os testes do TicketQueue no VS Code.

**Comando de compilação:**
gcc main.c fila.c interface.c -o TicketQueue.exe -mwindows

**Resultado da compilação:** Executável gerado sem mensagens de erro.

**Testes realizados:**

1. Inicialização do sistema:
   - Interface gráfica aberta corretamente.
   - Estoque inicial de 10 ingressos.
   - Botões de atendimento desativados com a fila vazia.
   - Resultado: APROVADO.

2. Cadastro de clientes:
   - Ana entrou na posição 1.
   - Raissa entrou na posição 2.
   - Bia entrou na posição 3.
   - Resultado: APROVADO.

3. Atendimento FIFO:
   - O botão "Chamar próximo" foi acionado.
   - Ana foi chamada primeiro.
   - Resultado: APROVADO.

4. Confirmação da compra:
   - Compra de Ana confirmada.
   - Estoque atualizado de 10 para 9 ingressos.
   - Atendimento encerrado.
   - Resultado: APROVADO.

**Problemas encontrados:** Nenhum erro relatado nesses testes.

**Resultado geral:** A implementação demonstrou corretamente a inserção e a remoção FIFO nos cenários testados.

**Observação técnica:** A estrutura utilizada no código é uma fila circular baseada em vetor, com capacidade máxima de 20 usuários. A interface gráfica utiliza a API Win32 do Windows, não a biblioteca Allegro.

**Testes pendentes:** Fila cheia, fila vazia, esgotamento de ingressos e reutilização das posições do vetor circular.

**Evidências:** Capturas de tela da execução e histórico da conversa com IA.
