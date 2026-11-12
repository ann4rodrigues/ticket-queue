
// ==========================================
// TICKETQUEUE - FILA VIRTUAL DE INGRESSOS
// Implementacao de fila circular FIFO
// Adaptada da versao original em C
// ==========================================

// Constantes equivalentes ao fila.h em C
const CAPACIDADE = 20;
const INGRESSOS_INICIAIS = 10;

// Estrutura equivalente a struct Fila
const fila = {
    usuarios: new Array(CAPACIDADE),
    inicio: 0,
    fim: 0,
    quantidade: 0
};

// Inicializa a fila circular
function inicializar_fila() {
    fila.usuarios = new Array(CAPACIDADE);
    fila.inicio = 0;
    fila.fim = 0;
    fila.quantidade = 0;
}

// Verifica se a fila esta vazia
function fila_vazia() {
    return fila.quantidade === 0;
}

// Verifica se a fila esta cheia
function fila_cheia() {
    return fila.quantidade === CAPACIDADE;
}

// Adiciona usuario ao final da fila
function enfileirar(nome) {
    if (fila_cheia() || !nome || !nome.trim()) {
        return false;
    }

    fila.usuarios[fila.fim] = {
        nome: nome.trim()
    };

    // Operacao circular igual a versao em C
    fila.fim = (fila.fim + 1) % CAPACIDADE;
    fila.quantidade++;

    return true;
}

// Remove e retorna o primeiro usuario
function desenfileirar() {
    if (fila_vazia()) {
        return null;
    }

    const usuario = fila.usuarios[fila.inicio];

    fila.usuarios[fila.inicio] = undefined;

    // Operacao circular igual a versao em C
    fila.inicio = (fila.inicio + 1) % CAPACIDADE;
    fila.quantidade--;

    return usuario;
}

// Consulta um usuario pela posicao na fila
function mostrar_fila(posicao) {
    if (posicao < 0 || posicao >= fila.quantidade) {
        return null;
    }

    const indice = (fila.inicio + posicao) % CAPACIDADE;

    return fila.usuarios[indice];
}

// ==========================================
// CONTROLE DE INGRESSOS E ATENDIMENTO
// ==========================================

let ingressos = INGRESSOS_INICIAIS;
let vendidos = 0;
let emAtendimento = null;

// Busca um elemento HTML pelo ID
function elemento(id) {
    return document.getElementById(id);
}

// Exibe mensagens ao usuario
function mensagem(texto, tipo = "info") {
    const aviso = elemento("aviso");

    aviso.textContent = texto;
    aviso.dataset.tipo = tipo;
}

// Atualiza os dados mostrados na tela
function atualizar_interface() {
    elemento("estoque").textContent = ingressos;
    elemento("vendidos").textContent = vendidos;
    elemento("aguardando").textContent = fila.quantidade;

    elemento("capacidade").textContent =
        fila.quantidade + "/" + CAPACIDADE;

    const porcentagem =
        (fila.quantidade / CAPACIDADE) * 100;

    elemento("barra").style.width = porcentagem + "%";

    // Limpa a lista visual
    const lista = elemento("lista");
    lista.replaceChildren();

    // Mostra os usuarios na ordem FIFO
    for (let i = 0; i < fila.quantidade; i++) {
        const usuario = mostrar_fila(i);

        const item = document.createElement("li");

        const posicao = document.createElement("span");
        posicao.className = "posicao";
        posicao.textContent =
            String(i + 1).padStart(2, "0");

        const nomeUsuario = document.createElement("span");
        nomeUsuario.textContent = usuario.nome;

        item.appendChild(posicao);
        item.appendChild(nomeUsuario);

        lista.appendChild(item);
    }

    elemento("vazia").hidden = !fila_vazia();

    // Atualiza quem esta em atendimento
    if (emAtendimento !== null) {
        elemento("atual").textContent =
            emAtendimento.nome;

        elemento("estado-atual").textContent =
            "Aguardando confirmacao de compra";
    } else {
        elemento("atual").textContent =
            "Ninguém em atendimento";

        elemento("estado-atual").textContent =
            "Aguardando chamada";
    }

    // Controle dos botoes
    elemento("entrar").disabled =
        fila_cheia() || ingressos === 0;

    elemento("chamar").disabled =
        fila_vazia() ||
        emAtendimento !== null ||
        ingressos === 0;

    elemento("confirmar").disabled =
        emAtendimento === null ||
        ingressos === 0;

    elemento("esgotado").hidden = ingressos > 0;
}

// ==========================================
// CADASTRO DE PARTICIPANTES
// ==========================================

function cadastrar_usuario(evento) {
    // Impede que o formulario recarregue a pagina
    evento.preventDefault();

    const campoNome = elemento("nome");
    const nome = campoNome.value.trim();

    if (nome === "") {
        mensagem("Digite um nome para entrar na fila.", "erro");
        return;
    }

    if (ingressos === 0) {
        mensagem("Os ingressos estão esgotados.", "erro");
        return;
    }

    if (fila_cheia()) {
        mensagem("A fila está cheia! Limite de 20 pessoas.", "erro");
        return;
    }

    const resultado = enfileirar(nome);

    if (resultado) {
        mensagem(
            nome + " entrou na fila! Posição: " +
            fila.quantidade,
            "sucesso"
        );

        campoNome.value = "";
        campoNome.focus();
    }

    atualizar_interface();
}

// ==========================================
// CHAMAR O PROXIMO PARTICIPANTE
// ==========================================

function chamar_proximo() {
    if (emAtendimento !== null) {
        mensagem(
            "Finalize a compra atual antes de chamar outro participante.",
            "erro"
        );
        return;
    }

    if (fila_vazia()) {
        mensagem("A fila está vazia.", "erro");
        return;
    }

    if (ingressos === 0) {
        mensagem("Os ingressos estão esgotados.", "erro");
        return;
    }

    // Remove o primeiro usuario da fila FIFO
    emAtendimento = desenfileirar();

    mensagem(
        emAtendimento.nome +
        " foi chamado(a) para comprar.",
        "sucesso"
    );

    atualizar_interface();
}

// ==========================================
// CONFIRMAR COMPRA
// ==========================================

function confirmar_compra() {
    if (emAtendimento === null) {
        mensagem(
            "Nenhum participante está em atendimento.",
            "erro"
        );
        return;
    }

    if (ingressos === 0) {
        mensagem("Os ingressos estão esgotados.", "erro");
        return;
    }

    const comprador = emAtendimento.nome;

    // Atualiza o estoque
    ingressos--;
    vendidos++;

    // Finaliza o atendimento
    emAtendimento = null;

    mensagem(
        "Compra confirmada para " + comprador + "!",
        "sucesso"
    );

    atualizar_interface();
}

// ==========================================
// INICIALIZACAO DO SISTEMA
// ==========================================

function iniciar_sistema() {
    inicializar_fila();

    elemento("formulario").addEventListener(
        "submit",
        cadastrar_usuario
    );

    elemento("chamar").addEventListener(
        "click",
        chamar_proximo
    );

    elemento("confirmar").addEventListener(
        "click",
        confirmar_compra
    );

    atualizar_interface();
}

// Espera o HTML estar pronto
document.addEventListener(
    "DOMContentLoaded",
    iniciar_sistema
);
