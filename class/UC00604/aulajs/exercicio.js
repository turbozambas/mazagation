function subtrair(a, b) {
    return a-b;
}

function paraMaiusculas(c) {
    return c.toUpperCase();
}

function contarCaracteres(d) {
    return d.length;
}

document.getElementById("btn-sub").addEventListener("click", function() {
    let a=document.getElementById("sub-a").value;
    let b=document.getElementById("sub-b").value;
    if (a.trim==="" || b.trim==="") {
        document.getElementById("sub-res").textContent="Preencha os dois campos";
    }
    document.getElementById("sub-res").textContent=subtrair(Number(a),Number(b));
});

document.getElementById("btn-upper").addEventListener("click", function() {
    let c=document.getElementById("nome").value;
    document.getElementById("upper-res").textContent=paraMaiusculas(c);
});

document.getElementById("btn-contar").addEventListener("click", function() {
    let d=document.getElementById("texto").value;
    document.getElementById("contar-res").textContent=contarCaracteres(d);
});