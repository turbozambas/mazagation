
const formulario = document.getElementById("formulario");
const mensagem = document.getElementById("mensagem");

formulario.addEventListener("submit", function(evento) {

    evento.preventDefault();

    const nome = document.getElementById("nome").value.trim();
    const email = document.getElementById("email").value.trim();
    const curso = document.getElementById("curso").value;

    if (nome === "") {
        mensagem.textContent = "Introduza o seu nome.";
        mensagem.style.color = "red";

    } else if (email === "") {
        mensagem.textContent = "Introduza o seu email.";
        mensagem.style.color = "red";

    } else if (!document.getElementById("email").checkValidity()) {
        mensagem.textContent = "Introduza um email válido.";
        mensagem.style.color = "red";

    } else if (curso === "") {
        mensagem.textContent = "Selecione um curso.";
        mensagem.style.color = "red";

    } else {
        mensagem.textContent = "Inscrição validada para " + nome +
            " no curso " + curso + ".";
        mensagem.style.color = "green";
    }

});
