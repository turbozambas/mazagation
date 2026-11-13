function maior(a, b) {
    if (a>b) return a;
    else if (b>a) return b;
    else return "Os números são iguais.";
}

function quadrado(n) {
    return n*n;
}

function maiorDeIdade(idade) {
    if (idade>=18) return "É maior de idade.";
    else return "É menor de idade."
}

document.getElementById("btn-maior").addEventListener("click", function() {
    let a=document.getElementById("maior-a").value;
    let b=document.getElementById("maior-b").value;
    document.getElementById("maior-res").textContent=maior(Number(a), Number(b));
});

document.getElementById("btn-quad").addEventListener("click", function() {
    let q=document.getElementById("quad-n").value;
    document.getElementById("quad-res").textContent=quadrado(q);
});

document.getElementById("btn-idade").addEventListener("click", function() {
    let i=document.getElementById("idade").value;
    document.getElementById("idade-res").textContent=maiorDeIdade(i);
});