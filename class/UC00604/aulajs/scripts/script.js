console.log("Coiso carregado com sucesso!");

const classificacoes=[12,15,18,7,19,9];
let soma=0;

const mensagem=document.getElementById("resultado");
for (i=0;i<classificacoes.length;i++) {
    soma+=classificacoes[i];

    if (classificacoes[i]<0 || soma[i]>20) { mensagem.innerHTML+=`${classificacoes[i]}Classificação inválida.<br>`; }
    else if (classificacoes[i]>=10) { mensagem.innerHTML+=`${classificacoes[i]} Classificação positiva.<br>`; }
    else { mensagem.innerHTML+=`${classificacoes[i]} Classificação negativa.<br>`; }
}

//let media=soma/classificacoes.length;
//mensagem.textContent+=`${media.toFixed(0)}`;