# Registro de Desenvolvimento com IA — TicketQueue

## Informações do projeto

**Projeto:** TicketQueue — Fila Virtual para Venda de Ingressos Online  
**Disciplina:** Algoritmos e Estruturas de Dados  
**Instituição:** Senac  
**Linguagens utilizadas:** C, HTML, CSS e JavaScript  
**Estrutura de dados:** Fila circular FIFO  
**Ambiente:** Visual Studio Code, GCC, MSYS2 e navegador Web  
**Versionamento:** Git e GitHub  
**Período documentado:** 09/11/2026 a 12/11/2026  
**Repositório:** https://github.com/ann4rodrigues/ticket-queue

---

## Etapa 1 — Planejamento do projeto

**Data:** 09/11/2026

**Objetivo:** Definir as funcionalidades do TicketQueue e a estrutura de dados utilizada.

**Solicitação à IA:** Desenvolver um projeto acadêmico de fila virtual para venda de ingressos online.

**Decisões tomadas:**

- Utilizar o conceito FIFO (*First In, First Out*).
- Organizar os participantes por ordem de chegada.
- Desenvolver inicialmente o projeto em C.
- Implementar uma fila circular.
- Controlar a capacidade máxima de participantes.
- Prever situações de fila cheia, fila vazia e ingressos esgotados.
- Criar uma interface para demonstrar o funcionamento.

**Resultado:** Foram definidos o tema, os requisitos e as etapas iniciais de desenvolvimento.

---

## Etapa 2 — Implementação inicial em C

**Data:** 10/11/2026

**Objetivo:** Desenvolver a primeira implementação funcional do TicketQueue.

A IA auxiliou na criação da versão original em linguagem C, utilizando uma fila circular baseada em vetor e uma interface gráfica Win32.

**Arquivos desenvolvidos:**

- `main.c`
- `fila.c`
- `fila.h`
- `interface.c`
- `interface.h`
- `teste_fila.c`

**Estrutura utilizada:**

A fila possuía capacidade máxima de 20 participantes, com três variáveis principais:

- `inicio`: posição do primeiro participante.
- `fim`: próxima posição de inserção.
- `quantidade`: número de participantes aguardando.

**Funções principais:**

- `inicializar_fila()`
- `fila_vazia()`
- `fila_cheia()`
- `enfileirar()`
- `desenfileirar()`
- `mostrar_fila()`

**Resultado:** Foi criada uma implementação inicial capaz de demonstrar as operações FIFO.

**Observação:** Esta etapa descreve a versão original, posteriormente substituída por uma implementação simplificada em um único arquivo C.

---

## Etapa 3 — Configuração do ambiente de desenvolvimento

**Data:** 10–11/11/2026

**Objetivo:** Configurar as ferramentas necessárias para desenvolver e executar programas em C.

**Atividades realizadas:**

- Configuração do MSYS2 UCRT64.
- Instalação e verificação do GCC.
- Configuração do Visual Studio Code.
- Instalação da biblioteca Allegro 5.
- Ajustes nos diretórios de inclusão do compilador.
- Correção de problemas de reconhecimento de bibliotecas.

**Problema encontrado:** O Visual Studio Code não reconhecia inicialmente o cabeçalho `allegro5/allegro.h`.

**Solução:** Foram configurados os caminhos do compilador e das bibliotecas.

**Teste realizado:** Execução de um programa de teste que abria uma janela de 800 × 600 pixels.

**Resultado:** O ambiente gráfico de teste funcionou corretamente.

**Observação:** O Allegro foi utilizado em testes de configuração, mas a interface gráfica original do TicketQueue utilizava Win32. A versão final simplificada não depende de nenhuma dessas bibliotecas gráficas.

---

## Etapa 4 — Organização dos arquivos

**Data:** 11/11/2026

**Objetivo:** Organizar os arquivos de código e documentação.

**Dificuldades encontradas:**

- Arquivos inicialmente acessados dentro de um ZIP.
- Dificuldade para abrir a pasta correta no VS Code.
- Existência de arquivos auxiliares e duplicados.
- Documentação incompleta.

**Orientações da IA:**

- Identificar a pasta principal do projeto.
- Separar os arquivos de código e documentação.
- Preservar os códigos originais.
- Registrar as alterações realizadas.
- Evitar a exclusão de arquivos antes de manter uma cópia.

**Resultado:** Os arquivos foram reorganizados para facilitar o desenvolvimento e o versionamento.

---

## Etapa 5 — Compilação e testes da implementação original em C

**Data:** 11/11/2026

**Objetivo:** Verificar o funcionamento da versão original com interface gráfica Win32.

**Comando de compilação registrado:**

```bash
gcc main.c fila.c interface.c -o TicketQueue.exe -mwindows
```

### Teste 1 — Inicialização

A interface gráfica foi aberta, apresentando o estoque inicial de 10 ingressos.

**Resultado:** Aprovado.

### Teste 2 — Cadastro de participantes

Foram cadastrados três participantes:

1. Ana.
2. Raissa.
3. Bia.

**Resultado:** Aprovado.

### Teste 3 — Atendimento FIFO

Ao chamar o próximo participante, Ana foi selecionada primeiro.

**Resultado:** Aprovado.

### Teste 4 — Confirmação de compra

Após a confirmação de uma compra, o estoque passou de 10 para 9 ingressos.

**Resultado:** Aprovado.

### Resultado geral

Os testes demonstraram o funcionamento das operações básicas da fila FIFO e do controle de estoque da implementação original.

**Limitação:** Não foram confirmados nessa etapa os testes completos de fila cheia, reutilização circular e esgotamento total dos ingressos.

**Observação:** Esses resultados pertencem à implementação original, não à versão simplificada em C.

---

## Etapa 6 — Desenvolvimento da versão Web

**Data:** 11/11/2026

**Objetivo:** Criar uma versão do TicketQueue executada diretamente no navegador.

**Tecnologias utilizadas:**

- HTML para a estrutura da página.
- CSS para a aparência visual.
- JavaScript para as operações da fila.

**Arquivos desenvolvidos:**

- `index.html`
- `style.css`
- `script.js`

**Decisões tomadas:**

- Preservar o conceito FIFO.
- Manter a capacidade máxima de 20 participantes.
- Manter o estoque inicial de 10 ingressos.
- Implementar uma fila circular em JavaScript.
- Personalizar a interface para uma simulação fictícia de show do Travis Scott.

### Testes da versão Web

**Teste 1 — Ordem FIFO:** Ana foi atendida antes de Raissa e Bia. Resultado: aprovado.

**Teste 2 — Controle de estoque:** Uma compra reduziu o estoque de 10 para 9 ingressos. Resultado: aprovado.

**Teste 3 — Fila cheia:** Após cadastrar 20 participantes, a tentativa de entrada do 21º foi impedida. Resultado: aprovado.

**Teste 4 — Reutilização circular:** Após o atendimento de participantes, novas pessoas conseguiram entrar na fila. Resultado: aprovado.

**Teste 5 — Esgotamento de ingressos:** O sistema apresentou uma mensagem informando que não havia mais ingressos disponíveis. Resultado: mensagem confirmada.

**Limitação:** O bloqueio de todas as operações após o esgotamento não foi registrado como teste independente.

**Resultado geral:** A versão Web demonstrou a aplicação da fila circular FIFO em uma simulação visual de venda de ingressos.

---

## Etapa 7 — Publicação da versão Web no GitHub

**Data:** 11/11/2026

**Objetivo:** Publicar o código-fonte e registrar o desenvolvimento do projeto.

**Ferramentas utilizadas:**

- Git.
- GitHub.
- PowerShell integrado ao Visual Studio Code.

**Etapas realizadas:**

1. Inicialização do repositório Git.
2. Configuração da branch `main`.
3. Adição dos arquivos.
4. Criação do commit inicial.
5. Conexão com o repositório remoto.
6. Envio utilizando `git push`.

**Commit inicial registrado:** `d357fc7`

**Repositório:** https://github.com/ann4rodrigues/ticket-queue

**Resultado:** A versão Web foi publicada no GitHub.

---

## Etapa 8 — Recuperação e publicação da versão original em C

**Data:** 12/11/2026

**Objetivo:** Preservar os arquivos originais em C no mesmo repositório da versão Web.

### 8.1. Recuperação

Foram recuperados os arquivos:

- `fila.c`
- `fila.h`
- `main.c`
- `interface.c`
- `interface.h`
- `teste_fila.c`

Os arquivos foram organizados na pasta `versao-c/TicketQueue`.

### 8.2. Análise da estrutura

A IA auxiliou na identificação dos elementos principais:

- Vetor de capacidade 20.
- Índices `inicio` e `fim`.
- Contador `quantidade`.
- Operações de inserção e remoção.
- Utilização do operador módulo `%`.
- Atendimento FIFO.

### 8.3. Dificuldades com o Git

Durante o processo, ocorreu o erro:

```text
fatal: not a git repository
```

**Causa:** Os comandos estavam sendo executados fora da pasta principal do repositório.

**Solução:** Acessar a pasta `Ticket-Final` antes de executar os comandos Git.

Também foram encontrados avisos de conversão de quebras de linha LF/CRLF, que não impediram o versionamento.

### 8.4. Publicação

Foram utilizados comandos de adição, commit e envio dos arquivos.

**Resultado:** A versão original em C passou a integrar o repositório, permitindo sua consulta e comparação com a implementação Web.

**Observação:** Posteriormente, foi identificado que um executável `.exe` também havia sido enviado. Foi recomendada sua remoção do controle de versão e a utilização de um arquivo `.gitignore`.

---

## Etapa 9 — Estudo e preparação para a apresentação

**Data:** 12/11/2026

**Objetivo:** Compreender o funcionamento do código para explicar as decisões técnicas ao professor.

**Conteúdos estudados:**

- Conceito FIFO.
- Funcionamento de uma fila circular.
- Diferença entre capacidade e quantidade de participantes.
- Índices `inicio` e `fim`.
- Operações `enfileirar()` e `desenfileirar()`.
- Tratamento de fila cheia e vazia.
- Reutilização de posições com o operador `%`.

Durante essa preparação, também foi discutida a possibilidade de utilizar uma fila de tamanho variável, em comparação com a capacidade fixa de 20 posições.

**Resultado:** O estudo ajudou a identificar a necessidade de simplificar o código em C para aproximá-lo dos conteúdos abordados em aula.

---

## Etapa 10 — Simplificação da implementação em C

**Data:** 12/11/2026

**Objetivo:** Adequar a implementação em C ao nível de conhecimento da equipe, mantendo a lógica FIFO.

### 10.1. Justificativa

A implementação original utilizava vários arquivos e uma interface gráfica Win32.

Após revisar o projeto e os conteúdos estudados na disciplina, foi decidido que uma implementação mais simples seria suficiente para demonstrar a estrutura de dados.

Como a versão Web já oferecia uma interface visual, a versão em C passou a ter como objetivo principal a demonstração da fila no terminal.

### 10.2. Referência utilizada

A organização do novo código foi baseada no estilo de um exemplo de pilha apresentado pelo professor.

Esse exemplo utilizava:

- Vetor global.
- Variáveis globais de controle.
- Funções declaradas antes de `main()`.
- Menu textual.
- Estruturas condicionais e de repetição.

A lógica da pilha não foi copiada, pois o TicketQueue utiliza fila FIFO, e não pilha LIFO.

### 10.3. Alterações realizadas

- Reunião do código em um único `main.c`.
- Remoção da dependência da interface gráfica Win32.
- Utilização de matriz de caracteres para armazenar nomes.
- Utilização de variáveis globais.
- Implementação de menu no terminal.
- Manutenção da fila circular.
- Preservação da capacidade de 20 participantes.
- Separação entre a demonstração em C e a simulação Web.

### 10.4. Estrutura de dados atual

```c
#define MAX 20
#define TAM_NOME 60

char fila[MAX][TAM_NOME];

int inicio = 0;
int fim = 0;
int quantidade = 0;
```

A matriz `fila` armazena os nomes dos participantes.

As variáveis `inicio`, `fim` e `quantidade` controlam o funcionamento da fila.

A operação circular utiliza o operador módulo:

```c
fim = (fim + 1) % MAX;
inicio = (inicio + 1) % MAX;
```

### 10.5. Funções implementadas

- `fila_vazia()`: verifica se a fila está vazia.
- `fila_cheia()`: verifica se a fila está cheia.
- `enfileirar()`: adiciona um participante.
- `desenfileirar()`: atende o primeiro participante.
- `consultar_primeiro()`: consulta o próximo sem removê-lo.
- `mostrar_fila()`: apresenta os participantes em ordem.
- `mostrar_quantidade()`: exibe a quantidade atual.
- `limpar_entrada()`: descarta caracteres restantes da entrada.
- `main()`: controla o menu e a execução.

### 10.6. Menu da aplicação

```text
===== TICKETQUEUE =====
1 - Entrar na fila
2 - Atender proximo usuario
3 - Mostrar fila
4 - Mostrar quantidade de usuarios
5 - Consultar proximo usuario
0 - Sair
```

O programa utiliza `do...while` para repetir o menu e `switch...case` para selecionar as operações.

### 10.7. Compilação

O código pode ser compilado com GCC:

```bash
gcc main.c -o TicketQueue.exe
```

No PowerShell, a execução pode ser realizada com:

```powershell
.\TicketQueue.exe
```

A versão atual não depende de bibliotecas gráficas.

### 10.8. Diferença entre as implementações

**Versão C atual:**

- Executada no terminal.
- Código concentrado em `main.c`.
- Demonstração da fila circular FIFO.
- Capacidade máxima de 20 participantes.
- Não possui venda ou controle de estoque de ingressos.

**Versão Web:**

- Executada no navegador.
- Desenvolvida em HTML, CSS e JavaScript.
- Interface visual personalizada.
- Fila circular FIFO.
- Simulação de venda de ingressos.
- Estoque inicial de 10 ingressos.

As duas versões são independentes e não compartilham automaticamente os dados cadastrados.

### 10.9. Testes da nova implementação

O código foi organizado para permitir os seguintes testes:

1. Cadastro de participantes.
2. Atendimento por ordem FIFO.
3. Consulta do próximo participante.
4. Exibição da fila.
5. Verificação de fila vazia.
6. Verificação de fila cheia.
7. Reutilização circular das posições.
8. Tratamento de opções inválidas.

**Situação:** A nova implementação foi disponibilizada para execução. Os testes completos de capacidade e reutilização circular ainda precisam ser confirmados e registrados pela equipe.

### 10.10. Resultado

A implementação em C foi simplificada, aproximando sua estrutura dos conteúdos estudados na disciplina.

O funcionamento FIFO foi preservado, enquanto a organização do código passou a utilizar apenas um arquivo principal e um menu textual.

---

## Histórico das interações com inteligência artificial

O histórico dos prompts e das respostas da IA está organizado separadamente no arquivo:

`documentacao/historico-prompt.md`

Esse documento registra as solicitações realizadas, as respostas resumidas e as decisões tomadas durante o desenvolvimento.

**Limitação documental:** Parte das respostas antigas foi recuperada por meio de resumos. Esses registros não substituem as transcrições completas das conversas originais.

Para atender a uma exigência de histórico integral, devem ser preservadas as conversas originais e os códigos fornecidos pela IA, quando disponíveis.

---

## Evidências do desenvolvimento

As principais evidências do projeto são:

- Código original em C.
- Código simplificado em `main.c`.
- Arquivos da versão Web.
- Registros de testes.
- Capturas de tela.
- Histórico de commits do GitHub.
- Diário de desenvolvimento.
- Histórico de prompts e respostas da IA.

---

## Conclusão

O desenvolvimento do TicketQueue permitiu aplicar o conceito de fila FIFO em uma simulação acadêmica de atendimento para venda de ingressos online.

O projeto passou por diferentes etapas, incluindo implementação inicial em C, configuração do ambiente, testes, desenvolvimento da versão Web, publicação no GitHub e simplificação do código original.

A versão atual em C utiliza uma matriz de caracteres, variáveis globais e funções simples, permitindo demonstrar as operações fundamentais de uma fila circular.

A versão Web permanece como demonstração visual da aplicação de venda de ingressos.

A utilização da inteligência artificial contribuiu para o planejamento, a programação, a identificação de problemas, a documentação e a organização do desenvolvimento.

As alterações realizadas foram registradas para preservar o histórico e justificar as decisões técnicas adotadas.