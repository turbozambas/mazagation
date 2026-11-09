const campo1 = document.getElementById("num1");
const campo2 = document.getElementById("num2");
const resultado = document.getElementById("resultado");




document.getElementById("somar").onclick = function() {
    
    if (campo1.value.trim() === "" || campo2.value.trim() === "") {
    resultado.textContent = "Os campos não podem estar vazios!";
    return;
    }

    const n1 = Number(campo1.value);
    const n2 = Number(campo2.value);
    if (isNaN(n1) || isNaN(n2)) {
        resultado.textContent = " Insere 2 números válidos " ;
    } else {
        resultado.textContent = "O resultado é: " + (n1 + n2);
    } 
};



document.getElementById("subtrair").onclick = function() {

    if (campo1.value.trim() === "" || campo2.value.trim() === "") {
    resultado.textContent = "Os campos não podem estar vazios!";
    return;
    }

    const n1 = Number(campo1.value);
    const n2 = Number(campo2.value);
    if (isNaN(n1) || isNaN(n2)) {
        resultado.textContent = " Insere 2 números válidos " ;
    } else {
        resultado.textContent = "O resultado é: " + (n1 - n2);
    } 
};


document.getElementById("multiplicar").onclick = function() {

    if (campo1.value.trim() === "" || campo2.value.trim() === "") {
    resultado.textContent = "Os campos não podem estar vazios!";
    return;
    }

    const n1 = Number(campo1.value);
    const n2 = Number(campo2.value);
    if (isNaN(n1) || isNaN(n2)) {
        resultado.textContent = " Insere 2 números válidos " ;
    } else {
        resultado.textContent = "O resultado é: " + (n1 * n2);
    } 
};

document.getElementById("dividir").onclick = function() {

    if (campo1.value.trim() === "" || campo2.value.trim() === "") {
    resultado.textContent = "Os campos não podem estar vazios!";
    return;
    }

    const n1 = Number(campo1.value);
    const n2 = Number(campo2.value);
    if (isNaN(n1) || isNaN(n2)) {
        resultado.textContent = " Insere 2 números válidos " ;
    } else if (n2 === 0) {
        resultado.textContent = "Não é possível dividir por zero!";
    } else {
        resultado.textContent = "O resultado é: " + (n1 / n2);
    } 
};