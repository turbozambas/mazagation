function somar(a, b) {
    return a + b;
}
 
document.getElementById("botao").addEventListener("click", function() {
    let campo1 = document.getElementById("num1").value;
    let campo2 = document.getElementById("num2").value;
 
    if (campo1.trim() === "" || campo2.trim() === "") {
        document.getElementById("resultado").textContent =
            "Preencha os dois campos!";
        return;
    }
 
    let a = Number(campo1);
    let b = Number(campo2);
    let resultado = somar(a, b);
 
    document.getElementById("resultado").textContent =
        "Resultado: " + resultado;
});
