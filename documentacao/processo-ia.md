# Registro de Desenvolvimento com IA — TicketQueue

## Informações do projeto

**Disciplina:** Algoritmos e Estruturas de Dados — SENAC  
**Projeto:** TicketQueue — Fila Virtual para Venda de Ingressos Online  
**Linguagens utilizadas:** C, HTML, CSS e JavaScript  
**Estrutura de dados:** Fila circular baseada em vetor (FIFO)  
**Ambiente de desenvolvimento:** Visual Studio Code, MSYS2 UCRT64, GCC e navegador Web  
**Versionamento:** Git e GitHub  
**Repositório:** https://github.com/ann4rodrigues/ticket-queue

---

## Etapa 1 — Planejamento do projeto

**Data:** 10/11/2026

**Objetivo:** Definir o problema, as funcionalidades e a estrutura de dados que seria utilizada no TicketQueue.

**Prompt utilizado:** Solicitação de planejamento do projeto acadêmico conforme as orientações do professor, utilizando o tema de fila virtual para venda de ingressos.

**Resposta recebida:** A IA propôs um sistema que organiza participantes por ordem de chegada, utilizando uma estrutura de dados FIFO (*First In, First Out*).

**Decisões tomadas:**

- Desenvolver inicialmente o projeto em linguagem C.
- Implementar uma fila circular baseada em vetor.
- Organizar o atendimento pela ordem de chegada.
- Controlar o estoque de ingressos.
- Tratar situações de fila cheia, fila vazia e ingressos esgotados.
- Utilizar uma interface simples para facilitar a demonstração.

**Resultado:** Foram definidas as funcionalidades, as operações da fila e as etapas de desenvolvimento.

---

## Etapa 2 — Implementação inicial em C

**Data:** 10/11/2026

**Objetivo:** Desenvolver a primeira versão funcional do TicketQueue.

**Prompt utilizado:** Solicitação de implementação do sistema em C, com explicações das funções e organização dos arquivos.

**Resposta recebida:** A IA auxiliou na implementação das operações de inserção, remoção, consulta e verificação da fila.

**Arquivos desenvolvidos:**

- `main.c`
- `fila.c`
- `fila.h`
- `interface.c`
- `interface.h`
- `teste_fila.c`

**Estrutura de dados utilizada:**

A fila foi implementada utilizando um vetor com capacidade máxima de 20 participantes.

Foram utilizadas três variáveis de controle:

- `inicio`: indica a posição do primeiro participante.
- `fim`: indica a próxima posição disponível para inserção.
- `quantidade`: controla o número de participantes aguardando.

**Principais funções:**

- `inicializar_fila()`: inicializa a estrutura.
- `fila_vazia()`: verifica se não existem participantes aguardando.
- `fila_cheia()`: verifica se a capacidade máxima foi atingida.
- `enfileirar()`: adiciona um participante ao final da fila.
- `desenfileirar()`: remove o primeiro participante.
- `mostrar_fila()`: consulta os participantes sem removê-los.

**Resultado:** Foi desenvolvida uma implementação em C que utiliza uma fila circular para organizar o atendimento FIFO.

---

## Etapa 3 — Configuração do ambiente de desenvolvimento

**Data:** 10–11/11/2026

**Objetivo:** Configurar o ambiente de programação em C e testar as ferramentas necessárias.

**Solicitações realizadas à IA:**

- Identificação do terminal correto do MSYS2.
- Orientações para atualização do MSYS2.
- Instalação e verificação do GCC.
- Instalação da biblioteca Allegro 5.
- Configuração do terminal UCRT64 no Visual Studio Code.
- Correção do reconhecimento de bibliotecas pelo IntelliSense.

**Problema encontrado:** O Visual Studio Code não reconhecia inicialmente o cabeçalho `allegro5/allegro.h`.

**Correção:** Foram configurados o caminho do compilador e os diretórios de inclusão no VS Code.

**Teste realizado:** Compilação e execução de um programa que criava uma janela gráfica de 800 × 600 pixels durante cinco segundos.

**Resultado:** A janela abriu corretamente e fechou após o tempo programado. Foi registrada a utilização da versão 5.2.11 do Allegro.

**Observação importante:** Embora o Allegro tenha sido configurado e testado durante o desenvolvimento, a interface gráfica original do TicketQueue foi implementada utilizando a API Win32 do Windows, e não o Allegro.

---

## Etapa 4 — Organização dos arquivos

**Data:** 11/11/2026

**Objetivo:** Organizar os arquivos e preparar a estrutura do projeto para desenvolvimento e documentação.

**Problemas encontrados:**

- Arquivos inicialmente acessados dentro de um ZIP.
- Dificuldade para abrir a pasta correta no VS Code.
- Arquivos duplicados ou auxiliares fora da pasta principal.
- Diário de desenvolvimento ainda incompleto.

**Orientações recebidas da IA:**

- Extrair os arquivos do ZIP.
- Abrir a pasta correta no Visual Studio Code.
- Identificar os arquivos principais do projeto.
- Preservar os códigos originais e os backups.
- Registrar as etapas de desenvolvimento.

**Resultado:** Os arquivos foram organizados e a documentação passou a ser atualizada durante o desenvolvimento.

---

## Etapa 5 — Compilação e testes funcionais da versão em C

**Data:** 11/11/2026

**Objetivo:** Verificar o funcionamento da interface gráfica, da fila FIFO e do controle de ingressos.

**Solicitação à IA:** Orientar a compilação e os testes do TicketQueue no Visual Studio Code.

**Comando de compilação registrado:**

```bash
gcc main.c fila.c interface.c -o TicketQueue.exe -mwindows
```

**Resultado da compilação:** O executável foi gerado sem mensagens de erro.

### Teste 1 — Inicialização

- Interface gráfica aberta corretamente.
- Estoque inicial de 10 ingressos.
- Botões de atendimento desativados quando a fila estava vazia.

**Resultado:** APROVADO.

### Teste 2 — Cadastro de participantes

Foram cadastrados os participantes:

1. Ana — posição 1.
2. Raissa — posição 2.
3. Bia — posição 3.

**Resultado:** APROVADO.

### Teste 3 — Atendimento FIFO

O botão de chamar o próximo participante foi acionado.

Ana foi chamada primeiro, respeitando a ordem de chegada.

**Resultado:** APROVADO.

### Teste 4 — Confirmação da compra

- Compra de Ana confirmada.
- Estoque atualizado de 10 para 9 ingressos.
- Atendimento encerrado.

**Resultado:** APROVADO.

**Resultado geral:** A implementação demonstrou corretamente o funcionamento das operações básicas de inserção, remoção e atendimento FIFO nos cenários testados.

**Observação técnica:** A fila utilizada é circular e baseada em vetor, com capacidade máxima de 20 participantes. A interface gráfica utiliza a API Win32.

**Testes ainda não confirmados nessa versão:** Capacidade máxima da fila, reutilização das posições circulares e esgotamento total dos ingressos.

---

## Etapa 6 — Migração para a versão Web

**Data:** 11/11/2026

**Objetivo:** Desenvolver uma versão Web do TicketQueue, preservando a lógica FIFO implementada inicialmente em C.

**Solicitações à IA:**

- Reconstruir o projeto utilizando HTML, CSS e JavaScript.
- Criar uma nova pasta de trabalho.
- Fornecer os códigos diretamente na conversa para copiar no VS Code.
- Personalizar a interface para a simulação de um show do Travis Scott.
- Melhorar a aparência visual da página.

**Decisões tomadas:**

- Utilizar HTML para estruturar a página.
- Utilizar CSS para a identidade visual.
- Utilizar JavaScript para implementar a fila circular.
- Manter a capacidade máxima de 20 participantes.
- Manter o estoque inicial de 10 ingressos.
- Preservar o atendimento FIFO.
- Executar o sistema diretamente no navegador.

**Arquivos principais:**

- `index.html`
- `style.css`
- `script.js`

### Funcionamento da versão Web

O sistema permite cadastrar participantes, visualizar a fila, chamar o próximo participante e confirmar compras.

A lógica utiliza os índices `inicio` e `fim`, além da variável `quantidade`, assim como na implementação original em C.

O operador módulo (`%`) é utilizado para permitir a reutilização circular das posições do vetor.

### Testes realizados

**Teste 1 — Cadastro e ordem FIFO**

Foram cadastrados Ana, Raissa e Bia. Ana foi chamada primeiro.

**Resultado:** APROVADO.

**Teste 2 — Controle de estoque**

Após a confirmação de uma compra, o estoque passou de 10 para 9 ingressos.

**Resultado:** APROVADO.

**Teste 3 — Capacidade máxima da fila**

Foram cadastrados 20 participantes. A tentativa de entrada do 21º participante foi impedida.

**Resultado:** APROVADO.

**Teste 4 — Reutilização de posições**

Após a retirada de participantes, novas pessoas conseguiram entrar na fila.

Esse comportamento demonstrou a reutilização das posições liberadas no vetor circular.

**Resultado:** APROVADO.

**Teste 5 — Esgotamento de ingressos**

O estoque foi reduzido até chegar a zero.

O sistema apresentou uma mensagem informando que não havia mais ingressos disponíveis.

**Resultado:** Mensagem de esgotamento confirmada.

**Observação:** O bloqueio de todas as operações de atendimento e compra após o esgotamento não foi registrado como teste independente.

**Resultado geral:** A versão Web demonstrou o funcionamento da fila circular FIFO nos cenários testados, com interface personalizada para o evento fictício.

---

## Etapa 7 — Publicação da versão Web no GitHub

**Data:** 11/11/2026

**Objetivo:** Publicar o projeto em um repositório remoto para permitir o acesso ao código e registrar seu desenvolvimento.

**Solicitação à IA:** Orientar a utilização do Git e do GitHub pelo terminal do Visual Studio Code.

**Ferramentas utilizadas:**

- Git.
- GitHub.
- Terminal PowerShell do VS Code.

**Etapas realizadas:**

1. Inicialização do repositório Git.
2. Configuração da branch `main`.
3. Adição dos arquivos do projeto.
4. Criação do commit inicial.
5. Conexão com o repositório remoto.
6. Envio dos arquivos utilizando `git push`.

**Commit inicial registrado:** `d357fc7`

**Repositório:** https://github.com/ann4rodrigues/ticket-queue

**Resultado:** A versão Web do TicketQueue foi publicada com sucesso no GitHub.

---

## Etapa 8 — Recuperação e publicação da versão original em C

**Data:** 12/11/2026

**Objetivo:** Recuperar os arquivos originais do TicketQueue desenvolvidos em linguagem C e adicioná-los ao repositório do GitHub, preservando a implementação Web.

### 8.1. Recuperação dos arquivos

Durante a organização do projeto, foram localizados os arquivos da implementação original em C:

- `fila.h`
- `fila.c`
- `main.c`
- `interface.h`
- `interface.c`
- `teste_fila.c`

Também foram identificados arquivos de documentação e um executável compilado.

A versão original foi preservada para permitir o estudo da estrutura de dados FIFO e sua comparação com a implementação em JavaScript.

### 8.2. Análise da estrutura FIFO

Os arquivos `fila.h` e `fila.c` foram compartilhados com a inteligência artificial para análise e explicação.

Foram identificados os seguintes elementos:

- Vetor de capacidade máxima de 20 participantes.
- Variável `inicio`, que indica o primeiro participante.
- Variável `fim`, que indica a próxima posição de inserção.
- Variável `quantidade`, que controla o número de participantes.
- Funções `enfileirar()` e `desenfileirar()`.
- Funções `fila_vazia()`, `fila_cheia()` e `mostrar_fila()`.

A implementação utiliza uma fila circular e o operador módulo (`%`) para permitir que os índices retornem ao início do vetor.

O princípio FIFO garante que o primeiro participante cadastrado seja o primeiro a ser atendido.

### 8.3. Organização dos arquivos

Foi criada uma pasta denominada `versao-c` dentro do projeto Web.

Os arquivos originais foram copiados para essa pasta, mantendo as versões em C e JavaScript no mesmo repositório.

**Estrutura do projeto:**

```text
Ticket-Final/
├── index.html
├── style.css
├── script.js
├── documentacao/
│   ├── processo-ia.md
│   └── historico-prompt.md
└── versao-c/
    └── TicketQueue/
        ├── fila.c
        ├── fila.h
        ├── main.c
        ├── interface.c
        ├── interface.h
        ├── teste_fila.c
        ├── README.md
        └── processo-ia.md
```

O executável `TicketQueue.exe` foi mantido fora do envio ao GitHub, pois não é necessário para a análise do código-fonte.

### 8.4. Dificuldades encontradas

Durante a publicação, o comando `git status` apresentou o erro:

```text
fatal: not a git repository
```

A causa foi a execução do comando fora da pasta principal do repositório.

Após acessar a pasta `Ticket-Final`, o Git passou a reconhecer corretamente o projeto.

Posteriormente, a pasta `versao-c` apareceu como não rastreada (*untracked*).

Uma tentativa inicial de commit não incluiu os arquivos, e o Git informou que não havia alterações preparadas.

### 8.5. Solução aplicada

A inteligência artificial orientou a inclusão dos arquivos de código-fonte e documentação utilizando o comando:

```powershell
git add -- "versao-c/**/*.c" "versao-c/**/*.h" "versao-c/**/*.md"
```

Em seguida, foram utilizados os comandos:

```powershell
git commit -m "Adiciona codigo original em C do TicketQueue"
git push
```

Durante a preparação dos arquivos, apareceram avisos relacionados à conversão de quebras de linha de LF para CRLF, que não impediram o versionamento.

### 8.6. Resultado

A publicação foi confirmada por meio da interface do GitHub.

O repositório passou a apresentar:

- `documentacao/`: histórico e diário de desenvolvimento.
- `versao-c/TicketQueue/`: implementação original em C.
- `index.html`, `style.css` e `script.js`: implementação Web.

**Repositório:** https://github.com/ann4rodrigues/ticket-queue

A recuperação dos arquivos permitiu preservar as duas versões do projeto e disponibilizar o código em C para estudo da estrutura FIFO.

---

## Etapa 9 — Preparação para a apresentação

**Data:** 12/11/2026

**Objetivo:** Preparar a equipe para explicar o funcionamento do TicketQueue e demonstrar a aplicação dos conceitos de estrutura de dados.

**Atividades realizadas:**

- Revisão do código original em C.
- Explicação das estruturas `Usuario` e `Fila`.
- Análise das funções `enfileirar()` e `desenfileirar()`.
- Explicação das verificações de fila cheia e fila vazia.
- Estudo da utilização do operador módulo na fila circular.
- Seleção de trechos do código para demonstrar o funcionamento FIFO.

**Pontos principais para a apresentação:**

1. O conceito FIFO e sua aplicação no sistema.
2. O funcionamento dos índices `inicio` e `fim`.
3. A utilização do vetor de 20 posições.
4. A inserção e remoção de participantes.
5. A reutilização de posições na fila circular.
6. A relação entre a versão original em C e a versão Web em JavaScript.

**Próxima atividade:** Continuar o estudo do código e ensaiar a demonstração do sistema.

---

## Histórico das interações com inteligência artificial

Este documento apresenta o registro cronológico das principais etapas, decisões, dificuldades e resultados do desenvolvimento do TicketQueue.

O histórico dos prompts e das respostas da IA está organizado separadamente no arquivo:

`documentacao/historico-prompt.md`

**Limitação documental:** Parte das respostas antigas da IA foi recuperada por meio de resumos e reconstruções. Esses registros não substituem as transcrições literais completas das conversas originais.

Para atender à exigência de histórico integral, as conversas originais e os códigos completos fornecidos pela IA devem ser preservados e anexados quando disponíveis.

**Evidências do desenvolvimento:**

- Arquivos originais em C.
- Código da versão Web.
- Registros dos testes realizados.
- Capturas de tela da execução.
- Histórico de commits do GitHub.
- Diário de desenvolvimento.
- Histórico de prompts e respostas da IA.

---

## Conclusão

O desenvolvimento do TicketQueue permitiu aplicar o conceito de fila FIFO em uma simulação de venda de ingressos online.

A primeira versão foi desenvolvida em linguagem C, utilizando uma fila circular baseada em vetor e uma interface gráfica Win32.

Posteriormente, o sistema foi adaptado para HTML, CSS e JavaScript, preservando os principais conceitos da estrutura de dados.

Os testes realizados demonstraram o funcionamento do atendimento por ordem de chegada, do controle de estoque, da capacidade máxima da fila e da reutilização de posições.

A utilização da inteligência artificial contribuiu para o planejamento, a implementação, a resolução de problemas, a documentação e a organização do projeto.

As duas versões foram preservadas no GitHub para consulta, estudo e apresentação acadêmica.