const formulario = document.getElementById("formulario");
const mensagem = document.getElementById("mensagem");
formulario.addEventListener("submit", function(evento) {
    evento.preventDefault();
    const nome = document.getElementById("nome").value.trim();
    const email = document.getElementById("email").value.trim();
    const curso = document.getElementById("curso").value;
    const observacoes = document.getElementById("observacoes").value.trim();
    if (nome === "" || email === "" || curso === "" || observacoes === "") {
        mensagem.textContent = "Preencha todos os campos.";
        mensagem.style.color = "red";
    } else if (!document.getElementById("email").checkValidity()) {
        mensagem.textContent = "Introduza um email válido.";
        mensagem.style.color = "red";
    } else {
        mensagem.textContent = "Inscrição validada para " + nome + " (" + email + ") no curso " + curso + ". Observações: " + observacoes;
        mensagem.style.color = "green";
    }
});
