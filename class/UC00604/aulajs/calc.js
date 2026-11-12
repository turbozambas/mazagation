function subtrair(a, b) {
    return a-b;
}

function somar(a, b) {
    return a+b;
}

function multiplicar(a, b) {
    return a*b;
}

function dividir(a, b) {
    return a/b;
}

document.getElementById("btn-subtrair").addEventListener("click", function() {
    let a=document.getElementById("sub-a").value;
    let b=document.getElementById("sub-b").value;
    if (a.trim==="" || b.trim==="") {
        document.getElementById("sub-res").textContent="Preencha os dois campos";
    }
    document.getElementById("sub-res").textContent=subtrair(Number(a),Number(b));
});

document.getElementById("btn-somar").addEventListener("click", function() {
    let a=document.getElementById("sub-a").value;
    let b=document.getElementById("sub-b").value;
    if (a.trim==="" || b.trim==="") {
        document.getElementById("sub-res").textContent="Preencha os dois campos";
    }
    document.getElementById("sub-res").textContent=somar(Number(a),Number(b));
});

document.getElementById("btn-multiplicar").addEventListener("click", function() {
    let a=document.getElementById("sub-a").value;
    let b=document.getElementById("sub-b").value;
    if (a.trim==="" || b.trim==="") {
        document.getElementById("sub-res").textContent="Preencha os dois campos";
    }
    document.getElementById("sub-res").textContent=multiplicar(Number(a),Number(b));
});

document.getElementById("btn-dividir").addEventListener("click", function() {
    let a=document.getElementById("sub-a").value;
    let b=document.getElementById("sub-b").value;
    if (a.trim==="" || b.trim==="") {
        document.getElementById("sub-res").textContent="Preencha os dois campos";
    }
    document.getElementById("sub-res").textContent=dividir(Number(a),Number(b));
});