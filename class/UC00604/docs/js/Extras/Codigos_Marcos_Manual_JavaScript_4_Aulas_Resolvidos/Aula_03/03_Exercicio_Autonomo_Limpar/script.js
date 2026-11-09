const mensagem = document.getElementById("mensagem");
document.getElementById("bomDia").addEventListener("click", function() {
    mensagem.textContent = "Bom dia!";
});
document.getElementById("boaTarde").addEventListener("click", function() {
    mensagem.textContent = "Boa tarde!";
});
document.getElementById("limpar").addEventListener("click", function() {
    mensagem.textContent = "";
});
