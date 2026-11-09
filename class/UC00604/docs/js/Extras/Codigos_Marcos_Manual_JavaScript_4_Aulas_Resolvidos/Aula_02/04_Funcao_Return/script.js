const resultado = document.getElementById("resultado");
function calcularMedia(a, b, c) {
    return (a + b + c) / 3;
}
let media = calcularMedia(12, 15, 18);
resultado.textContent = "Média: " + media;
