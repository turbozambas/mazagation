const resultado = document.getElementById("resultado");
let nota = 17;
if (nota < 0 || nota > 20) {
    resultado.textContent = "Nota inválida";
} else if (nota >= 10) {
    resultado.textContent = "Aprovado";
} else {
    resultado.textContent = "Não aprovado";
}
