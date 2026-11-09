const resultado = document.getElementById("resultado");
function verificarNota(nota) {
    if (nota < 0 || nota > 20) {
        return "Nota inválida";
    } else if (nota >= 10) {
        return "Aprovado";
    } else {
        return "Não aprovado";
    }
}
// Altere 8 para 14 ou 25 e atualize o navegador.
resultado.textContent = verificarNota(8);
